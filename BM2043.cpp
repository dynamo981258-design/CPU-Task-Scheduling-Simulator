#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int priority;

    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

struct Segment {
    int pid;
    int start;
    int end;
};

vector<Process> processes;

void addProcess() {

    Process p;

    cout << "\nEnter Process ID: ";
    cin >> p.pid;

    for (const Process &x : processes) {
        if (x.pid == p.pid) {
            cout << "Process ID already exists!\n";
            return;
        }
    }

    cout << "Enter Burst Time: ";
    cin >> p.burstTime;

    if (p.burstTime <= 0) {
        cout << "Burst Time must be positive!\n";
        return;
    }

    cout << "Enter Priority (smaller number = higher priority): ";
    cin >> p.priority;

    p.completionTime = 0;
    p.waitingTime = 0;
    p.turnaroundTime = 0;

    processes.push_back(p);

    cout << "\nProcess Added Successfully!\n";
}

void displayProcesses() {

    if (processes.empty()) {
        cout << "\nNo processes available!\n";
        return;
    }

    cout << "\n-------- PROCESS LIST --------\n";

    cout << left
         << setw(10) << "PID"
         << setw(15) << "Burst Time"
         << setw(10) << "Priority" << endl;

    for (const Process &p : processes) {

        cout << left
             << setw(10) << p.pid
             << setw(15) << p.burstTime
             << setw(10) << p.priority << endl;
    }
}

void displayGanttChart(const vector<Segment> &chart) {

    cout << "\n-------- GANTT CHART --------\n";

    cout << " ";

    for (const Segment &s : chart) {
        cout << "|  P" << s.pid << "  ";
    }

    cout << "|\n";

    if (!chart.empty()) {

        cout << chart[0].start;

        for (const Segment &s : chart) {
            cout << setw(7) << s.end;
        }
    }

    cout << "\n";
}

void displayResults(const vector<Process> &p) {

    double totalWaiting = 0;
    double totalTurnaround = 0;

    cout << "\n-------- SCHEDULING RESULTS --------\n";

    cout << left
         << setw(10) << "PID"
         << setw(15) << "Burst"
         << setw(15) << "Completion"
         << setw(15) << "Waiting"
         << setw(15) << "Turnaround"
         << endl;

    for (const Process &x : p) {

        cout << left
             << setw(10) << x.pid
             << setw(15) << x.burstTime
             << setw(15) << x.completionTime
             << setw(15) << x.waitingTime
             << setw(15) << x.turnaroundTime
             << endl;

        totalWaiting += x.waitingTime;
        totalTurnaround += x.turnaroundTime;
    }

    cout << fixed << setprecision(2);

    cout << "\nAverage Waiting Time: "
         << totalWaiting / p.size();

    cout << "\nAverage Turnaround Time: "
         << totalTurnaround / p.size() << endl;
}

void fcfsScheduling() {

    if (processes.empty()) {
        cout << "\nNo processes available!\n";
        return;
    }

    vector<Process> p = processes;

    vector<Segment> chart;

    int currentTime = 0;

    for (int i = 0; i < p.size(); i++) {

        int startTime = currentTime;

        currentTime += p[i].burstTime;

        p[i].completionTime = currentTime;

        p[i].turnaroundTime = p[i].completionTime;

        p[i].waitingTime =
            p[i].turnaroundTime - p[i].burstTime;

        chart.push_back({
            p[i].pid,
            startTime,
            currentTime
        });
    }

    cout << "\n===== FCFS SCHEDULING =====\n";

    displayGanttChart(chart);

    displayResults(p);
}

void sjfScheduling() {

    if (processes.empty()) {
        cout << "\nNo processes available!\n";
        return;
    }

    vector<Process> p = processes;

    stable_sort(p.begin(), p.end(),
        [](const Process &a, const Process &b) {
            return a.burstTime < b.burstTime;
        });

    vector<Segment> chart;

    int currentTime = 0;

    for (int i = 0; i < p.size(); i++) {

        int startTime = currentTime;

        currentTime += p[i].burstTime;

        p[i].completionTime = currentTime;

        p[i].turnaroundTime = p[i].completionTime;

        p[i].waitingTime =
            p[i].turnaroundTime - p[i].burstTime;

        chart.push_back({
            p[i].pid,
            startTime,
            currentTime
        });
    }

    cout << "\n===== SJF SCHEDULING =====\n";

    displayGanttChart(chart);

    displayResults(p);
}

void priorityScheduling() {

    if (processes.empty()) {
        cout << "\nNo processes available!\n";
        return;
    }

    vector<Process> p = processes;

    stable_sort(p.begin(), p.end(),
        [](const Process &a, const Process &b) {
            return a.priority < b.priority;
        });

    vector<Segment> chart;

    int currentTime = 0;

    for (int i = 0; i < p.size(); i++) {

        int startTime = currentTime;

        currentTime += p[i].burstTime;

        p[i].completionTime = currentTime;

        p[i].turnaroundTime = p[i].completionTime;

        p[i].waitingTime =
            p[i].turnaroundTime - p[i].burstTime;

        chart.push_back({
            p[i].pid,
            startTime,
            currentTime
        });
    }

    cout << "\n===== PRIORITY SCHEDULING =====\n";

    displayGanttChart(chart);

    displayResults(p);
}

void roundRobinScheduling() {

    if (processes.empty()) {
        cout << "\nNo processes available!\n";
        return;
    }

    int quantum;

    cout << "\nEnter Time Quantum: ";
    cin >> quantum;

    if (quantum <= 0) {
        cout << "Time Quantum must be positive!\n";
        return;
    }

    vector<Process> p = processes;

    int n = p.size();

    vector<int> remainingTime(n);

    queue<int> q;

    vector<Segment> chart;

    int currentTime = 0;

    for (int i = 0; i < n; i++) {

        remainingTime[i] = p[i].burstTime;

        q.push(i);
    }

    while (!q.empty()) {

        int i = q.front();

        q.pop();

        int startTime = currentTime;

        int executionTime =
            min(quantum, remainingTime[i]);

        currentTime += executionTime;

        remainingTime[i] -= executionTime;

        chart.push_back({
            p[i].pid,
            startTime,
            currentTime
        });

        if (remainingTime[i] == 0) {

            p[i].completionTime = currentTime;

        }
        else {

            q.push(i);
        }
    }

    for (int i = 0; i < n; i++) {

        p[i].turnaroundTime = p[i].completionTime;

        p[i].waitingTime =
            p[i].turnaroundTime - p[i].burstTime;
    }

    cout << "\n===== ROUND ROBIN SCHEDULING =====\n";

    displayGanttChart(chart);

    displayResults(p);
}

int main() {

    int choice;

    do {

        cout << "\n================================\n";
        cout << "     CPU TASK SCHEDULING SIMULATOR\n";
        cout << "================================\n";

        cout << "1. Add Process\n";
        cout << "2. Display Processes\n";
        cout << "3. FCFS Scheduling\n";
        cout << "4. SJF Scheduling\n";
        cout << "5. Round Robin Scheduling\n";
        cout << "6. Priority Scheduling\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addProcess();
                break;

            case 2:
                displayProcesses();
                break;

            case 3:
                fcfsScheduling();
                break;

            case 4:
                sjfScheduling();
                break;

            case 5:
                roundRobinScheduling();
                break;

            case 6:
                priorityScheduling();
                break;

            case 7:
                cout << "\nThank You for Using CPU Scheduler!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}