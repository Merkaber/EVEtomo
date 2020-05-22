/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "MarketWindow.h"

MarketWindow::MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) : Gtk::Window(object), builder(glade_ref)
{
    builder->get_widget(get_ts_items_name(), ts_items);
    builder->get_widget(get_se_item_name(), se_item);
}

void MarketWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}

const Glib::ustring& MarketWindow::get_ts_items_name() const noexcept
{
    static const Glib::ustring n(TS_ITEMS_NAME);
    return n;
}

const Glib::ustring& MarketWindow::get_se_item_name() const noexcept
{
    static const Glib::ustring n(SE_ITEM_NAME);
    return n;
}