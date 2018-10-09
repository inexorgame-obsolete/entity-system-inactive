// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>


namespace inexor {
namespace entity_system {


	// A template class for instances of types of any kind.
	template <typename T1, typename T2>
	class TypeInstanceBase
	{
		public:
			
			//
			std::string type_title;
			
			// TODO: Implement UUIDs!

		protected:

			// 
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
			void set_type_name(const std::string& type_name)
			{
				type_title = type_name;
			}

			// 
			const std::string get_type_name() const
			{
				return type_title;
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
