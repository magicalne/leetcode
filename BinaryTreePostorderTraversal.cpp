#include<vector>
#include<stack>
#include<algorithm>
#include<stdio.h>
using namespace std;
void foo();
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:		
		vector<int> postorderTraversal(TreeNode *root) {
			vector<int> ans;
			if (root == NULL)
				return ans;
			stack<TreeNode*> s;
			s.push(root);
			while (!s.empty()) {
				TreeNode* top = s.top();
				ans.push_back(top->val);
				s.pop();
				if (top->left != NULL)
					s.push(top->left);
				if (top->right != NULL)
					s.push(top->right);
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};
int main() {
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(3);
	a->right = b;
	b->left = c;
	Solution s;
	TreeNode *t = new TreeNode(3);
	vector<int> v = s.postorderTraversal(NULL);
	int i;
	for (i = 0; i < v.size(); i ++) {
		printf("%d ", v[i]);
	}
}
