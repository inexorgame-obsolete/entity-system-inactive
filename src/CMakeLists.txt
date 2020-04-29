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

# Those resources will be compiled into the binary.
corrade_add_resource(STATIC_BASE_RESOURCES ${PROJECT_SOURCE_DIR}/static/base-resources.conf)
corrade_add_resource(STATIC_IMAGE_RESOURCES ${PROJECT_SOURCE_DIR}/static/image-resources.conf)
corrade_add_resource(STATIC_FONT_RESOURCES ${PROJECT_SOURCE_DIR}/static/font-resources.conf)
corrade_add_resource(STATIC_TYPE_SYSTEM_RESOURCES ${PROJECT_SOURCE_DIR}/static/type-system-resources.conf)

add_executable(
    inexor-ecs-example
	
	InexorApplication.cpp
	main.cpp
	client/ClientLifecycle.cpp
	client/ClientModule.cpp
	command/CommandModule.cpp
	command/managers/CommandManager.cpp
	configuration/ConfigurationModule.cpp
	configuration/managers/CommandLineArgumentsConfigurationInitializer.cpp
	configuration/managers/ConfigurationManager.cpp
	configuration/managers/EnvVarConfigurationInitializer.cpp
	configuration/managers/SystemConfigurationInitializer.cpp
	input/InputModule.cpp
	input/managers/ClipboardManager.cpp
	input/managers/KeyboardInputManager.cpp
	input/managers/MouseInputManager.cpp
	input/processors/GlobalKeyProcessor.cpp
	input/processors/GlobalMouseButtonProcessor.cpp
	input/processors/InputProcessors.cpp
	logging/managers/LogManager.cpp
	renderer/RendererModule.cpp
	renderer/factories/TriangleFactory.cpp
	renderer/managers/FontManager.cpp
	renderer/managers/LoadingScreen.cpp
	renderer/managers/TriangleExample.cpp
	renderer/managers/UserInterfaceRenderer.cpp
	renderer/managers/WorldRenderer.cpp
	renderer/plugins/MagnumPlugins.cpp
	type-system/TypeSystemModule.cpp
	type-system/factories/TypeSystemFactories.cpp
	type-system/factories/data/DataFactories.cpp
	type-system/factories/data/constants/BoolConstantFactory.cpp
	type-system/factories/data/constants/ConstantFactories.cpp
	type-system/factories/data/constants/FloatConstantFactory.cpp
	type-system/factories/data/constants/IntConstantFactory.cpp
	type-system/factories/data/constants/StringConstantFactory.cpp
	type-system/factories/data/converters/ConverterFactories.cpp
	type-system/factories/data/converters/IntToFloatFactory.cpp
	type-system/factories/data/converters/IntToStringFactory.cpp
	type-system/factories/data/stores/FloatStoreFactory.cpp
	type-system/factories/data/stores/IntStoreFactory.cpp
	type-system/factories/data/stores/StoreFactories.cpp
	type-system/factories/data/stores/StringStoreFactory.cpp
	type-system/factories/generators/GeneratorFactories.cpp
	type-system/factories/generators/counters/CounterFactories.cpp
	type-system/factories/generators/counters/CounterFloatFactory.cpp
	type-system/factories/generators/counters/CounterIntFactory.cpp
	type-system/factories/generators/random/RandomFactories.cpp
	type-system/factories/generators/random/RandomNextFloatFactory.cpp
	type-system/factories/generators/random/RandomNextIntFactory.cpp
	type-system/factories/generators/timers/TimerFactories.cpp
	type-system/factories/generators/timers/TimerTickFactory.cpp
	type-system/factories/inout/InOutFactories.cpp
	type-system/factories/inout/keyboard/GlobalKeyFactory.cpp
	type-system/factories/inout/keyboard/KeyboardFactories.cpp
	type-system/factories/inout/logger/LoggerFactories.cpp
	type-system/factories/inout/logger/LoggerFactory.cpp
	type-system/factories/inout/mouse/GlobalMouseButtonFactory.cpp
	type-system/factories/inout/mouse/MouseFactories.cpp
	type-system/factories/logical/LogicalFactories.cpp
	type-system/factories/logical/comparison/ComparisonFactories.cpp
	type-system/factories/logical/comparison/EqualsBoolFactory.cpp
	type-system/factories/logical/comparison/EqualsIntFactory.cpp
	type-system/factories/logical/comparison/EqualsStringFactory.cpp
	type-system/factories/logical/comparison/GreaterThanFloatFactory.cpp
	type-system/factories/logical/comparison/GreaterThanIntFactory.cpp
	type-system/factories/logical/comparison/InRangeFloatFactory.cpp
	type-system/factories/logical/comparison/InRangeIntFactory.cpp
	type-system/factories/logical/comparison/LowerThanFloatFactory.cpp
	type-system/factories/logical/comparison/LowerThanIntFactory.cpp
	type-system/factories/logical/gates/AndFactory.cpp
	type-system/factories/logical/gates/GateFactories.cpp
	type-system/factories/logical/gates/NandFactory.cpp
	type-system/factories/logical/gates/NorFactory.cpp
	type-system/factories/logical/gates/NotFactory.cpp
	type-system/factories/logical/gates/OrFactory.cpp
	type-system/factories/logical/gates/XorFactory.cpp
	type-system/factories/math/MathFactories.cpp
	type-system/factories/math/arithmetic/AddFloatFactory.cpp
	type-system/factories/math/arithmetic/AddIntFactory.cpp
	type-system/factories/math/arithmetic/ArithmeticFactories.cpp
	type-system/factories/math/trigonometric/CosFactory.cpp
	type-system/factories/math/trigonometric/SinFactory.cpp
	type-system/factories/math/trigonometric/TanFactory.cpp
	type-system/factories/math/trigonometric/TrigonometricFactories.cpp
	type-system/initializer/TypeSystemInitializer.cpp
	ui/UserInterfaceModule.cpp
	ui/factories/MonitorFactory.cpp
	ui/factories/UserInterfaceFactories.cpp
	ui/factories/WindowFactory.cpp
	ui/managers/MonitorManager.cpp
	ui/managers/WindowManager.cpp
	ui/model/FpsLimiter.cpp
	visual-scripting/VisualScriptingSystemModule.cpp
	visual-scripting/managers/ConnectorManager.cpp
	visual-scripting/managers/ProcessorRegistry.cpp
	visual-scripting/model/Connector.cpp
	visual-scripting/model/Processor.cpp
	visual-scripting/processors/Processors.cpp
	visual-scripting/processors/data/DataProcessors.cpp
	visual-scripting/processors/data/converters/ConverterProcessors.cpp
	visual-scripting/processors/data/converters/IntToFloatProcessor.cpp
	visual-scripting/processors/data/converters/IntToStringProcessor.cpp
	visual-scripting/processors/generators/GeneratorProcessors.cpp
	visual-scripting/processors/generators/counters/CounterFloatProcessor.cpp
	visual-scripting/processors/generators/counters/CounterIntProcessor.cpp
	visual-scripting/processors/generators/counters/CounterProcessors.cpp
	visual-scripting/processors/generators/random/RandomNextFloatProcessor.cpp
	visual-scripting/processors/generators/random/RandomNextIntProcessor.cpp
	visual-scripting/processors/generators/random/RandomProcessors.cpp
	visual-scripting/processors/generators/timers/TimerProcessors.cpp
	visual-scripting/processors/generators/timers/TimerTickProcessor.cpp
	visual-scripting/processors/inout/InOutProcessors.cpp
	visual-scripting/processors/inout/console/ConsoleProcessors.cpp
	visual-scripting/processors/inout/console/StdErrProcessor.cpp
	visual-scripting/processors/inout/console/StdInProcessor.cpp
	visual-scripting/processors/inout/console/StdOutProcessor.cpp
	visual-scripting/processors/inout/logger/LoggerProcessor.cpp
	visual-scripting/processors/inout/logger/LoggerProcessors.cpp
	visual-scripting/processors/logical/LogicalProcessors.cpp
	visual-scripting/processors/logical/comparison/ComparisonProcessors.cpp
	visual-scripting/processors/logical/comparison/EqualsBoolProcessor.cpp
	visual-scripting/processors/logical/comparison/EqualsIntProcessor.cpp
	visual-scripting/processors/logical/comparison/EqualsStringProcessor.cpp
	visual-scripting/processors/logical/comparison/GreaterThanFloatProcessor.cpp
	visual-scripting/processors/logical/comparison/GreaterThanIntProcessor.cpp
	visual-scripting/processors/logical/comparison/InRangeFloatProcessor.cpp
	visual-scripting/processors/logical/comparison/InRangeIntProcessor.cpp
	visual-scripting/processors/logical/comparison/LowerThanFloatProcessor.cpp
	visual-scripting/processors/logical/comparison/LowerThanIntProcessor.cpp
	visual-scripting/processors/logical/gates/AndProcessor.cpp
	visual-scripting/processors/logical/gates/GateProcessors.cpp
	visual-scripting/processors/logical/gates/NandProcessor.cpp
	visual-scripting/processors/logical/gates/NorProcessor.cpp
	visual-scripting/processors/logical/gates/NotProcessor.cpp
	visual-scripting/processors/logical/gates/OrProcessor.cpp
	visual-scripting/processors/logical/gates/XorProcessor.cpp
	visual-scripting/processors/math/MathProcessors.cpp
	visual-scripting/processors/math/arithmetic/AddFloatProcessor.cpp
	visual-scripting/processors/math/arithmetic/AddIntProcessor.cpp
	visual-scripting/processors/math/arithmetic/ArithmeticProcessors.cpp
	visual-scripting/processors/math/trigonometric/CosProcessor.cpp
	visual-scripting/processors/math/trigonometric/SinProcessor.cpp
	visual-scripting/processors/math/trigonometric/TanProcessor.cpp
	visual-scripting/processors/math/trigonometric/TrigonometricProcessors.cpp
	${STATIC_BASE_RESOURCES}
	${STATIC_IMAGE_RESOURCES}
	${STATIC_FONT_RESOURCES}
	${STATIC_TYPE_SYSTEM_RESOURCES}
)

