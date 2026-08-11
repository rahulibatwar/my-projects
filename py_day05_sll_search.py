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

    # Search करने का मेथड
    def search(self, key):
        temp = self.head
        pos = 1
        while temp:
            if temp.data == key:
                print(f"[+] Element {key} found at position {pos}.")
                return True
            temp = temp.next
            pos += 1
        
        print(f"[-] Element {key} not found in the list.")
        return False

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
    print("=== PYTHON SLL SEARCH ELEMENT DEMO ===")
    
    ll = LinkedList()
    ll.insert_at_end(10)
    ll.insert_at_end(20)
    ll.insert_at_end(30)
    
    print("--- Current List ---")
    ll.display()
    
    print("\n--- Searching Operations ---")
    ll.search(20)  # मौजूद एलिमेंट
    ll.search(50)  # न मौजूद एलिमेंट