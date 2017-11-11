#pragma once
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
public:
	TSP::TSP();
	TSP::~TSP();
	bool load();
	void show_matrix();
	int route(int);
};