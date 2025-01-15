/*
* Binding interface for CSVParser module
* Defines and bind CSVParser methods for the python's usage
*/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "../statistics/CSVParser.hpp"

namespace py = pybind11;

void add_CSVParser(py::module_ &m) {

    m.doc() = "Python bindings for CSVParser class";

    // Bind the CSVParser class
    py::class_<CSVParser>(m, "CSVParser")
        .def(py::init<const std::string&, char, bool>(),
             py::arg("file_path"), py::arg("delimiter") = ',', py::arg("has_headers") = true,
             "Initialize a CSVParser instance")
        .def("parse", &CSVParser::parse, "Parse the CSV file")
        .def("getHeaders", &CSVParser::getHeaders, "Get the headers of the CSV file")
        .def("getHeaderIndex", &CSVParser::getHeaderIndex, "Get the index of a header")
        .def("getNumRows", &CSVParser::getNumRows, "Get the number of rows in the CSV file")
        .def("getHead", &CSVParser::getHead, "Get the first N rows")
        .def("getTail", &CSVParser::getTail, "Get the last N rows")
        .def("getRow", &CSVParser::getRow, "Get a specific row by index")
        .def("__getitem__", &CSVParser::operator[], "Access a row by index");

    // Export C++ exceptions to Python
    py::register_exception<std::runtime_error>(m, "RuntimeError");
    py::register_exception<std::out_of_range>(m, "OutOfRangeError");
}

