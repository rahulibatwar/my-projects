# Node Class: Stores the data and the pointer to the next element below it
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Stack Class: Handles LIFO operations
class Stack:
    def __init__(self):
        self.top = None
        self._size = 0

    # 1. Push: Add an element to the top of the stack
    def push(self, val):
        new_node = Node(val)
        new_node.next = self.top
        self.top = new_node
        self._size += 1
        print(f"Pushed {val} onto the stack.")

    # 2. Pop: Remove and return the top element of the stack
    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Cannot pop from an empty stack.")
            return None
        
        popped_value = self.top.data
        self.top = self.top.next
        self._size -= 1
        print(f"Popped {popped_value} from the stack.")
        return popped_value

    # 3. Peek: Return the top element without removing it
    def peek(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.top.data

    # 4. Is Empty: Check if the stack has no elements
    def is_empty(self):
        return self.top is None

    # 5. Size: Return the current number of elements in the stack
    def size(self):
        return self._size

    # 6. Display: Print the current stack elements from top to bottom
    def display(self):
        if self.is_empty():
            print("Stack is empty!")
            return
        
        temp = self.top
        print("Current Stack (Top -> Bottom):")
        while temp is not None:
            print(f"| {temp.data} |")
            temp = temp.next
        print(" ---- ")


# --- Main Driver Code ---
if __name__ == "__main__":
    my_stack = Stack()

    print("--- Push Operations ---")
    my_stack.push(10)
    my_stack.push(20)
    my_stack.push(30)
    
    print()
    my_stack.display()
    print(f"Top element (Peek): {my_stack.peek()}")
    print(f"Stack Size: {my_stack.size()}\n")

    print("--- Pop Operations ---")
    my_stack.pop()
    
    print()
    my_stack.display()
    print(f"Top element (Peek) after pop: {my_stack.peek()}")
    print(f"Stack Size: {my_stack.size()}")