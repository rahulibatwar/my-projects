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

    # Delete from Beginning (शुरुआत से हटाना)
    def delete_from_beginning(self):
        if self.head is None:
            print("[!] List is empty! Nothing to delete.")
            return
        
        deleted_value = self.head.data
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None
        
        print(f"[-] Deleted {deleted_value} from the beginning.")

    # Delete from End (अंत से हटाना)
    def delete_from_end(self):
        if self.head is None:
            print("[!] List is empty! Nothing to delete.")
            return
        
        if self.head.next is None:
            deleted_value = self.head.data
            self.head = None
            print(f"[-] Deleted {deleted_value} from the end.")
            return
        
        temp = self.head
        while temp.next:
            temp = temp.next
            
        deleted_value = temp.data
        temp.prev.next = None
        print(f"[-] Deleted {deleted_value} from the end.")

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
    print("=== PYTHON DLL DELETION DEMO ===")
    
    dll = DoublyLinkedList()
    dll.insert_at_end(10)
    dll.insert_at_end(20)
    dll.insert_at_end(30)
    dll.insert_at_end(40)
    
    print("\n--- Initial List ---")
    dll.display()
    
    print("\n--- Deleting from Beginning ---")
    dll.delete_from_beginning()
    dll.display()
    
    print("\n--- Deleting from End ---")
    dll.delete_from_end()
    dll.display()