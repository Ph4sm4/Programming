
#include <vector>
#include <string>
#include <variant>
#include <iostream>
#include "Column.h"

class Table
{
private:
public:
        //     friend std::ostream& operator<<(std::ostream& os, const Table& table);
        Table(
            std::string tableName,
            const std::vector<Column> &columns);

        std::string tableName;
        std::vector<Column> columns;

        /*void addColumn(
                const std::string& name,
                const Column& column
        );*/

        // void dropColumn();
        // void renameColumn();
        // void changeDataType();

        /*  void addColumn(const std::string &name, const Column &column, const Database &db);*/
};
