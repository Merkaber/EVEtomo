/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#define BTN_MARKET_NAME "btn_market"
#define BTN_INDUSTRY_NAME "btn_industry"

#include "../WindowManager.h"

class StartWindow : public Gtk::Window
{
public:
    StartWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref);

    void set_window_manager_context(WindowManager* context) noexcept;

    const Glib::ustring& get_btn_market_name() const noexcept;
    const Glib::ustring& get_btn_industry_name() const noexcept;

protected:
    const Glib::RefPtr<Gtk::Builder> builder;

    Gtk::Button* btn_market;
    Gtk::Button* btn_industry;

protected:
    void on_btn_market_clicked() const noexcept;

    void on_btn_industry_clicked() const noexcept;

private:
    WindowManager* window_manager_context = nullptr;

};
