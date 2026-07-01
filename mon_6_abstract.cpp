#include <iostream>
#include <string>

// Abstract Base Class (Cannot create its direct object)
class CloudBackupVault {
public:
    // Pure Virtual Function
    virtual void executeDataBackup() = 0;
    
    void printSystemLog() {
        std::cout << "📋 [SYSTEM LOG] Initializing core abstract storage protocol...\n";
    }
};

// Derived Class enforcing the contract
class RegionalBackupNode : public CloudBackupVault {
public:
    std::string regionName;
    long long allocatedStorageBytes;

    // Overriding the pure virtual function mandatory contract
    void executeDataBackup() override {
        std::cout << "==================================================\n";
        std::cout << "💾 [ABSTRACT ENGINE] EXECUTING SECURE COLD STORAGE BACKUP\n";
        std::cout << "==================================================\n";
        std::cout << "🌍 Target Cloud Region : " << regionName << "\n";
        
        long long storageInGB = allocatedStorageBytes / (1024 * 1024 * 1024);
        std::cout << "📦 Provisioned Capacity: " << storageInGB << " GB Distributed Array\n";
        std::cout << "🔒 Cryptographic Lock : SHA-256 Cloud Checksum Verified\n";
        std::cout << "✅ BACKUP LIFECYCLE COMPLETED SUCCESSFULLY\n";
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    RegionalBackupNode disasterRecovery;
    disasterRecovery.regionName = "Europe-West-Frankfurt-DR";
    disasterRecovery.allocatedStorageBytes = 536870912000LL; // 500 GB in bytes
    
    // Base class pointer pointing to child object
    CloudBackupVault* vaultPointer = &disasterRecovery;
    
    vaultPointer->printSystemLog();
    vaultPointer->executeDataBackup();
    
    return 0;
}