#pragma once
#include <vector>
using namespace std;
class TSP
{
private:
	int cities;
	int best;
	int** distance;
	int* first_subset;
	int** second_subset;
	int* third_subset;
	int** parents;
	vector<int> path;
public:
	TSP::TSP();
	TSP::~TSP();
	bool load();
	void show_matrix();
	void show_route();
	int route(int);
};