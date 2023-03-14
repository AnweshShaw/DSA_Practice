class Solution
{
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==0)
        {
            return 0;
        }
        if (isSameTree(root,subRoot))
        {
            return 1;
        }
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return left|right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        return 1;
        if(!p || !q)
        return 0;
        if(p->val!=q->val)
        return 0;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left&right;
    }
};
