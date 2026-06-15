#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Huffman Tree ka Node structure
struct MinHeapNode {
    char data;             // Character (e.g., 'a', 'b')
    unsigned freq;         // Frequency
    MinHeapNode *left, *right; // Left aur Right child pointers

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Priority Queue ke liye custom comparator structure
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq); // Min-Heap banane ke liye
    }
};

// Tree ko traverse karke binary codes print karne ka function
void printCodes(MinHeapNode* root, string str) {
    if (!root) return;

    // Agar leaf node hai (yaani core character hai)
    if (root->data != '$') {
        cout << root->data << " : " << str << endl;
    }

    // Left jaane par '0' add karein, Right jaane par '1'
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(vector<char>& data, vector<int>& freq, int size) {
    MinHeapNode *left, *right, *top;

    // 1. Min-Heap banayein aur saare characters ko insert karein (Greedy Base)
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    // 2. Loop jab tak chalega jab tak heap mein sirf 1 root node na bache
    while (minHeap.size() != 1) {
        // Sabse kam frequency wale do nodes nikaalein
        left = minHeap.top(); minHeap.pop();
        right = minHeap.top(); minHeap.pop();

        // Ek naya internal node banayein jiska weight dono ke sum ke barabar ho
        // '$' ek dummy character hai internal nodes ke liye
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // 3. Final Huffman tree se codes print karein
    cout << "Generated Huffman Codes for Compression:" << endl;
    printCodes(minHeap.top(), "");
}

int main() {
    cout << "--- DSA Masterclass: Huffman Coding (Greedy Compression) ---" << endl << endl;

    vector<char> arr = { 'a', 'b', 'c', 'd', 'e', 'f' };
    vector<int> freq = { 5, 9, 12, 13, 16, 45 };
    int size = arr.size();

    HuffmanCodes(arr, freq, size);

    cout << "------------------------------------------------------------" << endl;
    return 0;
}