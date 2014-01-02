#include "TreeNode.h"

TreeNode *Amazon_successor(TreeNode *root, int value)
{
	if (root == NULL)
		return NULL;
	TreeNode *pRet = root;
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
		TreeNode *pNode2 = Amazon_successor(root->right, value);
		if (pNode1 == NULL && pNode2 == NULL)
			return NULL;
		else if (pNode1 && pNode2 == NULL)
			return pNode1;
		else if (pNode1 == NULL && pNode2)
			return pNode2;
		else
			pRet = abs(pNode1->val - value) < abs(pNode2->val - value) ?
				pNode1 : pNode2;

	}
	return pRet;
}
