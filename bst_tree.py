# Node Class: Represents a single tree element
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# BST Class: Handles insertion and in-order traversal
class BinarySearchTree:
    def __init__(self):
        self.root = None

    # 1. Insert Operation: Adds a value to its correct BST position
    def insert(self, val):
        if self.root is None:
            self.root = TreeNode(val)
            print(f"Inserted root element: {val}")
        else:
            self._insert_recursive(self.root, val)

    def _insert_recursive(self, current_node, val):
        if val < current_node.data:
            if current_node.left is None:
                current_node.left = TreeNode(val)
                print(f"Inserted {val} to the left of {current_node.data}")
            else:
                self._insert_recursive(current_node.left, val)
        else:
            if current_node.right is None:
                current_node.right = TreeNode(val)
                print(f"Inserted {val} to the right of {current_node.data}")
            else:
                self._insert_recursive(current_node.right, val)

    # 2. In-Order Traversal: Prints elements in sorted order (Left -> Root -> Right)
    def display_in_order(self):
        if self.root is None:
            print("Tree is empty!")
            return
        
        print("In-Order Traversal (Sorted): ", end="")
        self._in_order_recursive(self.root)
        print("None")

    def _in_order_recursive(self, current_node):
        if current_node is not None:
            self._in_order_recursive(current_node.left)
            print(f"{current_node.data} -> ", end="")
            self._in_order_recursive(current_node.right)


# --- Main Driver Code ---
if __name__ == "__main__":
    bst = BinarySearchTree()

    print("--- Building the Binary Search Tree ---")
    bst.insert(50)
    bst.insert(30)
    bst.insert(70)
    bst.insert(20)
    bst.insert(40)
    
    print("\n--- Displaying Tree Structure ---")
    bst.display_in_order()