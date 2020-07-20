#include <iostream>
using namespace std;
void sortarray(int  &process[][5],int numberofprocess)
{
	int t[3];
	int arrivaltime;
	int bursttime;
	int completiontime;
	int temp = 0;
	for(int i=0; i < numberofprocess-1; i++)
	{
	    for(int j=0; j< numberofprocess-i-1; j++)
		{
			if(process[j][1] > process[j+1][1])
			{
			
				t[0] = process[j][0];
				t[1]= process[j][1];
				t[2]= process[j][2];
				process[j][0] = process[j+1][0];
				process[j][1] =process[j+1][1];
				process[j][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
			
			}
		}
	}
	
	for(int i=0; i < numberofprocess-1; i++)
	{
		arrivaltime = process[i][1];
		bursttime = process[i][2];
		completiontime = bursttime + arrivaltime;
		if(process[i][2] + temp > process[i+1][2] + temp)
		{
			
				t[0] = process[i][0];
				t[1]= process[i][1];
				t[2]= process[i][2];
				process[i][0] = process[i+1][0];
				process[i][1] =process[i+1][1];
				process[i][2] = process[i+1][2];
				process[i+1][0] = t[0];
				process[i+1][1] = t[1];
				process[i+1][2] = t[2];
		}
		arrivaltime = process[i][1];
		bursttime = process[i][2];
		completiontime = bursttime + arrivaltime;
		if(temp > arrivaltime)
		{
			completiontime = temp + bursttime;
			temp = completiontime;
		}
		else
		{
			temp = completiontime;
		}
	    for(int j=i+1; j< numberofprocess-1; j++)
		{
		
		    if( process[j][1] == process[j+1][1]  && temp + process[j][2] > process[j+1][2] + temp)
			{
			
				t[0] = process[j][0];
				t[1]= process[j][1];
				t[2]= process[j][2];
				process[j][0] = process[j+1][0];
				process[j][1] =process[j+1][1];
				process[j][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
			
			}
			
			else if(temp > process[j][1] && temp > process[j+1][1]  &&  process[j][2] > process[j+1][2])
			{
			
				t[0] = process[j][0];
				t[1]= process[j][1];
				t[2]= process[j][2];
				process[j][0] = process[j+1][0];
				process[j][1] =process[j+1][1];
				process[j][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
			
			}
		}
	}
	
}
int main()
{
	int arrivalflag, arrivaltime, bursttime, completiontime, turnarroundtime, waitingtime;
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                   Arrival Time Decision(0 for all or different)                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter 1 if you want different arrival time ,0 for same arrival time "<< endl;
	cin>> arrivalflag;
	int numberofprocess;
	
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                               Number of Processes                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<< "Enter Number of processes you want to create"<< endl;
	cin >> numberofprocess;
	int burstarray[numberofprocess];
	int arrivalarray[numberofprocess];
	
	
	
	
	if(arrivalflag == 1)
	{
	cout<<"###########################################################################"<< endl;
	cout<<"                      Enter Arrival Time for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
		for(int i = 0; i < numberofprocess; i++)
		{
			cout<< "Enter arrival time for process pid_"<< i<< endl;
			cin>> arrivaltime;
			arrivalarray[i] = arrivaltime;
		}
	}
	else
	{
		for(int i = 0; i < numberofprocess; i++)
		{
			arrivalarray[i] = 0;
		}
	}
	
	
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                      Enter Burst Time for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	for(int i = 0; i < numberofprocess; i++)
	{
			cout<< "Enter burst time for process pid_"<< i<< endl;
			cin>> bursttime;
			burstarray[i] = bursttime;
	}
	int temp = 0;
	// process[0] is pid
	// process[1] is arrivaltime
	// process[2] is bursttime
	// process[3] is completiontime
	// process[4] is newbursttime
	int process[numberofprocess][5];
	for(int i = 0; i < numberofprocess; i++)
	{
		process[i][0]= i;
		process[i][1]= arrivalarray[i];
		process[i][2]= burstarray[i];
		process[i][3] = 0;
		process[i][4] = 0;
	}
	
	
	int t[3]={0,0,0};
	// Sorting Array by Arrival time
	if(arrivalflag == 0)
	{
	
	
	for(int i=0; i < numberofprocess-1; i++)
	{
	    for(int j=0; j< numberofprocess-i-1; j++)
		{
			if(process[j][2] > process[j+1][2])
			{
			
				t[0] = process[j][0];
				t[1]= process[j][1];
				t[2]= process[j][2];
				process[j][0] = process[j+1][0];
				process[j][1] =process[j+1][1];
				process[j][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
			
			}
		}
	}
	
}
else
{
sortarray(process, numberofprocess);
}



	cout<<"###########################################################################"<< endl;
	cout<<"                     Evaluating Times for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;	
	float averagewaittime = 0;
	float averageturnarroundtime = 0;
	temp = 0;
	int clock = 0;
	
	cout<< "Arrival time | ProcessID | BurstTime | CompletionTime | TurnArroundTime | WaitingTime"<< endl;


	if(arrivalflag != 0)
	{
		while(true)
		{
		
			if(process[numberofprocess-1][2] == 0)
			{
				break;
			}
			clock = clock + 1;
			for(int i1 = 0; i1 < numberofprocess; i1++)
			{
				
				if(process[i1][2] != 0)
				{
					cout<< process[i1][1]<< endl;
					process[i1][2] = process[i1][2] - 1;
					process[i1][4] = process[i1][4] + 1;
					if(process[i1][2] == 0)
					{
						process[i1][3] = clock;
						break;
					}
					else
					{
						break;
					}
				}
			}
			sortarray(&process, numberofprocess);
	}
	}
	for(int i = 0; i < numberofprocess; i++)
	{
		arrivaltime = process[i][1];
		bursttime = process[i][4];
		completiontime = process[i][3];
		turnarroundtime = completiontime - arrivaltime;
		waitingtime= turnarroundtime - bursttime;
		cout<< arrivaltime<<" 	     |"<<"pid_"<< process[i][0]<<"    	 |"<< bursttime<<"  	     |"<<completiontime<<" 	      |"<<turnarroundtime<<"  		|"<<waitingtime<< endl;
		averagewaittime = averagewaittime + waitingtime;
		averageturnarroundtime = averageturnarroundtime + turnarroundtime;
   }
	averageturnarroundtime = averageturnarroundtime/numberofprocess;
	averagewaittime = averagewaittime/numberofprocess;
	cout<<"###########################################################################"<< endl;
	cout<<"                      Average Wait and Turn arround Time                  "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	
	cout<< "Average Turn Arround Time :"<< averageturnarroundtime << endl;
	cout<< "Average Wait Time :"<<averagewaittime<< endl;
}
	


