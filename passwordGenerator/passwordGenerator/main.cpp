#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Password.h"
using namespace std;

int main() {
	srand(time(NULL));
	
	Menu menu;
	menu.Display();
	
	return 0;
}