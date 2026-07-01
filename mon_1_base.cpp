#include <iostream>
#include <string>

class InfrastructureManager {
public:
    std::string dataCenterLocation;
    std::string clusterId;
    int totalRackCount;
    bool coolingSystemStatus;

    void bootClusterManager() {
        std::cout << "==================================================\n";
        std::cout << "🌐 [SYSTEM INITIALIZATION] STARTING BASE CORE ENGINE\n";
        std::cout << "==================================================\n";
        std::cout << "📍 Data Center Zone: " << dataCenterLocation << "\n";
        std::cout << "🆔 Cluster Identity : " << clusterId << "\n";
        std::cout << "🗄️ Total Server Racks: " << totalRackCount << " Units\n";
        
        if (coolingSystemStatus) {
            std::cout << "🟢 Thermal Regulation: OPTIMAL (Fans Running at 4500 RPM)\n";
        } else {
            std::cout << "⚠️ Thermal Regulation: CRITICAL SHUTDOWN WARNING\n";
        }
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    InfrastructureManager manager;
    manager.dataCenterLocation = "Asia-South-Mumbai-Zone-1";
    manager.clusterId = "MUM-PROD-CL-092A";
    manager.totalRackCount = 64;
    manager.coolingSystemStatus = true;
    
    manager.bootClusterManager();
    return 0;
}