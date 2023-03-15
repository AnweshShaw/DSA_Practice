// Left view of a binary tree.
#include <bits/stdc++.h>
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

void leftView(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    int n = q.size();
    while (!q.empty())
    {
        for (int i = 1; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == 1)
                cout << temp->data << " " << endl;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    /*
       1
     /  \
    2    3
    /\   /\
    4 5  6 7
    */
    cout << "The left view of the binary tree is :" << endl;
    leftView(root);
    return 0;
}