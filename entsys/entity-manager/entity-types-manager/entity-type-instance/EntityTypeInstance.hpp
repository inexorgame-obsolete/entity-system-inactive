// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of entities.
	// Only EntityTypeInstanceManager can create instances!
    class EntityTypeInstance :
	public TypeInstanceBase<EntityType,EntityTypeInstance>
    {
		private:

			// Every time we create an instance of an entity type
			// we must also create the corresponding instances of
			// entity attribute types which are linked to the entity type.
			std::unordered_map<std::shared_ptr<EntityAttributeType>, std::shared_ptr<EntityAttributeTypeInstance>> linked_entity_attribute_type_instances;
			
		public:

			// TODO: Remove default constructor!
			EntityTypeInstance(); // = delete;

			// TODO: Make this the default constructor.
			EntityTypeInstance(const std::shared_ptr<EntityType>&);

			// Destructor.
			~EntityTypeInstance();
			

			// Set attribute data.
			// TODO: Replace overloaded methods ?
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const int&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const bool&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const float&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const double&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const std::string&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const std::int64_t&);

			// Get methods for attribute data.
			// TODO: Inherit them directly from DataContainer ?
			const int get_attribute_data_int(const std::shared_ptr<EntityAttributeType>&) const;
			const bool get_attribute_data_bool(const std::shared_ptr<EntityAttributeType>&) const;
			const float get_attribute_data_float(const std::shared_ptr<EntityAttributeType>&) const;
			const double get_attribute_data_double(const std::shared_ptr<EntityAttributeType>&) const;
			const std::string get_attribute_data_string(const std::shared_ptr<EntityAttributeType>&) const;
			const std::int64_t get_attribute_data_int64(const std::shared_ptr<EntityAttributeType>&) const;
			

    };


};
};
