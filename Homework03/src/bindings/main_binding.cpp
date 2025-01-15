/*
* Binding interface for Statistics and Integration module for scientific_toolbox
* Integrates implementations for both modules and uses pybind11 to bind it togheter
*/

#include <pybind11/pybind11.h>

namespace py = pybind11;

void add_integration(py::module_ &m);
void add_statistics(py::module_ &m);
void add_CSVParser(py::module_ &m);

PYBIND11_MODULE(scientific_toolbox, m) {
    
    m.doc() = "Main module for Python scientific_toolbox";

    // Add submodule integration
    py::module_ integration_module = m.def_submodule("integration", "Numerical integration functionalities");
    add_integration(integration_module);

    // Add submodule statistics
    py::module_ statistics_module = m.def_submodule("statistics", "Statistical analysis functionalities");
    add_statistics(statistics_module);

    // Add submodule CSVParser
    py::module_ CSVParser_module = m.def_submodule("CSVParser", "CSVParser functionalities");
    add_CSVParser(CSVParser_module);
}

