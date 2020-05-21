/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#define APPLICATION_ID "de.piorecki.evetomo"

#pragma once

#include "gtkmm.h"

class WindowManager {
public:
    WindowManager(int screen_width, int screen_height) noexcept;
    ~WindowManager() noexcept;

    int run() const noexcept;

    const bool& is_running() const noexcept;

private:
    Glib::RefPtr<Gtk::Application> main_app;

    bool running = false;
};
