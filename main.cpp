#include "TSP.h"
#include <iostream>
using namespace std;
void main()
{
	TSP* lol = new TSP();
	if(lol->load()==false)
		cout << "Failed to open the file" << endl;
	lol->show_matrix();
	lol->route(0);
	cin.get();
}
