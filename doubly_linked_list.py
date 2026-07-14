# Node Class: Stores data, next pointer, and previous pointer
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None  # Pointer to the previous node

# Doubly Linked List Class: Handles all operations
class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # 1. Insert at End: Adds a new node at the tail of the list
    def insert_at_end(self, val):
        new_node = Node(val)
        
        # If the list is empty, make the new node the head
        if self.head is None:
            self.head = new_node
            return

        # Traverse to the last node
        temp = self.head
        while temp.next is not None:
            temp = temp.next
            
        # Establish double links
        temp.next = new_node
        new_node.prev = temp

    # 2. Delete Node: Deletes a node with a specific value
    def delete_node(self, val):
        if self.head is None:
            print("List is empty! Cannot delete.")
            return

        temp = self.head

        # Case 1: If the node to be deleted is the head node
        if temp.data == val:
            self.head = temp.next
            if self.head is not None:
                self.head.prev = None
            print(f"Value {val} deleted successfully.")
            return

        # Traverse to find the node to delete
        while temp is not None and temp.data != val:
            temp = temp.next

        # Case 2: Value not found in the list
        if temp is None:
            print(f"Value {val} not found in the list!")
            return

        # Case 3: Node to be deleted is in the middle or at the end
        if temp.next is not None:
            temp.next.prev = temp.prev
            
        if temp.prev is not None:
            temp.prev.next = temp.next
            
        print(f"Value {val} deleted successfully.")

    # 3. Display Forward: Traverses from Head to Tail
    def display_forward(self):
        if self.head is None:
            print("List is empty!")
            return
        
        temp = self.head
        while temp is not None:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("None")

    # 4. Display Backward: Traverses from Tail to Head
    def display_backward(self):
        if self.head is None:
            print("List is empty!")
            return
        
        # Step 1: Go to the last node
        temp = self.head
        while temp.next is not None:
            temp = temp.next
            
        # Step 2: Traverse backward using prev pointers
        while temp is not None:
            print(temp.data, end=" <-> ")
            temp = temp.prev
        print("None")


# --- Main Driver Code ---
if __name__ == "__main__":
    dll = DoublyLinkedList()

    print("--- Inserting elements into Doubly Linked List ---")
    dll.insert_at_end(10)
    dll.insert_at_end(20)
    dll.insert_at_end(30)
    dll.insert_at_end(40)
    
    print("Forward Display: ", end="")
    dll.display_forward()

    print("Backward Display: ", end="")
    dll.display_backward()

    print("\n--- Deleting node 30 ---")
    dll.delete_node(30)

    print("Updated Forward Display: ", end="")
    dll.display_forward()