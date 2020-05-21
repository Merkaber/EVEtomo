/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#define WND_DEFAULT_WIDTH 800
#define WND_DEFAULT_HEIGHT 600

#define APPLICATION_ID "de.piorecki.evetomo"

#define RLP_LAYOUT "../layout/"

#define WND_START "wnd_start"
#define WND_MARKET "wnd_market"
#define WND_INDUSTRY "wnd_industry"

#include "gtkmm.h"

class StartWindow;
class MarketWindow;
class IndustryWindow;

class WindowManager
{
public:
    enum Windows
    {
        START_WINDOW = 100u,
        MARKET_WINDOW = 200u,
        INDUSTRY_WINDOW = 300u
    };

public:
    WindowManager(int screen_width, int screen_height) noexcept;
    ~WindowManager() noexcept;

    int run() noexcept;

    const bool& is_running() const noexcept;

    void switch_window(WindowManager::Windows window) noexcept;

private:
    template <typename T_window>
    void build_window(Glib::ustring& window_name, T_window& window_ref) noexcept;

    template <typename T_window>
    void set_default_window_size(T_window& window_ref) noexcept;

    template <typename T_window>
    void set_default_window_style(T_window& window_ref) noexcept;

private:
    Glib::RefPtr<Gtk::Application> main_app;

    Gtk::Window* current_window = nullptr;

    StartWindow* start_window = nullptr;
    MarketWindow* market_window = nullptr;
    IndustryWindow* industry_window = nullptr;

    std::map<WindowManager::Windows, Glib::ustring> window_names;

    const int primary_screen_width;
    const int primary_screen_height;

    bool running = false;
};