add_dependencies(inexor-ecs-example inexor-ecs)
add_dependencies(inexor-ecs-example Magnum)
add_dependencies(inexor-ecs-example Corrade)

set_target_properties(
    inexor-ecs-example PROPERTIES

    CXX_EXTENSIONS OFF
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_compile_definitions(
    inexor-ecs-example

    PRIVATE
    GLM_FORCE_DEPTH_ZERO_TO_ONE
    GLM_FORCE_RADIANS
)

if(MSVC)
    # Use multiple cores to compile when using Visual Studio.
    target_compile_options(inexor-ecs-example PRIVATE "/MP")
	
	# Disable C++17 deprecation warnings.
	target_compile_definitions(inexor-ecs-example PRIVATE _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS=1)
endif()

target_include_directories(
    inexor-ecs-example

    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/submodules/magnum/src/
    ${PROJECT_SOURCE_DIR}/submodules/magnum/src/Magnum/GL
    ${PROJECT_SOURCE_DIR}/submodules/magnum/src/Magnum/Shaders
    ${PROJECT_SOURCE_DIR}/submodules/magnum/src/Magnum/Text
	${PROJECT_SOURCE_DIR}/build/submodules/magnum/src/Magnum
)

target_link_libraries(
    inexor-ecs-example

    PUBLIC
    ${CONAN_LIBS}
	
	PRIVATE
	Corrade::Utility
	Magnum::Magnum
	Magnum::Trade
)
