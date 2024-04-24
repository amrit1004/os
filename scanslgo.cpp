#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void scan(vector<int> requests, int head, int direction, int upper_bound, int lower_bound) {
    sort(requests.begin(), requests.end());

    int total_movement = 0;
    int current_position = head;

    if (direction == 0) { // Moving towards lower bound
        cout << "Sequence of disk accesses:\n";
        for (int i = head; i >= lower_bound; --i) {
            if (find(requests.begin(), requests.end(), i) != requests.end()) {
                cout << i << " -> ";
                total_movement += abs(i - current_position);
                current_position = i;
            }
        }

        cout << lower_bound << " -> ";
        total_movement += abs(lower_bound - current_position);
        current_position = lower_bound;

        for (int i = lower_bound + 1; i <= upper_bound; ++i) {
            if (find(requests.begin(), requests.end(), i) != requests.end()) {
                cout << i << " -> ";
                total_movement += abs(i - current_position);
                current_position = i;
            }
        }
    } else { // Moving towards upper bound
        cout << "Sequence of disk accesses:\n";
        for (int i = head; i <= upper_bound; ++i) {
            if (find(requests.begin(), requests.end(), i) != requests.end()) {
                cout << i << " -> ";
                total_movement += abs(i - current_position);
                current_position = i;
            }
        }

        cout << upper_bound << " -> ";
        total_movement += abs(upper_bound - current_position);
        current_position = upper_bound;

        for (int i = upper_bound - 1; i >= lower_bound; --i) {
            if (find(requests.begin(), requests.end(), i) != requests.end()) {
                cout << i << " -> ";
                total_movement += abs(i - current_position);
                current_position = i;
            }
        }
    }

    cout << endl;
    cout << "Total head movement: " << total_movement << endl;
}

int main() {
    vector<int> requests;
    int n, head, upper_bound, lower_bound, direction;

    cout << "Enter the number of disk requests: ";
    cin >> n;

    cout << "Enter the initial position of the head: ";
    cin >> head;

    cout << "Enter the upper bound of the disk: ";
    cin >> upper_bound;

    cout << "Enter the lower bound of the disk: ";
    cin >> lower_bound;

    cout << "Enter the direction of movement (0 for left, 1 for right): ";
    cin >> direction;

    cout << "Enter the disk request sequence:\n";
    for (int i = 0; i < n; ++i) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    scan(requests, head, direction, upper_bound, lower_bound);

    return 0;
}
    