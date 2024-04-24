#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void fcfs(vector<int> requests, int head) {
    int total_movement = 0;
    int current_position = head;

    cout << "Sequence of disk accesses:\n";
    for (int i = 0; i < requests.size(); ++i) {
        cout << current_position << " -> ";
        total_movement += abs(requests[i] - current_position);
        current_position = requests[i];
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

    fcfs(requests, head);

    return 0;
}
