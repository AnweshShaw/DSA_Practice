// This program checks wheteher a given Binary Tree is BST or not
// Left Node < Root < Right Node (Condition for valid BST)
#include <iostream>
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

bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return (leftValid and rightValid);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    if (isBST(root, NULL, NULL))
    {
        cout << "Valid BST" << endl;
    }
    else
    {
        cout << "Invalid BST" << endl;
    }
    return 0;
}