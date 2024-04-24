#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<limits.h>
using namespace std;

// Function to find page faults using LRU
int findPageFaults(vector<int> pages, int capacity) {
    vector<int> frame;
    unordered_map<int, int> indexes;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); i++) {
        // Check if the page is already present in the frame
        auto it = find(frame.begin(), frame.end(), pages[i]);
        
        // If not present, put the page into the frame
        if (it == frame.end()) {
            // If the frame is not full, simply add the page
            if (frame.size() < capacity) {
                frame.push_back(pages[i]);
                page_faults++;
            }
            // If the frame is full, find the least recently used page
            // Replace it with the current page
            else {
                int lru = INT_MAX, replace_page;
                for (int j = 0; j < frame.size(); j++) {
                    if (indexes[frame[j]] < lru) {
                        lru = indexes[frame[j]];
                        replace_page = j;
                    }
                }
                indexes[frame[replace_page]] = INT_MAX;
                frame[replace_page] = pages[i];
                page_faults++;
            }
        }
        // Update index of the used page
        indexes[pages[i]] = i;
    }
    return page_faults;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Reference string
    int capacity = 4; // Number of frames

    int page_faults = findPageFaults(pages, capacity);
    
    cout << "Total page faults using LRU: " << page_faults << endl;

    return 0;
}
