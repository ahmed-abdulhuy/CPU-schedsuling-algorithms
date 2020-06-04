// Implementation of FCFS scheduling using C++

#include<iostream> 
using namespace std; 

// Function to find the waiting time for processes 

void get_waiting_time(int processes[], int n, 
						int bt[], int wt[]) 
{ 
	// set the waiting time for first process to 0 
	wt[0] = 0; 

	// get waiting time 
	for (int i = 1; i < n ; i++ ) 
		wt[i] = bt[i-1] + wt[i-1] ; 
} 

// Function to calculate turn around time 
void get_turn_around_time( int processes[], int n, 
				int bt[], int wt[], int tat[]) 
{ 
	// get turnaround time by adding bt[i] + wt[i] 

	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

//Function to get average time 
void find_avg_Time( int processes[], int n, int bt[]) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 

	//Function to get waiting time of all processes 
	get_waiting_time(processes, n, bt, wt); 

	//Function to get turn around time for all processes 
	get_turn_around_time(processes, n, bt, wt, tat); 

	//Display processes along with all details 
	cout << "Processes "<< " Burst time "
		<< " Waiting time " << " Turn around time\n"; 

	// measuring total waiting time and total turn around time 
    
	for (int i=0; i<n; i++) 
	{ 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl; 
	} 

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
} 

// Driver code 
int main() 
{ 
	//process id's 
	int processes[] = { 1, 2, 3}; 
	int n = sizeof processes / sizeof processes[0]; 

	//Burst time of all processes 
	int burst_time[] = {10, 5, 8}; 

	find_avg_Time(processes, n, burst_time); 
	return 0; 
} 
