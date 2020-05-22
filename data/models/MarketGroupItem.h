/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include <vector>
#include <unordered_map>

#include "gtkmm.h"

class MarketGroupItem
{
public:
    explicit MarketGroupItem(
            unsigned int id,
            bool has_types = false,
            unsigned int icon_id = 0,
            unsigned int parent_id = 0,
            std::vector<std::unordered_map<Glib::ustring, Glib::ustring>> descriptions = {},
            std::vector<std::unordered_map<Glib::ustring, Glib::ustring>> names = {}
    );

    const unsigned int& get_id() const noexcept;
    const bool& get_has_types() const noexcept;
    const unsigned int& get_icon_id() const noexcept;
    const std::vector<std::unordered_map<Glib::ustring, Glib::ustring>>& get_descriptions() const noexcept;
    const std::vector<std::unordered_map<Glib::ustring, Glib::ustring>>& get_names() const noexcept;
    const unsigned int& get_parent_id() const noexcept;

private:
    const unsigned int id = 0;
    const bool has_types = false;
    const unsigned int icon_id = 0;
    const std::vector<std::unordered_map<Glib::ustring, Glib::ustring>> descriptions = {};
    const std::vector<std::unordered_map<Glib::ustring, Glib::ustring>> names = {};
    const unsigned int parent_id = 0;

};
