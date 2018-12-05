// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// A template base class
	/// for a map of instances of a templatable type.
	template <typename T1, typename T2>
	class TypeInstancesContainerTemplate
	{
		private:
			
			/// An unordered map which stored all type instances by type.
			std::unordered_map<std::shared_ptr<T1>, std::shared_ptr<T2>> linked_instances;

		protected:

			/// Constructor.
			TypeInstancesContainerTemplate()
			{
			}


			/// Destructor.
			~TypeInstancesContainerTemplate()
			{
			}


			/// Adds a type instance to the type instance map.
			/// @param type_key The type of the instance which will be added.
			/// @param type_instance_value The instance which will be added.
			void add_linked_instance(const std::shared_ptr<T1>& type_key, const std::shared_ptr<T2>& type_instance_value)
			{
				linked_instances[type_key] = type_instance_value;
			}


		public:

			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of a
			/// a shared pointer to a type instance of templatable type.
			/// @param int_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const int& int_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int_data);
			}


			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param bool_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const bool& bool_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(bool_data);
			}


			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param float_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const float& float_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(float_data);
			}


			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param double_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const double& double_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(double_data);
			}


			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param string_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const std::string& string_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(string_data);
			}


			/// Sets the data of an instance.
			/// @param type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param int64t_data The memory which will be copied to the instance.
			void set_data(const std::shared_ptr<T1>& type_inst_ptr, const std::int64_t& int64t_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int64t_data);
			}



			
			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] int_ref <b>Call by reference</b>: The integer memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, int& int_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) int_ref = linked_instances[type_ptr]->get_int();
				else int_ref = 0;
			}

			
			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] bool_ref <b>Call by reference</b>: The bool memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, bool& bool_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) bool_ref = linked_instances[type_ptr]->get_bool();
				else bool_ref = false;
			}

			
			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] float_ref <b>Call by reference</b>: The float memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, float& float_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr))
				{
					float_ref = linked_instances[type_ptr]->get_float();
				}
				else float_ref = 0.0f;
			}


			
			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] double_ref <b>Call by reference</b>: The double memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, double& double_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr))
				{
					double_ref = linked_instances[type_ptr]->get_double();
				}
				else double_ref = 0.0;
			}


			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] string_ref <b>Call by reference</b>: The std::string memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, std::string& string_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr))
				{
					string_ref = linked_instances[type_ptr]->get_string();
				}
				else string_ref = "";
			}


			/// Gets the data from an instance.
			/// @param[in] type_inst_ptr A const reference of
			/// a shared pointer to a type instance of templatable type.
			/// @param[out] int64_ref <b>Call by reference</b>: The 64 bit integer memory
			/// to which the data of the instance will be copied.
			/// @return None.
			void get_data(const std::shared_ptr<T1>& type_inst_ptr, std::int64_t& int64_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr))
				{
					int64_ref = linked_instances[type_ptr]->get_int64();
				}
				else int64_ref = 0;
			}

	};


};
};
