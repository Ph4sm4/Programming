#include <string>
#include <vector>
#include <variant>
using namespace std;

class Column
{
private:
    string columnName;
    string type;
    vector<variant<int, double, string>> data;

public:
    friend ostream &operator<<(ostream &os, const Column &column);

    Column(string columnName, string type,
           const vector<variant<int, double, string>> &data);

    // void insertRows(const string tableName, variant<int, double, string> data);
};
