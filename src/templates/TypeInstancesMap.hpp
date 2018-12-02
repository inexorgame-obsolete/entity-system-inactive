// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// @brief A template class for a map of type instances.
	template <typename T1, typename T2>
	class TypeInstancesMap
	{
		private:

			/// Map of type instances which are linked by type.
			std::unordered_map<std::shared_ptr<T1>, std::shared_ptr<T2>> linked_instances;

		protected:

			/// @brief Adds a type instance to the type instance map.
			/// @param type_key The type of the instance which will be added.
			/// @param type_instance_value The instance which will be added.
			void add_linked_instance(const std::shared_ptr<T1>& type_key, const std::shared_ptr<T2>& type_instance_value)
			{
				linked_instances[type_key] = type_instance_value;
			}

		public:

			/// @brief Sets the data of an instance.
			/// @param type_ptr
			/// @param int_data 
			void set_data(const std::shared_ptr<T1>& type_ptr, const int& int_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, const bool& bool_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(bool_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, const float& float_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(float_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, const double& double_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(double_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, const std::string& string_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(string_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, const std::int64_t& int64t_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int64t_data);
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, int& int_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) int_ref = linked_instances[type_ptr]->get_int();
				else int_ref = 0;
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, bool& bool_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) bool_ref = linked_instances[type_ptr]->get_bool();
				else bool_ref = false;
			}


			/// @brief Sets the data of an instance.
			void set_data(const std::shared_ptr<T1>& type_ptr, float& float_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) float_ref = linked_instances[type_ptr]->get_float();
				else float_ref = 0.0f;
			}



			/// @brief Gets the data from an instance.
			void get_data(const std::shared_ptr<T1>& type_ptr, double& double_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) double_ref = linked_instances[type_ptr]->get_double();
				else double_ref = 0.0;
			}


			/// @brief Gets the data from an instance.
			void get_data(const std::shared_ptr<T1>& type_ptr, std::string& string_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) string_ref = linked_instances[type_ptr]->get_string();
				else string_ref = "";
			}


			/// @brief Gets the data from an instance.
			void get_data(const std::shared_ptr<T1>& type_ptr, std::int64_t& int64_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) int64_ref = linked_instances[type_ptr]->get_int64();
				else int64_ref = 0;
			}

	};


};
};
