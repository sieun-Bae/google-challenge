using namespace std;

// This is the class of the input root. Do not edit it.
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


void branchSumsHelper(BinaryTree *node, int Sum, vector<int>& answer);
	
vector<int> branchSums(BinaryTree *root) {
	vector<int> answer;
	branchSumsHelper(root, 0, answer);
  return answer;
}

void branchSumsHelper(BinaryTree *node, int Sum, vector<int> &answer) {
	if (node == nullptr)
		return;
	
	int tmp = Sum+node->value;
	if (node->left==nullptr && node->right == nullptr) {
		answer.push_back(tmp);
		return;
	}
	branchSumsHelper(node->left, tmp, answer);
	branchSumsHelper(node->right, tmp, answer);
}

