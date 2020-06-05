/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include <iostream>
#include "MarketWindow.h"
#include "../data/model/MarketGroupItem.h"

MarketWindow::MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) noexcept : Gtk::Window(object), builder(glade_ref)
{
    // Set widgets to builder
    builder->get_widget(get_trv_mktg_name(), trv_market_groups);
    builder->get_widget(get_se_item_name(), se_item);

    // Make TreeModel with MarketGroupColumn
    ref_tree_model = Gtk::TreeStore::create(market_group_columns);

    // Set model to TreeView
    trv_market_groups->set_model(ref_tree_model);

    // Set activation function to TreeView
    trv_market_groups->signal_row_activated().connect(sigc::mem_fun(*this, &MarketWindow::on_trv_row_activated));
}

MarketWindow::~MarketWindow() noexcept
= default;

void MarketWindow::on_trv_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column)
{
    // stub implementation
    Gtk::TreeModel::iterator iter = ref_tree_model->get_iter(path);
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        std::cout << "Row  Name="
                  << row[market_group_columns.name] << std::endl;
    }
}

void MarketWindow::populate_market_group_trv(const std::vector<MarketGroupItem>& market_group_items) const noexcept
{
    std::vector<Gtk::TreeIter> parent_rows;
    std::vector<MarketGroupItem> mkgp_tmp(market_group_items);

    std::cout << mkgp_tmp.size() << std::endl;

    // Get the first rows
    for (std::vector<MarketGroupItem>::iterator it = mkgp_tmp.begin(); it != mkgp_tmp.end();) {
        if (it->get_parent_id() == 0) {

            // Make a new row
            Gtk::TreeIter tree_it = ref_tree_model->append();
            Gtk::TreeModel::Row r = *tree_it;

            // Set name to row
            r[market_group_columns.name] = get_market_group_name_by_language(*it);
            r[market_group_columns.id] = it->get_id();

            parent_rows.push_back(tree_it);
            mkgp_tmp.erase(it);
        } else {
            ++it;
        }
    }

    while (!mkgp_tmp.empty()) {
        std::vector<Gtk::TreeIter> children_tmp;

        // Do for all parents
        for (const Gtk::TreeIter& tree_it : parent_rows) {

            // Find item id of the parent row
            unsigned int item_id = (*tree_it)[market_group_columns.id];

            // Find all children of this row
            // Create a new row for this child
            // Add this child to the parent row
            // Add this child to the children_tmp vector
            // Delete this item from the mkgp_tmp vector
            for (std::vector<MarketGroupItem>::iterator it = mkgp_tmp.begin(); it != mkgp_tmp.end();) {
                if (it->get_parent_id() == item_id) {
                    Gtk::TreeIter child_it = ref_tree_model->append(tree_it->children());
                    Gtk::TreeModel::Row child_row = *child_it;

                    child_row[market_group_columns.id] = it->get_id();
                    child_row[market_group_columns.name] = get_market_group_name_by_language(*it);

                    children_tmp.push_back(child_it);
                    mkgp_tmp.erase(it);
                } else {
                    ++it;
                }
            }
        }

        parent_rows = children_tmp;
    }

    trv_market_groups->append_column("Icon", market_group_columns.icon);
    trv_market_groups->append_column("Name", market_group_columns.name);
}

Glib::ustring MarketWindow::get_market_group_name_by_language(const MarketGroupItem &item) const noexcept
{
    // Get all names and find the name with the specific language
    std::vector<std::pair<Glib::ustring, Glib::ustring>> names_tmp = item.get_names();
    for (const std::pair<Glib::ustring, Glib::ustring> &name : names_tmp) {
        if (name.first == current_language) {
            return name.second;
        }
    }

    return "";
}

void MarketWindow::set_current_language(const Glib::ustring& m_current_language) noexcept
{
    current_language = m_current_language;
}

const Glib::ustring& MarketWindow::get_current_language() const noexcept
{
    return current_language;
}

void MarketWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}

const WindowManager* MarketWindow::get_window_manager_context() const noexcept
{
    return window_manager_context;
}

const Glib::ustring& MarketWindow::get_trv_mktg_name() const noexcept
{
    static const Glib::ustring n(TRV_MKTG_NAME);
    return n;
}

const Glib::ustring& MarketWindow::get_se_item_name() const noexcept
{
    static const Glib::ustring n(SE_ITEM_NAME);
    return n;
}