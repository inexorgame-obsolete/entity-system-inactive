require('entity-system');
require('util');

// Load window
var uuid_window = 'a2c251d9-218a-4e1f-be56-b6bc3dba5f19';
var window = entity_system.entityInstanceManager.get_entity_instance(uuid_window);

while (!window.window_fullscreen) {
	sleep(2000);
	if (window.window_position_x > 1000) {
		window.window_position_x = 100;
	}
}
