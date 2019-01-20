// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>
#include <string>
#include <optional>
#include <unordered_map>
#include <crossguid/guid.hpp>

#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"
#include "entity-system/model/types/types/EntityType.hpp"


namespace inexor {
namespace entity_system {


    /// @class EntityTypeManager
	/// @brief A manager class for entity types.
	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		public:

			/// @brief Constructor.
			EntityTypeManager();

			/// @brief Destructor.
			~EntityTypeManager();
		
			/// @brief Creates a new entity type.
			/// @param ent_type_name The name of the new entity type.
            /// @return ?
			std::optional<ENT_TYPE> create_entity_type(const std::string&);


            /// @brief Creates a new entity type.
            /// @param ent_type_GUID The GUID of the new entity type.
            /// @param ent_type_name The name of the new entity type.
            /// @return ?
            std::optional<ENT_TYPE> create_entity_type(const xg::Guid&, const std::string&);
            

			/// @brief Checks if an entity type does already exist.
			/// @param ent_type_name The name of the entity type.
            /// @return True if the entity type already exists, false otherwise.
            bool does_entity_type_exist(const std::string&);
			

			/// @brief Checks if an entity type does already exist.
            /// @return True if the entity type already exists, false otherwise.
			bool does_entity_type_exist(const xg::Guid&);


			/// @brief Checks if an entity type does already exist.
			/// @param ent_type A const reference of a shared pointer to the entity type.
            /// @return True if the entity type already exists, false otherwise.
			bool does_entity_type_exist(const ENT_TYPE&);

            
            /// @brief Returns the number of existing entity types.
			/// @return The number of existing entity types.
			std::size_t get_entity_type_count() const;
			

            /// @brief Returns an entity type.
            /// @param ent_type_GUID The GUID of the entity type.
            /// @return A std::optional<ENT_TYPE> of the entity type.
            std::optional<ENT_TYPE> get_entity_type(const xg::Guid&);


            /// @brief Returns an entity type.
            /// @param ent_type_name The name of the entity type.
            /// @return A std::optional<ENT_TYPE> of the entity type.
            std::optional<ENT_TYPE> get_entity_type(const std::string&);


            /// @brief Deletes an entity type by name.
			/// @param ent_type_name The name of the entity type which will be deleted.
            /// @return ENTSYS_SUCCESS if deleting the entity type succeeded,
            /// <br>ENTSYS_ERROR if deleting the entity type failed.
			std::size_t delete_entity_type(const std::string&);
			

			/// @brief Deletes an entity type by GUID.
            /// @param ? The GUID of the entity type which will be deleted.
            /// @return ENTSYS_SUCCESS if deleting the entity type succeeded,
            /// <br>ENTSYS_ERROR if deleting the entity type failed.
			std::size_t delete_entity_type(const xg::Guid&);


			/// @brief Deletes an entity type by entity type.
			/// @param ent_type A const reference of a shared pointer to the entity type which will be deleted.
            /// @return ENTSYS_SUCCESS if deleting the entity type succeeded,
            /// <br>ENTSYS_ERROR if deleting the entity type failed.
			std::size_t delete_entity_type(const ENT_TYPE&);


			/// @brief Removes all types of entities.
			void delete_all_entity_types();


	};


};
};
