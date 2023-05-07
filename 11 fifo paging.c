#include<stdio.h>
int main()
{
	int a[30],pf=0,frames,m,n,s,pages,i;
	printf("enter the noof pages::");
	scanf("%d",&pages);
	printf("enter the noof frames::");
	scanf("%d",&frames);
	printf("enter the pages:");
	for(i=0;i<pages;i++)
	{
		scanf("%d",&a[i]);
	}
	int temp[frames];
	for(i=0;i<frames;i++)
	{
		temp[i]=-1;
	}
	printf("incoming \t");
	for(m=0;m<pages;m++)
	{
		s=0;
		for(n=0;n<frames;n++)
		{
			if(a[m]==temp[n])
			{
				s++;
				pf--;
			}
		}
		pf++;
		if((pf<=frames)&&(s==0))
		{
			temp[m]=a[m];
		}
		else if(s==0)
		{
			temp[(pf - 1) % frames] = a[m];
		}
		printf("\n");
		printf("%d\t",a[m]);
		for(n=0;n<frames;n++)
		{
			if(temp[n] != -1)
                printf(" %d\t", temp[n]);
            else
                printf(" - \t");
		}
	}
	printf("\nTotal noof pagefaults is %d\n",pf);
	return 0;
}
