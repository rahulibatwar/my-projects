# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # C++ के NULL की जगह None इस्तेमाल होता है

# Singly Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None

    # End में Insert करने का मेथड
    def insert_at_end(self, data):
        new_node = Node(data)
        
        # अगर लिस्ट खाली है
        if self.head is None:
            self.head = new_node
            print(f"[+] Inserted {data} as Head.")
            return

        # आख़िरी node तक Traverse करें
        temp = self.head
        while temp.next:
            temp = temp.next
            
        temp.next = new_node
        print(f"[+] Inserted {data} at the end.")

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
    print("=== PYTHON SINGLY LINKED LIST DEMO ===")
    
    ll = LinkedList()
    
    # Elements इंसर्ट करना
    ll.insert_at_end(10)
    ll.insert_at_end(20)
    ll.insert_at_end(30)
    
    # Display करना
    print("\n--- Final List ---")
    ll.display()