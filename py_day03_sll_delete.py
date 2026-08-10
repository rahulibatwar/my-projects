# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Singly Linked List Class
class LinkedList:
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

    # Beginning (शुरुआत) से Delete करने का मेथड
    def delete_from_beginning(self):
        if self.head is None:
            print("[-] List is empty, nothing to delete.")
            return

        deleted_val = self.head.data
        self.head = self.head.next  # Head ko agle node par move kiya
        print(f"[-] Deleted {deleted_val} from beginning.")

    # Linked List डिस्प्ले करने का मेथड
    def display(self):
        if self.head is None:
            print("List is empty.")
            return
        
        temp = self.head
        print("Current List: ", end="")
        while temp:
            print(f"[{temp.data}] -> ", end="")
            temp = temp.next
        print("None")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON SLL DELETE FROM BEGINNING DEMO ===")
    
    ll = LinkedList()
    ll.insert_at_end(10)
    ll.insert_at_end(20)
    ll.insert_at_end(30)
    
    print("--- Initial List ---")
    ll.display()
    
    # Beginning से 1 node डिलीट करेंगे
    print("\n--- Deleting Head Element ---")
    ll.delete_from_beginning()
    
    print("\n--- List After Deletion ---")
    ll.display()