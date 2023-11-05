// LeetCode BinarySearchTree Explore
// https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/536/

/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // More Improved Solution.
    bool isMirror(TreeNode* leftp, TreeNode* rightp)
    {
        if(leftp == nullptr && rightp == nullptr) return true;
        if(leftp == nullptr || rightp == nullptr) return false;
        if(leftp->val != rightp->val) return false;
        return isMirror(leftp->right,rightp->left) && isMirror(rightp->right,leftp->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
    
    // My first Solution.
    // bool TraversalTree(TreeNode* left, TreeNode* right)
    // {
    //     // subtree all traversal
    //     if (left == nullptr && right == nullptr)
    //         return true;
    //
    //     // if false, it is not symmetric
    //     if (left == nullptr || right == nullptr)
    //         return false;
    //
    //     return (left->val == right->val && TraversalTree(left->left, right->right) && TraversalTree(left->right, right->left));
    // }
    //
    // bool isSymmetric(TreeNode* root) {
    //
    //     if (root == nullptr)
    //         return false;
    //
    //     return TraversalTree(root->left, root->right);
    // }
};