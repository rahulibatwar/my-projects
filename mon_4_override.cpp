#include <iostream>
#include <string>

class StandardComputeInstance {
public:
    void provisionHardwareAllocations() {
        std::cout << "📟 [COMPUTE] Initiating standard vanilla hardware boot...\n";
        std::cout << "💾 Memory Allocation: 4GB Dynamic RAM Assigned.\n";
        std::cout << "🎛️ CPU Cores Allocated: 2 vCPU HyperThread Enabled.\n";
    }
};

class MissionCriticalServer : public StandardComputeInstance {
public:
    // Overriding the base class method completely
    void provisionHardwareAllocations() {
        std::cout << "==================================================\n";
        std::cout << "🚀 [ENTERPRISE OVERRIDE] INITIALIZING HIGH-COMPUTE ENGINE\n";
        std::cout << "==================================================\n";
        std::cout << "⚠️ Warning: Standard Vanilla Provisioning Interrupted!\n";
        std::cout << "🔥 Booting up High Performance Computing Tier.\n";
        std::cout << "💾 Upgraded Memory Allocation: 128GB Solid ECC Server RAM Assigned.\n";
        std::cout << "🎛️ Upgraded CPU Cores Allocated: 64 Core Dedicated Bare-Metal Unit.\n";
        std::cout << "🔒 Hardware Level Isolated Isolation Guard: ACTIVE\n";
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    MissionCriticalServer prodServer;
    
    // This will invoke the overridden child method at compile-time resolution
    prodServer.provisionHardwareAllocations();
    return 0;
}