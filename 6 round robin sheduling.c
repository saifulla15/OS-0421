#include<stdio.h>
 int main()
{
    int bt[20],p[20],wt[20],twt[20],tat[20],i,n,c,k,ttat,towt;
    printf("Enter number of process:");
    scanf("%d",&n);
  	//getting burst time and puting them in temperory wt for future use.
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        twt[i]=bt[i];
        p[i]=i+1;         
    }
    
    printf("enter the time constrain::");
    scanf("%d",&c);
    k=c;
    
    while(bt[0]!=0 || bt[1]!=0 || bt[2]!=0 || bt[3]!=0)
    {
    for(i=0;i<n;i++)
    {
    	if(bt[i]>=c)
    	{
    		if(bt[i]!=0)
    		{
    		bt[i]=bt[i]-c;
    		if(bt[i]==0)
    			{
    				tat[i]=k;
				}
    		printf("p%d = %d %d \n",i+1,bt[i],k);
    		}
    		else
    		{
    			continue;
			}
		}
		else
		{
			if(bt[i]!=0)
			{
			bt[i]=bt[i]-bt[i];
			if(bt[i]==0)
				{
					tat[i]=k;
				}
			printf("p%d = %d %d \n",i+1,bt[i],k);
			}
			else
			{
				continue;
			}
		}
		k=k+c;
	}
	}
	//gathering waiting time wt[].
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-twt[i];
	}
	//printing the wt,twt.
	printf("\nProcess\t    \tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\t\t  %d\t\t\t%d",p[i],wt[i],tat[i]);
	}
	//finding total wt and tat.
	for(i=0;i<n;i++)
	{
		ttat=ttat+tat[i];
		towt=towt+wt[i];
	}   
    printf("\nAverage Waiting Time=%f",(float)towt/n);
    printf("\nAverage Turnaround Time=%fn",(float)ttat/n);
}
