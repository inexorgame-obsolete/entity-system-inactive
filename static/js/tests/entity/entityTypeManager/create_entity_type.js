require('util');
require('entity-system');

var entity_type_name = 'INT_CONSTANT_2';
var entity_type = entity_system.entityTypeManager.create_entity_type(entity_type_name);
log(entity_type.uuid);
log(entity_type.name);

/*
var type_int_constant = entity_system.entityTypeManager.get_entity_type('INT_CONSTANT');
log(type_int_constant.uuid);
log(type_int_constant.name);
var new_int_constant = entity_system.entityInstanceManager.create_entity_instance(type_int_constant);
log(new_int_constant.uuid);
log(new_int_constant.int_constant_name);
log(new_int_constant.int_constant_value);
new_int_constant.int_constant_name = 'HELLO';
new_int_constant.int_constant_value = 'WORLD';
log(new_int_constant.int_constant_name);
log(new_int_constant.int_constant_value);
*/
