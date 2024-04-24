#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void calculateTimes(Process &process, int &currentTime) {
    process.completionTime = currentTime + process.burstTime;
    process.turnaroundTime = process.completionTime - process.arrivalTime;
    process.waitingTime = process.turnaroundTime - process.burstTime;
    currentTime = process.completionTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    sort(processes.begin()+1, processes.end(), [](const Process &a, const Process &b) {
        return a.burstTime < b.burstTime;
    });

    int currentTime = 1;

    for (int i = 0; i < n; ++i) {
        calculateTimes(processes[i], currentTime);
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const auto &process : processes) {
        cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.burstTime
             << "\t\t" << process.completionTime << "\t\t" << process.turnaroundTime
             << "\t\t" << process.waitingTime << "\n";
    }

 return  0;
}