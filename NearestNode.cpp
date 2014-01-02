#include "TreeNode.h"

TreeNode *Amazon_successor(TreeNode *root, int value)
{
	TreeNode *pRet = root;
	if (root == NULL)
		return NULL;
	if (value < root->val) {
		TreeNode *pNode = Amazon_successor(root->left, value);
		if (pNode != NULL)
			pRet = abs(pRet->val - value) < abs(pNode->val - value) ?
				pRet : pNode;
	} else if (root->val < value) {
		TreeNode *pNode = Amazon_successor(root->right, value);
		if (pNode != NULL)
			pRet = abs(pRet->val - value) < abs(pNode->val - value) ?
				pRet : pNode;
	} else {
		TreeNode *pNode1 = Amazon_successor(root->left, value);
		if (pNode1 != NULL)
			pRet = abs(pRet->val - value) < abs(pNode1->val - value) ?
				pRet : pNode1;
		TreeNode *pNode2 = Amazon_successor(root->right, value);
		if (pNode2 != NULL)
			pRet = abs(pRet->val - value) < abs(pNode2->val - value) ?
				pRet : pNode2;
	}
	return pRet;
}
