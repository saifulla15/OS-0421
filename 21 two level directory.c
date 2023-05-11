#include<stdio.h>
#include<string.h>
struct st
{
   char dname[10];
   char sdname[10][10];
   char fname[10][10][10];
   int ds,sds[10];
}
dir[10];
int main()
{
   int i,j,k,n;
   printf("enter number of directories:");
   scanf("%d",&n);
   for(i=0;i<1;i++)
   {
     printf("enter directory %d names:",i+1);
     scanf("%s",&dir[i].dname);
     printf("enter size of directories:");
     scanf("%d",&dir[i].ds);
     for(j=0;j<1;j++)
     {
       printf("enter subdirectory name and size:");
       scanf("%s",&dir[i].sdname[j]);
       scanf("%d",&dir[i].sds[j]);
       for(k=0;k<1;k++)
       {
         printf("enter file name:");
         scanf("%s",&dir[i].fname[j][k]);
       }
   }
}
printf("\ndirname\t\tsize\tsubdirname\tsize\tfiles");
printf("\n******************************************************\n");
for(i=0;i<=1;i++)
{
printf("%s\t\t%d",dir[i].dname,dir[i].ds);
for(j=0;j<=1;j++)
{
printf("\t%s\t\t%d\t",dir[i].sdname[j],dir[i].sds[j]);
for(k=0;k<=1;k++)

printf("%s\t",dir[i].fname[j][k]);
printf("\n\t\t");
}
printf("\n");
}
}
