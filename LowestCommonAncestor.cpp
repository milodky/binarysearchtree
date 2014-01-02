#include "TreeNode.h"

TreeNode *PickUp(TreeNode *root)
{
	if (root == NULL)
		return NULL;
	int Num = root->holder.size();
	int i = rand() % Num;
	return root->holder[i];
}


TreeNode *LCA(TreeNode *root, TreeNode *pNode1, TreeNode *pNode2)
{
	if (root == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;
	if (root == pNode1 || root == pNode2)
		return root;
	TreeNode *left = LCA(root->left, pNode1, pNode2);
	TreeNode *right = LCA(root->right, pNode1, pNode2);
	if (left && right)
		return root;
	if (left == NULL && right == NULL)
		return NULL;
	return (left != NULL) ? left : right;
}


TreeNode *LCA_Golden(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root)
		return NULL;
	if (root == p || root == q)
		return root;
	TreeNode *L = LCA(root->left, p, q);
	TreeNode *R = LCA(root->right, p, q);
	if (L && R) return root;  // if p and q are on both sides
	return L ? L : R; // either one of p,q is on one side OR p,q is not in L&R subtrees 
}
