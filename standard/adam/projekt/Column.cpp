#include "Column.h"
#include <utility>
#include <variant>

Column::Column(std::string columnName, std::string type,
               const std::vector<std::variant<int, double, std::string>> &data) : columnName(std::move(columnName)), type(std::move(type)),
                                                                                  data(data) {}

std::ostream &operator<<(std::ostream &os, const Column &column)
{
    // os << column.columnName << "\n";
    // // os << column.type << " ";
    // for (const auto &it : column.data)
    // {
    //     std::visit([&os](const auto &valueToPass1)
    //                { os << valueToPass1 << "\n"; }, it);
    // }
    return os;
}
