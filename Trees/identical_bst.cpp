// Check whether both BST's are equal or not.
/*
Algorithm - 1) If both empty, then return true
            2) If both non-empty,
            a) Check that data at the nodes is equal
            b) Check if left subtrees are same
            c) Check if right subtrees are same
            3) if abc are true, return true, else return false
*/
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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->right);
        bool cond3 = isIdentical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    /*
        2
       / \
      1   3
    */
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    /*
        6
       / \
      4   8
    */

    Node *root2 = new Node(6);
    root2->left = new Node(4);
    root2->right = new Node(8);

    if (isIdentical(root, root2))
    {
        cout << "BST's are identical" << endl;
    }
    else
    {
        cout << "BST's are not identical" << endl;
    }
    return 0;
}