# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Singly Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None

    # Beginning (शुरुआत) में Insert करने का मेथड
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head  # Naya node puraane head ko point karega
        self.head = new_node       # Head ab naye node ko point karega
        print(f"[+] Inserted {data} at beginning.")

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
    print("=== PYTHON SLL INSERT AT BEGINNING DEMO ===")
    
    ll = LinkedList()
    
    # 30, 20, 10, 5 को एक-एक करके शुरुआत में इंसर्ट करेंगे
    ll.insert_at_beginning(30)
    ll.insert_at_beginning(20)
    ll.insert_at_beginning(10)
    ll.insert_at_beginning(5)
    
    print("\n--- Final List ---")
    ll.display()