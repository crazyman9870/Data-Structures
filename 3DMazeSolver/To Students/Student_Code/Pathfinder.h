/*
 * Pathfinder.h
 *
 *  Created on: May 29, 2014
 *      Author: aconstan
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathfinderInterface.h"
#include "Factory.h"

#include <fstream>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <ctime>

#define D1 5
#define D2 5
#define D3 5

using namespace std;

class Pathfinder : public PathfinderInterface
{
private:
	vector<string> solution;
	string maze[D1][D2][D3];
	//vector<string> maze[D1][D2][D3]; //(D1, D2, D3);
	//vector<vector<vector<string>>> maze;
	/*maze.resize(D1);
	for(int i = 0; i < D1; i++)
	{
		maze[i].resize(D2);
		for(int j = 0; j < D2; j++)
			maze[i][j].resize(D3);
	}
	*/

public:
	Pathfinder();
	virtual ~Pathfinder();

void  initialize();

void print();

string maze_to_string();

int string_to_int(string expression);

string int_to_string(int n);

string add_onto_vector(int x, int y, int z);

bool fix_maze(int x, int y, int z, vector<string>& solution);

bool find_maze_path(int x, int y, int z);

void print_vector(vector<string> solution);


//Part 1-----------------------------------------------------------------------------------

string getMaze();

void createRandomMaze();
//-----------------------------------------------------------------------------------------

//Part 2-----------------------------------------------------------------------------------

bool importMaze(string file_name);
//-----------------------------------------------------------------------------------------

//Part 3-----------------------------------------------------------------------------------

vector<string> solveMaze();

//-----------------------------------------------------------------------------------------


};

#endif /* PATHFINDER_H_ */
