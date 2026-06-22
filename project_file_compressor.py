import heapq
from collections import Counter

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Defining comparators for priority queue
    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
    # Count frequency of each character
    frequency = Counter(text)
    
    # Create a min-heap priority queue
    heap = [HuffmanNode(char, freq) for char, freq in frequency.items()]
    heapq.heapify(heap)
    
    # Iterate until only one node remains in the heap
    while len(heap) > 1:
        node1 = heapq.heappop(heap)
        node2 = heapq.heappop(heap)
        
        merged = HuffmanNode(None, node1.freq + node2.freq)
        merged.left = node1
        merged.right = node2
        
        heapq.heappush(heap, merged)
        
    return heap[0] if heap else None

def generate_codes(root, current_code, huffman_codes):
    if root is None:
        return
    
    # If it's a leaf node (contains character)
    if root.char is not None:
        huffman_codes[root.char] = current_code
        return
        
    generate_codes(root.left, current_code + "0", huffman_codes)
    generate_codes(root.right, current_code + "1", huffman_codes)

def main():
    print("=" * 50)
    print("      AI Data Compression Engine (Huffman)       ")
    print("=" * 50)
    
    print("\nEnter the data/sentence you want to compress:")
    text_input = input("👉 ").strip()
    
    if not text_input:
        print("Empty string! Exiting.")
        return
        
    # Build Tree and Generate Codes
    root = build_huffman_tree(text_input)
    huffman_codes = {}
    generate_codes(root, "", huffman_codes)
    
    # Compress the input text
    compressed_binary = "".join([huffman_codes[char] for char in text_input])
    
    # Calculate Bit Savings
    original_bits = len(text_input) * 8
    compressed_bits = len(compressed_binary)
    savings = ((original_bits - compressed_bits) / original_bits) * 100
    
    print("\n" + "-"*40)
    print("⚡ COMPRESSION ENGINE RESULTS ⚡")
    print("-"*40)
    print("Character Encoded Formats:")
    for char, code in sorted(huffman_codes.items(), key=lambda x: len(x[1])):
        char_display = f"'{char}'" if char != " " else "'Space'"
        print(f"  {char_display} -> Binary Bit Route: {code}")
        
    print("\nStorage Metric Analysis:")
    print(f"  Uncompressed Size : {original_bits} bits (Assuming standard 8-bit ASCII)")
    print(f"  Huffman Compressed : {compressed_bits} bits")
    print(f"  Net Storage Saved  : {savings:.2f}% reduction in size!")
    print("-"*40)
    print(f"Compressed Bit Stream Output:\n{compressed_binary}\n")

if __name__ == "__main__":
    main()