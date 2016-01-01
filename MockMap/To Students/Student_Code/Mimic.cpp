/*
 * Mimic.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: aconstan
 */

#include "Mimic.h"

using namespace std;

Mimic::Mimic()
{

}

Mimic::~Mimic()
{

}

//Part 1--------------------------------------------------------------
/**
 * createMap
 *
 * Creates a prefix-suffix map based on the input text.
 *
 * Go through the input text and examine each group of 3 words. Refer
 * to the first two words as the "prefix" and the third word as the
 * "suffix". Create a map that associates each prefix with each suffix.
 *  If you encounter a prefix that has been read already, add the new
 *  suffix to the list of suffixes already associated with that prefix;
 *  in this manner, each prefix can be associated with multiple
 *  suffixes and even multiple copies of the same suffix. Note that
 *  the input texts will only contain words separated by spaces.  Also
 *  note that the last two word prefix in the text should be associated
 *  with the suffix "THE_END".
 *
 * @param input
 * 		the sample text to be mimicked
 */
void Mimic::createMap(string input)
{
	break_string(input);

	/*for (int i = 0; i < map.size(); i++)
	{
		map[i].clearSlist();
	}*/

	//clear_vector(prefix);
	//clear_vector(temp);
	//cout << "\n" "Prefix Vector" "\n" << endl;
	//print_vec(prefix);
	//cout << "\n" "Temp Vector" "\n" << endl;
	//print_vec(temp);
	//clear_vector(prefix);
	//clear_vector(temp);

	//cout << "Sentence\t" << input << endl;
	for (int i = 0; i < temp.size(); i++)
	{


		if (i+2 == temp.size())
		{
			pre1 = temp[i];
			pre2 = temp[i+1];
			suff = "THE_END";

			prefix.push_back(pre1 + " " + pre2);

			int found = searchMap(map, prefix[i]);
			//cout << "Iteration " << i << "\tFOUND = " << found << endl;

			//print_vec(prefix);
			//print_vec(suffix);
			if (found == -1)
			{

			Pair a(prefix[i], suff);

			map.push_back(a);

			//cout << "Prefix " << map[i].getPrefix() << endl;
			//cout << "Suffix " << map[i].getSuffix() << endl;

			}
			else
			{
				//cout << "\"" << suff << "\"" << " was added to " << map[found].getPrefix() << endl;
				map[found].addSlist(suff);
			}

			//cout << "\n" "Prefix Vector2" "\n" << endl;
			//print_vec(prefix);
			//cout << "\n" "Temp Vector2" "\n" << endl;
			//print_vec(temp);
			//cout << "\n" "Map Prefixes2" "\n" <<endl;
			//print_map(map);

			clear_vector(prefix);
			clear_vector(temp);

			return;
		}
		else
		{
			pre1 = temp[i];
			pre2 = temp[i+1];
			suff = temp[i+2];

			prefix.push_back(pre1 + " " + pre2);

			int found = searchMap(map, prefix[i]);
			//cout << "Iteration " << i << "\tFOUND = " << found << endl;

			//print_vec(prefix);
			//print_vec(suffix);
			if (found == -1)
			{

				Pair a(prefix[i], suff);


				map.push_back(a);

				//cout << "Prefix " << map[i].getPrefix() << endl;
				//cout << "Suffix " << map[i].getSuffix() << endl;
			}
			else
			{
				//cout << "\"" << suff << "\"" << " was added to " << map[found].getPrefix() << endl;
				map[found].addSlist(suff);
			}
		}

		/*pre1 = pre2;
		pre2 = suff;
		if (i+3 == temp.size())
		{
			suff = "THE_END";
		}
		else
		{
		suff = temp[i+3];
		}*/
	}


}

/**
 * getSuffixList
 *
 * Returns the list of suffixes associated with the given prefix.
 * Returns an empty vector if the given prefix is not in the map or no
 * map has been created yet.
 *
 * @param prefix
 * 		the prefix to be found
 * @return a list of suffixes associated with the given prefix if the
 * 		prefix is found; an empty vector otherwise
 */
vector<string> Mimic::getSuffixList(string prefix)
{
	int pos = searchMap(map, prefix);
	if (pos == -1)
	{
		return empty;
	}
	else
	{
		//cout << "POS = " << pos << endl;
		return map[pos].getSlist();
	}



}

//Part 2--------------------------------------------------------------
/**
 * generateText
 *
 * Generates random text using the map created by the createMap method.
 *
 * To generate the new text, start with the first prefix that was read
 * and randomly select one of the suffixes associated with that prefix.
 * The next prefix is the second word from the previous prefix and the
 * selected suffix. Continue selecting random suffixes and building the
 * next prefix until the suffix "THE_END" is selected. The token
 * "THE_END" should not be returned as part of your generated text.
 *
 * @return random text generated using the map created with the sample
 * 		text; an empty string if no map has been created yet
 */
string Mimic::generateText()
{
	string space = " ";
	string text = map[0].getPrefix() + space + map[0].random();
	string final = text;
	string add = "";
	string end = "END";
	int pos = 0;

	while (end == "END")
	{
		text = bs2(final);
		pos = searchMap(map, text);

		add = map[pos].random();
		if (add == "THE_END")
		{
			end = "done";
			break;
		}
		else
		{
			final += space + add;
		}
	}


	return final;
}

//=====================================================================

int Mimic::searchMap(vector<Pair> list, string find)
{
	for (int i; i <list.size(); i++)
	{
		if (list[i].getPrefix() == find)
		{
			return i;
		}
	}
	return -1;
}

bool Mimic::search(vector<string> list, string find)
{
	for (int i; i <list.size(); i++)
	{
		if (list[i] == find)
		{
			return true;
		}
	}
	return false;
}

void Mimic::print_vec(vector<string> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "pos " << i << "\t" << list[i] << endl;
	}
}

void Mimic::print_map(vector<Pair> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "pos " << i << "\tPrefix\t" << list[i].getPrefix() << endl;
	}
}

void Mimic::break_string(string input)
{
	string a;
	stringstream ss;
	ss << input;
	while (ss >> a)
	{
		//cout << "a = " << a << endl;
		temp.push_back(a);
	}
	//print_vec(temp);

}

string Mimic::bs2(string input)
{
	vector<string> t;
	string a;
	stringstream ss;
	ss << input;
	while (ss >> a)
	{
		t.push_back(a);
	}
	string str1 = t[t.size() - 1];
	string str2 = t[t.size() - 2];
	string final = str2 + " " + str1;
	return final;
}

void Mimic::clear_vector(vector<string> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		list.pop_back();
	}
}
