// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>


namespace inexor {
namespace entity_system {


	// A template class for instances of types of any kind.
	// T1 = type, T2 = type instance.
	template <typename T1, typename T2>
	class TypeInstanceBase
	{
		public:
			
			// The unique name of this type base instance.
			std::string type_title;
			
			// TODO: Implement UUIDs!

		protected:

			// A pointer to the type of this type instance.
			std::shared_ptr<T1> type_pointer;

		public:

			// 
			TypeInstanceBase()
			{
			}

			// 
			~TypeInstanceBase()
			{
			}


			// 
			const std::string get_type_name() const
			{
				return type_title;
			}


			// 
			void set_type_name(const std::string& type_name)
			{
				type_title = type_name;
			}


			// 
			void set_type_pointer(const std::shared_ptr<T1>& type_ptr)
			{
				type_pointer = type_ptr;
			}

			
			// TODO: Implement UUID get methods.

	};

};
};
