/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "MarketGroupItem.h"

MarketGroupItem::MarketGroupItem(
        unsigned int id,
        std::vector<std::pair<Glib::ustring, Glib::ustring>> descriptions,
        std::vector<std::pair<Glib::ustring, Glib::ustring>> names,
        bool has_types,
        unsigned int icon_id,
        unsigned int parent_id
        ) : id(id), has_types(has_types), icon_id(icon_id), descriptions(std::move(descriptions)), names(std::move(names)), parent_id(parent_id)
{

}

const unsigned int& MarketGroupItem::get_id() const noexcept
{
    return id;
}

const bool& MarketGroupItem::get_has_types() const noexcept
{
    return has_types;
}

const unsigned int& MarketGroupItem::get_icon_id() const noexcept
{
    return icon_id;
}

const std::vector<std::pair<Glib::ustring, Glib::ustring>>& MarketGroupItem::get_descriptions() const noexcept
{
    return descriptions;
}

const std::vector<std::pair<Glib::ustring, Glib::ustring>>& MarketGroupItem::get_names() const noexcept
{
    return names;
}

const unsigned int& MarketGroupItem::get_parent_id() const noexcept
{
    return parent_id;
}
