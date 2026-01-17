#include <bits/stdc++.h>
using namespace std;
struct Job {
    int id, deadline, profit;
};
int main() {
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (auto &j : jobs) 
    maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int totalProfit = 0;
    for (auto &j : jobs) {
        for (int t = j.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }
    cout << "Final Job Sequence: ";
    for (int t = 1; t <= maxDeadline; t++) {
        if (slot[t] != -1)
            cout << "Job" << slot[t] << " ";
    }

    cout << "\nTotal Profit = " << totalProfit << endl;
    return 0;
}
