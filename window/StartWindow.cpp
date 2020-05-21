/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "StartWindow.h"

StartWindow::StartWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) : Gtk::Window(object), builder(glade_ref)
{
}

void StartWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}