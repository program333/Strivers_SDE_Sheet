https://www.geeksforgeeks.org/sort-a-linked-list-of-0s-1s-or-2s/
https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/


// CPP Program to sort a linked list 0s, 1s
// or 2s by changing links
#include <bits/stdc++.h>

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data);

// Sort a linked list of 0s, 1s and 2s
// by changing pointers.
Node* sortList(Node* head)
{
	if (!head || !(head->next))
		return head;

	// Create three dummy nodes to point to beginning of
	// three linked lists. These dummy nodes are created to
	// avoid many null checks.
	Node* zeroD = newNode(0);
	Node* oneD = newNode(0);
	Node* twoD = newNode(0);

	// Initialize current pointers for three
	// lists and whole list.
	Node *zero = zeroD, *one = oneD, *two = twoD;

	// Traverse list
	Node* curr = head;
	while (curr) {
		if (curr->data == 0) {
			zero->next = curr;
			zero = zero->next;
		}
		else if (curr->data == 1) {
			one->next = curr;
			one = one->next;
		}
		else {
			two->next = curr;
			two = two->next;
		}
		curr = curr->next;
	}

	// Attach three lists
	zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
	one->next = twoD->next;
	two->next = NULL;

	// Updated head
	head = zeroD->next;

	// Delete dummy nodes
	delete zeroD;
	delete oneD;
	delete twoD;

	return head;
}

// Function to create and return a node
Node* newNode(int data)
{
	// allocating space
	Node* newNode = new Node;

	// inserting the required data
	newNode->data = data;
	newNode->next = NULL;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Driver program to test above function*/
int main(void)
{
	// Creating the list 1->2->4->5
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(0);
	head->next->next->next = newNode(1);

	printf("Linked List Before Sorting\n");
	printList(head);

	head = sortList(head);

	printf("Linked List After Sorting\n");
	printList(head);

	return 0;
}




//C++ code to implement the above approach
#include <iostream>

// Define a structure for a node in a linked list
struct Node {
int data;
Node *next;
};

// Function to insert a new node at the end of the linked list
void push(Node **head, int data) {
Node *newNode = new Node();
newNode->data = data;
newNode->next = nullptr;

if (*head == nullptr) {
	*head = newNode;
	return;
}

Node *last = *head;
while (last->next != nullptr) {
	last = last->next;
}

last->next = newNode;
}

// Function to print the linked list
void printList(Node *head) {
Node *current = head;
while (current != nullptr) {
	std::cout << current->data << " ";
	current = current->next;
}
std::cout << std::endl;
}

// Function to sort the linked list containing 0's, 1's, and 2's
void sortList(Node *head) {
int count[3] = {0, 0, 0};

// Count the number of 0's, 1's, and 2's in the linked list
Node *current = head;
while (current != nullptr) {
	count[current->data]++;
	current = current->next;
}

// Overwrite the linked list with the sorted elements
current = head;
int i = 0;
while (current != nullptr) {
	if (count[i] == 0) {
	i++;
	} else {
	current->data = i;
	count[i]--;
	current = current->next;
	}
}
}

int main() {
Node *head = nullptr;

// Insert some elements into the linked list
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 2);
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	push(&head, 2);

std::cout << "Linked List before Sorting: "<<std::endl;
printList(head);

sortList(head);

std::cout << "Linked List after Sorting: "<<std::endl;
printList(head);

return 0;
}

/*
Output
Linked List before Sorting
2 1 2 1 1 2 0 1 0 
Linked List after Sorting
0 0 1 1 1 1 2 2 2 
 
Time Complexity: O(n) where n is the number of nodes in the linked list. 
Auxiliary Space: O(1) 
*/
