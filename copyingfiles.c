#include<stdio.h>
#include<stdlib.h>                                   //note :: creATE THE SOURCE FILE IN THE SAME LOCATION WHERE PROGRAM IS SAVED
int main()
{
	char ch,sourcefile[20],targetfile[20];
	FILE *fs,*ft;
	printf("enter name of the  source file to copy along with extension.\n");
	gets(sourcefile);
	fs= fopen(sourcefile,"r");
	if(fs == NULL)
	{
		printf(" error.press any key to exit...\n");
		return 0;
	}
	
	printf("enter the name of the target file along with extension.\n");
	gets(targetfile);
	ft=fopen(targetfile,"w");
	if(ft == NULL)
	{
		printf("error.press any key to exit...\n");
		return 0;
	}
	ch=fgetc(fs);
	while(ch!=EOF)
	{
	fputc(ch,ft);
	ch=fgetc(fs);
	}
	printf("File copied sucessfully.\n");
	fclose(fs);
	fclose(ft);
	return 0;
}
