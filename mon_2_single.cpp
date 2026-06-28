#include <iostream>
#include <string>

class NetworkNode {
public:
    std::string gatewayIP;
    std::string subnetMask;
    
    // Constructor inside Base Class
    NetworkNode() {
        gatewayIP = "192.168.10.1";
        subnetMask = "255.255.255.0";
    }
};

// SubnetRouter inherits NetworkNode
class SubnetRouter : public NetworkNode {
public:
    int totalConnectedDevices;
    long totalPacketsProcessed;

    void executeRoutingPipeline() {
        std::cout << "==================================================\n";
        std::cout << "🚦 [ROUTING ENGINE] EXECUTING SUBNET MANAGEMENT PUSH\n";
        std::cout << "==================================================\n";
        std::cout << "🔗 Active Gateway Target  : " << gatewayIP << "\n";
        std::cout << "🔏 Subnet Mask Security   : " << subnetMask << "\n";
        std::cout << "👥 Active Client Leases   : " << totalConnectedDevices << " Devices Connected\n";
        std::cout << "📦 Total Network Ingestion: " << totalPacketsProcessed << " Packets Synchronized\n";
        
        long averagePacketSize = 1500; // MTU size bytes
        long totalDataVolumeMB = (totalPacketsProcessed * averagePacketSize) / (1024 * 1024);
        std::cout << "💾 Total Data Volume Pushed: " << totalDataVolumeMB << " MB Processed Safely\n";
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    SubnetRouter router;
    router.totalConnectedDevices = 142;
    router.totalPacketsProcessed = 859402;
    
    router.executeRoutingPipeline();
    return 0;
}