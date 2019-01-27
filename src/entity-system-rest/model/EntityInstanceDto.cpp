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



#include "EntityInstanceDto.hpp"

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

	EntityInstanceDto::EntityInstanceDto()
	{
		m_Entity_instance_uuid = "";
		m_Entity_type_uuid = "";

	}

	EntityInstanceDto::~EntityInstanceDto()
	{
	}

	std::string EntityInstanceDto::toJsonString()
	{
		std::stringstream ss;
		ptree pt;
		pt.put("entity_instance_uuid", m_Entity_instance_uuid);
		pt.put("entity_type_uuid", m_Entity_type_uuid);
		write_json(ss, pt, false);
		return ss.str();
	}

	void EntityInstanceDto::fromJsonString(std::string const& jsonString)
	{
		std::stringstream ss(jsonString);
		ptree pt;
		read_json(ss,pt);
		m_Entity_instance_uuid = pt.get("entity_instance_uuid", "");
		m_Entity_type_uuid = pt.get("entity_type_uuid", "");
	}

	std::string EntityInstanceDto::getEntityInstanceUuid() const
	{
		return m_Entity_instance_uuid;
	}
	void EntityInstanceDto::setEntityInstanceUuid(std::string value)
	{
		m_Entity_instance_uuid = value;
	}
	std::string EntityInstanceDto::getEntityTypeUuid() const
	{
		return m_Entity_type_uuid;
	}
	void EntityInstanceDto::setEntityTypeUuid(std::string value)
	{
		m_Entity_type_uuid = value;
	}
	std::vector<std::shared_ptr<AttributeDto>> EntityInstanceDto::getAttributes() const
	{
		return m_Attributes;
	}
	void EntityInstanceDto::setAttributes(std::vector<std::shared_ptr<AttributeDto>> value)
	{
		m_Attributes = value;
	}

}
}
}
}

