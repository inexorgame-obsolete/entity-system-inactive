/**
 * This test shows how to manipulate the stdin
 */
require('logging');
require('entity-system');
require('util');

// Currently you have to know the uuid of the entity instance
var uuid = '36d83a62-4bf3-4f83-a35e-fbf7f862ad73';

// Request the entity instance
var stdin = entity_system.entityInstanceManager.get_entity_instance(uuid);

for (var i = 0; i < 10; i++) {
	sleep(250);
	var text = `Hello Inexor ${i}!`;
	stdin.console_stdin = text;
}
 