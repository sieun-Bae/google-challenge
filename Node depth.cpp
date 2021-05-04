#include <vector>
#include <iostream>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};
void nodeDepthsHelper(BinaryTree* node, int temp_depth, vector<int>& Sum);

int nodeDepths(BinaryTree *root) {
	vector<int> Sum;
	int answer = 0;
	nodeDepthsHelper(root, 0, Sum);
	for (int i=0;i<Sum.size();i++) {
		answer += Sum[i];
	}
  return answer;
}

void nodeDepthsHelper(BinaryTree* node, int temp_depth, vector<int>& Sum)
{
	if (node == nullptr)
		return;
	Sum.push_back(temp_depth);
	nodeDepthsHelper(node->left, temp_depth+1, Sum);
	nodeDepthsHelper(node->right, temp_depth+1, Sum);
}

/*
int nodeDepths(BinaryTree* root, int depth = 0)
{
	if (root == nullptr)
		return 0;
	return depth + nodeDepths(root->left, depth+1) + nodeDepths(root->right, depth+1);
}
*/
