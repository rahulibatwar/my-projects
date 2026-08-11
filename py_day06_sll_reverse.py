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

    # List को Reverse करने का मेथड
    def reverse(self):
        prev = None
        curr = self.head
        
        while curr:
            next_node = curr.next  # 1. Store next node
            curr.next = prev       # 2. Reverse current node pointer
            prev = curr            # 3. Move prev one step forward
            curr = next_node       # 4. Move curr one step forward
            
        self.head = prev  # Reset head to the new first node
        print("\n[+] Linked List reversed successfully!")

    # Linked List डिस्प्ले करने का मेथड
    def display(self):
        if self.head is None:
            print("List is empty.")
            return
        
        temp = self.head
        while temp:
            print(f"[{temp.data}] -> ", end="")
            temp = temp.next
        print("None")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON SLL REVERSE DEMO ===")
    
    ll = LinkedList()
    ll.insert_at_end(10)
    ll.insert_at_end(20)
    ll.insert_at_end(30)
    ll.insert_at_end(40)
    
    print("\n--- Original List ---")
    ll.display()
    
    # Reversing the list
    ll.reverse()
    
    print("--- Reversed List ---")
    ll.display()