/*
 * Pathfinder.cpp
 *
 *  Created on: May 29, 2014
 *      Author: aconstan
 */

#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder()
{
	maze[0][0][0] = "-1";
}

Pathfinder::~Pathfinder()
{

}
//Extra Fxns-------------------------------------------------------------------------------

void Pathfinder::initialize()
{
	//stringstream ss;
	int count = 0;
	//string fill = "1";

	//ss << fill;
	while (count < 125)
	{
		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					maze[x][y][z] = "1";
					count++;
				}
				//count++;
			}
			//count++;
		}
		//count++;
	}
	//ss >> maze;

}

void Pathfinder::print()
{
	int count = 0;

	//while (count < 125)
	//{
		for (int z = 0; z < 5; z++)
		{
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					cout << maze[x][y][z] << " ";
					count++;
				}
				cout << endl;
			}
			cout << endl;
		}
		//count++; count << "\t" <<
	//}
}

string Pathfinder::maze_to_string()
{
	string maze_mod = "";

	for (int z = 0; z < 5; z++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				maze_mod += maze[x][y][z];
				if (x < 4)
				{
					maze_mod += " ";
				}
			}
			maze_mod += "\n";
		}
		if (z < 4)
		{
			maze_mod += "\n";
		}
	}

	return maze_mod;
}

int Pathfinder::string_to_int(string expression)
{
	istringstream strm;
	strm.str(expression);
	int n = 0;
	strm >> n;
	return n;
}

string Pathfinder::int_to_string(int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}

string Pathfinder::add_onto_vector(int x, int y, int z)
{
	string x1 = int_to_string(x);
	string y1 = int_to_string(y);
	string z1 = int_to_string(z);
	string final = "(" + x1 + ", " + y1 + ", " + z1 + ")";
	return final;
}

bool Pathfinder::fix_maze(int x, int y, int z, vector<string>& solution)
{
	string final;

	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4)
		{
			return false;
		}
		else if (maze[x][y][z] != "2" && maze[x][y][z] != "3")
		{
			return false;
		}
		else if (x == 4 && y == 4 && z == 4)
		{
			//cout << "Maze Fixed" << endl;
			final = add_onto_vector(x, y, z);
			solution.push_back(final);
			maze[x][y][z] = "1";
			return true;
		}
		else
		{
			//print();
			if (maze[x][y][z] == "2")
			{
				final = add_onto_vector(x, y, z);
				solution.push_back(final);
			}
			maze[x][y][z] = "1";
			//print();
			//cout << "here" << endl;
			if (fix_maze(x + 1, y, z, solution)
					|| fix_maze(x - 1, y, z, solution)
					|| fix_maze(x, y + 1, z, solution)
					|| fix_maze(x, y - 1, z, solution)
					|| fix_maze(x, y, z + 1, solution)
					|| fix_maze(x, y, z - 1, solution))
			{
				//cout << "made it" << endl;
				return true;
			}
			else
			{
				//cout << "didn't make it" << endl;
				//maze[x][y][z] = "0";
				return false;
			}
		}
}

bool Pathfinder::find_maze_path(int x, int y, int z)
{
	//cout << 1 << endl;
	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4)
	{
		return false;
	}
	else if (maze[x][y][z] != "1")
	{
		return false;
	}
	else if (x == 4 && y == 4 && z == 4)
	{
		//cout << "FINISH" << endl;
		maze[x][y][z] = "2";
		//print();
		return true;
	}
	else
	{
		//cout << 3 << endl;
		maze[x][y][z] = "2";
		if (find_maze_path(x + 1, y, z)
				|| find_maze_path(x - 1, y, z)
				|| find_maze_path(x, y + 1, z)
				|| find_maze_path(x, y - 1, z)
				|| find_maze_path(x, y, z + 1)
				|| find_maze_path(x, y, z - 1))
		{
			return true;
		}
		else
		{
			maze[x][y][z] = "3";
			return false;
		}
	}
}

void Pathfinder::print_vector(vector<string> solution)
{
	for (int i = 0; i < solution.size(); i++)
	{
		cout << solution[i] << endl;
	}
}
//Part 1-----------------------------------------------------------------------------------
/*
 * getMaze
 *
 * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
 * has yet been generated or imported.
 *
 * A valid string representation of a maze consists only of 125 1s and 0s (each separated
 * by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
 * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
 *
 * Cell (0, 0, 0) is represented by the first number in the string representation of the
 * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
 * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
 * sixth number. Increasing in z means moving downward to a new grid, meaning cell
 * (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
 *
 * Returns:		string
 *				A single string representing the current maze
 */
