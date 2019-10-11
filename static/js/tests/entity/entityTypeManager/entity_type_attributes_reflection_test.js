/**
 * This test shows how to find out which attributes are available for a given
 * entity type.
 */
require('logging');
require('util');
require('entity-system');

// Currently you have to know the uuid of the entity instance
var entity_type_name = 'INT_CONSTANT';

// Request the entity type
var entity_type = entity_system.entityTypeManager.get_entity_type(entity_type_name);

// Reflect the attribute names
var attribute_names = Object.getOwnPropertyNames(entity_type);

var entity_type_summary = 'Entity Type ' + uuid + ' has ' + attribute_names.length + ' attributes';
for (var i = 0; i < attribute_names.length; i++) {

	// Access attributes by name using the bracket operator
	entity_type_summary += `\n  entity_type.${attribute_names[i]}`;
}

// Output the summary
log(entity_type_summary);
 