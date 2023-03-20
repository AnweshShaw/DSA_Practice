// Zig Zag Traverrsal - It traverses one leel from left to right and next level from right to left and so on.
/*
Algorithm - 1) Use 2 stacks - Current Level and Next Level
            2) variable left to right
            3) if left to right, push leftchild then Rightchild, else push right, then left
*/
#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool lefttoRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (lefttoRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
            if (currLevel.empty())
            {
                lefttoRight = !lefttoRight;
                swap(currLevel, nextLevel);
            }
        }
    }
}

int main()
{
    /*
        12
        / \
       9   15
      / \    \
     5  10
    */
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    zigzagTraversal(root);
    cout << endl;
    return 0;
}
