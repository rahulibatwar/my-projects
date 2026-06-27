#include <iostream>
#include <string>

class AdvancedServerNode {
private:
    std::string serverName;
    int* connectionHistory; // Pointer: Dynamic array ka address store karne ke liye
    int maxCapacity;
    int activeCount;

public:
    // Constructor: Heap par dynamic memory space allocate karne ke liye
    AdvancedServerNode(std::string name, int capacity) {
        serverName = name;
        maxCapacity = capacity;
        activeCount = 0;
        
        // Runtime par memory allocate ho rahi hai (Heap Space)
        connectionHistory = new int[maxCapacity]; 
        std::cout << "📦 [Heap Memory] Allocated buffer array of size " << maxCapacity << " for " << serverName << ".\n";
    }

    // Method: Inside allocated memory dynamic entry push karna
    void registerClientLog(int clientId) {
        if (activeCount < maxCapacity) {
            connectionHistory[activeCount] = clientId;
            activeCount++;
            std::cout << "🔗 [Register] Client ID " << clientId << " saved at index slot [" << activeCount - 1 << "].\n";
        } else {
            std::cout << "❌ [Memory Overflow] No available slots left in heap buffer!\n";
        }
    }

    // Destructor: Memory leakage se bachne ke liye cleanup logic
    ~AdvancedServerNode() {
        delete[] connectionHistory; // Freeing allocated heap space
        std::cout << "🗑️ [Destructor] Deallocated storage array. Memory leak successfully prevented for " << serverName << ".\n";
    }
};

int main() {
    std::cout << "🚀 STARTING DYNAMIC INFRASTRUCTURE SIMULATION\n\n";

    // Allocating the entire object dynamically on Heap
    AdvancedServerNode* edgeNode = new AdvancedServerNode("Google-Edge-Router", 3);

    // Simulating safe runtime data insertion
    edgeNode->registerClientLog(7001);
    edgeNode->registerClientLog(7002);
    edgeNode->registerClientLog(7003);
    
    // Overflow trigger check
    edgeNode->registerClientLog(7004); 

    std::cout << "\nShutting down microservice instance...\n";
    
    // Object delete hote hi destructor call hoga aur poori heap clear ho jayegi
    delete edgeNode; 

    return 0;
}