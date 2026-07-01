#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Job ka structure define karte hain
struct Job {
    char id;      // Job ka naam (A, B, C, D...)
    int deadline; // Job ki deadline
    int profit;   // Job ka profit
};

// Custom comparator: Jobs ko profit ke basis par sort karne ke liye
bool compareJobs(Job a, Job b) {
    return a.profit > b.profit; // Descending order (Mehengi job pehle)
}

void printJobScheduling(vector<Job>& jobs) {
    // 1. Profit ke hisab se sort karne ka step
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    
    // 2. Maximum deadline dhoondhein taaki slots array bana sakein
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Slots array: check karne ke liye ki kaunsa time unit empty hai
    // Shuruat mein -1 (matlab slot khali hai)
    vector<int> resultSlot(maxDeadline + 1, -1); 
    
    int totalProfit = 0;
    int countJobs = 0;

    // 3. Greedy tarike se har job ko slot allot karein
    for (int i = 0; i < n; i++) {
        // Job ko uski deadline se lekar piche ke slots tak check karein
        for (int j = jobs[i].deadline; j > 0; j--) {
            // Agar slot khali mil jaye
            if (resultSlot[j] == -1) {
                resultSlot[j] = i; // Is slot par ye job fix kar di
                totalProfit += jobs[i].profit;
                countJobs++;
                break; // Is job ka kaam ho gaya, khali slot milte hi break
            }
        }
    }

    // Output print karte hain
    cout << "Scheduled Jobs Sequence: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (resultSlot[i] != -1) {
            cout << jobs[resultSlot[i]].id << " ";
        }
    }
    cout << endl << "Total Jobs Done: " << countJobs << endl;
    cout << "Maximum Total Profit: RS " << totalProfit << endl;
}

int main() {
    cout << "--- DSA Masterclass: Job Sequencing Problem (Greedy) ---" << endl << endl;

    // Jobs list format: {ID, Deadline, Profit}
    vector<Job> jobs = {
        {'A', 4, 20},
        {'B', 1, 10},
        {'C', 1, 40},
        {'D', 1, 30}
    };

    printJobScheduling(jobs);

    cout << "--------------------------------------------------------" << endl;
    return 0;
}