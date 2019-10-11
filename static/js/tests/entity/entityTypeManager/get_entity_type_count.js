require('util');
require('entity-system');

var count = entity_system.entityTypeManager.get_entity_type_count();
log(`Entity type count: ${count}`);
