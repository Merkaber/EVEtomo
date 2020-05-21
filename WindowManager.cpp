/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "WindowManager.h"

WindowManager::WindowManager(int screen_width, int screen_height) noexcept
{
    main_app = Gtk::Application::create(APPLICATION_ID);
}

WindowManager::~WindowManager() noexcept
{

}

int WindowManager::run() const noexcept
{
    if (running) {
        return 0;
    } else {
        main_app->run();
        return 1;
    }
}

const bool& WindowManager::is_running() const noexcept
{
    return running;
}