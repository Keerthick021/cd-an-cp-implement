/*Name : keerthick vasa M
Date :02/07/2024
description :Implement cd and cp command
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char *argv[])
{
    if(strcmp(argv[1],"cd")==0)
    {
	if(argc!=3)
	{
	    printf("GIVE VALIDE INPUT\n");
	    return 0;
	}
	else
	{
	    char buff[1024];
	    if(getcwd(buff,1024)!=NULL)
	    {

		printf("%s\n",getcwd(buff,1024));
		chdir(argv[2]);
		printf("%s\n", getcwd(buff,1024));
		return 0;
	    }
	    else
	    {
		printf("There are no directory like that name\n");
		return 0;
	    }
	}

    }
    else if(strcmp(argv[1],"cp")==0)
    {
	if(argc!=4)
	{
	    printf("GIVE VALIDE SOURCE FILE AND DESTINATION FILE\n");
	    return 0;
	}
	FILE *ptr1=fopen(argv[2],"r");
	FILE *ptr2=fopen(argv[3],"w");
	if(ptr1==NULL)
	{
	    printf("There is no contant present in the source file\n");
	    return 0;
	}
	else
	{
	    if(ptr2==NULL)
	    {
		printf("Cannot open the file\n");
		return 0;
	    } 
	    else
	    {
		char ch;
		while((ch=fgetc(ptr1))!=EOF)
		{
		    fputc(ch,ptr2);
		}
		printf("FILE COPIED SUCCESSFULLY\n");
	    }
	}
	fclose(ptr1);
	fclose(ptr2);
    }



}





