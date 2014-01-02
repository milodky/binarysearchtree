#include "TreeNode.h"

void GetLinkedList(TreeNode *root, TreeNode *&pLast)
{
	if (root == NULL)
		return;
	GetLinkedList(root->left, pLast);
	if (pLast == NULL)
		pLast = root;
	else {
		pLast->right = root;
		root->left = pLast;
		pLast = root;
	}
	GetLinkedList(root->right, pLast);
}

TreeNode* GetBSTfromLL(TreeNode *&pCurrent, int begin, int end)
{
	if (end < begin)
		return NULL;
	int mid = (end - begin) / 2 + begin;
	TreeNode *left = GetBSTfromLL(pCurrent, begin, mid - 1);
	TreeNode *root = new TreeNode(pCurrent->val);
	pCurrent = pCurrent->right;
	TreeNode *right = GetBSTfromLL(pCurrent, mid + 1, end);
	root->left = left;
	root->right = right;
	return root;
}

