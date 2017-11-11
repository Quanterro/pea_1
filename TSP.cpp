#include "TSP.h"
#include <iostream>
#include <fstream>
using namespace std;
TSP::TSP()
{}
TSP::~TSP()
{}
bool TSP::load()
{
	ifstream file("test.txt");
	if( file.good() == true )
	{
		file >> cities;
		file >> best;
		cout << "Cities: " << cities << endl;
		cout << "Best known solution: " << best << endl;
		distance = new int*[cities];

		for (int i = 0; i<cities; i++)
		{
			distance[i] = new int[cities];
			for (int j = 0; j<cities; j++)
			{
				file >> distance[i][j];
			}
		}
		file.close();
		return true;
	}else
		return false;

}
void TSP::show_matrix()
{
		for (int i = 0; i<cities; i++)
		{
			for (int j = 0; j<cities; j++)
			{
				cout << distance[i][j] << " ";
			}
			cout << endl;
		}
}
int TSP::route(int start)
{
	int x=0,y=0,z=0;
	first_subset = new int[cities-1];
	second_subset = new int*[cities-1];
	third_subset = new int[cities-1];
	parents = new int*[cities-1];
	for(int i=0; i<cities; i++)
	{
		if(start!=i)
		{
			first_subset[x] = distance[start][i];
			x++;
		}
	}
	x=0;
	for(int i=0; i<cities; i++)
	{
		if(i!=start)
		{
			second_subset[x] = new int[cities-2];
			parents[x] = new int[cities-2];
		}
		for(int j=0; j<cities;j++)
		{
			if(i!=start && j!=start && i!=j)
			{
				second_subset[x][y]=distance[i][j]+first_subset[x];
				parents[x][y] = j;
				y++;
			}
		}
		y=0;
		if(i!=start)
		x++;
	}
	x=0;
	for(int i=0; i<cities-1; i++)
	{
		if(i==start)
			z++;
		y=INT_MAX;
		for(int j=0; j<cities-2; j++)
		{
			//for(int k=0; k<cities-2;k++)
			{cout << z << " " << j << " ";
				if(y>second_subset[i][j]+distance[z][parents[i][j]])
				{
					
					cout << distance[z][parents[i][j]] << endl;
					y= second_subset[i][j]+distance[z][parents[i][j]];
				}
			}
		}
		third_subset[x]=y;
		x++;
		z++;
	}

	//sprawdzenie subsetow
	cout << endl;
	for (int j = 0; j<cities-1; j++)
			{
				cout << first_subset[j] << " ";
			}
	cout << endl;
	cout << endl;
			for (int i = 0; i<cities-1; i++)
		{
			for (int j = 0; j<cities-2; j++)
			{
				cout << second_subset[i][j]-first_subset[i] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i<cities-1; i++)
		{
			for (int j = 0; j<cities-2; j++)
			{
				cout << second_subset[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i<cities-1; i++)
		{
			for (int j = 0; j<cities-2; j++)
			{
				cout << parents[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int j = 0; j<cities-1; j++)
			{
				cout << third_subset[j] << " ";
				cout << endl;
			}
	cout << endl;
	return 0;
}