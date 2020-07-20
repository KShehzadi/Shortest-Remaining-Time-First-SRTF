#include <iostream>
using namespace std;

int main()
{
	int arrivalflag, numberofprocess, arrivaltime, bursttime, completiontime, turnarroundtime, waitingtime;
	
	
	
	cout<<"###########################################################################"<< endl;
	cout<<"                   Arrival Time Decision(0 for all or different)                       "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;
	cout<<"Enter 1 if you want different arrival time ,0 for same arrival time "<< endl;
	cin>> arrivalflag;
	
	
	
	
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
	int process[numberofprocess][6];
	for(int i = 0; i < numberofprocess; i++)
	{
		process[i][0]= i;
		process[i][1]= arrivalarray[i];
		process[i][2]= burstarray[i];
		process[i][3] = 0;
		process[i][4] = 0;
		process[i][5] = 0;
	}
	
	
	int t[3]={0,0,0};
	// Sorting Array by Arrival time
	if(arrivalflag == 0)
	{
	
	

	for(int i=0; i < numberofprocess-1; i++)
	{
	    for(int j=i+1; j< numberofprocess; j++)
		{
			if(process[i][1] > process[j][1])
			{
			
				t[0] = process[i][0];
				t[1]= process[i][1];
				t[2]= process[i][2];
				process[i][0] = process[j][0];
				process[i][1] =process[j][1];
				process[i][2] = process[j][2];
				process[j][0] = t[0];
				process[j][1] = t[1];
				process[j][2] = t[2];
			
			}
		}
	}	
}
else
{
	for(int i=0; i < numberofprocess-1; i++)
	{
	    for(int j=i+1; j< numberofprocess; j++)
		{
			if(process[i][1] > process[j][1])
			{
			
				t[0] = process[i][0];
				t[1]= process[i][1];
				t[2]= process[i][2];
				process[i][0] = process[j][0];
				process[i][1] =process[j][1];
				process[i][2] = process[j][2];
				process[j][0] = t[0];
				process[j][1] = t[1];
				process[j][2] = t[2];
			
			}
		}
	}
	temp = 0;
	int i = 0;
	for(i=0; i < numberofprocess-1; i++)
	{
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
	    for(int j=i+1; j< numberofprocess - 1; j++)
		{   	
			if(temp >= process[i+1][1] && temp >= process[j+1][1]  &&  process[i+1][2] > process[j+1][2])
			{
				t[0] = process[i+1][0];
				t[1]= process[i+1][1];
				t[2]= process[i+1][2];
				process[i+1][0] = process[j+1][0];
				process[i+1][1] =process[j+1][1];
				process[i+1][2] = process[j+1][2];
				process[j+1][0] = t[0];
				process[j+1][1] = t[1];
				process[j+1][2] = t[2];
				
			}
		}
		
		
	}

}



	cout<<"###########################################################################"<< endl;
	cout<<"                     Evaluating Times for each Process                     "<< endl;
	cout<<"###########################################################################"<< endl;
	cout<< endl;	
	float averagewaittime = 0;
	float averageturnarroundtime = 0;
	temp = 0;
	int clock = 0;
	for(int i = 0; i < numberofprocess; i++)
	{
		process[i][4] = 0;
	}
	
	cout<< "Arrival time | ProcessID | BurstTime | CompletionTime | TurnArroundTime | WaitingTime"<< endl;

	if(arrivalflag != 0)
	{
		while(true)
		{
			
			int t1[5];
	        for(int i=0; i < numberofprocess-1; i++)
	        {
		      arrivaltime = process[i][1];
		      bursttime = process[i][2];		
	         for(int j=i+1; j< numberofprocess; j++)
		     {
			
			  if(clock >= process[i][1] && clock >= process[j][1]  &&  process[i][2] > process[j][2] )
			  {	
				t1[0] = process[i][0];
				t1[1]= process[i][1];
				t1[2]= process[i][2];
				t1[4]= process[i][4];
				t1[3]= process[i][3];
				t1[5]= process[i][5];
				process[i][0] = process[j][0];
				process[i][1] =process[j][1];
				process[i][2] = process[j][2];
				process[i][4] = process[j][4];
				process[i][3] = process[j][3];
				process[i][5] = process[j][5];
				process[j][0] = t1[0];
				process[j][1] = t1[1];
				process[j][2] = t1[2];
				process[j][3] = t1[3];
				process[j][4] = t1[4];
				process[j][5] = t1[5];
			   }
		      }
	         }
		    clock = clock + 1;
			if(process[numberofprocess-1][2] == 0)
			{
				break;
			}
			for(int i1 = 0; i1 < numberofprocess; i1++)
			{
				
				if(process[i1][2] != 0)
				{
					process[i1][2] = process[i1][2] - 1;
					process[i1][4] = process[i1][4] + 1;
				
					int tempindex = i1;
					for(int i = 0; i < numberofprocess; i++)
					{
						if(i != tempindex && process[i][2] > 0 && process[i][1] < clock)
						{
						
							process[i][5] = process[i][5] + 1;
						}
					}
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
	}
	}
	for(int i = 0; i < numberofprocess; i++)
	{
		arrivaltime = process[i][1];
		bursttime = process[i][4];
		completiontime = process[i][3];
		turnarroundtime = completiontime - arrivaltime;
		waitingtime = process[i][5];
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
	


