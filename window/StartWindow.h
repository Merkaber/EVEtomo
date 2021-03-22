/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#define BTN_MARKET_NAME "btn_market"
#define BTN_INDUSTRY_NAME "btn_industry"
#define BTN_REACTIONS_NAME "btn_reactions"

#include "../WindowManager.h"

class StartWindow : public Gtk::Window
{
public:
    StartWindow(BaseObjectType* object, Glib::RefPtr<Gtk::Builder>& glade_ref);

    void set_window_manager_context(WindowManager* context) noexcept;

    const Glib::ustring& get_btn_market_name() const noexcept;
    const Glib::ustring& get_btn_industry_name() const noexcept;
    const Glib::ustring& get_btn_reactions_name() const noexcept;

protected:
    const Glib::RefPtr<Gtk::Builder> builder;

    Gtk::Button* btn_market;
    Gtk::Button* btn_industry;
    Gtk::Button* btn_reactions;

protected:
    void on_btn_market_clicked() const noexcept;

    void on_btn_industry_clicked() const noexcept;

    void on_btn_reactions_clicked() const noexcept;

private:
    WindowManager* window_manager_context = nullptr;

};
