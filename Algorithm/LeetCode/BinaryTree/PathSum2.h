#pragma once
#include <vector>
#include <iostream>
#include <numeric>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

class PathSum2
{
public:
    std::vector<std::vector<int>> result;
    int sum = 0;

    void backtrack(TreeNode* cur, std::vector<int>& path)
    {
        if (!cur->left && !cur->right)
        {
            if (accumulate(path.begin(), path.end(), 0) == sum)
                result.push_back(path);
        }
        else
        {
            if (cur->left)
            {
                path.push_back(cur->left->val);
                backtrack(cur->left, path);
                path.pop_back();
            }

            if (cur->right)
            {
                path.push_back(cur->right->val);
                backtrack(cur->right, path);
                path.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if (!root)
            return result;

        this->sum = targetSum;

        std::vector<int> path = {root->val};
        backtrack(root, path);

        return result;
    }
        
};
