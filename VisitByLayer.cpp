#include "TreeNode.h"
#include <queue>
using namespace std;
void VisitByLayer(TreeNode *root)
{
	if (root == NULL)
		return;
	queue<TreeNode*> First;
	First.push(root);
	while (true) {
		queue<TreeNode *> Second;
		while (First.empty() == false) {
			TreeNode *Current = First.front();
			cout << Current->val << " ";
			First.pop();
			if (Current->left)
				Second.push(Current->left);
			if (Current->right)
				Second.push(Current->right);
		}
		cout << endl;
		if (Second.empty() == true)
			break;
		First = Second;
	}
}

