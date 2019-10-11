require('util');
require('entity-system');

var entity_type_name = 'INT_CONSTANT';
var entity_type = entity_system.entityTypeManager.get_entity_type(entity_type_name);
log(`Entity type ${entity_type.name}: ${entity_type.uuid}`);
