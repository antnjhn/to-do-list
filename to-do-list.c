#include<stdio.h>
int main()
    {   
        //writing to the file
        FILE *fp;
        int k,i;
        char buffer[100];
        char task[100];
        fp=fopen("to do list.txt","w");
        printf("Enter how many tasks to add to the to do list?:");
        scanf("%d",&k);
        for(i=0;i<k;i++)
            {
                printf("Enter today's task:");
                scanf("%s",&task);
                fprintf(fp,"%s",task);
            }
        fclose(fp);
        //Reading the file
        fp = fopen("to do list.txt","r");//to open the file and read
        if (fp == NULL)
            {
                printf("Error reading this file\n");
                return 1;
            }
        while(fgets(buffer,sizeof(buffer),fp) != NULL)
            {
                printf("%s",buffer);
            }
        fclose(fp);
    }
