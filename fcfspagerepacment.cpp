#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find page faults using FIFO
int findPageFaults(vector<int> pages, int capacity) {
    vector<int> frame(capacity, -1); // Initialize all frames to -1
    int page_faults = 0;
    int pointer = 0; // To store the index of the page to be replaced

    for (int i = 0; i < pages.size(); i++) {
        // Check if the page is already present in the frame
        auto it = find(frame.begin(), frame.end(), pages[i]);
        
        // If not present, put the page into the frame
        if (it == frame.end()) {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % capacity;
            page_faults++;
        }
    }
    return page_faults;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Reference string
    int capacity = 4; // Number of frames

    int page_faults = findPageFaults(pages, capacity);
    
    cout << "Total page faults using FCFS: " << page_faults << endl;

    return 0;
}
