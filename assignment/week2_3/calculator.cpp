/* Calculator */

// Infix to Postfix reference: https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
// Stack reference: http://www.cplusplus.com/reference/stack/stack/
// Precedence and associativity reference: https://docs.microsoft.com/en-us/cpp/cpp/cpp-built-in-operators-precedence-and-associativity?view=vs-2019
// Stack reference: https://gist.github.com/mycodeschool/7867739
// Postfix Evaluation reference: https://gist.github.com/mycodeschool/7702441
// Lexer reference: https://blog.csdn.net/weixin_36191602/article/details/82824666
// Enumerator and FSM reference: https://www.programmingnotes.org/?p=4737

#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;

/* 
This enumerator that has the postfix transition states which would be used later in the Finite State Machine.
*/
enum postTrans
{
	Reject,
	Integer,
	Decipoint,
	Negative,
	Operator,
	Unknown,
	Space,
	Letter
};

/* 
This Finite State Machine specifies the correct and incorrect combination of tokens to be used in the calculation later.
For instance, a decipoint token is not allowed to be next to another one, in that sense, an operand 12.392.20 is rejected.
*/
int stateTable[][7] = { {0, Integer, Decipoint, Negative, Operator, Unknown,  Space},
				{ Integer, Integer, Decipoint,   Reject,   Reject,  Reject,  Reject},
				{Decipoint,Decipoint,  Reject,   Reject,   Reject,  Reject,	 Reject},
				{Negative, Integer, Decipoint,   Reject,   Reject,  Reject,  Reject},
				{Operator,  Reject,    Reject,   Reject,   Reject,  Reject,  Reject},
				{ Unknown,  Reject,    Reject,   Reject,   Reject,  Reject,	 Reject},
				{   Space,  Reject,    Reject,   Reject,   Reject,  Reject,  Reject} };

void displayDir(); // User instructions
string findUnary(string infix); // Convert unary operators in infix strings to char
string inToPost(string infix); // Convert infix to postfix notation
bool isOperator(char c); // Determine whether the char is an operator
int orderOfOprt(char token); // Determine the precedence of operators
vector<string> Lexer(string postfix); // Tokenize multiple digit, negative and decimal
int get_postTrans_col(char& currentChar); // Specify the current char in the postTrans enumerator for the FSM
double EvaPostfix(const vector<string>& postfix); // Evaluate postfix notation
double calculator(char token, double op1, double op2); // Calculate the tokens 

int main()
{
	string infix = "";
	double answer = 0;
	vector<string> tokens;
	displayDir();
	cout << "========Calculator========\n";
	while (true)
	{
		getline(cin, infix);
		infix = findUnary(infix);
		string postfix = inToPost(infix);
		tokens = Lexer(postfix);
		answer = EvaPostfix(tokens);
		cout << answer << endl;
	}
	return 0;
}


void displayDir()
{
	cout << "Calculator Index:\n";
	cout << "+ 	-> 	addtion\n";
	cout << "- 	-> 	subtraction\n";
	cout << "* 	-> 	multiplication\n";
	cout << "/ 	-> 	division\n";
	cout << "% 	-> 	modulus\n";
	cout << "^ 	-> 	power\n";
	cout << "! 	-> 	positive integer factorial\n";
	cout << "sqrt 	-> 	square root\n";
	// This calculator uses radian system. 
	cout << "sin 	-> 	sine(radian)\n";
	cout << "cos 	-> 	cosine(radian)\n";
	cout << "tan 	-> 	tangent(radian)\n";
	cout << "- 	-> 	negative number*\n";
	cout << "pi 	-> 	pi\n";
	// This calculator exits when enter is pressed.
	cout <<"**DON'T PRESS ENTER**\n"; 
}

