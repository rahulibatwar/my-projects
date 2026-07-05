#include <iostream>
#include <vector>
#include <numeric> // Sabse zaroori header aaj ke liye!

using namespace std;

int main() {
    cout << "=== ENTERPRISE BANDWIDTH BILLING ENGINE (STL Accumulate) ===" << endl;

    // Alag-alag cloud data centers ka network data consumption logs (in GB)
    vector<int> bandwidthUsageGB = {120, 450, 310, 89, 215};

    cout << "[TELEMETRY] Captured data consumption from " << bandwidthUsageGB.size() << " cloud nodes.\n\n";

    // std::accumulate(start, end, initial_sum_value)
    // Yeh pure vector ke numbers ko aapas mein jod dega. Teesra parameter '0' shuruati value (initial sum) hai.
    int totalUsage = accumulate(bandwidthUsageGB.begin(), bandwidthUsageGB.end(), 0);

    cout << "[PROCESSING] Summing up total infrastructure usage...\n";
    cout << "---------------------------------------------------------\n";
    cout << "  -> Total Cloud Bandwidth Consumed: " << totalUsage << " GB\n";
    cout << "---------------------------------------------------------\n\n";

    // Billing logic based on total aggregated sum
    int costPerGB = 2; // ₹2 per GB cloud cost
    cout << "[BILLING] Estimated Infrastructure Cost: ₹" << totalUsage * costPerGB << "\n";
    cout << "---------------------------------------------------------\n";

    return 0;
}