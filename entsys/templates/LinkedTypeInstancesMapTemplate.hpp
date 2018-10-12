// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	// typename T1 = type, typename T2 = type instance.
	template <typename T1, typename T2>
	class LinkedTypeInstancesMapTemplate
	{
		private:

			//
			std::unordered_map<std::shared_ptr<T1>, std::shared_ptr<T2>> linked_instances;

		protected:

			//
			void add_linked_instance(const std::shared_ptr<T1>& key, const std::shared_ptr<T2>& value)
			{
				linked_instances[key] = value;
			}

		public:

			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const int& int_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const bool& bool_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(bool_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const float& float_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(float_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const double& double_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(double_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const std::string& string_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(string_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, const std::int64_t& int64t_data)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) linked_instances[type_ptr]->set(int64t_data);
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, int& int_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) int_ref = linked_instances[type_ptr]->get_int();
				else int_ref = 0;
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, bool& bool_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) bool_ref = linked_instances[type_ptr]->get_bool();
				else bool_ref = false;
			}


			//
			void set_data(const std::shared_ptr<T1>& type_ptr, float& float_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) float_ref = linked_instances[type_ptr]->get_float();
				else float_ref = 0.0f;
			}



			//
			void get_data(const std::shared_ptr<T1>& type_ptr, double& double_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) double_ref = linked_instances[type_ptr]->get_double();
				else double_ref = 0.0;
			}


			//
			void get_data(const std::shared_ptr<T1>& type_ptr, std::string& string_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) string_ref = linked_instances[type_ptr]->get_string();
				else string_ref = "";
			}


			//
			void get_data(const std::shared_ptr<T1>& type_ptr, std::int64_t& int64_ref)
			{
				if(linked_instances.end() != linked_instances.find(type_ptr)) int64_ref = linked_instances[type_ptr]->get_int64();
				else int64_ref = 0;
			}

	};


};
};
