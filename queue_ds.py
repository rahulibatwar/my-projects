# Node Class: Stores the data and the pointer to the next element behind it
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Queue Class: Handles FIFO operations
class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self._size = 0

    # 1. Enqueue: Add an element to the rear of the queue
    def enqueue(self, val):
        new_node = Node(val)
        if self.is_empty():
            self.front = new_node
            self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node
        self._size += 1
        print(f"Enqueued {val} to the queue.")

    # 2. Dequeue: Remove and return the front element of the queue
    def dequeue(self):
        if self.is_empty():
            print("Queue Underflow! Cannot dequeue from an empty queue.")
            return None
        
        dequeued_val = self.front.data
        self.front = self.front.next
        
        # If the queue becomes empty after removing the element
        if self.front is None:
            self.rear = None
            
        self._size -= 1
        print(f"Dequeued {dequeued_val} from the queue.")
        return dequeued_val

    # 3. Get Front: Look at the front element without removing it
    def get_front(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        return self.front.data

    # 4. Is Empty: Check if the queue contains no elements
    def is_empty(self):
        return self.front is None

    # 5. Size: Return the total count of elements inside the queue
    def size(self):
        return self._size

    # 6. Display: Print the current queue elements from Front to Rear
    def display(self):
        if self.is_empty():
            print("Queue is empty!")
            return
        
        temp = self.front
        print("Current Queue: Front -> ", end="")
        while temp is not None:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("Rear")


# --- Main Driver Code ---
if __name__ == "__main__":
    my_queue = Queue()

    print("--- Enqueue Operations ---")
    my_queue.enqueue(10)
    my_queue.enqueue(20)
    my_queue.enqueue(30)
    
    print()
    my_queue.display()
    print(f"Front element: {my_queue.get_front()}")
    print(f"Queue Size: {my_queue.size()}\n")

    print("--- Dequeue Operations ---")
    my_queue.dequeue()
    
    print()
    my_queue.display()
    print(f"Front element after dequeue: {my_queue.get_front()}")
    print(f"Queue Size: {my_queue.size()}")