string findUnary(string infix)
{
	size_t indexs = 0;
	while (true)
	{
		indexs = infix.find("sqrt", indexs);
		if (indexs == std::string::npos) break;
		infix.replace(indexs, 4, "$   ");
		indexs += 4;
	}
	size_t indexsin = 0;
	while (true)
	{
		indexsin = infix.find("sin", indexsin);
		if (indexsin == std::string::npos) break;
		infix.replace(indexsin, 3, "@  ");
		indexsin += 3;
	}
	size_t indexcos = 0;
	while (true)
	{
		indexcos = infix.find("cos", indexcos);
		if (indexcos == std::string::npos) break;
		infix.replace(indexcos, 3, "#  ");
		indexs += 3;
	}
	size_t indextan = 0;
	while (true)
	{
		indextan = infix.find("tan", indextan);
		if (indextan == std::string::npos) break;
		infix.replace(indextan, 3, "`  ");
		indextan += 3;
	}
	// This calculator specifies pi to be 3.1415.
	size_t indexpi = 0;
	while (true)
	{
		indexpi = infix.find("pi", indexpi);
		if (indexpi == std::string::npos) break;
		infix.replace(indexpi, 6, "3.1415");
		indexpi += 6;
	}
	return infix;
}


string inToPost(string infix)
{
	stack<char> stack; 
	int len = infix.length();
	string postfix = ""; 
	for (unsigned i = 0; i < len; i++)
	{
		//if scanned is blank space or comma, continue
		if ((infix[i] == ' ') || (infix[i] == ','))
		{
			continue;
		}
		else if (((infix[i] == '-') && (i == 0)) || ((infix[i] == '-') && ((i > 0) && (isOperator(infix[i - 1])) || (infix[i-1] == '(') )))
		{
			postfix += '~';
		}
		// if scanned is digit, add it to output
		else if (isdigit(infix[i]) || (infix[i] == '.'))
		{
			postfix += infix[i];
		}
		// if scanned is operator, add a blank space in the output and output the first element in the stack
		else if (isOperator(infix[i]))
		{
			postfix += " ";
			while ((!stack.empty()) && (orderOfOprt(stack.top()) >= orderOfOprt(infix[i])))
			{
				postfix += stack.top();
				stack.pop();
			}
			stack.push(infix[i]);
		}
		// if scanned is'(', push into the stack
		else if (infix[i] == '(')
		{
			stack.push('(');
		}

		// if scanned is ')', check for '(' and add the first element of the stack to the output
		else if (infix[i] == ')')
		{
			while ((!stack.empty()) && (stack.top() != '('))
			{
				char c = stack.top();
				stack.pop();
				postfix += c;
			}
			if (stack.top() == '(')
			{
				char c = stack.top();
				stack.pop();
			}
			// This output indicates that no '(' is found.
			else
			{
				cout << "\nERROR:parentheses mismatch #1\n";
				exit(1);
			}
		}
		// This shouldn't be the case if input is correct.
		else
		{
			cout << "\nERROR:invalid input #1\n";
			exit(1);
		}

	}

	// Clear out the stack
	while (!stack.empty())
	{
		char c = stack.top();
		stack.pop();
		postfix += c;

	}
	return postfix;
}

vector<string> Lexer(string postfix)
{
	vector<string> tokens;
	char currentChar = ' ';
	int col = Reject;
	int currentState = Reject;
	string currentToken = "";

	for (unsigned x = 0; x < postfix.length();)
	{
		currentChar = postfix[x];
		col = get_postTrans_col(currentChar);
		// This checks for multiple decimal points in a token.
		if ((currentState == Decipoint) && (col == Decipoint))
		{
			cerr << "\nERROR:invalid input #2\n";
			exit(1);
		}
		currentState = stateTable[currentState][col];
		// This checks if the previous token is successfully parsed. 
		if (currentState == Reject)
		{
			if (currentToken != " ")
			{
				tokens.push_back(currentToken);
			}
			currentToken = "";
		}
		else
		{
			currentToken += currentChar;
			++x;
		}

	}
	// This ensures every token is saved.
	if (currentToken != " ")
	{
		tokens.push_back(currentToken);
	}
	return tokens;
}

