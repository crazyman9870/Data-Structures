#pragma once
#include "Factory.h"
#include "ExpressionManagerInterface.h"

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <locale>
#include <cmath>
#include <stdlib.h>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
public:
	ExpressionManager()
	{

	};
	~ExpressionManager()
	{

	};

//===================================================================================================

bool isNumber(string expression);

bool isOper(string expression);

bool isOpen(string expression);

bool isClose(string expression);

bool isValid(string expression);

int check_precedence(string oper);

bool check_number(string expression);

bool num_oper_ratio(string expression);

int string_to_int(string s);

string int_to_string(int n);

//===================================================================================================

bool isBalanced(string expression);

string postfixToInfix(string postfixExpression);

string infixToPostfix(string infixExpression);

string postfixEvaluate(string postfixExpression);


};



