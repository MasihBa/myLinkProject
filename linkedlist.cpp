#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node(const int& nVal):value(nVal), next(nullptr){}
};

void addToEnd(Node*& head, const int& nVal) {
	Node* newNode = new Node(nVal);
	
	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* tmp = head;
	
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}

	tmp->next = newNode;
}

void addToFront(Node*& head, const int& nVal) {
	Node* newNode = new Node(nVal);

	if (head == nullptr) {
		head = newNode;
		return;
	}
	
	newNode->next = head;
	head = newNode;
}

void deleteFromEnd(Node*& head) {
	if (head == nullptr)return;

	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	Node* tmp = head;
	while (tmp->next->next != nullptr) {
		tmp = tmp->next;
	}

	delete tmp->next;
	tmp->next = nullptr;
}

void deleteFromFront(Node*& head) {
	if (head == nullptr)return;

	Node* tmp = head;
	head = head->next;
	delete tmp;
	return;
}

void deleteFromIndex(Node*& head, const int& index) {
	if (head == nullptr)return;

	Node* tmp = head;
	if (index == 0) {
		tmp = head;
		head = head->next;
		delete tmp;
		return;
	}

	int count = 0;
	while (tmp != nullptr && count < index - 1) {
		tmp = tmp->next;
		count++;
	}

	if (tmp == nullptr) {
		cout << "ERROR! The index is not valid" << endl;
		return;
	}

	Node* toDelete = tmp->next;
	tmp->next = toDelete -> next;
	delete toDelete;
	return;
}

void addFromIndex(Node*& head, const int& nVal, const int& index) {
	Node* newNode = new Node(nVal);

	if (index < 0)return;
	
	if (head == nullptr) {
		head = newNode;
		return;
	}

	Node* tmp = head;
	int count = 0;
	while (tmp != nullptr && count < index - 1) {
		tmp = tmp->next;
		count++;
	}

	if (tmp == nullptr) {
		cout << "ERROR! The index is not valid!" << endl;
		delete newNode;
		return;
	}

	newNode->next = tmp->next;
	tmp->next = newNode;
	return;
}

void print(Node*& head) {
	if (head == nullptr) {
		cout << "ERROR! The linked list is empty!" << endl;
		return;
	}

	Node* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->value << " -> ";
		tmp = tmp->next;
	}

	cout << "NULL" << endl;
	return;
}

int main() {
		Node* head = nullptr;

		cout << "Printing empty list:" << endl;
		print(head);

		cout << "\nAdding nodes using addToFront and addToEnd:" << endl;
		addToFront(head, 10);
		addToFront(head, 5);
		addToEnd(head, 15);
		print(head);

		cout << "\nInserting 12 at index 2 using addFromIndex:" << endl;
		addFromIndex(head, 12, 2);
		print(head);

		cout << "\nDeleting node from front:" << endl;
		deleteFromFront(head);
		print(head);

		cout << "\nDeleting node from end:" << endl;
		deleteFromEnd(head);
		print(head);

		cout << "\nDeleting node at index 1:" << endl;
		deleteFromIndex(head, 1);
		print(head);

		cout << "\nAttempting to delete node at invalid index 5:" << endl;
		deleteFromIndex(head, 5);
		print(head);

		cout << "\nCleaning up the list:" << endl;
		deleteFromFront(head);
		print(head);

		return 0;
}