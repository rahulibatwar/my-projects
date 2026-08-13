# Node Class for Doubly Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None  # Pointer to previous node
        self.next = None  # Pointer to next node

# Doubly Linked List Class
class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # End में Insert करने का मेथड
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        
        temp = self.head
        while temp.next:
            temp = temp.next
            
        temp.next = new_node
        new_node.prev = temp  # Link back to previous node

    # Forward Traversing (आगे से पीछे डिस्प्ले करना)
    def display_forward(self):
        if self.head is None:
            print("List is empty.")
            return None
        
        temp = self.head
        last_node = None
        print("Forward:  ", end="")
        while temp:
            print(f"[{temp.data}] <-> ", end="")
            if temp.next is None:
                last_node = temp
            temp = temp.next
        print("None")
        return last_node

    # Backward Traversing (पीछे से आगे डिस्प्ले करना)
    def display_backward(self, last_node):
        if last_node is None:
            print("List is empty.")
            return
        
        temp = last_node
        print("Backward: ", end="")
        while temp:
            print(f"[{temp.data}] <-> ", end="")
            temp = temp.prev
        print("None")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON DOUBLY LINKED LIST (DLL) DEMO ===")
    
    dll = DoublyLinkedList()
    dll.insert_at_end(10)
    dll.insert_at_end(20)
    dll.insert_at_end(30)
    dll.insert_at_end(40)
    
    print("\n--- Traversing Forward ---")
    last = dll.display_forward()
    
    print("\n--- Traversing Backward ---")
    dll.display_backward(last)