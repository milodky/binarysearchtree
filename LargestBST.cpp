/*
 * find the largest binary search subtree in a given tree
 */
#include <algorithm>
#include "TreeNode.h"
#define MAX 0x3f3f3f3f
#define MIN (0 - 0x3f3f3f3f)

static int LargestBST(TreeNode *root, int &mymin, int &mymax, int &MaxCnt, TreeNode *&TheRoot)
{
	/*
	 * if it returns -1, it means this subtree is not a BST
	 */
	if (root == NULL)
		return 0;
	int ret = -1;
	bool IsBst = true;
	int left = LargestBST(root->left, mymin, mymax, MaxCnt, TheRoot);
	if (left == -1 || (left != 0 && root->val < mymax))
		IsBst = false; 
	int right = LargestBST(root->right, mymin, mymax, MaxCnt, TheRoot);
	if (right == -1 || (right != 0 && mymin <= root->val))
		IsBst = false;
	if (IsBst) {
		mymin = (left == 0) ? root->val : mymin;
		mymax = (right == 0) ? root->val : mymax;
		ret = left + right + 1;
		if (MaxCnt < ret) {
			MaxCnt = ret;
			TheRoot = root;
		}
	}
	return ret;
}



static TreeNode* GetLargestBST(TreeNode *root)
{
	if (root == NULL)
		return NULL;
	int NodeCnt = 0;
	TreeNode *ret = NULL;
	int mymax = MAX;
	int mymin = MIN;
	LargestBST(root, mymin, mymax, NodeCnt, ret);
	return ret;
}


int findLargestBSTSubtree(TreeNode *root, int &min, int &max, 
		int &maxNodes, TreeNode *& largestBST) {
	if (!root) return 0;
	bool isBST = true;
	int leftNodes = findLargestBSTSubtree(root->left, min, max, maxNodes, largestBST);
	int currMin = (leftNodes == 0) ? root->val : min;
	if (leftNodes == -1 || (leftNodes != 0 && root->val <= max))
		isBST = false;
	int rightNodes = findLargestBSTSubtree(root->right, min, max, maxNodes, largestBST);
	int currMax = (rightNodes == 0) ? root->val : max;
	if (rightNodes == -1 || (rightNodes != 0 && root->val >= min))
		isBST = false;
	if (isBST) {
		min = currMin;
		max = currMax;
		int totalNodes = leftNodes + rightNodes + 1;
		if (totalNodes > maxNodes) {
			maxNodes = totalNodes;
			largestBST = root;
		}
		return totalNodes;
	} else {
		return -1;   // This subtree is not a BST
	}
}

TreeNode* findLargestBSTSubtree(TreeNode *root) {
	TreeNode *largestBST = NULL;
	int min, max;
	int maxNodes = MIN;
	findLargestBSTSubtree(root, min, max, maxNodes, largestBST);
	return largestBST;
}
