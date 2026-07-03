#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Ek unique Notification Job structure banaya
struct NotificationJob {
    string recipient;  // Kisko bhejna hai
    string channel;    // Kaise bhejna hai (SMS, Email, Push Notification)
    string payload;    // Message ka content क्या है
};

int main() {
    cout << "=== ENTERPRISE MESSAGE BROKER CORE (STL Queue) ===" << endl;

    // NotificationJobs store karne ke liye ek FIFO queue banayi
    queue<NotificationJob> brokerQueue;

    // 1. Production servers ne queue mein 3 jobs incoming push kiye (FIFO Order)
    brokerQueue.push({"Rahul", "EMAIL", "Welcome to the Enterprise Architecture Track!"});
    brokerQueue.push({"Amit", "SMS", "Security Alert: Your OTP code is 9942."});
    brokerQueue.push({"Sneha", "PUSH", "New login detected from Pune, India."});

    cout << "[BROKER] Inbound pipeline initialized. " << brokerQueue.size() << " pending jobs in queue.\n\n";

    cout << "Starting Asynchronous Message Dispatcher:\n";
    cout << "---------------------------------------------------------\n";

    // 2. Queue se ek-ek karke FIFO order mein data process karna
    while (!brokerQueue.empty()) {
        // .front() humesha sabse PEHLE aaya hua element (line ka sabse aage wala) nikal kar deta hai
        NotificationJob currentJob = brokerQueue.front();

        cout << "  [DISPATCH] Routing [" << currentJob.channel << "] to User: " << currentJob.recipient << "\n";
        cout << "             Content: \"" << currentJob.payload << "\"\n\n";

        // Processing khatam hote hi line ke aage waale element ko hata (pop) dete hain
        brokerQueue.pop();
    }

    cout << "---------------------------------------------------------\n";
    cout << "[SUCCESS] Message broker pipeline completely cleared! All packets dispatched.\n";

    return 0;
}