// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "entity-system/EntitySystem.hpp"

using namespace std;
using namespace inexor::entity_system;

namespace inexor {
namespace entity_system {
namespace example {

	class ColorManager
	{
		public:

			/// Constructor.
			ColorManager(
				std::shared_ptr<EntityTypeManager> entity_type_manager,
				std::shared_ptr<EntityInstanceManager> entity_instance_manager
			);

			/// Destructor.
			~ColorManager();

			/// Initialization
			void init();

			/// Creates a new color
			void create_color(string name , float r, float g, float b);

			/// Deletes a color
			void delete_color(string name);

			/// Returns true, if the color with the given name exists.
			bool color_exists(string name);

			/// Returns the red component of the color with the given name.
			float r(string name);

			/// Returns the green component of the color with the given name.
			float g(string name);

			/// Returns the blue component of the color with the given name.
			float b(string name);

		private:

			/// The entity type manager
			std::shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity type manager
			std::shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity type: color
			ENT_TYPE entity_type_color;

			/// The pool of colors by name
			std::unordered_map<string, ENT_INST> colors;
	};


};
};
};
