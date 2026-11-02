CPU Scheduling Simulator

A menu-driven CPU Scheduling Simulator developed in C++ to demonstrate and compare different CPU scheduling algorithms used in operating systems.

The program allows users to add processes, execute scheduling algorithms, visualize execution order through Gantt charts, and calculate performance metrics.

Features

* Add processes with unique process IDs, burst times, and priorities.
* Display all entered processes.
* Implement four CPU scheduling algorithms.
* Display process execution order using text-based Gantt charts.
* Calculate completion time, waiting time, and turnaround time.
* Calculate average waiting time and average turnaround time.
* Execute multiple scheduling algorithms on the same set of processes.
* Interactive menu-driven interface.

Scheduling Algorithms

1. First Come First Served (FCFS)

* Non-preemptive scheduling algorithm.
* Processes execute in the order in which they are added.
* Each process runs until completion.

2. Shortest Job First (SJF)

* Non-preemptive scheduling algorithm.
* The process with the smallest burst time executes first.
* Processes with equal burst times retain their original order.

3. Round Robin (RR)

* Preemptive scheduling algorithm.
* Each process receives a fixed time quantum.
* Incomplete processes return to the end of the ready queue.
* Scheduling continues until every process finishes.

4. Priority Scheduling

* Non-preemptive scheduling algorithm.
* Processes execute according to their priority.
* A smaller priority number indicates higher priority.
* Processes with equal priorities retain their original order.

Technologies Used

* Language: C++
* Standard: C++11 or later
* Interface: Command-line interface
* Libraries: iostream, vector, queue, algorithm, iomanip

Data Structures Used

Data Structure	Purpose
Structure (struct)	Store process information and Gantt chart segments
Vector (vector)	Store processes and execution segments
Queue (queue)	Manage processes during Round Robin scheduling
Stable Sort (stable_sort)	Order processes by burst time or priority

How to Run

Requirements

A C++ compiler supporting C++11 or later, such as GCC or Clang.

Step 1: Clone the Repository

git clone https://github.com/dynamo981258-design/CPU-Task-Scheduling-Simulator

Step 2: Open the Project Directory

cd CPU-Scheduling-Simulator

Step 3: Compile

g++ -std=c++11 BM2043.cpp -o scheduler

Step 4: Execute

On macOS or Linux:

./scheduler

On Windows:

scheduler.exe

Program Menu

================================
 CPU TASK SCHEDULING SIMULATOR
================================
1. Add Process
2. Display Processes
3. FCFS Scheduling
4. SJF Scheduling
5. Round Robin Scheduling
6. Priority Scheduling
7. Exit

Example

Consider the following processes:

Process ID	Burst Time	Priority
P1	5	2
P2	3	1
P3	2	3

FCFS Scheduling

Execution order:

P1 -> P2 -> P3
0     5     8    10
| P1  | P2  | P3 |

Results:

PID	Completion Time	Waiting Time	Turnaround Time
P1	5	0	5
P2	8	5	8
P3	10	8	10

Average Waiting Time: 4.33 units

Average Turnaround Time: 7.67 units

Scheduling Formulas

Turnaround Time

Turnaround Time = Completion Time - Arrival Time

Waiting Time

Waiting Time = Turnaround Time - Burst Time

Average Waiting Time

Average Waiting Time = Total Waiting Time / Number of Processes

Average Turnaround Time

Average Turnaround Time = Total Turnaround Time / Number of Processes

Assumptions and Limitations

* All processes are assumed to arrive at time zero.
* FCFS uses the order in which processes are added.
* SJF and Priority Scheduling are non-preemptive.
* Round Robin uses a user-defined time quantum.
* Context-switching overhead is ignored.
* Process information is stored in memory during program execution.
* The program does not save process information between runs.

Future Improvements

* Support different arrival times.
* Implement preemptive SJF (Shortest Remaining Time First).
* Implement preemptive Priority Scheduling.
* Add response time calculations.
* Include a comparison of algorithm performance.

Project Objective

To understand CPU scheduling techniques, process execution order, and scheduling performance metrics through a simple C++ simulation.

Authors

Rohit and Shubham
