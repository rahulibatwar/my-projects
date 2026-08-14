# Node Class for Doubly Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

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
        new_node.prev = temp

    # Reverse DLL Method (Swapping prev and next pointers)
    def reverse(self):
        temp = None
        curr = self.head

        if curr is None:
            print("List is empty.")
            return

        # Swap prev and next for all nodes
        while curr:
            temp = curr.prev
            curr.prev = curr.next
            curr.next = temp
            curr = curr.prev  # Move to next node (which is now curr.prev)

        # Before changing head, check if the list was not empty or had only 1 node
        if temp:
            self.head = temp.prev
        
        print("\n[+] Doubly Linked List reversed successfully!")

    # Linked List डिस्प्ले करने का मेथड
    def display(self):
        if self.head is None:
            print("DLL: Empty")
            return
        
        temp = self.head
        print("DLL: ", end="")
        while temp:
            print(f"[{temp.data}] <-> ", end="")
            temp = temp.next
        print("None")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON DLL REVERSE DEMO ===")
    
    dll = DoublyLinkedList()
    dll.insert_at_end(10)
    dll.insert_at_end(20)
    dll.insert_at_end(30)
    dll.insert_at_end(40)
    
    print("\n--- Original List ---")
    dll.display()
    
    # Reversing DLL
    dll.reverse()
    
    print("--- Reversed List ---")
    dll.display()