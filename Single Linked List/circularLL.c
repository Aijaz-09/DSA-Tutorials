#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
}*head = NULL;

void insertAtKth_CLL(int k, int x) {
    // Invalid index handling
    if(k <=0)
    {
      printf("Invalid index!");
      return;
    }
    // If list doesn't exit, CREATE THE FIRST NODE
    if (head == NULL) {
        printf("\nCircular linked list doesn't exist, so creating the first node..: ");
        head = (struct Node*)malloc(sizeof(struct Node));
        head->data = x;
        head->next = head; // CIRCULAR LINK
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    // Insert at HEAD (position/k == 1)
    if (k == 1) {
        struct Node* temp = head;  //to use temp for traversal and not modify head
        // Traverse to LAST NODE
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    // Insert at Kth position (OTHER THAN HEAD)
    struct Node *temp = head;
    for (int i = 1; i < k - 1 && temp->next != head; i++) {
        temp = temp->next;
    }//We will insert before head(after node linking to head) if k is bigger than the legal indexes
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtKth_CLL(int k)
{
    // Handling Invalid Indexes
    if (k <= 0)
    {
        printf("\nInvalid index! Deletion index must be >= 1.");
        return;
    }
    // if list is EMPTY
    if (head == NULL)
    {
        printf("\nList empty, Nothing to delete!");
        return;
    }
    // if only one Node exists
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    // DELETE at head (position 1)
    if (k == 1) {
        struct Node* temp = head;
        while(temp->next != head)
        {
          temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    // DELETE at kth position (not head)
    struct Node *prev = head;
    struct Node *curr = head->next;
    int i;

    for(i=2; i<k && curr->next != head; i++)  //We have already resolved the case for head deletion
    {
      prev = prev->next;
      curr = curr->next;
    }
    if(i != k)
      printf("\nIllegal Index!...deleting the last node.");
    prev->next = curr->next;
    free(curr);
}

void display_CLL()
{
  if(head==NULL)
  {
    printf("\nList is empty!");
    return;
  }
  struct Node *temp;
  temp = head;
  printf("\n");
  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  while(temp != head);
}




int main()
{
  int data, pos, status=1;

  do
  {
    printf("\n*******************************************************************************************");
    printf("\nWhat?");
    printf("\n1.Insert a Node in Circular Linked List.");
    printf("\n2.Delete a Node from CLL.");
    printf("\n3.Display CLL.");
    printf("\n4.Exit");
    printf("\n*******************************************************************************************");
    printf("\nYour Choice: ");
    scanf("%d", &status);

    switch(status)
    {
      case 1:
        printf("\nEnter data to insert in the new Node: ");
        scanf("%d", &data);
        if(head != NULL)
        {
          printf("\nEnter position(k) where you want to insert new Node(starting from 1): ");
          scanf("%d", &pos);
        }
        else pos=1;
        insertAtKth_CLL(pos, data);
        display_CLL();
        break;
      case 2:
        // for deletion at k
        printf("\nEnter position (k) for deletion(higer than allowed indexes mean deleting the last node!): ");
        scanf("%d", &pos);
        deleteAtKth_CLL(pos);
        display_CLL();
        break;
      case 3:
        display_CLL();
        break;
      case 4:
        status = -1;
        break;
      default:
        printf("\nInvalid Choice!");
    }
  }while(status != -1);

  return 0;
}
