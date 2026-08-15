# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Circular Linked List Class
class CircularLinkedList:
    def __init__(self):
        self.head = None

    # End में Insert करने का मेथड
    def insert_at_end(self, data):
        new_node = Node(data)
        
        # अगर लिस्ट खाली है
        if self.head is None:
            self.head = new_node
            new_node.next = self.head  # Points to itself
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next
            
        temp.next = new_node
        new_node.next = self.head  # Complete the circle

    # Display Method
    def display(self):
        if self.head is None:
            print("CLL is empty.")
            return

        temp = self.head
        print("CLL: ", end="")
        while True:
            print(f"[{temp.data}] -> ", end="")
            temp = temp.next
            if temp == self.head:
                break
        print("(Back to Head)")

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON CIRCULAR LINKED LIST (CLL) DEMO ===")
    
    cll = CircularLinkedList()
    cll.insert_at_end(10)
    cll.insert_at_end(20)
    cll.insert_at_end(30)
    cll.insert_at_end(40)
    
    print("\n--- Displaying Circular Linked List ---")
    cll.display()