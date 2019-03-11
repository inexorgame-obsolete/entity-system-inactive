#include "Processor.hpp"

namespace inexor {
namespace visual_scripting {

	Processor::Processor(
		EntityTypePtr entity_type
	)
		: entity_type(entity_type)
	{
	}

	Processor::~Processor()
	{
	}

	EntityTypePtr Processor::get_entity_type()
	{
		return entity_type;
	}

}
}
