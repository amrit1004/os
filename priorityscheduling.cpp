#include <iostream>
#include <vector>
#include <algorithm>
#include<iomanip>
using namespace std;

class Process {
public:
    int burst_time;
    int priority;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

bool compareArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

bool comparePriority(const Process& p1, const Process& p2) {
    return p1.priority > p2.priority;
}

void priorityScheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    for (Process& process : processes) {
        process.waiting_time = max(0, currentTime - process.arrival_time);
        process.completion_time = currentTime + process.burst_time;
        process.turnaround_time = process.completion_time - process.arrival_time;
        currentTime = process.completion_time;
    }

    sort(processes.begin(), processes.end(), comparePriority);
}

void displayResults(const vector<Process>& processes) {
    cout << setw(15) << left << "Completion Time" << setw(15) << "Waiting Time" << setw(15) << "Turnaround Time" << endl;
    for (const Process& process : processes) {
        cout << setw(15) << process.completion_time << setw(15) << process.waiting_time << setw(15) << process.turnaround_time << endl;
    }
}

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<Process> processes(numProcesses);

    for (int i = 0; i < numProcesses; ++i) {
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
        cout << "Enter Arrival Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrival_time;
        cout << "Enter Priority for Process " << i + 1 << ": ";
        cin >> processes[i].priority;
    }

    priorityScheduling(processes);
    displayResults(processes);

    return 0;
}
