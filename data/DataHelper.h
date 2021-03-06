/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#pragma once

#include <glibmm/ustring.h>
#include <vector>
#include <map>

#define MKTG_DESCRIPTION_ID_KEY "descriptionID"
#define MKTG_HAS_TYPES_KEY "hasTypes"
#define MKTG_ICON_ID_KEY "iconID"
#define MKTG_NAME_ID "nameID"
#define MKTG_PARENT_GROUP_ID "parentGroupID"

class MarketWindow;
class IndustryWindow;
class ReactionsWindow;

class MarketGroupItem;

class DataHelper
{
public:
    enum MarketGroupKeys {
        DESCRIPTION_ID_KEY = 100u,
        HAS_TYPES_KEY = 200u,
        ICON_ID_KEY = 300u,
        NAME_ID_KEY = 400u,
        PARENT_GROUP_ID = 500u
    };

public:
    DataHelper();
    ~DataHelper();

    void load_market_groups() noexcept;
    void load_types() noexcept;
    void load_iconIDs() noexcept;
    void load_blueprints() noexcept;

    void set_yaml_market_groups_path(std::string m_yaml_market_groups_path) noexcept;
    const std::string& get_yaml_market_groups_path() const noexcept;

    void set_market_window(const MarketWindow& window) noexcept;
    void set_industry_window(const IndustryWindow& window) noexcept;
    void set_reactions_window(const ReactionsWindow& window) noexcept;

private:
    std::string load_file(const std::string& path) const noexcept;

private:
    const MarketWindow* market_window;
    const IndustryWindow* industry_window;
    const ReactionsWindow* reactions_window;

    std::vector<MarketGroupItem> market_group_items;

    std::map<DataHelper::MarketGroupKeys, std::string> market_group_keys;

    /// Default path to the file: "marketGroups.yaml"
    std::string yaml_market_groups_path = "sde/fsd/marketGroups.yaml";

    /// Default path to the file: "typeIDs.yaml"
    std::string yaml_types_path = "sde/fsd/typeIDs.yaml";

    /// Default path to the file: "iconIDs.yaml"
    std::string yaml_icon_ids_path = "sde/fds/iconIDs.yaml";

    /// Default path to the file: "blueprints.yaml"
    std::string yaml_blueprints_path = "sde/fds/blueprints.yaml";

};