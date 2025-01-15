/*
* Define the Cell type alias
*/

#ifndef CELLTYPE_HPP__
#define CELLTYPE_HPP__

#include <variant>
#include <string>
#include <optional>

using Cell = std::optional<std::variant<int, double, std::string>>;

#endif // CELLTYPE_HPP__
