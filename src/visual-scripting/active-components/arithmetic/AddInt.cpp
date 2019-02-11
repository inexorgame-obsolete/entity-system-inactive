// Inexor entity system
// (c)2018-2019 Inexor

#include "AddInt.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

	AddInt::AddInt(
		shared_ptr<AddIntEntityTypeProvider> entity_type_provider
	)
	{
		this->entity_type_provider = entity_type_provider;
	}

	AddInt::~AddInt()
	{
	}

	/// The execution function of the active component.
	void AddInt::execute(const shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const
	{
		std::optional<std::shared_ptr<class EntityAttributeInstance>> o_augend = entity_instance->get_attribute_instance("augend");
		std::optional<std::shared_ptr<class EntityAttributeInstance>> o_addend = entity_instance->get_attribute_instance("addend");
		std::optional<std::shared_ptr<class EntityAttributeInstance>> o_sum = entity_instance->get_attribute_instance("sum");
		if (o_augend.has_value() && o_addend.has_value() && o_sum.has_value())
		{
			// std::shared_ptr<class EntityAttributeInstance> sum = o_sum.value();
			o_sum.value()->value.Set(
				std::get<DataType::INT>(o_augend.value()->value.Value()) + std::get<DataType::INT>(o_addend.value()->value.Value())
			);
		}
	}

	/// Returns the entity type to bind.
	shared_ptr<inexor::entity_system::EntityType> AddInt::get_entity_type() const
	{
		return entity_type_provider->get_type();
	}


};
};
