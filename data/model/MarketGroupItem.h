/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include <utility>
#include <vector>

#include "gtkmm.h"

class MarketGroupItem
{
public:
    explicit MarketGroupItem(
            unsigned int id,
            std::vector<std::pair<Glib::ustring, Glib::ustring>> descriptions,
            std::vector<std::pair<Glib::ustring, Glib::ustring>> names,
            bool has_types = false,
            unsigned int icon_id = 0,
            unsigned int parent_id = 0
    );

    const unsigned int& get_id() const noexcept;
    const bool& get_has_types() const noexcept;
    const unsigned int& get_icon_id() const noexcept;
    const std::vector<std::pair<Glib::ustring, Glib::ustring>>& get_descriptions() const noexcept;
    const std::vector<std::pair<Glib::ustring, Glib::ustring>>& get_names() const noexcept;
    const unsigned int& get_parent_id() const noexcept;

private:
    unsigned int id = 0;
    bool has_types = false;
    unsigned int icon_id = 0;
    std::vector<std::pair<Glib::ustring, Glib::ustring>> descriptions;
    std::vector<std::pair<Glib::ustring, Glib::ustring>> names;
    unsigned int parent_id = 0;

};
