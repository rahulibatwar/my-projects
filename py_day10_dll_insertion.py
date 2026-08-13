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

    # Insert at Beginning (शुरुआत में जोड़ना)
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
        print(f"[+] Inserted {data} at the beginning.")

    # Insert at End (अंत में जोड़ना)
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
        print(f"[+] Inserted {data} at the end.")

    # Linked List डिस्प्ले करने का मेथड
    def display(self):
        if self.head is None:
            print("List is empty.")
            return
        
        temp = self.head
        print("DLL: ", end="")
        while temp:
            print(f"[{temp.data}] <-> ", end="")
            temp = temp.next
        print("None")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON DLL INSERTION DEMO ===")
    
    dll = DoublyLinkedList()
    
    # Inserting elements at the end
    dll.insert_at_end(20)
    dll.insert_at_end(30)
    dll.display()
    
    # Inserting elements at the beginning
    print("\n--- Inserting at Beginning ---")
    dll.insert_at_beginning(10)
    dll.insert_at_beginning(5)
    
    print("\n--- Final List ---")
    dll.display()