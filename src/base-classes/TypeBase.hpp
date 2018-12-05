// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../data-validation//DataValidation.hpp"


namespace inexor {
namespace entity_system {


	/// A template base class for types.
	class TypeBase : public DataValidation
	{
		private:
			
			/// The unique name of this type.
			std::string type_title;

			// TODO: Implement UUID!
			
		protected:

			/// Constructor.
			TypeBase();

			/// Destructor.
			~TypeBase();

			/// Sets the name of this type.
			/// @param type_name The unique name of the type.
			void set_type_name(const std::string& type_name);

			// TODO: Implement get_UUID() method!

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override = 0;
					
		public:

			/// Returns the name of this type.
			/// @return The namf ot this type.
			std::string get_type_name() const;


	};

};
};
