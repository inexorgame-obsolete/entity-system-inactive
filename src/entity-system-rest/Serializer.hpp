#pragma once

#include <memory>

#include <nlohmann/json.hpp>

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

// for convenience
using namespace std;
using json = nlohmann::json;

namespace inexor {
namespace entity_system {
    struct adl_serializer<shared_ptr<EntityAttributeInstance>> {
        static void to_json(json& j, const T& value) {
            j = json{
                {"attribute_uuid": ""},
                {"name", ""},
                {"datatype": ""},
                {"value": ""}
            };
        }

        static void from_json(const json& j, T& value) {

        }
    };

    struct adl_serializer<shared_ptr<EntityInstance>> {
        static void to_json(json& j, const T& value) {

        }

        static void from_json(const json& j, T& value) {

        }
    };
};
};