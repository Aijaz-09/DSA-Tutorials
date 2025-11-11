


/* BOILERPLATE CODE FOR SINGLE LINKED IMPLEMENTATIONS (INSERT, DELETE, TRAVERSAL) */


#include <stdio.h>


int mainmenu()
{
    unsigned int choice;
    
    printf("\n\n***************************************************");
    printf("\n****** SINGLE LINKED LIST IMPLEMENTATION **********\n");
    printf("***************************************************");

    printf("\n 1. Insert a new node at start\n 2. Insert a new node at end\n 3. Insert a new node at any kth position\n 4. Delete the starting node \n 5. Delete the node at end of the list\n 6. Delete a node at kth position \n 7. Exit \n ENTER YOUR CHOICE: ");
    
    
    scanf("%d", &choice);
    return choice;

}

void insert_at_start()
{
    printf("This function implements inserting a new node at the start");
}

void insert_at_end()
{
    printf("This function implements inserting a new node at the end");
}

void insert_at_k()
{
    printf("This function implements inserting a new node at any kth position");
}

void delete_at_start()
{
    printf("This function implements deleting the start/head node");
}

void delete_at_end()
{
    printf("This function implements deleting a node at the end");
}

void delete_at_k()
{
    printf("This function implements deleting a node at any kth position");
}






int main()

{
    unsigned int choice;

    do {
        choice = mainmenu();


        switch(choice)
        {
            case 1: insert_at_start(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_k(); break;
            case 4: delete_at_start(); break;
            case 5: delete_at_end(); break;
            case 6: delete_at_k(); break;
            default: printf("Exiting"); break;
        }
    }while (choice < 7);

}