//deep rather than wide
//recursively
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Node {
	public:
		string name;
		vector<Node*> children;
		Node(string str) {
			name = str;
		}
		//O(V+E) time | O(V) space
		vector<string> depthFirstSearch(vector<string>* array)
		{
			array->push_back(this->name);
			cout<<this->name;
			for (int i=0;i < this->children.size();i++) {
				children[i] -> depthFirstSearch(array);
			}
			return *array;
		}

		Node* addChild(string name) {
			Node* child = new Node(name);
			children.push_back(child);
			return this;
		}
};

int main()
{
	Node* root = new Node("A");
	root->addChild("B");
	//root->addChild("C");
	//root->addChild("D");
	vector<string>* dfs;
	root->depthFirstSearch(dfs);
}