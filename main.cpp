#include "TSP.h"
#include <iostream>
using namespace std;
void main()
{
	TSP* lol = new TSP();
	if(lol->load()==false)
		cout << "Failed to open the file" << endl;
	lol->show_matrix();
	cout << "Shortes path found: " <<lol->route(3) << endl;
	lol->show_route();
	cin.get();
}
