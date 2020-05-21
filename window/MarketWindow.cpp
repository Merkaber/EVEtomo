/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "MarketWindow.h"

MarketWindow::MarketWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) : Gtk::Window(object), builder(glade_ref)
{
}

void MarketWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}