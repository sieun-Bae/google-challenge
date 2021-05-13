using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  LinkedList* cur = linkedList;
	
	while (cur != NULL) {
		LinkedList* nxt = cur->next;
		while (nxt != NULL && cur->value == nxt->value) {
			nxt = nxt->next;
		}
		cur->next = nxt;
		cur = nxt;
	}
	return linkedList;
}

