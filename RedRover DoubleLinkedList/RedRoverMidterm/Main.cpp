//Anthony Constantino CS 235 Spring 2014 Midterm

//READ ME!

/*I decided to remove the players from the program completely after the game was over
 * because it was not specified in the midterm packet and I asked a TA and they said I
 * would not be docked points no matter what I did with the players after the game ended
 * (whether they remain or are removed after the game ends) so I chose to remove them
 */

/*Another thing I wanted to mention is about my program.
 * This program is possibly different from the one expected in such that I did make a double
 * Linked List and it works, but no matter what I tried I could not get it to work in the main
 * function.
 * I could get it to work in classes that I created such as my station (stack, queue, and deque)
 * and several others, that I had created, and then modified the classes so much that they no
 * longer worked anymore with the classes I had created
 *
 * After spending between 15-20 hours trying to get this to work unsuccessfully, leaving me with no
 * working program to even turn in. I decided instead of taking the zero I was going to at least
 * make the program work even it be by other means, resulting in the program we have here.
 * This redRover program works perfectly in the sense that it does everything that was expected from
 * us in the score sheet.
 * Also, with this program I have my double linked list in the same folder so that you can take a
 * look at it as well.
 * I can't ask for anything more than a fair assessment of my work, understanding that I probably
 * will be docked for not being able to incorporate my double Linked List in the program.
 * But I hope that this works better than just handing in a broken project that doesn't even compile
 *
 * Thanks for taking the time to read this and I hope everything works out
 * I am at your mercy
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>


#include "Player.h"
#include "DLinkedList3.h"

using namespace std;

//template <class T>

void print_roster(vector<Player> list)
{
	int count = 0;
	cout << "\n";
	for (int i = 0; i < list.size(); i++)
	{
		count++;
		cout << list[i].getName() << endl;
	}
}

void print_teams(vector<Player> a, vector<Player> b)
{
	int count = 0;
	cout << "\n" << "Team A:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		count++;
		cout << "\t" << a[i].getName() << " " << a[i].getStrength() << " " << a[i].getSpeed() << endl;
	}
	cout << "\n" << "Team B:" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		count++;
		cout << "\t" << b[i].getName() << " " << b[i].getStrength() << " " << b[i].getSpeed() << endl;
	}
}

void print_A(vector<Player> a)
{
	int count = 0;
	cout << "\n" << "Team A:" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		count++;
		cout << "\t" << a[i].getName() << " " << a[i].getStrength() << " " << a[i].getSpeed() << endl;
	}
}

void print_B(vector<Player> b)
{
	int count = 0;
	cout << "\n" << "Team B:" << endl;
	for (int i = 0; i < b.size(); i++)
	{
		count++;
		cout << "\t" << b[i].getName() << " " << b[i].getStrength() << " " << b[i].getSpeed() << endl;
	}
}

int search_roster(vector<Player> list, string find)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (find == list[i].getName())
		{
			return i;
		}
	}
	return -1;
}

void remove(vector<Player>& list, int to_remove)
{
	for (int i = to_remove + 1; i < list.size(); i++)
	{
		//print_roster(list);
		//cout << i << endl;
		list[i - 1]  = list[i];
	}
	list.pop_back();
}

void add_player(vector<Player> from, vector<Player>& to, int pos1, int pos2)
{
	int count = to.size() - 1;
	Player p = to[to.size() -1];
	to.push_back(p);
	if (pos1 == count)
	{
		to[to.size() - 1] = from[pos1];
	}
	else
	{
		for (int i = 0; i < (count - pos2); i++)
		{
			to[count] = to[count - 1];
		}
		to[count] = from[pos1];
	}
	//print_roster(to);

	//print_roster(to);
}

void shuffle(vector<Player>& roster)
{
	int pos = 0;
	vector<Player> n_list;
	while (roster.size() != 0)
	{
		pos = rand() % roster.size();
		n_list.push_back(roster[pos]);
		remove(roster, pos);
	}
	while (n_list.size() != 0)
	{
		pos = rand() % n_list.size();
		roster.push_back(n_list[pos]);
		remove(n_list, pos);
	}
}



int main()
{
    cout << "\t\t\t\t" "Welcome to Red Rover" << endl;

    srand(time(0));
    string initial_input = "";
	bool quit = true;
	vector<Player> roster;
    //LinkedList<Player> LL;

	vector<Player> team_a;
	vector<Player> team_b;

	while (quit)
    {
        cout << "\n" "What would you like to do?" << endl;
		cout << "\n" "Type \"1\" to create a roster" << endl;
		cout << "Type \"2\" to view the current roster" << endl;
		cout << "Type \"3\" to shuffle the current roster" << endl;
		cout << "Type \"4\" to create teams" << endl;
		cout << "Type \"5\" to view the current teams" << endl;
		cout << "Type \"6\" to being \"user play\"" << endl;
		cout << "Type \"7\" to  being \"auto play\"" << endl;
		cout << "Type \"8\" to quit the program" << endl;

		cin >> initial_input;
		cin.ignore(1000, '\n');
		if (initial_input == "1")
		{
			//import files into the roster
            cout << "\n" "Please enter the name of the file you wish to load to the roster" << endl;
            string filename;
            cin >> filename;
            ifstream in_file(filename.c_str());
            if (in_file.is_open())
            {
                string name;
                int strength;
                int speed;
                //Player a("jim", 15, 12);
                //cout << a.getName() << endl; cout << a.getStrength() << endl; cout << a.getSpeed() << endl;
                while(in_file >> name >> strength >> speed)
                {
                    //cout << name << endl; cout << strength << endl; cout << speed << endl;
                    Player guy(name, strength, speed);
                    roster.push_back(guy);
                }
            }

            in_file.close();
            /*for (int i = 0; i < roster.size(); i++)
            {
            	LL.insertTail(roster[i]);
            }*/
		}
		else if (initial_input == "2")
		{
			if (roster.size() == 0)
			{
				cout << "\n" "Roster Empty" << endl;
			}
			//print the roster
			print_roster(roster);
		}
		else if (initial_input == "3")
		{
			//shuffle the roster
			if (roster.size() == 0)
			{
				cout << "\n" "Roster Empty" << endl;
			}
			shuffle(roster);
			
		}
		else if (initial_input == "4")
		{
			//create teams
			if (roster.size() < 4)
			{
				cout << "\n" "Cannot play red rover with less than 4 players" << endl;
			}
			else
			{
				int counter = roster.size();
				//cout << "counter 1: " << counter << endl;
				if (counter % 2 == 1)
				{
					counter -= 1;
				}
				//cout << "counter 2: " << counter << endl;
				for (int i = 0; i < counter; i++)
				{
					if ((i % 2) == 0)
					{
						team_a.push_back(roster[i]);
						//remove(roster, i);
					}
					if ((i % 2) == 1)
					{
						team_b.push_back(roster[i]);
						//remove(roster, i);
					}
				}
				for (int i = 0; i < counter; i++)
				{
					remove(roster, 0);
				}
			}

		}
		else if (initial_input == "5")
		{
			//print the teams
			print_teams(team_a, team_b);
		}
		else if (initial_input == "6")
		{
			//user play
			cout << "\n" "You have chosen user play" << endl;

			while (team_a.size() > 1 && team_b.size() > 1)
			{
				//team A attack
				string pick1;
				int pos1;
				string pick2;
				int pos2;
				int power1;
				int power2;
				int round = 1;

				cout << "\n" "Round " << round << endl;

				cout << "\n" "It is team A's turn" << endl;

				cout << "\n" "Please choose someone from team A to attack" << endl;
				print_A(team_a);
				cin >> pick1;
				pos1 = search_roster(team_a, pick1);
				while (pos1 == -1)
				{
					cin.ignore(1000, '\n');
					cout << "\n" "Invalid input please try again" << endl;
					cin >> pick1;
					pos1 = search_roster(team_a, pick1);
				}
				power1 = team_a[pos1].getStrength() + team_a[pos1].getSpeed();
				//cout << "\nPower 1: " << power1 << endl;

				//team B defense
				cout << "\n" "now choose a person from team B to attack that spot" << endl;
				print_B(team_b);
				cin >> pick2;
				pos2 = search_roster(team_b, pick2);
				while (pos2 == -1)
				{
					cin.ignore(1000, '\n');
					cout << "\n" "Invalid input please try again" << endl;
					cin >> pick2;
					pos2 = search_roster(team_b, pick2);
				}
				if (pos2 == (team_b.size()- 1))
				{
					pos2 -= 1;
				}
				power2 = team_b[pos2].getStrength() + team_b[pos2 + 1].getStrength();
				//cout << "\nPower 2: " << power2 << endl;

				//result 1
				if (power1 > power2)
				{
					cout << "\nTeam A took a Team B player" << endl;
					add_player(team_b, team_a, pos2, (pos1 + 1));
					remove(team_b, pos2);
				}
				else
				{
					cout << "\nTeam B took a Team A player" << endl;
					add_player(team_a, team_b, pos1, (pos2 +1));
					remove(team_a, pos1);
				}

				print_A(team_a);
				print_B(team_b);

				if (team_a.size() > 1 && team_b.size() > 1)
				{
					power1 = 0;
					power2 = 0;
					pick1 = "";
					pick2 = "";

					cout << "\n" "It is team B's turn" << endl;
					//team B attack
					cout << "\n" "Please choose someone from team B to attack" << endl;
					print_B(team_b);
					cin >> pick2;
					pos2 = search_roster(team_b, pick2);
					while (pos2 == -1)
					{
						cin.ignore(1000, '\n');
						cout << "\n" "Invalid input please try again" << endl;
						cin >> pick2;
						pos2 = search_roster(team_b, pick2);
					}
					power2 = team_b[pos2].getStrength() + team_b[pos2].getSpeed();
					//cout << "\nPower 2: " << power2 << endl;

					//team A defense
					cout << "\n" "now choose a person from team A to attack that spot" << endl;
					print_A(team_a);
					cin >> pick1;
					pos1 = search_roster(team_a, pick1);
					while (pos1 == -1)
					{
						cin.ignore(1000, '\n');
						cout << "\n" "Invalid input please try again" << endl;
						cin >> pick1;
						pos1 = search_roster(team_a, pick1);
					}

					if (pos1 == (team_a.size()- 1))
					{
						pos1 -= 1;
					}
					power1 = team_a[pos1].getStrength() + team_a[pos1 + 1].getStrength();
					//cout << "\nPower 1: " << power1 << endl;

					//result 2
					if (power2 > power1)
					{
						cout << "\nTeam B took a Team A player" << endl;
						add_player(team_a, team_b, pos1, (pos2 + 1));
						remove(team_a, pos1);
					}
					else
					{
						cout << "\nTeam A took a Team B player" << endl;
						add_player(team_b, team_a, pos2, (pos1 +1));
						remove(team_b, pos2);
					}

					print_A(team_a);
					print_B(team_b);

					round++;
				}
			}

			if (team_b.size() == 1)
			{
				cout << "\n" "Team A Wins!" << endl;
			}
			if (team_a.size() == 1)
			{
				cout << "\n" "Team B Wins!" << endl;
			}

			//clearing teams and removing the players
			/*I decided to remove the players from the program completely after the game was over
			 * because it was not specified in the midterm packet and I asked a TA and they said I
			 * would not be docked points no matter what I did with the players after the game ended
			 * (whether they remain or are removed after the game ends) so I chose to remove them
			 */
			while (team_a.size() != 0)
			{
				remove(team_a, 0);
			}
			while (team_b.size() != 0)
			{
				remove(team_b, 0);
			}

		}
		else if (initial_input == "7")
		{
			//Auto play
			cout << "\n" "You have chosen auto play" << endl;

			string pick1;
			int pos1;
			string pick2;
			int pos2;
			int power1;
			int power2;
			int round = 1;



			while (team_a.size() > 1 && team_b.size() > 1)
			{
				cout << "\n" "Round " << round << endl;

				cout << "\n" "It is team A's turn" << endl;

				//team A attack
				pos1 = rand() % team_a.size();
				power1 = team_a[pos1].getStrength() + team_a[pos1].getSpeed();

				//team B defense


				pos2 = rand() % team_b.size();
				if (pos2 == (team_b.size()- 1))
				{
					pos2 -= 1;
				}
				power2 = team_b[pos2].getStrength() + team_b[pos2 + 1].getStrength();

				//result 1

				if (power1 > power2)
				{
					cout << "\nTeam A took a Team B player" << endl;
					add_player(team_b, team_a, pos2, (pos1 + 1));
					remove(team_b, pos2);
				}
				else
				{
					cout << "\nTeam B took a Team A player" << endl;
					add_player(team_a, team_b, pos1, (pos2 +1));
					remove(team_a, pos1);
				}

				print_A(team_a);
				print_B(team_b);

				cout << "\n" "It is team B's turn" << endl;

				if (team_a.size() > 1 && team_b.size() > 1)
				{
					//team B attack

					pos2 = rand() % team_b.size();
					power2 = team_b[pos2].getStrength() + team_b[pos2].getSpeed();

					//team A defense

					pos1 = rand() % team_a.size();
					if (pos1 == (team_a.size()- 1))
					{
						pos1 -= 1;
					}
					power1 = team_a[pos1].getStrength() + team_a[pos1 + 1].getStrength();

					//result 2
					if (power2 > power1)
					{
						cout << "\nTeam B took a Team A player" << endl;
						add_player(team_a, team_b, pos1, (pos2 + 1));
						remove(team_a, pos1);
					}
					else
					{
						cout << "\nTeam A took a Team B player" << endl;
						add_player(team_b, team_a, pos2, (pos1 +1));
						remove(team_b, pos2);
					}

					print_A(team_a);
					print_B(team_b);

					round++;
				}

			}
			if (team_b.size() == 1)
			{
				cout << "\n" "Team A Wins!" << endl;
			}
			if (team_a.size() == 1)
			{
				cout << "\n" "Team B Wins!" << endl;
			}

			//clearing all players
			while (team_a.size() != 0)
			{
				remove(team_a, 0);
			}
			while (team_b.size() != 0)
			{
				remove(team_b, 0);
			}

		}
		else if (initial_input == "8")
		{
			quit = false;
		}
		else if (initial_input == "save")
        {
           /* string filename;
			cin >> filename;

			ofstream file_out(filename.c_str());

            for (int i = 0; i < roster.size(); i++)
			{
				file_out << roster.getName() << endl;
				file_out << roster.getStrength() << endl;
				file_out << roster.getSpeed()) << endl;
			}*/
        }
		else
		{
			cout << "\n" "Invalid input please try again" << endl;
		}
    }

    return 0;
}

//create the file g++ -o redRover *.h *.cpp
