#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    cout << "--- ENTERPRISE DNS ROUTING ENGINE ---" << endl;

    // Ek map banaya: Key (Domain Name) -> Value (IP Address)
    map<string, string> dnsCache;

    // 1. Map ke andar records insert karna
    dnsCache["google.com"] = "142.250.190.46";
    dnsCache["github.com"] = "140.82.121.4";
    dnsCache["stackoverflow.com"] = "151.101.129.69";

    cout << "[INITIALIZED] DNS Cache loaded with " << dnsCache.size() << " records.\n\n";

    // 2. Saare active routes ko display karna (Map automatic keys ko alphabetically sort kar deta hai!)
    cout << "Listing Active DNS Routes:\n";
    for (auto const& [domain, ip] : dnsCache) {
        cout << "  -> " << domain << " maps to IP: [ " << ip << " ]\n";
    }
    cout << "-------------------------------------\n\n";

    // 3. Real-Time DNS Lookup (Searching a Key)
    string searchDomain = "github.com";
    cout << "[LOOKUP] Searching IP for domain: " << searchDomain << "...\n";

    auto it = dnsCache.find(searchDomain);
    if (it != dnsCache.end()) {
        cout << "[SUCCESS] Route found! Directing traffic to: " << it->second << "\n\n";
    } else {
        cout << "[ERROR] 404 Route Not Found!\n\n";
    }

    // 4. Kisi record ko delete karna (Using Key)
    string expiredDomain = "stackoverflow.com";
    cout << "[MAINTENANCE] Removing expired domain: " << expiredDomain << "...\n";
    dnsCache.erase(expiredDomain);

    // 5. Updated Cache check karna
    cout << "\nUpdated DNS Cache:\n";
    for (auto const& [domain, ip] : dnsCache) {
        cout << "  -> " << domain << " maps to IP: [ " << ip << " ]\n";
    }
    cout << "-------------------------------------\n";

    return 0;
}