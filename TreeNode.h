#ifndef TREENODE_H_
#define TREENODE_H_
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define BST	1
#define GENERAL	2
using std::cout;
using std::endl;
using std::queue;
using std::vector;
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x = 0, TreeNode *l = NULL, TreeNode *r = NULL) : val(x), left(l), right(r) {}
	~TreeNode();
	TreeNode *BuildTree(int, int);
	void InsertNode(TreeNode *, TreeNode *, int);
	static void InOrderPrint(TreeNode *);
	static void BFPrint(TreeNode*);
	static void DeleteTree(TreeNode *);
	static void PreOrderPrint(TreeNode *);


	vector<TreeNode *> holder;
	
};



#endif
