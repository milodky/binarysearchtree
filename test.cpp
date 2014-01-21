#include "TreeNode.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "LargestBST.cpp"
void LargestBST_Test(TreeNode *root)
{
	TreeNode *Result = GetLargestBST(root);
	cout << "Result is: " << endl;
	TreeNode::InOrderPrint(Result);
	cout << endl;
	
	TreeNode *Golden = findLargestBSTSubtree(root);
	cout << "Golden is: " << endl;
	TreeNode::InOrderPrint(Golden);
	cout << endl;
}
#include "LowestCommonAncestor.cpp"
void LCA_Test(TreeNode *root)
{
	TreeNode *p = PickUp(root);
	TreeNode *q = PickUp(root);
	
	TreeNode *Result = LCA(root, p, q);
	TreeNode *Golden = LCA_Golden(root, p, q);
	
	cout << "Result: " << Result << endl;
	cout << "Golden: " << Golden << endl;
}
#include "NearestNode.cpp"
void NearestTreeNode(TreeNode *root, int val)
{
	TreeNode* pRet = Amazon_successor(root, val);
	cout << "value is: " << val << ", nearest node is: " << pRet->val << endl;
}

#include "BST2LinkedList.cpp"

void Bst2LL(TreeNode *root, int Num)
{
	TreeNode *previous = NULL;
	GetLinkedList(root, previous);
	TreeNode *pHead;
	previous = root;
	while (root) {
		previous = root;
		root = root->left;
	}
	root = previous;
	pHead = root;
	TreeNode *bbst = GetBSTfromLL(pHead, 0, Num - 1);
	cout << "double linked list: " << endl;
	while (root) {
		cout << root->val << " ";
		root = root->right;
		delete previous;
		previous = root;
	}
	cout << endl;
	cout << "Balanced Binary Search tree: " << endl;
	TreeNode::InOrderPrint(bbst);
	cout << endl;
	TreeNode::BFPrint(bbst);
	cout << endl;
	TreeNode::DeleteTree(bbst);
	cout << endl;
}

#include "CompleteOrNot.cpp"

#include "VisitByLayer.cpp"


int main(int argn, char *argv[])
{
	int Num = atoi(argv[1]);
	TreeNode *root = new TreeNode(50);
	srand(time(NULL));
	root->BuildTree(Num, GENERAL);
	TreeNode::InOrderPrint(root);
	cout << endl;
	TreeNode::BFPrint(root);
	cout << endl << endl;

	LargestBST_Test(root);
//	LCA_Test(root);
//	int RandInt = rand() % 100 + 1;
//	NearestTreeNode(root, RandInt);
//	TreeNode::DeleteTree(root);

//	Bst2LL(root, Num);
	TreeNode::PreOrderPrint(root);
	cout << endl;
//	bool flag = IsComplete(root);
//	if (flag == true)
//		cout << "Yes.";
//	else
//		cout << "No.";
//	cout << endl;

	VisitByLayer(root);
}
