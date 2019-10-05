require('logging');
require('entity-system');
require('util');

var uuid_window = 'a2c251d9-218a-4e1f-be56-b6bc3dba5f19';
var window = entity_system.entityInstanceManager.get_entity_instance(uuid_window);
while (!window.window_maximized) {
	sleep(5000);
	window.window_fullscreen = !window.window_fullscreen;
}
