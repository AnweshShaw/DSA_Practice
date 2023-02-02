// Creation of a Tree

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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] = curr)
        {
            return i;
        }
    }
    return -1;
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

Node *buildtree(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[index];
    index++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildtree(preorder, inorder, start, pos - 1);
    node->right = buildtree(preorder, inorder, pos + 1, end);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 2, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildtree(preorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}