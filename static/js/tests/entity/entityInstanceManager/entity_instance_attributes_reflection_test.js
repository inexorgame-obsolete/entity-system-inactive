/**
 * This test shows how to find out which attributes are available for a given
 * entity instance and how to get their values.
 */
require('logging');
require('util');
require('entity-system');

// Currently you have to know the uuid of the entity instance
var uuid = 'f3225bb6-9ce3-443b-b075-d06d4c585673';

// Request the entity instance
var entity_instance = entity_system.entityInstanceManager.get_entity_instance(uuid);

// Reflect the attribute names
var attribute_names = Object.getOwnPropertyNames(entity_instance);

var entity_instance_summary = 'Entity Instance ' + uuid + ' has ' + attribute_names.length + ' attributes';
for (var i = 0; i < attribute_names.length; i++) {

	// Access attributes by name using the bracket operator
	entity_instance_summary += `\n  entity_instance.${attribute_names[i]} = ${entity_instance[attribute_names[i]]}`;
}

// Output the summary
log(entity_instance_summary);


/**
 * Sample output:
 *
 *
 * Entity Instance 7cc782c0-d84b-419e-b459-1233a3341a7d has 18 attributes
 *   entity_instance.uuid = 7cc782c0-d84b-419e-b459-1233a3341a7d
 *   entity_instance.type = WINDOW
 *   entity_instance.window_focused = false
 *   entity_instance.window_restore_width = 800
 *   entity_instance.window_vsync = true
 *   entity_instance.window_fullscreen = false
 *   entity_instance.window_visible = true
 *   entity_instance.window_fps = 60
 *   entity_instance.window_height = 600
 *   entity_instance.window_title = Loading Inexor...
 *   entity_instance.window_iconified = false
 *   entity_instance.window_opacity = 0.949999988079071
 *   entity_instance.window_restore_height = 600
 *   entity_instance.window_id = 1
 *   entity_instance.window_position_y = 827
 *   entity_instance.window_width = 800
 *   entity_instance.window_maximized = false
 *   entity_instance.window_position_x = 2338
 *
 */
 
 