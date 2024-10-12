#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>>& intervals) {
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // Min-heap to track the end times of intervals
    priority_queue<int, vector<int>, greater<int>> pq;

    // Iterate through each interval
    for (const auto& interval : intervals) {
        int start = interval[0];
        int end = interval[1];

        // If the current interval starts after the earliest ending interval, remove the earliest
        if (!pq.empty() && pq.top() < start) {
            pq.pop();
        }

        // Add the current interval's end time to the heap
        pq.push(end);
    }

    // The size of the heap is the number of groups required
    return pq.size();
}

int main() {
    int n, a, b;
    cout << "Enter your array size: ";
    cin >> n;

    // Initialize the 2D vector of intervals
    vector<vector<int>> intervals(n, vector<int>(2));

    // Input each interval directly
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        intervals[i] = {a, b};
    }

    // Output the result of minGroups
    cout << "Minimum group is: " << minGroups(intervals) << endl;

    return 0;
}
