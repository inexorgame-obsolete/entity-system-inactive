// Inexor entity system prototype
// (c)2018 Inexor

#include <memory>


namespace inexor {
namespace entity_system {
	

	/// These macros make initialisations shorter.

	#define ENT_ATTR_TYPE			 std::shared_ptr<class EntityAttributeType>
	#define ENT_ATTR_TYPE_INST       std::shared_ptr<class EntityAttributeTypeInstance>
	#define ENT_TYPE                 std::shared_ptr<class EntityType>
	#define ENT_TYPE_INST            std::shared_ptr<class EntityTypeInstance>
	#define ENT_REL_TYPE             std::shared_ptr<class EntityRelationType>
	#define ENT_REL_TYPE_INST        std::shared_ptr<class EntityRelationTypeInstance>
	#define ENT_REL_ATTR_TYPE        std::shared_ptr<class EntityRelationAttributeType>
	#define ENT_REL_ATTR_TYPE_INST   std::shared_ptr<class EntityRelationAttributeTypeInstance>

};
};
