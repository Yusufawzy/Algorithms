#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

bool func(string &a) {
	string::iterator it = a.begin();
	stack<char> s;
	while (it != a.end()) {
		if (*it == '[' || *it == '(' || *it == '{'){
			s.push(*it);
		}
		else if (*it == '/' && it + 1 != a.end()) {
			
			 if (*(it+1)=='*') {
				s.push(*it);it++;
			}
			
		}
		else if (*it == ']' || *it == ')' || *it == '}') {
			if (s.empty())return false;
			else {
			char c = s.top();
			s.pop();
			if ((c == '[' && *it != ']') || (c == '(' && *it != ')') || (c == '{' && *it != '}')) {
				return false;
			} 
			
			}
			

		}
		else if (*it == '*' && it + 1 != a.end()) {
		
		 if (*(it+1)=='/' &&!s.empty()) {

				char c = s.top();
				s.pop();
				if (c != *(it+1))return false;
				it++;
			}
		}
		it++;


	}
	
	return (s.empty()?true:false);
}
int main()
{	
	string a("     t[5] + u / (v * (w + y))");	cout << (func(a) ? "Valid":"Invalid" )<<'\n';

	a = "[()]";	cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "({/*)}]]]]]]}*/})";	cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "({))";	cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "[{/*******/}]";cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "({/*[][[]]]]]})";	cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "*"; cout << (func(a) ? "Valid" : "Invalid") << '\n';

	a = "/*/";cout << (func(a) ? "Valid" : "Invalid") << '\n';

	system("pause");
    return 0;
}

