#include <map>
#include <string>
#include <vector>
#include "Table.h"
using namespace std;

class Database
{
private:
public:
    vector<Table> tables;

    Database(vector<Table> t);
};
