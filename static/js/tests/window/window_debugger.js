require('logging');
require('entity-system');
require('util');

// Load window
var uuid_window = 'a2c251d9-218a-4e1f-be56-b6bc3dba5f19';
var window = entity_system.entityInstanceManager.get_entity_instance(uuid_window);

var old_x = window.window_position_x;
var old_y = window.window_position_y;
while (!window.window_fullscreen) {
	sleep(50);
	if (window.window_position_x != old_x
		|| window.window_position_y != old_y
	) {
		// Yes, I've noticed that the window position has changed
		
		log(`The window '${window.window_title}' has moved to (${window.window_position_x},${window.window_position_y})`);
		old_x = window.window_position_x;
		old_y = window.window_position_y;
	}
}
