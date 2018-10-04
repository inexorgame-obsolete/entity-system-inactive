// Inexor entity system prototype
// (c)2018 Inexor

#include "TypeInstanceManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	template <typename T1, typename T2>
	TypeInstanceManagerTemplate<T1,T2>::TypeInstanceManagerTemplate()
	{
	}


	template <typename T1, typename T2>
	TypeInstanceManagerTemplate<T1,T2>::~TypeInstanceManagerTemplate()
	{
	}


	template <typename T1, typename T2>
	std::shared_ptr<T2> TypeInstanceManagerTemplate<T1,T2>::create_type_instance(const std::shared_ptr<T1>& type_pointer)
	{
		std::shared_ptr<T2> new_type_instance = std::make_shared<T2>(type_pointer);
		type_instances.push_back(new_type_instance);
		return new_type_instance;
	}


	template <typename T1, typename T2>
	const std::size_t TypeInstanceManagerTemplate<T1,T2>::get_type_instance_count() const
	{
		return type_instances.size();
	}


	template <typename T1, typename T2>
	void TypeInstanceManagerTemplate<T1,T2>::delete_all_type_instances()
	{
		type_instances.clear();
	}


};
};
