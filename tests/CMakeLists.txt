add_executable(
    inexor-ecs-tests

    ecs_unit_tests_main.cpp
)

set_target_properties(
    inexor-ecs-tests PROPERTIES

    CXX_EXTENSIONS OFF
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(
    inexor-ecs-tests

    PRIVATE
    inexor-ecs-renderer
)
