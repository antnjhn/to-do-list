#include<stdio.h>
#include<string.h>
void deletetask(const char *filename,int taskname)
    {   
        int line=1;
        FILE *fp1,*fp2;
        char buffer[100];
        
    }
int main()
    {    
        FILE *fp;
        int k,i,a,z=1,taskno=1;
        char buffer[100];
        char task[100];
        char opt;
        do{ 
            printf("___________________    ________   ________    .____    .___  ____________________\n");
        printf("\\__    ___/\\_____  \\   \\______ \\  \\_____  \\   |    |   |   |/   _____/\\__    ___/\n");
        printf("  |    |    /   |   \\   |    |  \\  /   |   \\  |    |   |   |\\_____  \\   |    |\n");
        printf("  |    |   /    |    \\  |    `   \\/    |    \\ |    |___|   |/        \\  |    |\n");
        printf("  |____|   \\_______  / /_______  /\\_______  / |_______ \\___/_______  /  |____|\n");
        printf("                   \\/          \\/         \\/          \\/           \\/\n\n");

            printf("(1)-Display\n(2)-New tasks\n");
            printf("Enter your choice??:");
            scanf("%d",&a);
            getchar();
            if (a == 2)
                {
             //writing to the file
                fp=fopen("to do list.txt","a");
                if (fp == NULL)
                    {
                        printf("Error opening the file ");
                        return 1;
                    }
                printf("Enter how many tasks to add to the to do list?:");//to iterate  the no of times to be written in the file
                scanf("%d",&k);
                //consume the newline character left in the input buffer
                while (getchar() !='\n');
                for(i=0;i<k;i++)
                    {
                        printf("Enter today's task:");
                        fgets(task, sizeof(task), stdin);
                        //Remove new line character from the task string
                        if (task[strlen(task) -1 ] == '\n') /*this part of the code checks if the end of the string(task )is a new line character or not*/
                            {
                                task[strlen(task) -1] = '\0';/*this line of code replaces the newline character(\n) from the end of the character with a null terminator*/
                            }
                        fprintf(fp,"%d:%s\n",taskno,task);
                        ++taskno;
                    }
                fclose(fp);
                }
            else if (a==1)
                {
                //Reading the file
                fp = fopen("to do list.txt","r");//to open the file and read
                if (fp == NULL)
                    {
                        printf("Error reading this file\n");
                        return 1;
                    }
                printf("Tasks:\n");
                while(fgets(buffer,sizeof(buffer),fp) != NULL)//this is to get the file pointer to prinnt the tasks inputed
                    {
                        printf("%s",buffer);
                        z++;
                    }
                fclose(fp);
                }
            else
                {
                    printf("Check what you've written\n");
                }
            printf("Do you want to continue?(Y/N):");
            scanf(" %c",&opt);
            getchar();
            }while(opt =='Y' || opt == 'y');
            return 0;
    }
