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
			
			// The unique name of this type.
			std::string type_title;

			// TODO: Implement UUID!
			
		protected:

			TypeBase();
			~TypeBase();

			// Set the name of this type.
			void set_type_name(const std::string& type_name);

			// TODO: Implement get_UUID() method!

			// Every class which inherits from this base class needs to implement this data validation method.
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override = 0;

		
		public:

			// Get the name of this type.
			const std::string get_type_name() const;


	};

};
};
