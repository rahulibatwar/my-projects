#include <iostream>
#include <string>

class CoreSecurityShield {
protected:
    int encryptionKeyLength;
    int baseThreatMitigationLevel;
public:
    // Constructor inside Protected Base Class
    CoreSecurityShield() {
        encryptionKeyLength = 256; // AES-256 Bit standard
        baseThreatMitigationLevel = 8;
    }
};

// CloudWAF inherits CoreSecurityShield
class CloudWAF : public CoreSecurityShield {
public:
    std::string deploymentEnvironment;

    void runDeepPacketInspection(int localizedThreatScore) {
        std::cout << "==================================================\n";
        std::cout << "🛡️ [SECURITY AUDIT] RUNNING DEEP PACKET INSPECTION\n";
        std::cout << "==================================================\n";
        std::cout << "🌐 Target Infrastructure : " << deploymentEnvironment << "\n";
        std::cout << "🔑 Cipher Encryption Key : " << encryptionKeyLength << " Bit AES Protected\n";
        
        int finalRiskAssessment = localizedThreatScore - baseThreatMitigationLevel;
        std::cout << "📉 Calculated Risk Score: " << finalRiskAssessment << " Metrics Point\n";
        
        if (finalRiskAssessment > 5) {
            std::cout << "❌ ALARM: THREAT LEVEL EXCEEDED SAFE STANDARDS! BLOCKING IP.\n";
        } else {
            std::cout << "✅ STATUS: SYSTEM SECURE. ALL TRAFFIC SIGNALS PASSED CLEAN.\n";
        }
        std::cout << "--------------------------------------------------\n";
    }
};

int main() {
    CloudWAF waf;
    waf.deploymentEnvironment = "Production-GoogleCloud-Cluster-B";
    
    // Simulating low risk traffic
    waf.runDeepPacketInspection(4);
    
    // Simulating dangerous malicious attack traffic
    waf.runDeepPacketInspection(15);
    return 0;
}