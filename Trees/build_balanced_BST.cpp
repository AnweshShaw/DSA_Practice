// Build Balanced BST from a sorted Array
/*
 Algo:
 1) Make middle element the root.
 2) Recursively, do the same forr subbtrees
    a) start to mid-1 for Left subtree
    b)mid+1 to end for Right subtree
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

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void preorderprint(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    Node *root = sortedArrayToBST(arr, 0, 4);
    preorderprint(root);
    cout << endl;
    return 0;
}