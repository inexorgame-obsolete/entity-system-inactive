#pragma once

#include "entity-system/util/uuid/GUIDBase.hpp"

#include <string>

namespace inexor {
namespace entity_system {

	/// @class TypeBase
	/// @brief A template base class for types.
	class TypeBase
	{
		private:

			/// The unique name of this type.
			std::string type_title;

			/// The mutex of this class.
			std::mutex type_base_mutex;

		protected:

			/// @brief Constructor.
			/// @param type_name The unique name of this type.
			TypeBase(const std::string& type_name);

			/// @brief Destructor.
			~TypeBase();

		public:

			/// @brief Returns the name of this type.
			/// @return The name of this type.
			std::string get_type_name() const;

	};

}
}
