/**
 * Inexor Entity System
 * No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
 *
 * OpenAPI spec version: 3.0.0
 * Contact: info@inexor.org
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 4.0.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "RelationInstanceDto.hpp"

#include <string>
#include <sstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace inexor {
namespace entity_system {
namespace rest {
namespace model {

	RelationInstanceDto::RelationInstanceDto()
	{
		relation_instance_uuid = "";
		relation_type_uuid = "";
		start_node_entity_instance_uuid = "";
		end_node_entity_instance_uuid = "";
	}

	RelationInstanceDto::~RelationInstanceDto()
	{
	}

	std::string RelationInstanceDto::to_json_string()
	{
		std::stringstream ss;
		ptree pt;
		pt.put("relation_instance_uuid", relation_instance_uuid);
		pt.put("relation_type_uuid", relation_type_uuid);
		pt.put("start_node_entity_instance_uuid", start_node_entity_instance_uuid);
		pt.put("end_node_entity_instance_uuid", end_node_entity_instance_uuid);
		write_json(ss, pt, false);
		return ss.str();
	}

	void RelationInstanceDto::from_json_string(std::string const& jsonString)
	{
		std::stringstream ss(jsonString);
		ptree pt;
		read_json(ss,pt);
		relation_instance_uuid = pt.get("relation_instance_uuid", "");
		relation_type_uuid = pt.get("relation_type_uuid", "");
		start_node_entity_instance_uuid = pt.get("start_node_entity_instance_uuid", "");
		end_node_entity_instance_uuid = pt.get("end_node_entity_instance_uuid", "");
	}

	std::string RelationInstanceDto::get_relation_instance_uuid() const
	{
		return relation_instance_uuid;
	}
	void RelationInstanceDto::set_relation_instance_uuid(std::string relation_instance_uuid)
	{
		this->relation_instance_uuid = relation_instance_uuid;
	}
	std::string RelationInstanceDto::get_relation_type_uuid() const
	{
		return relation_type_uuid;
	}
	void RelationInstanceDto::set_relation_type_uuid(std::string relation_type_uuid)
	{
		this->relation_type_uuid = relation_type_uuid;
	}
	std::string RelationInstanceDto::get_start_node_entity_instance_uuid() const
	{
		return start_node_entity_instance_uuid;
	}
	void RelationInstanceDto::set_start_node_entity_instance_uuid(std::string start_node_entity_instance_uuid)
	{
		this->start_node_entity_instance_uuid = start_node_entity_instance_uuid;
	}
	std::string RelationInstanceDto::get_end_node_entity_instance_uuid() const
	{
		return end_node_entity_instance_uuid;
	}
	void RelationInstanceDto::set_end_node_entity_instance_uuid(std::string end_node_entity_instance_uuid)
	{
		this->end_node_entity_instance_uuid = end_node_entity_instance_uuid;
	}
	std::vector<std::shared_ptr<AttributeDto>> RelationInstanceDto::get_attributes() const
	{
		return attributes;
	}
	void RelationInstanceDto::set_attributes(std::vector<std::shared_ptr<AttributeDto>> attributes)
	{
		this->attributes = attributes;
	}

}
}
}
}
