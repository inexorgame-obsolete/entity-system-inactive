// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <memory>


namespace inexor {
namespace entity_system {


	/// A template class for instances.
	template <typename T1, typename T2>
	class TypeInstanceBase
	{
		protected:
			
			/// A pointer to the type of this type instance.
			std::shared_ptr<T1> type_pointer;

		public:
			
			/// Constructor.
			TypeInstanceBase(const std::shared_ptr<T1>& type_ptr)
			{
				type_pointer = type_ptr;
			}
			

			/// Destructor.
			~TypeInstanceBase()
			{
			}


	};

};
};
