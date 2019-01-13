// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <string>
#include <memory>


namespace inexor {
namespace entity_system {


	/// @brief A template base class for instances.
	/// @param T1 The type of the instance.
	/// @param T2 The type instance.
	template <typename T> class InstanceBase
	{
		private:
			
			/// A pointer to the type of this type instance.
			std::shared_ptr<T> type_pointer;

        protected:

            /// 
            std::shared_ptr<T> get_type() const
            {
                return type_pointer;
            }

		public:
			
			/// Constructor.
			InstanceBase(const std::shared_ptr<T>& type_ptr)
			{
				type_pointer = type_ptr;
			}
			

			/// Destructor.
			~InstanceBase()
			{
			}


	};

};
};
