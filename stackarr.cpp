#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int top, n = 100;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow";
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.Top() << endl;
    st.pop();
}
