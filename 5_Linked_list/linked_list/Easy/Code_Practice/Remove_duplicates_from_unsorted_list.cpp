Given an unsorted Linked List, the task is to remove duplicates from the list. 
Examples:
Input: linked_list = 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21 
Output: 12 -> 11 -> 21 -> 41 -> 43 
Explanation: Second occurrence of 12 and 21 are removed.

Input: linked_list = 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21 
Output: 12 -> 11 -> 21 -> 41 -> 43   
---------------------------------------------------------------------------------- 
 /* C++ Program to remove duplicates in an unsorted
   linked list */
#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node {
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(Node* start)
{
    // Hash to store seen values
    unordered_set<int> seen;

    /* Pick elements one by one */
    Node* curr = start;
    Node* prev = NULL;
    while (curr != NULL) {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete (curr);
        }
        else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    Node* start = new Node(10);
    start->next = new Node(12);
    start->next->next = new Node(11);
    start->next->next->next = new Node(11);
    start->next->next->next->next = new Node(12);
    start->next->next->next->next->next = new Node(11);
    start->next->next->next->next->next->next
        = new Node(10);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(start);

    return 0;
}
 
