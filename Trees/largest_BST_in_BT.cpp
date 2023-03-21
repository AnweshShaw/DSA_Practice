/*
Algorithm - For each node store the following info:
1) Min in subtree
2) Max in subtree
3) Subtree size
4) Size of largest BST
5) isBST
*/

#include <bits/stdc++.h>
#include <vector>
#include <climits>
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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool IsBST;
};

Info LargestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    Info leftInfo = LargestBSTinBT(root->left);
    Info rightInfo = LargestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.IsBST && rightInfo.IsBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = min(rightInfo.max, max(rightInfo.max, root->data));
        curr.ans = curr.size;
        curr.IsBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.IsBST = false;
    return curr;
}

int main()
{
    /*
        15
       /  \
      20   30
      /
      5
    */
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << "Largest Node in BT is : " << LargestBSTinBT(root).ans << endl;
    return 0;
}
