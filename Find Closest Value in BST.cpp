class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBstHelper(BST* tree, int target, int closest);

int findClosestValueInBst(BST *tree, int target) {
  return findClosestValueInBstHelper(tree, target, tree->value); 
}

int findClosestValueInBstHelper(BST *tree, int target, int closest)
{
	if (abs(target-closest) > abs(target-tree->value)) {
		closest = tree->value;
	}
	if (target < tree->value && tree->left != nullptr) {
		return findClosestValueInBstHelper(tree->left, target, closest);
	} else if (target > tree->value && tree->right != nullptr) {
		return findClosestValueInBstHelper(tree->right, target, closest);
	} else {
		return closest;
	}
}