/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include "../WindowManager.h"

#define TS_ITEMS_NAME "ts_items"
#define SE_ITEM_NAME "se_item"

class MarketWindow : public Gtk::Window
{
public:
    MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref);

    void set_window_manager_context(WindowManager* context) noexcept;

    const Glib::ustring& get_ts_items_name() const noexcept;
    const Glib::ustring& get_se_item_name() const noexcept;

protected:
    const Glib::RefPtr<Gtk::Builder> builder;

    Gtk::TreeStore* ts_items = nullptr;
    Gtk::SearchEntry* se_item = nullptr;

private:
    WindowManager* window_manager_context = nullptr;
};

