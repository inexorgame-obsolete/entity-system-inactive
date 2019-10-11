require('logging');
require('entity-system');
require('util');

// Load window
var uuid_window = 'a2c251d9-218a-4e1f-be56-b6bc3dba5f19';
var window = entity_system.entityInstanceManager.get_entity_instance(uuid_window);

log('start');
for (var i = 0; i < 1000000; i++) {
	var tmp = window.window_position_x;
}
log('end');
