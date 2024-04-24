#include <iostream>
#include <queue>

using namespace std;

struct Process
{
    int id, arrivalTime, burstTime, completionTime, turnaroundTime, waitingTime;
};

void roundRobin(Process processes[], int n, int timeQuantum)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = processes[i].burstTime;
    }

    int currentTime = 0;

    while (true)
    {
        bool allProcessesDone = true;

        for (int i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0 && processes[i].arrivalTime <= currentTime)
            {
                allProcessesDone = false;

                if (remainingTime[i] <= timeQuantum)
                {
                    currentTime += remainingTime[i];
                    processes[i].completionTime = currentTime;
                    remainingTime[i] = 0;
                }
                else
                {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }

                cout << "Process " << processes[i].id << " executed at time " << currentTime << endl;
            }
        }

        if (allProcessesDone)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        // calcultate turn around time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        // calculate waiting time
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

void enterData(Process processes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << processes[i].id << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
    }
}

int main()
{
    int n, timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];

    enterData(processes, n);

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    roundRobin(processes, n, timeQuantum);
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime
             << "\t\t" << processes[i].completionTime << "\t\t" << processes[i].turnaroundTime << "\t\t" << processes[i].waitingTime << endl;
    }
  return 0;
}