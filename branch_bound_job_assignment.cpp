#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define N 4 // 4 Persons and 4 Jobs

int minTotalCost = INT_MAX;
vector<int> bestAssignment(N, -1);

// Utility function to find minimum cost allocation using Branch and Bound logic
void assignJobs(vector<vector<int>>& costMatrix, int person, int currentCost, vector<bool>& jobAssigned, vector<int>& currentAssignment) {
    // Base Case: If all persons are assigned a job
    if (person == N) {
        if (currentCost < minTotalCost) {
            minTotalCost = currentCost;
            bestAssignment = currentAssignment;
        }
        return;
    }

    // Branching: Try assigning every available job to the current person
    for (int job = 0; job < N; job++) {
        // If job is not yet assigned
        if (!jobAssigned[job]) {
            
            // BOUND: Skip this branch if the cost already exceeds our minimum found cost
            if (currentCost + costMatrix[person][job] < minTotalCost) {
                
                jobAssigned[job] = true;
                currentAssignment[person] = job;

                // Move to next person
                assignJobs(costMatrix, person + 1, currentCost + costMatrix[person][job], jobAssigned, currentAssignment);

                // Backtrack / Unbind branch
                jobAssigned[job] = false;
                currentAssignment[person] = -1;
            }
        }
    }
}

int main() {
    cout << "--- DSA Masterclass: Job Assignment using Branch & Bound (C++) ---" << endl << endl;

    // Row = Person, Column = Job Cost
    vector<vector<int>> costMatrix = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    vector<bool> jobAssigned(N, false);
    vector<int> currentAssignment(N, -1);

    assignJobs(costMatrix, 0, 0, jobAssigned, currentAssignment);

    cout << "Optimal Job Allocation Mapping:" << endl;
    cout << "---------------------------------" << endl;
    for (int i = 0; i < N; i++) {
        cout << "  Person " << i << " -> assigned to Job " << bestAssignment[i] 
             << " (Cost: " << costMatrix[i][bestAssignment[i]] << ")" << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "Minimum Total Safe Cost: " << minTotalCost << endl;

    return 0;
}