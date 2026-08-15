# Node Class for Circular Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Circular Linked List Class
class CircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert at Beginning (शुरुआत में जोड़ना)
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
            print(f"[+] Inserted {data} at the beginning.")
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next

        new_node.next = self.head
        temp.next = new_node
        self.head = new_node
        print(f"[+] Inserted {data} at the beginning.")

    # Insert at End (अंत में जोड़ना)
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
            print(f"[+] Inserted {data} at the end.")
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next

        temp.next = new_node
        new_node.next = self.head
        print(f"[+] Inserted {data} at the end.")

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
    print("=== PYTHON CLL INSERTION DEMO ===")
    
    cll = CircularLinkedList()
    
    # Inserting elements at end
    cll.insert_at_end(20)
    cll.insert_at_end(30)
    cll.display()
    
    # Inserting elements at beginning
    print("\n--- Inserting at Beginning ---")
    cll.insert_at_beginning(10)
    cll.insert_at_beginning(5)
    
    print("\n--- Final Circular Linked List ---")
    cll.display()