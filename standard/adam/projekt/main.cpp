#include <vector>
#include <variant>
#include <iostream>
#include <map>
#include "Database.h"

auto main() -> int
{

        std::vector<Column> columns1 = {{"employee_id", "int", {1, 2, 3}}, {"name", "std::string", {"John", "Mario", "Emanuel"}}};
        std::vector<Column> columns2 = {{"alcohols_id", "int", {1, 2, 3}}, {"alcohol_type", "std::string", {"Vodka", "Whiskey", "Beer"}}};

        Table table1{"employees", columns1};
        Table table2{"alcohols", columns2};

        std::vector<Table> tablesxfd;
        tablesxfd.emplace_back(table1);
        tablesxfd.emplace_back(table2);

        Database db(tablesxfd);
}
