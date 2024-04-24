#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to perform FCFS scheduling
void fcfs(vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;

    // Sort processes based on arrival time (if not already sorted)
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Calculate completion time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;

        // If the process arrives after the current time, wait for it to arrive
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        // Update completion time
        processes[i].completionTime = currentTime + processes[i].burstTime;

        // Update turnaround time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        // Move to the completion time of the current process
        currentTime = processes[i].completionTime;
    }

    // Display the order of execution, completion time, and turnaround time for each process
    cout << "Order of Execution: ";
    for (const Process& p : processes) {
        cout << "P" << p.id << " ";
    }
    cout << "\nCompletion Time and Turnaround Time for each process:\n";
    for (const Process& p : processes) {
        cout << "P" << p.id << ": CT = " << p.completionTime << ", TAT = " << p.turnaroundTime << " ,  WAT = "<<p.waitingTime<<endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input arrival time and burst time for each process
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "P" << processes[i].id << " Arrival Time: ";
        cin >> processes[i].arrivalTime;
        cout << "P" << processes[i].id << " Burst Time: ";
        cin >> processes[i].burstTime;
    }

    fcfs(processes);

    return 0;
}
