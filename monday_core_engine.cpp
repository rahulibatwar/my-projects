#include <iostream>
#include <string>

class ServerNode {
private:
    // Private variables: Core architecture security data protection
    std::string serverName;
    int activeConnections;
    double memoryLoad;

public:
    // Constructor: Node initialize karne ke liye
    ServerNode(std::string name, double initialLoad) {
        serverName = name;
        activeConnections = 0;
        memoryLoad = initialLoad;
        std::cout << "🖥️ [System] Server Node '" << serverName << "' deployed successfully.\n";
    }

    // Setter Method: Connections badhane ke liye safe validation logic ke sath
    void addConnections(int count) {
        if (count > 0) {
            activeConnections += count;
            memoryLoad += (count * 1.8); // Hardware scaling simulation
            std::cout << "🚀 [Traffic] Connected " << count << " new clients to " << serverName << ".\n";
        }
    }

    // Getter Method: System telemetry data print karne ke liye
    void printHealthReport() {
        std::cout << "\n====================================\n";
        std::cout << "📊 SYSTEM HEALTH REPORT: " << serverName << "\n";
        std::cout << "====================================\n";
        std::cout << "Active Connections : " << activeConnections << "\n";
        std::cout << "Current Memory Load: " << memoryLoad << "%\n";
        
        if (memoryLoad > 80.0) {
            std::cout << "⚠️ STATUS          : CRITICAL DEGRADED PERFORMANCE\n";
        } else {
            std::cout << "🟢 STATUS          : OPTIMAL OPERATION\n";
        }
        std::cout << "====================================\n\n";
    }
};

int main() {
    // Instantiating the class object
    ServerNode clusterNode("Google-Cloud-Zone-A", 35.5);

    // Simulating real-time server traffic spikes
    clusterNode.addConnections(12);
    clusterNode.printHealthReport();

    clusterNode.addConnections(20); // High load testing scenario
    clusterNode.printHealthReport();

    return 0;
}