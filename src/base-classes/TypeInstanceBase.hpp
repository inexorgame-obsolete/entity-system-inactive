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
			
			/// The unique name of the type of this instance.
			std::string type_title;

			/// A pointer to the type of this type instance.
			std::shared_ptr<T1> type_pointer;

			/// Sets the name of the type.
			/// @param type_name a const reference to
			/// a std::string which is the name of this type.
			void set_type_name(const std::string& type_name)
			{
				type_title = type_name;
			}


			/// Sets the pointer of a type.
			/// @param type_ptr A const reference to a shared pointer of the source type.
			void set_type_pointer(const std::shared_ptr<T1>& type_ptr)
			{
				type_pointer = type_ptr;
			}


		public:

			/// Constructor.
			TypeInstanceBase()
			{
			}
			

			/// Destructor.
			~TypeInstanceBase()
			{
			}


			/// Returns the name of this type.
			/// @return The unique name of this type 
			const std::string get_type_name() const
			{
				return type_title;
			}


			// TODO: Implement UUID get methods.

	};

};
};
