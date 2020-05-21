//
// Created by Merkaber on 21.05.2020.
//

#pragma once

#include "../WindowManager.h"

class StartWindow : public Gtk::Window
{
public:
    StartWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>  glade_ref) noexcept;

    void set_window_manager_context(WindowManager* context) noexcept;

protected:
    const Glib::RefPtr<Gtk::Builder> builder;

private:
    WindowManager* window_manager_context = nullptr;

};
