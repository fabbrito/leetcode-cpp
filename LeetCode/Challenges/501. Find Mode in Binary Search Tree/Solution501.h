#ifndef FIND_MODE_IN_BST_H_INCLUDED
#define FIND_MODE_IN_BST_H_INCLUDED

// 501. Find Mode in Binary Search Tree
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

namespace leetcode_501 {
	class Solution {
	public:
		std::vector<int> findMode(TreeNode* root);
	};
}

int test_501();

#endif