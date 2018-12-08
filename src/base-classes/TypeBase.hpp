// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../data-validation//DataValidation.hpp"
#include "base-classes/GUID/GUIDBase.hpp"


namespace inexor {
namespace entity_system {

	/// @note It does not make sense to let TypeBase or AttributeBase
	/// inherit from GUIDBase, because then EntityAttributeType would
	/// contain multiple get_GUID() methods!

	/// A template base class for types.
	class TypeBase : public DataValidation
	{
		private:
			
			/// The unique name of this type.
			std::string type_title;
			
		protected:

			/// Constructor.
			TypeBase(const std::string&);

			/// Destructor.
			~TypeBase();

			/// Implement a data validation method as
			/// required by class inheritance of DataValidation!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override = 0;
					
		public:

			/// Returns the name of this type.
			/// @return The name of this type.
			std::string get_type_name() const;


	};

};
};
