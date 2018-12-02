// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../data-validation//DataValidation.hpp"


namespace inexor {
namespace entity_system {


	/// @brief A template class for types.
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

			/// @brief Sets the name of this type.
			/// @param type_name The name of the type.
			void set_type_name(const std::string& type_name);

			// TODO: Implement get_UUID() method!

			/// @brief Every class which inherits from this base class needs to implement this data validation method.
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override = 0;
					
		public:

			/// Returns the name of this type.
			std::string get_type_name() const;


	};

};
};
