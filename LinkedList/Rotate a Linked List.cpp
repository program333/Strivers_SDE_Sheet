https://www.geeksforgeeks.org/rotate-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// Function to rotate a linked list.
Node* rotate(Node* head, int k)
{
	// let us consider the example
	// 10->20->30->40->50->60 - k=4
	// initialising 2 nodes temp and last
	Node* last = head;
	Node* temp = head;

	// if head is null or k==0 no rotation is required
	if (head == NULL || k == 0) {
		return head;
	}

	// Making last point to the last-node of the given
	// linked list in this case 60
	while (last->next != NULL) {
		last = last->next;
	}

	// Rotating the linked list k times, one rotation at a
	// time.
	while (k) {

		// Make head point to next of head
		// so in the example given above head becomes 20
		head = head->next;

		// Making next of temp as NULL
		// In the above example :10->NULL
		temp->next = NULL;

		// Making temp as last node
		// (head)20->30->40->50->60->10(last)
		last->next = temp;
		last = temp;

		// Point temp to head again for next rotation
		temp = head;
		k--;
	}

	return head;
}

void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void push(Node** head_ref, int new_data)
{
	// allocate node
	Node* new_node = new Node();

	// put in the data
	new_node->data = new_data;

	// link the old list of the new node
	new_node->next = (*head_ref);

	// move the head to point to the new node
	(*head_ref) = new_node;
}

int main()
{
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	head = rotate(head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);
	return 1;
}

/*
Output
Given linked list 
10 20 30 40 50 60 

Rotated Linked list 
50 60 10 20 30 40 
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
