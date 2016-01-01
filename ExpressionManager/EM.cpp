/*
 * EM.cpp
 *
 *  Created on: May 19, 2014
 *      Author: aconstan
 */

#include "EM.h"

using namespace std;

//ExpressionManager::ExpressionManager()

//ExpressionManager::~ExpressionManager()


//==================================================================================================

bool ExpressionManager::isNumber(string expression)
 {
	/*

 	stringstream ss(expression);
	int check = 0;
 	ss >> check;

	*/

	//int string to int(string expression)

	istringstream strm;
	strm.str(expression);
	int n = 0;
	strm >> n;

 	if (strm.fail())
 	{
 		 return false;
 	}
 	else
 	{
 		 return true;
 	}
 }

bool ExpressionManager::isOper(string expression)
 {
	stringstream ss(expression);
	string a = "";

 	ss >> a;

 	if (a != "+" && a != "-" && a != "*" && a != "/" && a != "%")
 	{
 	 	 return false;
	}
	else
	{
	 	 return true;
	}
 }

bool ExpressionManager::isOpen(string expression)
 {
	 stringstream ss(expression);
	 string a = expression;

	 ss >> a;

	 if (a != "(" && a != "{" && a != "[")
	 {
		 return false;
	 }
	 else
	 {
		 return true;
	 }
 }

bool ExpressionManager::isClose(string expression)
 {
	 stringstream ss(expression);
	 string a = "";

	 ss >> a;

	 //cout << "close" << endl;

	 if (a != ")" && a != "}" && a != "]")
	 {
		 return false;
	 }
	 else
	 {
		 return true;
	 }
 }

bool ExpressionManager::isValid(string expression)

{
	stringstream ss(expression);
	bool balanced = true;

	string a = "";

	//cout << "isValid" << endl;

	while(balanced == true && !ss.eof())
	{
		ss >> a;

		if (isNumber(a) != true && isOper(a) != true && isOpen(a) != true && isClose(a) != true)
		{
			balanced = false;
		}
		else
		{
			balanced = true;
		}
	}


	if (balanced == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int ExpressionManager::check_precedence(string oper)
{
	string to_compare = "";

	if (oper == "*")
	{
		return 2;
	}
	else if (oper == "/")
	{
		return 2;
	}
	else if (oper == "%")
		{
			return 2;
		}
	else if (oper == "+")
		{
			return 1;
		}
	else if (oper == "/")
		{
			return 1;
		}

	return 0;
}

bool ExpressionManager::check_number(string expression)
{
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] == '.')
		{
			return false;
		}
	}
	return true;
}

