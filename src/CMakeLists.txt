add_library(
    inexor-ecs
	
	entity-system/EntitySystemModule.cpp
	entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.cpp
	entity-system/builders/entities/entity-type-builder/EntityTypeBuilder.cpp
	entity-system/builders/relations/relation-instance-builder/RelationInstanceBuilder.cpp
	entity-system/builders/relations/relation-type-builder/RelationTypeBuilder.cpp
	entity-system/debugger/EntitySystemDebugger.cpp
	entity-system/factories/BuilderFactories.cpp
	entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.cpp
	entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.cpp
	entity-system/factories/relations/relation-instance-builder-factory/RelationInstanceBuilderFactory.cpp
	entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.cpp
	entity-system/managers/EntityManager.cpp
	entity-system/managers/RelationManager.cpp
	entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.cpp
	entity-system/managers/entities/entity-type-manager/EntityTypeManager.cpp
	entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.cpp
	entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.cpp
	entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.cpp
	entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.cpp
	entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.cpp
	entity-system/managers/relations/relation-type-manager/RelationTypeManager.cpp
	entity-system/model/base/attribute/AttributeBase.cpp
	entity-system/model/base/guid/GUIDBase.cpp
	entity-system/model/base/type/TypeBase.cpp
	entity-system/model/entities/entity-instances/EntityInstance.cpp
	entity-system/model/entities/entity-types/EntityType.cpp
	entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.cpp
	entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.cpp
	entity-system/model/relation-attributes/relation-attribute-instances/RelationAttributeInstance.cpp
	entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.cpp
	entity-system/model/relations/relation-instances/RelationInstance.cpp
	entity-system/model/relations/relation-types/RelationType.cpp
	entity-system/serializers/EntityInstanceJsonSerializer.cpp
	entity-system/serializers/EntitySystemSerializers.cpp
	entity-system/serializers/EntityTypeJsonSerializer.cpp
)

set_target_properties(
    inexor-ecs PROPERTIES

    CXX_EXTENSIONS OFF
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

if(MSVC)
    # Use multiple cores to compile when using Visual Studio.
    target_compile_options(inexor-ecs PRIVATE "/MP")
	
	# Disable C++17 deprecation warnings.
	target_compile_definitions(inexor-ecs PRIVATE _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS=1)
endif()

target_include_directories(
    inexor-ecs

    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    inexor-ecs

    PUBLIC
    ${CONAN_LIBS}
)
