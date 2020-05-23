/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include <glibmm/ustring.h>
#include <vector>

class MarketGroupItem;

class DataHelper
{
public:
    DataHelper();
    ~DataHelper();

    void set_yaml_market_groups_path(std::string m_yaml_market_groups_path) noexcept;
    const std::string& get_yaml_market_groups_path() const noexcept;

private:
    void load_market_groups() noexcept;

    std::string load_file(const std::string& path) const noexcept;

private:
    std::vector<MarketGroupItem> market_group_items;

    /// Default path to the file: "marketGroups.yaml"
    std::string yaml_market_groups_path = "sde/fsd/marketGroups.yaml";

};