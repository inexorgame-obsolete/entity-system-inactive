// Inexor entity system
// (c)2018-2019 Inexor

#include "Processor.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

	/// @brief The constructor.
	Processor::Processor(
		std::shared_ptr<inexor::entity_system::EntityType> entity_type
//		std::shared_ptr<inexor::entity_system::EntityTypeProvider> entity_type_provider,
//		std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
	)
		: entity_type(entity_type)
//		  entity_type_provider(entity_type_provider),
//		  entity_instance_manager(entity_instance_manager)
	{
	};

	/// @brief The destructor.
	Processor::~Processor()
	{
	};

	std::shared_ptr<inexor::entity_system::EntityType> Processor::get_entity_type()
	{
		return entity_type;
	}

};
};
