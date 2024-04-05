#include<stdio.h>
#include<string.h>
int main()
    {    
        FILE *fp;
        int k,i;
        char buffer[100];
        char task[100];
        char a,opt;
        do{
        printf("Do you want to write new tasks or display the remaining tasks??(W/D):");
        scanf(" %c",&a);
        getchar();
        if (a == 'W')
            {
             //writing to the file
            if (fp == NULL)
                {
                    printf("Error opening the file ");
                    return 1;
                }
            fp=fopen("to do list.txt","w");
            printf("Enter how many tasks to add to the to do list?:");
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
                    fprintf(fp,"%s\n",task);
                }
            fclose(fp);
            }
        else if (a=='D')
            {
            //Reading the file
            fp = fopen("to do list.txt","r");//to open the file and read
            if (fp == NULL)
                {
                    printf("Error reading this file\n");
                    return 1;
                }
            printf("Tasks:\n");
            while(fgets(buffer,sizeof(buffer),fp) != NULL)
                {
                    printf("%s",buffer);
                }
            fclose(fp);
            }
        else
            {
                printf("Check what you've written\n");
            }
        printf("Do you want to continue?(Y/N):");
        scanf("%c",&opt);
        getchar();
        }while(opt =='Y' || opt == 'y');
        return 0;
    }
