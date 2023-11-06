/**
 * LeetCode : https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/
 * Date : 2023/11/06
 * Definition for a binary tree node.
 */

#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Improve Solution
// Using Queue
class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return {};

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;

        // push root onto queue
        q.push(root);
        while (!q.empty())
        {
            int qsize = q.size();
            std::vector<int> levelValues;

            for (int i = 0; i < qsize; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);

                levelValues.push_back(node->val);
            }

            result.push_back(levelValues);
        }

        return result;
    }
};

// First Solution
// class Solution {
// public:
//     
//     int height(TreeNode* node)
//     {
//         if (node == nullptr)
//             return 0;
//         
//         int lheight = height(node->left);
//         int rheight = height(node->right);
//         
//         if (lheight > rheight)
//             return (lheight + 1);
//         else
//             return (rheight + 1);
//     }
//     
//     void AddCurrentLevel(TreeNode* node, int level, vector<int>& result)
//     {
//         if (node == nullptr)
//             return;
//         else if (level == 1)
//             result.push_back(node->val);
//         else if (level > 1)
//         {
//             AddCurrentLevel(node->left, level - 1, result);
//             AddCurrentLevel(node->right, level - 1, result);
//         }
//     }
//     
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         
//         if (root == nullptr)
//             return result;
//         
//         // get height
//         int h = height(root);
//         int i;
//         
//         // traverse
//         for (i =1; i <= h; i++)
//         {
//             vector<int> levelResult;
//             AddCurrentLevel(root, i, levelResult);
//             result.push_back(levelResult);
//         }
//         
//         return result;
//     }
// };