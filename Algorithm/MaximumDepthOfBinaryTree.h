#pragma once
#include <algorithm>

class MaximumDepthOfBinaryTree
{
private:

	// Define for a binary tree node
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(0), left(left), right(right) {}
	};

public:
	// the number of nodes in the tree is in the range [0, 10^4]
	// -100 <= node.val <= 100
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;
		else if (root->left == nullptr && root->right == nullptr)
			return 1;
		else
			return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}
};