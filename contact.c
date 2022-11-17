#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
// Creating Struct to store data krub
struct contact
{
    long phone;
    char name[30],add[100],email[60];
} list;
char namefind[30],name[30];
FILE *fp, *ft;
int i,n,ch,length,found;
int main(){
main:
    // Creating Main Menu Interface krub
    system("cls");    
    printf("\n\t <<< Contact Management System by GFKK >>>");
    printf("\n\n\t\t\tM-E-N-U\n");
    printf("\t\t<+-+-+-+-+-+-+-+-+-+>\n");
    printf("\t\t<1> Add\n");
    printf("\t\t<2> List all\n");
    printf("\t\t<3> Search\n");
    printf("\t\t<4> Edit\n");
    printf("\t\t<5> Delete\n");
    printf("\t\t<0> Exit\n");
    printf("\t\t<+-+-+-+-+-+-+-+-+-+>\n");
    printf("\t\tEnter number: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
        printf("\n\n\t\tDo you want to exit?");
        break;
    // Add function
    case 1:
        system("cls");
        fp=fopen("contact.txt","a");
        for (;;)
        {
            fflush(stdin);
            printf("Enter blank space to exit\nName:");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
            break;
            fflush(stdin);
            printf("Phone:");
            scanf("%ld",&list.phone);
            fflush(stdin);
            printf("Address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("Email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
    case 2:
        //see contact
        system("cls");
        printf("\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("\t\t\tLIST OF CONTACTS\n");
        printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
        printf("\nName\t\tPhone No\t    Address\t\tE-mail ad.\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        for(i=97; i<=122; i=i+1)//usefor %c toshow 
        {
            fp=fopen("contact.txt","r");
            fflush(stdin);
            found = 0;
            while(fread(&list, sizeof(list),1,fp)==1)
            {
                if (list.name[0] == i || list.name[0] == i - 32) //EX.A, a is true
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.phone,list.add,list.email);
                    found++;
                }
            }
            if (found!=0)
            {
               printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= [%c]-(%d)\n\n",i-32,found);
               getch();//to continute
            }
            fclose(fp);
        }
        break;
    
    
    case 3:
        //find Name to show
        system("cls");
        do{
            found = 0;
            printf("\n\n\t<--CONTACT SEARCH-->\n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\tName of contact to search: ");
            fflush(stdin);
            scanf("%[^\n]", &namefind);
            length=strlen(namefind);
            fp=fopen("contact.txt","r");
            system("cls");
            printf("\n\nSearch result for '%s' \n=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n",namefind);
            while(fread(&list, sizeof(list),1,fp)==1)
            {
                for (i=0; i<=length; i++)
                    name[i] = list.name[i];
                
                name[length] = '\0';
                if (stricmp(name, namefind)== 0)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.phone,list.add,list.email);
                    found++;
                    if (found%4==0)
                    {
                        printf("Press any key to continue...");
                        getch();
                    }
                }
            }
            if(found==0)
                printf("\nNo match found!");
            else
                printf("\n%d match(s) found!",found);
            fclose(fp);
            printf("\n Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;

        /* *********************edit contacts************************/

    case 4:

        system("cls");

        fp=fopen("contact.txt","r");

        ft=fopen("temp.dat","w");

        fflush(stdin);

        printf("Edit contact\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
        printf("\tEnter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        /*check name in list*/
        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\nEditing '%s'\n\n",name);

        printf("Name:");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("Phone:");

        scanf("%ld",&list.phone);

        fflush(stdin);

        printf("address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("email address:");

        gets(list.email);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.dat","contact.txt");

        break;            
    case 5:
        system("cls");
        fflush(stdin);
        printf("\n\n\tDelete contact\n\t==========================\n\tEnter name to delete:");
        scanf("%[^\n]", &name);
        fp = fopen("contact.txt", "r");
        ft = fopen("temp.dat", "w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("contact.txt");
        rename("temp.dat","contact.txt");
        break;

    
    default:
        printf("Invalid Choice");
        break;
    }
    

    
    printf("\n\n\nEnter Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    // run main or break na krub
    scanf("\t\t%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
    return 0;
}
