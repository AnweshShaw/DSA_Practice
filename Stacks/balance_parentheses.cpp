// C++ program to check if the expression is balanced or not.

#include <iostream>
#include <stack>
using namespace std;

bool isBalancedExp(string exp)
{
    stack<char> st;
    char x;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            st.push(exp[i]);
            continue;
        }
        if (st.empty())
            return false;
        switch (exp[i])
        {
        case ')':
            x = st.top();
            st.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case '}':
            x = st.top();
            st.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        case ']':
            x = st.top();
            st.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (st.empty());
}
int main()
{
    std::string s; // Method of taking multi-word input(String) in C++
    std::getline(std::cin, s);
    if (isBalancedExp(s))
        cout << "It is a balanced expression";
    else
        cout << "It is not a balanced expression";
}