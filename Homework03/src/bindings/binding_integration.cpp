/*
* Binding interface for Integration module
* Defines and bind Integration methods for the python's usage
*/

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include "../integration/Integration.hpp"

namespace py = pybind11;

// Add submodule
void add_integration(py::module_ &m) {

    m.doc() = "Python bindings for numerical integration";

    py::class_<Integration>(m, "Integration")
        .def(py::init<>(), "Initialize an Integration instance")
        .def("midpoint_rule", &Integration::midpointRule,
             "Compute integral using the Midpoint Rule",
             py::arg("f"), py::arg("a"), py::arg("b"), py::arg("N"))
        .def("trapezoidal_rule", &Integration::trapezoidalRule,
             "Compute integral using the Trapezoidal Rule",
             py::arg("f"), py::arg("a"), py::arg("b"), py::arg("N"))
        .def("simpsons_rule", &Integration::simpsonsRule,
             "Compute integral using Simpson's Rule",
             py::arg("f"), py::arg("a"), py::arg("b"), py::arg("N"))
        .def("step_size", &Integration::stepSize,
             "Calculate the step size",
             py::arg("a"), py::arg("b"), py::arg("N"));
     
     // Export C++ exceptions to Python
     py::register_exception<std::invalid_argument>(m, "InvalidArgumentError");
}
