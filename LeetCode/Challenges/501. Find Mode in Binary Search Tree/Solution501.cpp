#include <iostream>
#include <vector>
#include <algorithm>
#include "./Solution501.h"
#include "utils.h"

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

void inOrderTraversal(TreeNode* node, int& current_val, int& current_count, int& max_count, std::vector<int>& modes) {
	if (!node) return;

	inOrderTraversal(node->left, current_val, current_count, max_count, modes);

	current_count = (node->val == current_val) ? current_count + 1 : 1;
	if (current_count == max_count) {
		modes.push_back(node->val);
	}
	else if (current_count > max_count) {
		max_count = current_count;
		modes = { node->val };
	}
	current_val = node->val;

	inOrderTraversal(node->right, current_val, current_count, max_count, modes);
}

std::vector<int> leetcode_501::Solution::findMode(TreeNode* root) {
	int current_val = 0;
	int current_count = 0;
	int max_count = 0;
	std::vector<int> modes;
	inOrderTraversal(root, current_val, current_count, max_count, modes);
	return modes;
}

void insertBST(int val, TreeNode*& root) {
	if (val == root->val) {
		if (!root->left) {
			root->left = new TreeNode(val);
		}
		else if (!root->right) {
			root->right = new TreeNode(val);
		}
		else {
			insertBST(val, root->left);
		}
	}
	else if (val < root->val) {
		if (!root->left) {
			root->left = new TreeNode(val);
		}
		else {
			insertBST(val, root->left);
		}
	}
	else {
		if (!root->right) {
			root->right = new TreeNode(val);
		}
		else {
			insertBST(val, root->right);
		}
	}
}

TreeNode* constructTree(std::vector<int>& vec)
{
	TreeNode* root = new TreeNode(vec[0]);
	for (int i = 1; i < vec.size(); i++) {
		insertBST(vec[i], root);
	}
	return root;
}

void printInorder(TreeNode* node)
{
	if (node == NULL) {
		return;
	}
	printInorder(node->left);
	std::cout << node->val << " ";
	printInorder(node->right);
}

void printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;
		std::cout << (isLeft ? "|--" : "L--");
		// print the value of the node
		std::cout << " (" << node->val << ") " << std::endl;
		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
	}
}
void printBT(const TreeNode* node)
{
	printBT("", node, false);
}

int test_501()
{
	using namespace leetcode_501;
	Solution* solution = new Solution;
	std::vector<int> result;
	struct Test {
		std::vector<int> rootVec;
		std::vector<int> expected;
	};
	std::vector<Test> tests = {
		{{3,2,1,2,4,4,5}, {2,4}},
		{{1,2,2,3,4,4,5}, {2,4}},
		{{1,2,2}, {2}},
	};

	std::cout << "Testing Solution" << std::endl;
	for (auto& test : tests) {
		TreeNode* root = constructTree(test.rootVec);
		printBT(root);
		std::cout << std::endl;
		result = solution->findMode(root);
		std::sort(result.begin(), result.end());
		utils::printVector(result);
		if (result != test.expected) return 1;
	}
	return 0;
}
