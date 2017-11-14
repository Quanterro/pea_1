#include "TSP.h"
#include <iostream>
#include <fstream>
#include <vector>
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
	int x=0,y=0,z=0, temp=0,c,o;
	vector <int> tab;
	int** second_subset2 = new int*[cities];
	int* second_parent = new int[cities-1];
	first_subset = new int[cities-1];
	second_subset = new int*[cities-1];
	third_subset = new int[cities-1];
	parents = new int*[cities-1];

	path.push_back(start);
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
			parents[x] = new int[cities-2];
		}
		second_subset2[i] = new int[cities];
		for(int j=0; j<cities;j++)
		{
			if(i!=start && j!=start && i!=j)
			{
				second_subset2[i][z]=distance[i][j]+first_subset[x];
				parents[x][y] = j;
				y++;
				z++;
			}
			else
			{
				second_subset2[i][z]=-1;
				z++;
			}

		}
		y=0;
		z=0;
		if(i!=start)
		x++;
	}

z=0;
x=0;

for(int k=0; k<cities; k++)
{
	for(int i=cities-1; i>=0; i--)
	{
		
		for(int j=cities-1; j>=0; j--)
		{
			if(i!=k && j!=k && second_subset2[i][j]>0 && k!=start)
			{
				tab.push_back(second_subset2[i][j]);
									
			}
		}
	}
}
x=0;
z=0;
temp =0;
for(int i=0; i<cities -1; i++)
{
	y=INT_MAX;
	if(i==start)
		z++;
	for(int j=0; j<cities -2; j++)
	{
		if(y>tab[x]+distance[parents[i][j]][z])
		{
			y = tab[x]+distance[parents[i][j]][z];
			temp = parents[i][j];
			x++;
		}else
			x++;
	}
	second_parent[i]=temp;
	third_subset[i]=y;
	z++;
}
z=0;
x=0;
y=INT_MAX;
for (int i=0; i<cities -1; i++)
{
	if(i==start)
		z++;
	if(y>third_subset[i]+distance[z][start])
	{
		y=third_subset[i]+distance[z][start];
		x=z;
		o=x;
		temp = i;
	}
	z++;
}
path.push_back(x);
path.push_back(second_parent[temp]);
c=INT_MAX;
for(int i=0;i<cities;i++)
{
	if(c>second_subset2[i][second_parent[temp]] && second_subset2[i][second_parent[temp]]>0 && i!=o)
	{
		
		c=second_subset2[i][second_parent[temp]];
		x=i;
	}
}
path.push_back(x);
path.push_back(start);
	//sprawdzenie subsetow
	//cout << endl;
	//for (int j = 0; j<cities-1; j++)
	//		{
	//			cout <<second_parent[j] << " ";
	//		}
	//cout << endl;
	//cout << endl;
	//		for (int i = 0; i<cities-1; i++)
	//	{
	//		for (int j = 0; j<cities-2; j++)
	//		{
	//			cout << second_subset[i][j]-first_subset[i] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//	for (int i = 0; i<cities; i++)
	//	{
	//		for (int j = 0; j<cities; j++)
	//		{
	//			cout << second_subset2[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//	for (int i = 0; i<cities-1; i++)
	//	{
	//		for (int j = 0; j<cities-2; j++)
	//		{
	//			cout << second_subset[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
		//cout << endl;
		//for (int i = 0; i<cities-1; i++)
		//{
		//	for (int j = 0; j<cities-2; j++)
		//	{
		//		cout << parents[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		//for (int j = 0; j<cities-1; j++)
		//	{
		//		cout << third_subset[j] << " ";
		//		cout << endl;
		//	}
		//for (int j = 0; j<tab.size(); j++)
		//	{

		//		cout << tab[j] << " ";
		//		cout << endl;
		//	}
		//for (int j = 0; j<path.size(); j++)
		//	{

		//		cout << path[j] << " ";
		//		cout << endl;
		//	}
	cout << endl;
	return y;
}
void TSP::show_route()
{
	cout << "Salesman path: ";
	for(int i=path.size()-1; i>=0; i--)
	{
		if(i!=0)
		cout  << path[i] << "->"; 
		else
		cout  << path[i]; 
	}
	cout << endl;
}