// Creation of postorder traversal from inorder

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

int search(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] = val)
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

Node *buildtree(int postorder[], int inorder[], int start, int end)
{
    static int index = 4;
    if (start > end)
    {
        return NULL;
    }
    int val = postorder[index];
    index--;
    Node *curr = new Node(val);
    if (start == end)
    {
        return curr;
    }
    int pos = search(inorder, start, end, val);
    curr->left = buildtree(postorder, inorder, start, pos - 1);
    curr->right = buildtree(postorder, inorder, pos + 1, end);
    return curr;
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildtree(postorder, inorder, 0, 4);
    inorderPrint(root);
    return 0;
}