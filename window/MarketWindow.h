/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include "../WindowManager.h"
#include "../data/DataHelper.h"

#define TRV_MKTG_NAME "trv_market_groups"
#define SE_ITEM_NAME "se_item"

class MarketWindow : public Gtk::Window
{
    // Interface functions
public:
    MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) noexcept;
    ~MarketWindow() noexcept override;

    /**
     * Function which will populate the market group tree view when called
     * @param market_group_items The market group items
     */
    void populate_market_group_trv(const std::vector<MarketGroupItem>& market_group_items) const noexcept;

    // Member
protected:
    /// Builder for the whole window
    const Glib::RefPtr<Gtk::Builder> builder;

    /// Search entry for market groups
    Gtk::SearchEntry* se_item = nullptr;

    // TreeView related member and functions
protected:
    /**
     * Function which gets called when activating a market group row
     * @param path The path to the tree model
     * @param column The tree model column
     */
    void on_trv_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);

    /**
     * Market group column model class
     */
    class MarketGroupColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        MarketGroupColumns()
        {
            add(icon);
            add(name);
            add(id);
        }

        Gtk::TreeModelColumn<Glib::RefPtr<Gdk::Pixbuf>> icon;
        Gtk::TreeModelColumn<Glib::ustring> name;
        Gtk::TreeModelColumn<unsigned int> id;
    };

    /// Market group column object
    MarketGroupColumns market_group_columns;

    /// TreeStore for the market groups
    Glib::RefPtr<Gtk::TreeStore> ref_tree_model;

    /// TreeView for the market groups
    Gtk::TreeView* trv_market_groups = nullptr;

    // Functions
private:
    /**
     * Select the name in the current_language of the given item and return it
     * @param item The given MarketGroupItem
     * @return The name in the current_language
     */
    Glib::ustring get_market_group_name_by_language(const MarketGroupItem& item) const noexcept;

    // Member
private:
    /// Currently selected language for this program
    Glib::ustring current_language = "en";

    /// Context of the window manager
    WindowManager* window_manager_context = nullptr;

    // Getter and setter
public:
    // window_manager_context
    void set_window_manager_context(WindowManager* context) noexcept;
    const WindowManager* get_window_manager_context() const noexcept;

    // view names
    const Glib::ustring& get_trv_mktg_name() const noexcept;
    const Glib::ustring& get_se_item_name() const noexcept;

    // current_language
    const Glib::ustring& get_current_language() const noexcept;
    void set_current_language(const Glib::ustring& m_current_language) noexcept;
};

