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
		private:

			//
			std::string type_name;

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
			void set_type_name(const std::string& param_type_name)
			{
				type_name = param_type_name;
			}

			// 
			const std::string get_type_name() const
			{
				return type_name;
			}


			// 
			void set_type_pointer(const std::shared_ptr<T1>& param_type_pointer)
			{
				type_pointer = param_type_pointer;
			}


	};

};
};
