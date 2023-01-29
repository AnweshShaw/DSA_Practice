// C++ program to evaluate a postfix expression

#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int postfixevaluation(string s)
{
    stack<int> st;
    // In prefix expression, string is traversed first to last character
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0'); // Push as an integer not as ASCII character(Converts character to integer)
        }
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    std::string s; // Method of taking multi-word input(String) in C++
    std::getline(std::cin, s);
    cout << "Answer = " << postfixevaluation(s) << endl;
    return 0;
}