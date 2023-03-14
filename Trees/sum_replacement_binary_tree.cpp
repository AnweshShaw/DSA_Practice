// This program finds the replacement of c++ in binary tree.
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

void sumReplacement(Node *root)
{
    if (root == NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
    cout << "The original tree is =" << endl;
    preorder(root);
    cout << endl;
    sumReplacement(root);
    cout << "The new sum replacement tree is =" << endl;
    preorder(root);
    return 0;
}