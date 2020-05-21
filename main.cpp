/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include <iostream>

#ifdef WIN32
#include <windows.h>
#endif

#include "WindowManager.h"

int get_primary_screen_width();
int get_primary_screen_height();

int main(int argc, char* argv[])
{
    int screen_width = get_primary_screen_width();
    int screen_height= get_primary_screen_height();

    if (screen_width == 0 || screen_height == 0) {
        std::cout << "Could not retrieve the screen size!" << std::endl;
        return 1;
    }

    auto window_manager = new WindowManager(screen_width, screen_height);
    int res = window_manager->run();

    delete window_manager;

    if (res == 0) {
        std::cout << "Something went wrong!" << std::endl;
        return 1;
    } else {
        return 0;
    }
}

int get_primary_screen_width()
{
#ifdef WIN32
    return GetSystemMetrics(SM_CXSCREEN);
#endif
}

int get_primary_screen_height()
{
#ifdef WIN32
    return GetSystemMetrics(SM_CYSCREEN);
#endif
}
