/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "IndustryWindow.h"

IndustryWindow::IndustryWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) : Gtk::Window(object), builder(glade_ref)
{
}

void IndustryWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}