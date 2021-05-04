#include <iostream>
#include <vector>
using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree(int value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
}

/*
Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout<<"Memory Error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, int data)
{
	if (root == NULL){
		root = CreateNode(data);
		return root;
	}
	queue<Node*> q;
	q.push(root);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}
		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}
*/

vector<int> branchSums(BinaryTree* root) {
	vector<int> answer;
	branchSumsHelper(root, 0, answer);
	return answer;
}

void branchSumsHelper(BinaryTree* node, int Sum, vector<int> &answer)
{
	if (node == nullptr)
		return;
	int tmp = Sum + node->value;
	if (node->left == nullptr && node->right == nullptr) {
		ansewr.push_back(tmp);
		return;
	}
	branchSumsHelper(node->left, tmp, answer);
	branchSumsHelper(node->right, tmp, answer);
}

int main()
{

	return 0;
}