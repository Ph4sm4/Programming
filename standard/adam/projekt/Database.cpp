#include "Database.h"

// /*Database::Database(const std::map<std::string, Table>& tables) : tables(tables){}*/

Database::Database(std::vector<Table> t)
{
    this->tables = t;
}

// /*
// std::map<std::string, Table> Database::getTables() const {
//     return tables;
// }

// void Database::addTable(const std::string &name, const std::vector<Column> &columns) {
//         //dopisac logike
//        tables.insert(std::make_pair(name, Table(name, columns)));
// }

// void Database::dropTable(const std::string &name) {
//     //dopisac logike
//     tables.erase(name);
// }*/

// /*std::ostream operator<<(std::ostream &os, Database &db) {
//         for(const auto& pair : db.tables) {
//             std::visit([&os](const auto& val) { os << val; }, *pair);
//         }
//     return os;
// }*/
