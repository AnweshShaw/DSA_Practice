// Flatten Binary Tree to Linked List
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

void flatten(Node *root)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    Node *temp = root->right;
    root->right = root->left;
    root->left = NULL;
    Node *t = root->right;
    while (t->right != NULL)
    {
        t = t->right;
    }
    t = t->right;
    t->right = temp;
}

void inorderPrint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
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
    flatten(root);
    inorderPrint(root);
    cout << endl;
    return 0;
}