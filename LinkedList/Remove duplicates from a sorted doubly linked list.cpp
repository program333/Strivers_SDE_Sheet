https://www.geeksforgeeks.org/remove-duplicates-sorted-doubly-linked-list/

/* C++ implementation to remove duplicates from a
sorted doubly linked list */
#include <bits/stdc++.h>

using namespace std;

/* a node of the doubly linked list */
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

/* Function to delete a node in a Doubly Linked List.
head_ref --> pointer to head node pointer.
del --> pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del)
{
	/* base case */
	if (*head_ref == NULL || del == NULL)
		return;

	/* If node to be deleted is head node */
	if (*head_ref == del)
		*head_ref = del->next;

	/* Change next only if node to be deleted
		is NOT the last node */
	if (del->next != NULL)
		del->next->prev = del->prev;

	/* Change prev only if node to be deleted
	is NOT the first node */
	if (del->prev != NULL)
		del->prev->next = del->next;

	/* Finally, free the memory occupied by del*/
	free(del);
}

/* function to remove duplicates from a
sorted doubly linked list */
void removeDuplicates(struct Node** head_ref)
{
	/* if list is empty */
	if ((*head_ref) == NULL)
		return;

	struct Node* current = *head_ref;
	struct Node* next;

	/* traverse the list till the last node */
	while (current->next != NULL) {

		/* Compare current node with next node */
		if (current->data == current->next->data)

			/* delete the node pointed to by
			'current->next' */
			deleteNode(head_ref, current->next);

		/* else simply move to the next node */
		else
			current = current->next;
	}
}

/* Function to insert a node at the beginning
of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* since we are adding at the beginning,
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list */
void printList(struct Node* head)
{
	/* if list is empty */
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Create the doubly linked list:
	4<->4<->4<->4<->6<->8<->8<->10<->12<->12 */
	push(&head, 12);
	push(&head, 12);
	push(&head, 10);
	push(&head, 8);
	push(&head, 8);
	push(&head, 6);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);

	cout << "Original doubly linked list:\n";
	printList(head);

	/* remove duplicate nodes */
	removeDuplicates(&head);

	cout << "\nDoubly linked list after"
			" removing duplicates:\n";
	printList(head);

	return 0;
}

/*
Output
Original Doubly linked list:n4 4 4 4 6 8 8 10 12 12 
Doubly linked list after removing duplicates:n4 6 8 10 12 
Time Complexity: O(n)
Auxiliary Space: O(1) since using constant space for pointers
*/
