class Node:
    def __init__(self, data):
        self.data = data  # Assigns the given data to the node
        self.next = None  # Initialize the next attribute to null

class LinkedList:
    def __init__(self):
        self.head = None  # Initialize head as None

    def addAtbeg(self, new_data):
        new_node = Node(new_data)  # Create a new node
        new_node.next = self.head  # Next for new node becomes the   current head
        self.head = new_node  # Head now points to the new node

    def addAtEnd(self, new_data):
        new_node = Node(new_data)
        if self.head == None:
            self.head = new_node
        else:
            temp_node = self.head
            while temp_node.next:
                temp_node = temp_node.next
            temp_node.next = new_node

    def printList(self):
        temp = self.head  # Start from the head of the list
        while temp:
            print(temp.data, end=' ')  # Print the data in the current node
            temp = temp.next  # Move to the next node
        print()  # Ensures the output is followed by a new line



if __name__ == '__main__':
    # Create a new LinkedList instance
    llist = LinkedList()

    # Insert each letter at the beginning using the method we created
    llist.addAtbeg(10)
    llist.addAtbeg(20)
    llist.addAtEnd(30)

    # Print the list
    llist.printList()

----------------------------------------------------------------------------------------------------------- 
# Python Program for traversal of Singly Linked list
from sqlalchemy import delete

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def add_at_beg(head, data):
    new_node = Node(data)
    new_node.next = head
    return new_node


def add_at_end(head, data):
    new_node = Node(data)
    if head == None:
        head = new_node

    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node
    return head

def delete_at_beg(head):
    if head == None:
        return head

    else:
        temp = head
        head = head.next
        del temp
    return head

def delete_at_end(head):
    if head == None:
        return head

    else:
        temp = head
        while temp.next.next:
            temp = temp.next
        temp.next = None
    return head

def reverseList(head):
    current = head
    prev = None
    temp = None
    while current:
        temp = current.next
        current.next = prev
        prev = current
        current = temp
    head = prev
    return head


def printList(head):
    temp = head
    while temp:
        print(str(temp.data) + " -> ", end=" ")
        temp = temp.next

    print("None")


# Singly linked list created and its head stored in a variable named "head"
head = None
head = add_at_end(head, 5)
head = add_at_beg(head, 4)
head = add_at_beg(head, 3)
head = add_at_beg(head, 2)
head = add_at_beg(head, 1)

# To traverse and print the nodes:
printList(head)

head = delete_at_beg(head)
head = delete_at_end(head)

# To traverse and print the nodes:
printList(head)

#reverse list
head = reverseList(head)

# To traverse and print the nodes:
printList(head)

