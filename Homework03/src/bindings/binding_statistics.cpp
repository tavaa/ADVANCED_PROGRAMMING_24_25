/*
* Binding interface for Statistical module
* Defines and bind statistics methods for the python's usage
*/

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include "../statistics/Statistics.hpp"
#include "../statistics/CellType.hpp"

namespace py = pybind11;

// Add submodule
void add_statistics(py::module_ &m) {

    m.doc() = "Python bindings for Statistical Methods";

    py::class_<Statistics>(m, "Statistics")
        .def(py::init<const std::string&, char, bool>(),
             py::arg("file_path"), py::arg("delimiter") = ',', py::arg("has_headers") = true,
             "Initialize Statistics with a CSV file")
        .def("get_headers", &Statistics::getHeaders,
             "Get the headers of the CSV file")
        .def("get_column", &Statistics::getColumn,
             py::arg("column_name"),
             "Get the values of a specific column")
        .def_static("min_value", &Statistics::minValue, py::arg("column_values"),
                    "Calculate the minimum value of a column")
        .def_static("max_value", &Statistics::maxValue, py::arg("column_values"),
                    "Calculate the maximum value of a column")
        .def_static("calculate_mean", &Statistics::calculateMean, py::arg("column_values"),
                    "Calculate the mean of a column")
        .def_static("calculate_median", &Statistics::calculateMedian, py::arg("column_values"),
                    "Calculate the median of a column")
        .def_static("calculate_variance", &Statistics::calculateVariance, py::arg("column_values"),
                    "Calculate the variance of a column")
        .def_static("calculate_sd", &Statistics::calculateSd, py::arg("column_values"),
                    "Calculate the standard deviation of a column")
        .def_static("frequency_count", &Statistics::frequencyCount, py::arg("column_values"),
                    "Calculate the frequency count of a column")
        .def_static("calculate_correlation", &Statistics::calculateCorrelation,
                    py::arg("column_values1"), py::arg("column_values2"),
                    "Calculate the correlation between two columns")
        .def_static("draw_histogram", [](const std::vector<Cell>& column_values) {
            std::ostringstream oss;
            Statistics::drawHistogram(column_values, oss);
            return oss.str();
        }, py::arg("column_values"),
        "Draw a histogram of a column");

    // Export C++ exceptions to Python
    py::register_exception<std::runtime_error>(m, "RuntimeError");
    py::register_exception<std::invalid_argument>(m, "InvalidArgumentError");
}


