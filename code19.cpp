#include <iostream>
#include <vector>
#include <algorithm> // Iske andar std::count library milti hai
#include <string>

using namespace std;

int main() {
    cout << "=== ENTERPRISE LOG INCIDENT COUNTER (STL Count) ===" << endl;

    // Server telemetry se nikale gaye status tags ki list
    vector<string> securityLogs = {"INFO", "WARN", "ERROR", "INFO", "ERROR", "INFO", "ERROR", "WARN"};

    cout << "[INITIALIZED] Total active log entries fetched: " << securityLogs.size() << "\n\n";

    // std::count(start, end, target_value)
    // Yeh pure vector mein scan karega ki "ERROR" shabd kitni baar aaya hai
    int errorCount = count(securityLogs.begin(), securityLogs.end(), "ERROR");
    int warnCount = count(securityLogs.begin(), securityLogs.end(), "WARN");

    cout << "[AUDIT RUNNING] Scanning infrastructure database logs...\n";
    cout << "---------------------------------------------------------\n";
    cout << "  -> Total [WARN] Incidents Found  : " << warnCount << "\n";
    cout << "  -> Total [ERROR] Critical Breaches: " << errorCount << "\n";
    cout << "---------------------------------------------------------\n\n";

    // Breach count ke basis par automatic mitigation trigger karna
    if (errorCount > 2) {
        cout << "[CRITICAL ALERT] Security breach threshold exceeded!\n";
        cout << "                 Triggering automated DevSecOps patch protocol...\n";
    } else {
        cout << "[STATUS] System firewall and server cluster health is stable.\n";
    }

    cout << "---------------------------------------------------------\n";
    return 0;
}