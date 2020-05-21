/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "StartWindow.h"

StartWindow::StartWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref) : Gtk::Window(object), builder(glade_ref)
{
    builder->get_widget(get_btn_market_name(), btn_market);
    builder->get_widget(get_btn_industry_name(), btn_industry);

    btn_market->signal_clicked().connect(sigc::mem_fun(*this, &StartWindow::on_btn_market_clicked));
    btn_industry->signal_clicked().connect(sigc::mem_fun(*this, &StartWindow::on_btn_industry_clicked));
}

void StartWindow::set_window_manager_context(WindowManager* context) noexcept
{
    window_manager_context = context;
}

void StartWindow::on_btn_market_clicked() const noexcept
{
    window_manager_context->switch_window(WindowManager::Windows::MARKET_WINDOW);
}

void StartWindow::on_btn_industry_clicked() const noexcept
{
    window_manager_context->switch_window(WindowManager::Windows::INDUSTRY_WINDOW);
}

const Glib::ustring& StartWindow::get_btn_market_name() const noexcept
{
    static const Glib::ustring n(BTN_MARKET_NAME);
    return n;
}

const Glib::ustring& StartWindow::get_btn_industry_name() const noexcept
{
    static const Glib::ustring n(BTN_INDUSTRY_NAME);
    return n;
}