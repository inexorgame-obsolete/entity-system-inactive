// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// @brief A template base class
	/// for instance manager classes.
	/// @param T The type for this type instance manager.
	template <typename T>
	class TypeInstanceManagerTemplate
	{
		private:

			/// A vector of stored instances of templatable type.
			// TODO: Replace this with std::unordered_map of xg::Guid to std::shared_ptr<T> ?
			std::vector<std::shared_ptr<T>> type_instances;

			// This error instance will be returned when a method fails.
			// It will be set when the constructor is called
			std::shared_ptr<T> error_instance;

		protected:
			
			/// 
			TypeInstanceManagerTemplate(const std::shared_ptr<T>& param_error_inst)
			{
				error_instance = param_error_inst;
			}


			/// Adds an instance to the instance buffer.
			/// @param type_instance The instance which will be added.
			void add_instance_to_buffer(const std::shared_ptr<T>& type_instance)
			{
				// TODO: Add MUTEX here!
				type_instances.push_back(type_instance);
			}


			/// Returns the number of existing instances.
			/// @return The number of existing instances.
			const std::size_t get_type_instance_count() const
			{
				return type_instances.size();
			}


			/// Deletes all instances.
			void delete_all_type_instances()
			{
				// TODO: Add MUTEX here!
				type_instances.clear();
			}


			// TODO: Delete instance by UUID.
			void delete_instance(const xg::Guid& type_GUID)
			{
				// TODO: Implement!
			}


			// TODO: Get instance by UUID.
			std::shared_ptr<T> get_instance(const xg::Guid&)
			{
				return error_instance;
			}
			
	};


};
};
