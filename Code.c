#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void cover_page()
{
    printf("\n\n\t\t\t\t===================================================\n");
    printf("\t\t\t\t===================================================\n");//
    printf("\t\t\t\t= =\t\t\t\t\t\t= =\n");
    printf("\t\t\t\t= =\t\t     WELCOME TO\t\t\t= =\n");
    printf("\t\t\t\t= =\t     LIBRARY MANAGEMENT SYSTEM\t\t= =\n");
    printf("\t\t\t\t= =\t\t\t\t\t\t= =\n");
    printf("\t\t\t\t===================================================\n");//
    printf("\t\t\t\t===================================================\n");
}

struct node
{
    int id;
    char name[20];
    char author[20];
    struct node *next_add;
}*head,*temp;

struct node *head= NULL;
struct node *insert_book(struct node *);
struct node *delete_book(struct node *);
void show_book();

void menu()
{
    printf("\n\n\t\tMain Menu :- \n");
    printf("\n\t\t\t 1. Insert New Book");
    printf("\n\t\t\t 2. Search Book");
    printf("\n\t\t\t 3. Update Book");
    printf("\n\t\t\t 4. Delete Book");
    printf("\n\t\t\t 5. Show all Book");
    printf("\n\t\t\t 6. Exit");
    int num,n;
    printf("\n\n\t\t\tEnter Your Choice : ");
    scanf("%d",&num);
    system("cls");
    switch(num)
    {
    case 1:
        while(1)
        {
            head=insert_book(head);
            system("cls");
            printf("\n\n\t\t\t\t\t Book Add Successful\n");
            printf("\t\t\t------------------------------------------------------\n");
            menu();
            break;
        }
    case 2:
    {
        head=search_book(head);
        break;
    }
    case 3:
    {
        // update_book();
        break;
    }
    case 4:
    {
        head=delete_book(head);
        break;
    }
    case 5:
    {
        show_book(head);
        printf("\n\n\n\n\t\tEnter any key to return the Menu : ");
        getch();
        system("cls");
        menu();
    }
    case 6:
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\tProcessing Successful\n\n");
        printf("\t\t\t\t\t\t***** THANK YOU *****\n\n\n\n\n\n\n\n\n\n\n");
        break;
    }
    default:
    {
        printf("\n\n\t\t\t\t\tInvalid Input..Please Try Again");
        printf("\n\n\t\t\t -----------------------------------------------------------\n");
        printf("\n\n\t\t\tEnter any key to return the Menu: ");
        getch();
        system("cls");
        menu();
        break;
    }
    }
}

struct node* insert_book(struct node* head)
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n\n\t\tAdd Book : \n");
    printf("\n\t\t\tEnter The Book Id Number : ");
    scanf("%d",&newnode->id);
    printf("\t\t\tEnter The Book Name : ");
    scanf("%s",&newnode->name);
    printf("\t\t\tEnter The Book Author : ");
    scanf("%s",&newnode->author);
    newnode->next_add=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next_add!=NULL)
        {
            temp=temp->next_add;
        }
        temp->next_add=newnode;
    }
    printf("\n");
    return head;
};

void search_book(struct node* head)
{
    int id,i=0;
    printf("\n\n\t\tSearch by book ID : ");
    scanf("%d",&id);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            i=1;
            printf("\n\n\t\tThis book details : \n");
            printf("\n\n\t\t\t\tID \tBook \tAuthor\n\n");
            printf("\t\t\t\t%d \t%s \t%s\n",temp->id,temp->name,temp->author);
            printf("\n\n\t\t  ------------------------------------------------\n");
            printf("\n\t\t\tEnter any key to return the Menu : ");
            getch();
            system("cls");
            menu();
            break;
        }
        else
        {
            temp=temp->next_add;
        }
    }
    if(i==0)
    {
        printf("\n\n\n\n\t\t\t\t\tSorry! This Book Not Found.\n\n\n");
        printf("\t\t\t------------------------------------------------------------\n");
        printf("\n\n\t\t\tEnter any key to return the Menu : ");
        getch();
        system("cls");
        menu();
    }
}

struct node* delete_book(struct node* head)
{
     int ID;
     struct node *new_head;
     printf("\n\n\t\tDelete by book ID : ");
     scanf("%d",&ID);
     new_head=(struct node*)malloc(sizeof(struct node));
     if(head->id==ID)
     {
         temp=head;
         head=head->next_add;
         free(temp);
         printf("Book deleted successfully\n\n");
     }
};

void show_book(struct node *head)
{
    struct node *temp;
    temp=head;
    printf("\n\n\t\tBook List : \n");
    if(head==NULL){
        printf("\n\n\n\t\t\t\tTHERE IS NO BOOK.\n\n");
        printf("\t\t------------------------------------------------");}
    else
    {
        printf("\n\n\t\t\t\tID \tBook \tAuthor\n\n");
        while(temp!=NULL)
        {
            printf("\t\t\t\t%d \t%s \t%s\n",temp->id,temp->name,temp->author);
            temp=temp->next_add;
        }
    }
}

int main()
{
    cover_page();
    menu();
    return 0;
}
