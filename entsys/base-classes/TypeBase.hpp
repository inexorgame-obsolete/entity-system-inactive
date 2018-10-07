// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../data-validation//DataValidation.hpp"


namespace inexor {
namespace entity_system {


	// A template class for types of any kind.
	class TypeBase : public DataValidation
	{
		private:
			
			// The name of the type
			std::string type_name;

			// TODO: Implement UUID here!
			
		protected:

			// 
			TypeBase()
			{
				// TODO: Create UUID!
			}


			// 
			~TypeBase()
			{
			}


			// 
			void set_type_name(const std::string& param_type_name)
			{
				type_name = param_type_name;
			}


			// TODO: Implement get_UUID() method!

			// Every class which inherits from this base class needs to implement this data validation method.
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override = 0;

		
		public:

			//
			const std::string get_type_name() const
			{
				return type_name;
			}



	};

};
};
