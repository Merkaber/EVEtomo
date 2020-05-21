/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include "../WindowManager.h"

class MarketWindow : public Gtk::Window
{
public:
    MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref);

    void set_window_manager_context(WindowManager* context) noexcept;

protected:
    const Glib::RefPtr<Gtk::Builder> builder;

private:
    WindowManager* window_manager_context = nullptr;
};

