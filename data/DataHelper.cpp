/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "DataHelper.h"

#include <fstream>
#include <utility>
#include <iostream>

#include "ryml.hpp"
#include "models/MarketGroupItem.h"

DataHelper::DataHelper()
{
    load_market_groups();
}

DataHelper::~DataHelper()
{

}

void DataHelper::load_market_groups() noexcept
{
    std::string market_groups_yaml = load_file(yaml_market_groups_path);
    ryml::Tree tree = ryml::parse(c4::to_substr(&market_groups_yaml[0]));

    c4::yml::NodeRef node_ref(tree);
    if (node_ref.has_children()) {
        for (c4::yml::NodeRef c : node_ref.children()) {
            unsigned int id;
            std::vector<std::pair<Glib::ustring, Glib::ustring>> descriptions;
            std::vector<std::pair<Glib::ustring, Glib::ustring>> names;

            if (c.has_key()) {
                std::cout << "key: " << c.key();
            }

            if (c.has_val()) {
                std::cout << "-- val: " << c.val() << std::endl;
            }

            MarketGroupItem m(id, descriptions, names);
            market_group_items.push_back(m);
        }
    }
}

std::string DataHelper::load_file(const std::string& path) const noexcept
{
    std::ifstream ifstream;
    ifstream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        ifstream.open(path);
        return std::string((std::istreambuf_iterator<char>(ifstream)), std::istreambuf_iterator<char>());
    } catch (std::system_error& e) {
        std::cerr << e.code().message() << std::endl;
        return "";
    }
}

void DataHelper::set_yaml_market_groups_path(std::string m_yaml_market_groups_path) noexcept
{
    yaml_market_groups_path = std::move(m_yaml_market_groups_path);
}

const std::string& DataHelper::get_yaml_market_groups_path() const noexcept
{
    return yaml_market_groups_path;
}