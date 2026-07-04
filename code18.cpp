#include <iostream>
#include <vector>
#include <algorithm> // Iske andar std::min_element aur std::max_element hain

using namespace std;

int main() {
    cout << "=== ENTERPRISE CLOUD RESOURCE MONITOR (Min/Max Metrics) ===" << endl;

    // Ek server ke pure din ki CPU Utilization % logs (Hourly Telemetry)
    vector<int> cpuLoadMetrics = {42, 15, 88, 95, 34, 12, 76, 61};

    cout << "[INITIALIZED] Telemetry data loaded with " << cpuLoadMetrics.size() << " data points.\n\n";

    // 1. std::min_element se sabse low load dhoondna
    // Yeh function ek iterator (pointer) return karta hai, isiliye value ke liye '*' use karte hain
    auto minIt = min_element(cpuLoadMetrics.begin(), cpuLoadMetrics.end());
    cout << "[OPTIMIZER] Minimum CPU Load Detected: " << *minIt << "%\n";
    cout << "            System was running efficiently at this point.\n\n";

    // 2. std::max_element se peak load dhoondna
    auto maxIt = max_element(cpuLoadMetrics.begin(), cpuLoadMetrics.end());
    cout << "[WARNING] Peak CPU Load Detected: " << *maxIt << "%\n";
    
    // Agar load 90% se upar hai toh alert trigger karo
    if (*maxIt > 90) {
        cout << "          [ALERT] Server reached CRITICAL peak load! Scaling up resources...\n";
    }
    
    cout << "---------------------------------------------------------\n";
    return 0;
}