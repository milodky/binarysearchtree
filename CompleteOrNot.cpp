#include "TreeNode.h"

bool CheckLeft(TreeNode *, int &, int &);
bool CheckRight(TreeNode *, int &, int &);

bool Check(TreeNode *root, int &Max, int &Min)
{
	if (root == NULL) {
		Max = 0;
		Min = 0;
		return true;
	}
	if (root->left == false && root->right == false) {
		Max = 1;
		Min = 1;
		return true;
	}
	if (root->left == false && root->right)
		return false;
	int LMin = 0;
	int LMax = 0;

	int RMin = 0;
	int RMax = 0;

	bool Left = Check(root->left, LMin, LMax);
	bool Right = Check(root->right, RMin, RMax);
	if (Left == false || Right == false)
		return false;

	if (LMin == LMax && RMin == RMax && LMin == RMin) {
		Max = LMin + 1;
		Min = LMin + 1;
		return true;
	}

	if (LMax == LMin + 1 && LMin == RMin && RMin == RMax) {
		Max = LMax + 1;
		Min = LMin + 1;
		return true;
	}
	if (LMax == LMin && LMax == RMax + 1 && RMax == RMin) {
		Max = LMax + 1;
		Min = RMax + 1;
		return true;
	}
	return false;
}




static bool IsComplete(TreeNode *root)
{
	int LMin = 0;
	int LMax = 0;
	int RMin = 0;
	int RMax = 0;
	bool Left = Check(root->left, LMin, LMax);
	bool Right = Check(root->right, RMin, RMax);
	if (Left == false || Right == false)
		return false;

	if (LMin == LMax && RMin == RMax && LMin == RMin)
		return true;

	if (LMax == LMin + 1 && LMin == RMin && RMin == RMax)
		return true;
	if (LMax == LMin && LMax == RMax + 1 && RMax == RMin)
		return true;
	return false;
	
}