int get_postTrans_col(char& currentChar)
{
	if (isspace(currentChar))
	{
		return Space;
	}
	else if (isdigit(currentChar))
	{
		return Integer;
	}
	else if (currentChar == '.')
	{
		return Decipoint;
	}
	else if (currentChar == '~')
	{
		currentChar = '-';
		return Negative;
	}
	else if (isOperator(currentChar))
	{
		return Operator;
	}
	return Unknown;
}

double EvaPostfix(const vector<string>& postfix)
{
	double op1 = 0;
	double op2 = 0;
	double answer = 0;
	stack<double> doubleStack;
	for (unsigned j = 0; j < postfix.size(); ++j)
	{
		// Push digit into doubleStack
		if ((isdigit(postfix[j][0])) || (postfix[j][0] == '.'))
		{
			doubleStack.push(atof(postfix[j].c_str()));
		}
		// Push negative numbers into doubleStack
		else if ((postfix[j].length() > 1) && ((postfix[j][0] == '-') &&
			(isdigit(postfix[j][1]) || (postfix[j][1] == '.'))))
		{
			doubleStack.push(atof(postfix[j].c_str()));
		}
		else if (isOperator(postfix[j][0]) && (!doubleStack.empty()))
		{
			char token = tolower(postfix[j][0]);
			// Special operator calculations with only one operand involved
			if (token == '$' || token == '@' || token == '&' || token == '`' || token == '!')
			{
				op2 = 0;
				op1 = doubleStack.top();
				doubleStack.pop();
				answer = calculator(token, op1, op2);
				doubleStack.push(answer);
			}
			// Operator calculations
			else if (doubleStack.size() > 1)
			{
				op2 = doubleStack.top();
				doubleStack.pop();
				op1 = doubleStack.top();
				doubleStack.pop();
				answer = calculator(token, op1, op2);
				doubleStack.push(answer);
			}
		}
		else
		{
			cout << "\nERROR:invalid input #3\n";
			exit(1);
		}
	}
	// Return the answer of the evaluation
	if (!doubleStack.empty())
	{
		answer = doubleStack.top();
	}
	return answer;
}

double calculator(char token, double op1, double op2)
{
	double ans = 0;
	switch (tolower(token))
	{	
		case '+':
			ans = op1 + op2;
			break;
		case '-':
			ans = op1 - op2;
			break;
		case '*':
			ans = op1 * op2;
			break;
		case '/':
			ans = op1 / op2;
			break;
		case '%':
			ans = ((int)op1 % (int)op2) + modf(op1, &op2);
			break;
		case '^':
			ans = pow(op1, op2);
			break;
		case '$':
			ans = sqrt(op1);
			break;
		case '@':
			ans = sin(op1);
			break;
		case '&':
			ans = cos(op1);
			break;
		case '`':
			ans = tan(op1);
			break;
		
		case '!':
			// This calculator only allows factorial calculation for positive integers.
			int res;
			res = op1 / 1;
			if (op1 <= 0 || res * 1 != op1)
			{
				cerr << "\nERROR:invalid input:not positive integer #4\n";
				exit(1);
			}
			else
			{
				ans = 1;
				for (int i = 1; i <= op1; i++)
				{
					ans = ans * i;
				}
			}
			break;
		default:
			ans = 0;
			break;
	}
	return ans;
}

bool isOperator(char c)
{
	switch (tolower(c))
	{
	case '+': case '-': case '*': case '/':
	case '%': case '^': case '$': case '@':
	case '#': case '`': case '!': 
		return true;
		break;
	default:
		return false;
		break;
	}
}

int orderOfOprt(char token)
{
	if(token == '@' || token == '&' || token == '`')
		return 5;
	else if (token == '!')
		return 4;
	else if (token == '^' || token == '$')
		return 3;
	else if (token == '*' || token == '/')
		return 2;
	else if (token == '+' || token == '-')
		return 1;
	else
		return -1;
}

