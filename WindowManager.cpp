/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "WindowManager.h"

#include "window/StartWindow.h"

WindowManager::WindowManager(int screen_width, int screen_height) noexcept : primary_screen_width(screen_width), primary_screen_height(screen_height)
{
    main_app = Gtk::Application::create(APPLICATION_ID);

    window_names = {
            {WindowManager::Windows::START_WINDOW, WND_START}
    };

    build_window(window_names[WindowManager::Windows::START_WINDOW], start_window);
    set_default_window_size(start_window);
    set_default_window_style(start_window);
}

WindowManager::~WindowManager() noexcept
{
}

int WindowManager::run() noexcept
{
    if (running) {
        return 0;
    } else {
        current_window = start_window;
        main_app->run(*start_window);
        return 1;
    }
}

template <typename T_window>
void WindowManager::build_window(Glib::ustring& window_name, T_window* window_ref) noexcept
{
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(RLP_LAYOUT + window_name + ".glade");

    builder->get_widget_derived(window_name, start_window);

    start_window->set_window_manager_context(this);
}

template <typename T_window>
void WindowManager::set_default_window_size(T_window* window_ref) noexcept
{
    if (primary_screen_width >= WND_DEFAULT_WIDTH && primary_screen_height >= WND_DEFAULT_HEIGHT) {
        window_ref->set_default_size(WND_DEFAULT_WIDTH, WND_DEFAULT_HEIGHT);
    } else {
        window_ref->set_default_size(primary_screen_width, primary_screen_height);
    }
}

template <typename T_window>
void WindowManager::set_default_window_style(T_window* window_ref) noexcept
{
    Glib::RefPtr<Gdk::Screen> screen = window_ref->get_screen();

    Glib::RefPtr<Gtk::CssProvider> css_provider = Gtk::CssProvider::create();

    css_provider->load_from_path(Glib::ustring(RLP_LAYOUT) + "style/style.css");

    Glib::RefPtr<Gtk::StyleContext> style_context = Gtk::StyleContext::create();

    style_context->add_provider_for_screen(screen, css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

const bool& WindowManager::is_running() const noexcept
{
    return running;
}