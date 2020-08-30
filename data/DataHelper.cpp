/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#include "DataHelper.h"

#include <fstream>
#include <utility>
#include <thread>
#include <iostream>

#include "ryml.hpp"
#include "model/MarketGroupItem.h"
#include "../window/MarketWindow.h"
#include "../window/IndustryWindow.h"

DataHelper::DataHelper() : market_window(nullptr), industry_window(nullptr)
{
    market_group_keys = {
            {DataHelper::MarketGroupKeys::DESCRIPTION_ID_KEY, MKTG_DESCRIPTION_ID_KEY},
            {DataHelper::MarketGroupKeys::HAS_TYPES_KEY, MKTG_HAS_TYPES_KEY},
            {DataHelper::MarketGroupKeys::ICON_ID_KEY, MKTG_ICON_ID_KEY},
            {DataHelper::MarketGroupKeys::NAME_ID_KEY, MKTG_NAME_ID},
            {DataHelper::MarketGroupKeys::PARENT_GROUP_ID, MKTG_PARENT_GROUP_ID}
    };

    std::thread(&DataHelper::load_market_groups, this).detach();
    std::thread(&DataHelper::load_types, this).detach();
    std::thread(&DataHelper::load_iconIDs, this).detach();
}

DataHelper::~DataHelper()
{

}

void DataHelper::load_iconIDs() noexcept
{
    std::string iconIDs_yaml = load_file(yaml_icon_ids_path);
    ryml::Tree tree = ryml::parse(c4::to_substr(&iconIDs_yaml[0]));

    c4::yml::NodeRef node_ref(tree);
}

void DataHelper::load_types() noexcept
{
    std::string types_yaml = load_file(yaml_types_path);
    ryml::Tree tree = ryml::parse(c4::to_substr(&types_yaml[0]));

    c4::yml::NodeRef node_ref(tree);
}

void DataHelper::load_market_groups() noexcept
{
    std::string market_groups_yaml = load_file(yaml_market_groups_path);
    ryml::Tree tree = ryml::parse(c4::to_substr(&market_groups_yaml[0]));

    c4::yml::NodeRef node_ref(tree);
    for (c4::yml::NodeRef nr : node_ref.children()) {
        unsigned int id_tmp = 0;
        std::vector<std::pair<Glib::ustring, Glib::ustring>> descriptions_tmp;
        std::vector<std::pair<Glib::ustring, Glib::ustring>> names_tmp;
        bool has_types_tmp = false;
        unsigned int icon_id_tmp = 0;
        unsigned int parent_id_tmp = 0;

        if (nr.key().is_integer()) {
            c4::atou(nr.key(), &id_tmp);
        }

        for (c4::yml::NodeRef nrr : nr.children()) {
            if (nrr.key() == c4::to_substr(&(market_group_keys[DataHelper::MarketGroupKeys::DESCRIPTION_ID_KEY])[0])) {
                for (c4::yml::NodeRef nrrr : nrr.children()) {
                    descriptions_tmp.emplace_back(std::string(nrrr.key().str, nrrr.key().len), std::string(nrrr.val().str, nrrr.val().len));
                }
            }

            if (nrr.key() == c4::to_substr(&(market_group_keys[DataHelper::MarketGroupKeys::HAS_TYPES_KEY])[0])) {
                if (nrr.val() == "true") {
                    has_types_tmp = true;
                }
            }

            if (nrr.key() == c4::to_substr(&(market_group_keys[DataHelper::MarketGroupKeys::ICON_ID_KEY])[0])) {
                if (nrr.val().is_integer()) {
                    c4::atou(nrr.val(), &icon_id_tmp);
                }
            }

            if (nrr.key() == c4::to_substr(&(market_group_keys[DataHelper::MarketGroupKeys::NAME_ID_KEY])[0])) {
                for (c4::yml::NodeRef nrrr : nrr.children()) {
                    names_tmp.emplace_back(std::string(nrrr.key().str, nrrr.key().len), std::string(nrrr.val().str, nrrr.val().len));
                }
            }

            if (nrr.key() == c4::to_substr(&(market_group_keys[DataHelper::MarketGroupKeys::PARENT_GROUP_ID])[0])) {
                if (nrr.val().is_integer()) {
                    c4::atou(nrr.val(), &parent_id_tmp);
                }
            }
        }

        market_group_items.emplace_back(id_tmp, descriptions_tmp, names_tmp, has_types_tmp, icon_id_tmp, parent_id_tmp);
    }

    market_window->populate_market_group_trv(market_group_items);
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

void DataHelper::set_market_window(const MarketWindow& window) noexcept
{
    market_window = &window;
}

void DataHelper::set_industry_window(const IndustryWindow& window) noexcept
{
    industry_window = &window;
}