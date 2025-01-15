pybind11_add_module(scientific_toolbox
    bindings/main_binding.cpp
    bindings/binding_statistics.cpp
    bindings/binding_integration.cpp
    bindings/binding_CSVParser.cpp
    statistics/Statistics.cpp
    statistics/CSVParser.cpp
    integration/Integration.cpp
)

target_include_directories(scientific_toolbox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/statistics
    ${CMAKE_CURRENT_SOURCE_DIR}/integration
)

target_link_libraries(scientific_toolbox PRIVATE pybind11::module)
