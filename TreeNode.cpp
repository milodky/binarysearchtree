#include "TreeNode.h"
TreeNode* TreeNode::BuildTree(int Num, int mode)
{
	if (Num == 0)
		return NULL;
	//val = rand() % 100 + 1;
	holder.push_back(this);
	for (int i = 1; i < Num; i++) {
		int value = rand() % 100 + 1;
		TreeNode *pNode = new TreeNode(value);
		holder.push_back(pNode);
		InsertNode(this, pNode, mode);
	}
	return this; 
}
void TreeNode::InsertNode(TreeNode *root, TreeNode *pNode, int Mode)
{
	if (Mode == BST) {
		if (root->val < pNode->val) {
			if (root->right == NULL) {
				root->right = pNode;
				return;
			} else {
				InsertNode(root->right, pNode, Mode);
				return;
			}
		} else {
			if (root->left == NULL) {
				root->left = pNode;
				return;
			} else {
				InsertNode(root->left, pNode, Mode);
				return;
			}
		}
	} else if (Mode == GENERAL) {
		int rl = rand() % 2;
		if (rl == 0) {
			if (root->left == NULL) {
				root->left = pNode;
				return;
			} else {
				InsertNode(root->left, pNode, Mode);
				return;
			}
		} else {
			if (root->right == NULL) {
				root->right = pNode;
				return;
			} else {
				InsertNode(root->right, pNode, Mode);
			}
		}
	}
}


void TreeNode::InOrderPrint(TreeNode *root)
{
	if (root == NULL)
		return;
	if (root->left)
		InOrderPrint(root->left);
	cout << root->val << " ";
	if (root->right)
		InOrderPrint(root->right);
}

TreeNode::~TreeNode()
{
	//DeleteTree(this);
}

void TreeNode::DeleteTree(TreeNode *root)
{
	if (root == NULL)
		return;
	DeleteTree(root->left);
	DeleteTree(root->right);
	delete root;
}


void TreeNode::BFPrint(TreeNode *root)
{
	if (root == NULL) {
		cout << "I have no root.." << endl;
		return;
	}
	queue<TreeNode *> Queen;
	Queen.push(root);
	while (Queen.empty() == false) {
		TreeNode *pCurrent = Queen.front();
		Queen.pop();
		cout << pCurrent->val << " ";
		if (pCurrent->left)
			Queen.push(pCurrent->left);
		else
			cout << "# ";
		if (pCurrent->right)
			Queen.push(pCurrent->right);
		else
			cout << "* ";
	}
}



