bool ExpressionManager::num_oper_ratio(string expression)
{
	int num = 0;
	int oper = 0;
	string a = "";

	stringstream ss(expression);

	while (!ss.eof())
	{
		ss >> a;
		if (isNumber(a) == true)
		{
			num++;
		}
		if (isOper(a) == true)
		{
			oper++;
		}
	}

	if (num > oper)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ExpressionManager::string_to_int(string s)
{
	istringstream strm;
	strm.str(s);
	int n = 0;
	strm >> n;
	return n;
}

string ExpressionManager::int_to_string(int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}

//==================================================================================================

bool ExpressionManager::isBalanced(string expression)
{
	stack<string> b_stack;
	stringstream ss(expression);

	string a = "0";

	while (!ss.eof())
	{
		ss >> a;

		if (a != "(" && a != ")" && a != "[" && a != "]" && a != "{" && a != "}"
				&& isNumber(a) == false && isOper(a) == false)
		{
			return false;
		}

		if (a == "(" || a == ")" || a == "[" || a == "]" || a == "{" || a == "}")
		{
			if (a == "(" || a == "{" || a == "[")
			{
				b_stack.push(a);
			}
			else if (a == "}")
			{
				if (b_stack.top() != "{")
				{
					return false;
				}
				else
				{
					b_stack.pop();
				}
			}
			else if (a == ")")
			{
				if (b_stack.top() != "(")
				{
					return false;
				}
				else
				{
					b_stack.pop();
				}
			}
			else if (a == "]")
			{
				if (b_stack.top() != "[")
				{
					return false;
				}
				else
				{
					b_stack.pop();
				}
			}
		}
	}
	if (b_stack.empty() == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	stack<string> box;

	//bool balanced;

	string a = postfixExpression;
	string b = "";
	//string c = "";
	string pos1 = "";
	string pos2 = "";
	string bottom = "";

	if (isValid(a) == false)
	{
		return "invalid";
	}
	else
	{
		stringstream ss(postfixExpression);
		while (!ss.eof())
		{
			pos1 = "";
			pos2 = "";
			ss >> b;

			if (isNumber(b) == true)
			{
				if (check_number(b) == false)
				{
					return "invalid";
				}
				box.push(b);
			}
			else if (isOper(b) == true)
			{
				if (box.size() < 2)
				{
					return "invalid";
				}
				else
				{
					pos2 = box.top();
					box.pop();
					pos1 = box.top();
					box.pop();
					bottom = "( " + pos1 + " " + b + " " + pos2 + " )";
					box.push(bottom);
				}
			}
		}
	}

	//cout << box.size() << endl;
	if (box.empty() == false)
	{
		bottom = box.top();
		box.pop();
	}

	if (box.empty() == false)
		{
			return "invalid";
		}
		else
		{
			return bottom;
		}

	return "invalid";
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	stack<string> box;

	string a = infixExpression;
	string b = "";
	string pos1 = "";
	string pos2 = "";
	string outside = "";
	string precedence;
	int precedence1 = 0;
	int precedence2 = 0;


	//cout << 1 << endl;

	if (isValid(a) == false)
	{
		return "invalid";
	}
	else if (isBalanced(a) == false)
	{
		return "invalid";
	}
	else if(num_oper_ratio(a) == false)
	{
		return "invalid";
	}
	else
	{
		//cout << 2 << endl;
		stringstream ss(infixExpression);
		while (!ss.eof())
		{
			pos1 = "";
			pos2 = "";
			ss >> b;

			if (isNumber(b) == true)
			{
				//cout << "num" << endl;
				if (check_number(b) == false)
				{
					return "invalid";
				}
				if (outside == "")
				{
					outside = b;
				}
				else
				{
					outside += " " + b;
				}
			}
			else if (isOpen(b) == true)
			{
				//cout << "open" << endl;

				box.push(b);
			}
			else if (isOper(b) == true)
			{
				//cout << "operator" << endl;
				if (outside == "")
				{
					return "invalid";
				}

				if (box.size() == 0)
				{
					box.push(b);
				}
				else if (isOpen(box.top()) == true) //box.top() == "(" || box.top() == "{" || box.top() == "[")
				{
					box.push(b);
				}
				else
				{
					pos1 = box.top();
					pos2 = b;
					precedence1 = check_precedence(pos1);
					precedence2 = check_precedence(pos2);

					if (precedence2 <= precedence1)
					{
						outside += " " + pos1;
						box.pop();
						box.push(b);
					}
					else
					{
						//pos1 = box.top();
						//outside += " " + pos1;
						box.push(b);
					}
				}
			}
			else if (isClose(b) == true)
			{
				//cout << "close" << endl;
				while (isOpen(box.top()) == false) //box.top() != "(" && box.top() != "{" && box.top() != "[")
				{
					pos1 = box.top();
					outside += " " + pos1;
					box.pop();
				}
				box.pop();
			}
		}

		//return outside;

		//cout << "empty" << endl;
		if (box.size() > 0)
		{
			for (int i = box.size(); i > 0; i--)
			{
				pos1 = box.top();
				outside += " " + pos1;
				box.pop();
			}
			return outside;
			//return "invalid";
		}
		else
		{
			return outside;
		}
	}



	//return "invalid";
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
	{
		stack<string> box;
		string a = postfixExpression;
		string b = "";
		string c = "";
		string pos1 = "";
		string pos2 = "";
		string bottom = "";
		int num1 = 0;
		int num2 = 0;
		int answer = 0;

		//cout << postfixExpression << endl;

		if (box.size() == 0)
		{
			stringstream strm(postfixExpression);
			strm >> c;
			if (isClose(c) == true)
			{
				return "invalid";
			}

		}

		if (isValid(a) == false)
		{
			return "invalid";
		}
		else if (isBalanced(a) == false)
		{
			return "invalid";
		}
		else if(num_oper_ratio(a) == false)
		{
			return "invalid";
		}
		else
		{
			//cout << 1 << endl;
			stringstream ss(postfixExpression);
			while (!ss.eof())
			{
				//cout << 2 << endl;
				ss >> b;
				if (isNumber(b) == true)
				{
					//cout << 3 << endl;
					if (check_number(b) == false)
					{
						return "invalid";
					}
					box.push(b);
				}
				else if (isOper(b) == true)
				{
					//cout << 4 << endl;
					if (box.size() < 2)
					{
						return "invalid";
					}
					else
					{
						//cout << 5 << endl;
						pos2 = box.top();
						box.pop();
						pos1 = box.top();
						box.pop();

						num1 = string_to_int(pos1);
						num2 = string_to_int(pos2);

						if (b == "+")
						{
							answer = num1 + num2;
						}
						if (b == "-")
						{
							answer = num1 - num2;
						}
						if (b == "*")
						{
							answer = num1 * num2;
						}
						if (b == "%")
						{
							if (num2 == 0)
							{
								return "invalid";
							}
							answer = num1 % num2;
						}
						if (b == "/")
						{
							if (num2 == 0)
							{
								return "invalid";
							}
							answer = num1 / num2;
						}

						bottom = int_to_string(answer);

						box.push(bottom);
					}
				}
			}
		}


		//cout << box.top() << endl;
		//cout << box.size() << endl;

		if (box.size() == 1)
		{
			//cout << "box size 1" << endl;
			bottom = box.top();
			box.pop();
			return bottom;
		}
		else
		{
			return "invalid";
		}
	}

