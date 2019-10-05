require('logging');
require('entity-system');
require('util');

// Load window
var uuid_triangle = '5721b79b-b3c0-4057-9344-b935276625dd';
var triangle = entity_system.entityInstanceManager.get_entity_instance(uuid_triangle);

var uuid_window = 'a2c251d9-218a-4e1f-be56-b6bc3dba5f19';
var window = entity_system.entityInstanceManager.get_entity_instance(uuid_window);



while (!window.window_fullscreen) {
	sleep(100);
	log(`Triangle (${triangle.triangle_x}, ${triangle.triangle_y})`);
}
