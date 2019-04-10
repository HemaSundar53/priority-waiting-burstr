#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>
	float priority[10];
	int arv_time[10];
	float bur_time[10];
	int starting_time[10];
	int completion_time[10];
	float waiting_time[10];
	int turn_ar_time[10];
	int p[10];
int main()
{    int i,n,j,temp,temp1,temp2,temp3,min,y,x=0;
	int total_ta,avg_wt,avg_ta,total_wt;
	printf("*******************************OPERATING SYSTEM PROJECT*********************************\n");
	                              
	                                       //INPUT FROM USER: NUMBER OF PROCESSES
	int op()
	{
	printf("Enter the number of process:");
    scanf("%d",&n);
	}
	op();
    if(n<=0)
    {
    	/*for(c=0;c<10;c++)
    	{
    		printf(p);
		}*/
		printf("LOADING PLEASE WAIT\n");
		for(i=0;i<35;i++)
			{
			
			printf("*");
			for(j=0;j<100000000;j++);
			}
    	printf("\nInvalid Input\n");
    	printf("PLEASE TRY AGAIN\n");
		
		op();
	}
	
	
	                                           //INPUT FROM THE USER: AT & BT
    for(i=0;i<n;i++)
    {
    	p[i]=i+1;
	}
    for(i=0; i<n; i++)
    {
	    printf("Enter the arrival & burst time of p%d\n",p[i]);
		printf("AT:");
		scanf("%d",&arv_time[i]);
		if(arv_time[i]<0)
		{
			
			printf("-------------LOADING------------------\n");
			for(i=0;i<35;i++)
			{
			
			printf("*");
			for(j=0;j<100000000;j++);
			}
			printf("\nInvalid Input\n");
    		printf("PLEASE TRY AGAIN\n");
    		exit(0);
		}
		printf("BT:");
		scanf("%f",&bur_time[i]);
		if(bur_time[i]<=0)
		{
			printf("-------------LOADING------------------\n");
			for(i=0;i<35;i++)
			{
			
			printf("*");
			for(j=0;j<100000000;j++);
			}
			printf("\nInvalid Input\n");
    		printf("PLEASE TRY AGAIN\n");
    		exit(0);
		}
	}
	
	
	
	                                           //SORTING ACCORDING TO ARRIVAL TIME
	
      for(j=0;j<n-1;j++)
	  {                                         
        for( i=0;i<n-j-1;i++)
        {
            if(arv_time[i]>arv_time[i+1])
                {
                	int temp1,temp2,temp3;
                    temp1=p[i];
                    p[i]=p[i+1];
                    p[i+1]=temp1;
                    temp2=arv_time[i];
                    arv_time[i]=arv_time[i+1];
                    arv_time[i+1]=temp2;
                    temp3=bur_time[i];
                    bur_time[i]=bur_time[i+1];
                    bur_time[i+1]=temp3;
                }
        }
    
       }                                       
	   
	   
	   
	                                                  //SORTED ACCORDING TO SJF
    for(i=0;i<n;i++)
    {
    	x++;
        y=y+bur_time[i];
        min=bur_time[x];
        for( j=x;j<n;j++)
        {
            if(arv_time[j]<=y&&min>bur_time[j])
            {
            	int temp;
                temp=p[x];
                p[x]=p[j];
                p[j]=temp;
                temp=arv_time[x];
                arv_time[x]=arv_time[j];
                arv_time[j]=temp;
                temp=bur_time[x];
                bur_time[x]=bur_time[j];
                bur_time[j]=temp;
            }
        }
    }
    
                                           //CALCULATING WAITING TIME, TURN AROUND TIME, COMPLETION TIME
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            starting_time[i]=arv_time[i];
        }
        else
        {
            starting_time[i]=completion_time[i-1];
        }
        waiting_time[i]=starting_time[i]-arv_time[i];
        completion_time[i]=starting_time[i]+bur_time[i];
        turn_ar_time[i]=completion_time[i]-arv_time[i];
        total_wt+=waiting_time[i];
        total_ta+=turn_ar_time[i];
    }
    avg_wt=(float)total_wt/n;
    avg_ta=(float)total_ta/n;
    printf("AFTER SHORTEST JOB FIRST SEARCH");
    printf("\nProcess\tarrivaltime\tBursttime\twaitingtime\t Turn around time");
    for(i=0; i<n; i++)
        {
		printf("\np%d\t%5d\t\t%.2f\t\t%.2f\t\t%5d",p[i],arv_time[i],bur_time[i],waiting_time[i],turn_ar_time[i]);
    	}
    	
    	
    	                                         //CALCULATING PRIORITY
	for(i=0;i<n;i++)
    {
    	float k;
        k=(waiting_time[i]/bur_time[i]);
		priority[i]=1+k;
    }
                                             //SORTED ACCORDING TO PRIORITY

printf("\nAFTER CALCULATING: PRIORITY=1+WAITING_TIME/BURST_TIME");
    printf("\n      Process       Arrival Time        Burst Time        Starting Time     completion Time     Waiting Time  Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\tP%d\t\t%d\t\t  %.2f\t\t\t%d\t\t%d\t\t\t%.2f\t%.2f\n",p[i],arv_time[i],bur_time[i],starting_time[i],completion_time[i],waiting_time[i],priority[i]);
    }

}
