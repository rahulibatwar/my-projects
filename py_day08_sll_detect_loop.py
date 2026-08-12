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

    # Loop डिटेक्ट करने का मेथड
    def detect_loop(self):
        slow = self.head
        fast = self.head

        while fast and fast.next:
            slow = slow.next          # Move 1 step
            fast = fast.next.next     # Move 2 steps

            if slow == fast:
                print("[!] Loop detected in the Linked List!")
                return True

        print("[+] No loop found in the Linked List.")
        return False

# Main Execution
if __name__ == "__main__":
    print("=== PYTHON SLL DETECT LOOP DEMO ===")
    
    ll = LinkedList()
    ll.insert_at_end(10)
    ll.insert_at_end(20)
    ll.insert_at_end(30)
    ll.insert_at_end(40)
    
    # Test 1: Normal List without loop
    print("\n--- Test 1: Normal List ---")
    ll.detect_loop()
    
    # Test 2: Manually creating a loop for testing (40 -> 20)
    print("\n--- Test 2: Creating Artificial Loop (40 -> 20) ---")
    ll.head.next.next.next.next = ll.head.next  # Connecting node 40 to node 20
    
    # Checking for loop again
    ll.detect_loop()