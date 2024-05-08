#include <iostream>
#include <algorithm>
#include <utility>
#include "Table.h"

Table::Table(std::string tableName,
             const std::vector<Column> &columns) : tableName(std::move(tableName)), columns(columns) {}

std::ostream &operator<<(std::ostream &os, const Table &table)
{
    os << "table: " << table.tableName << "\n";
    for (auto const &column : table.columns)
    {
        os << " " << column;
    }
    return os;
}

/*void Table::addColumn(const std::string& name, const Column& column, const Database& db){
        auto tables = db.getTables().at(name);
        tables.columns.emplace_back(column);
}*/
