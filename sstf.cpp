#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int findClosestRequest(const vector<int>& requests, int current_position, vector<bool>& visited) {
    int min_distance = INT_MAX;
    int index = -1;

    for (int i = 0; i < requests.size(); ++i) {
        if (!visited[i]) {
            int distance = abs(requests[i] - current_position);
            if (distance < min_distance) {
                min_distance = distance;
                index = i;
            }
        }
    }

    return index;
}

void sstf(vector<int> requests, int head) {
    int total_movement = 0;
    int current_position = head;
    vector<bool> visited(requests.size(), false);

    cout << "Sequence of disk accesses:\n";
    for (int i = 0; i < requests.size(); ++i) {
        int closest_index = findClosestRequest(requests, current_position, visited);
        cout << current_position << " -> ";
        total_movement += abs(requests[closest_index] - current_position);
        current_position = requests[closest_index];
        visited[closest_index] = true;
    }
    cout << endl;

    cout << "Total head movement: " << total_movement << endl;
}

int main() {
    vector<int> requests;
    int n, head;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    cout << "Enter the initial position of the head: ";
    cin >> head;

    cout << "Enter the disk request sequence:\n";
    for (int i = 0; i < n; ++i) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    sstf(requests, head);

    return 0;
}
