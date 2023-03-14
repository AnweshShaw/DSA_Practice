// Balanced Height Tree is a tree in which for each node, the differnce between the heights
// of left subtree and right subtree <=1
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return false;
    }
    if (isBalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
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
    if (isBalanced(root))
        cout << "Balanced Tree" << endl;
    else
        cout << "Unbalanced Tree" << endl;

    // Unbalanced Height Tree
    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    if (isBalanced(root2))
        cout << "Balanced Tree" << endl;
    else
        cout << "Unbalanced Tree" << endl;
    return 0;
}