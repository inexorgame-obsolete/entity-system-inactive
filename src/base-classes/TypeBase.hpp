// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>

#include "../data-validation//DataValidation.hpp"

/// TODO: Fix conan package manager for dependencies!
/// This file will not be contained in the repository itself.
/// https://github.com/graeme-hill/crossguid
#include <crossguid/guid.hpp>


namespace inexor {
namespace entity_system {


	/// A template base class for types.
	class TypeBase : public DataValidation
	{
		private:
			
			/// The unique name of this type.
			std::string type_title;

			/// The Universally Unique Identifier of this type.
			xg::Guid type_UUID = xg::newGuid();
			
		protected:

			/// Constructor.
			TypeBase(const std::string&);

			/// Destructor.
			~TypeBase();

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