string Pathfinder::getMaze()
{
	stringstream ss;
	string the_maze;

	//print();

	//initialize();
	if (maze[0][0][0] != "1" && maze[4][4][4] != "1")
	{
		initialize();
		the_maze = maze_to_string();
		//print();
	}
	else
	{
		the_maze = maze_to_string();
		//cout << "Let do this" << endl;
		//cout << the_maze;
	}
	return the_maze;

}

/*
 * createRandomMaze
 *
 * Generates a random maze and stores it as the current maze.
 *
 * The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
 * in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
 * solvable or unsolvable, and this method should be able to produce both kinds of mazes.
 */
void Pathfinder::createRandomMaze()
{

	//int rand_maze[5][5][5];

	string var = "";

	for (int z = 0; z < 5; z++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
			int n = rand() % 2;
			var = int_to_string(n);
			maze[x][y][z] = var;
			}
		}
	}
	maze[0][0][0] = "1";
	maze[4][4][4] = "1";


}
//-----------------------------------------------------------------------------------------

//Part 2-----------------------------------------------------------------------------------
/*
 * importMaze
 *
 * Reads in a maze from a file with the given file name and stores it as the current maze.
 * Does nothing if the file does not exist or if the file's data does not represent a valid
 * maze.
 *
 * The file's contents must be of the format described above to be considered valid.
 *
 * Parameter:	file_name
 *				The name of the file containing a maze
 * Returns:		bool
 *				True if the maze is imported correctly; false otherwise
 */
bool Pathfinder::importMaze(string file_name)
{

	ifstream filename(file_name.c_str());
	stringstream ss;
	int count = 1;
	if (!filename.fail())
	{
		//cout << file_name << endl;
		//cout << filename << endl;
		//cout << "here" << endl;
		string x;
		filename >> x;
		//cout << x << endl;

		if (x != "1")
		{
			//cout << "fail 1" << endl;
			return false;
		}
		ss << x << " ";
		while (filename >> x)
		{
			count++;
			if (x != "0" && x != "1")
			{
				//cout << "fail 2" << endl;
				return false;
			}
			ss << x << " ";

		}
			//cout << x << endl;

		if (count != 125)
		{
			//cout << "fail 5" << endl;
			return false;
		}
		if (x != "1")
		{
			//cout << "fail 3" << endl;
			return false;
		}
		for (int z = 0; z < 5; z++)
		{
			//cout << "enter" << endl;
			//cout << "starting new maze" << endl;
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 5; x++)
				{
					//cout << x << "\t" << y << "\t" << z << endl;
					ss >> maze[x][y][z];
				}
			}
		}
	}
	else
	{
		return false;
	}
	//print();

	return true;

	//read in a file
	/*string filename;
	cin >> filename;
	ifstream in;
	in.open(filename);

	if (in.is_open())
	{
	}
	else
	{
	}*/


	//save a file
	/*
	 * string save_filename;
	 * cin >> save_filename;
	 * ofstream file_out(save_filename);
	 *
	 * file_out << whatever you want to save in the file << endl;
	 * */

}
//-----------------------------------------------------------------------------------------

//Part 3-----------------------------------------------------------------------------------
/*
 * solveMaze
 *
 * Attempts to solve the current maze and returns a solution if one is found.
 *
 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
 * (or an empty vector if no solution is found). This list cannot contain duplicates, and
 * any two consecutive coordinates in the list can only differ by 1 for only one
 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
 * in the solution. Each string in the solution vector must be of the format "(x, y, z)",
 * where x, y, and z are the integer coordinates of a cell.
 *
 * Understand that most mazes will contain multiple solutions
 *
 * Returns:		vector<string>
 *				A solution to the current maze, or an empty vector if none exists
 */
vector<string> Pathfinder::solveMaze()
{
	vector<string> solution;
	int x = 0;
	int y = 0;
	int z = 0;
	bool found_path;
	bool fixed_maze;

	if (maze[0][0][0] != "1" && maze[4][4][4] != "1")
	{
		//cout << "This is the vector if it is a FAIL 1" << endl;
		//print_vector(solution);
		return solution;
	}
	found_path = find_maze_path(x, y, z);
	//print();
	if (found_path == false)
	{
		//cout << "This is the vector if it is a FAIL 2" << endl;
		fixed_maze = fix_maze(x, y, z, solution);
		//print_vector(solution);
		return solution;
	}
	else
	{
		//cout << "This is the vector before fixing the maze" << endl;
		//print_vector(solution);
		fixed_maze = fix_maze(x, y, z, solution);
		//cout << "This is the vector after fixing the maze" << endl;
		//print_vector(solution);
	}
	//cout << "\n" << "THIS IS AFTER THE FIXING OF MAZE" << "\n" << endl;
  	//print();

	return solution;
}
//-----------------------------------------------------------------------------------------
