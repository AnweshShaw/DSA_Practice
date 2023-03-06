#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteinBST(Node *root, int key)
{
    if (key < root->data)
        root->left = deleteinBST(root->left, key);
    else if (key > root->data)
        root->right = deleteinBST(root->right, key);
    else
    {
        // Case 1: If the left child of a node is null, we'll free the right node
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        // Case 2: If the right child of a node is null, we'll free the left node
        if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3:
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, key);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    /* Binary Search Tree
             4
            / \
           2   5
          / \   \
         1   3   6
    */
    inorder(root);
    cout << endl;
    root = deleteinBST(root, 5);
    inorder(root);
    cout << endl;
    return 0;
}