#include <stdio.h>
#include <stdlib.h>

struct Node
{   // elements of linked list
    int data;
    struct Node* next;
};
struct Node* head;

void Insert_end (int x);
void Insert_begin (int x);
void Insert_nth(int x, int n);
void Delete(int n);
void Reverse();
void Reverse_rec(int x);
void Print();

int main()
{
    int i,n,x,ele,m;
    head = NULL;
    printf("Enter number of elements = ");
    scanf("%d",&n);

    for( i = 0 ; i < n ; i++)
    {
        printf("\nEnter element number %d = ",i);
        scanf("%d",&x);
        Insert_begin(x);
        Print();
    }
    Reverse_rec(0);
    Print();

    return 0;
}

void Insert_end (int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(int));
    struct Node* temp1 = (struct Node*) malloc(sizeof(int));
    temp1 = head ;

    if(head == NULL){
        temp->data = x;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        temp->data = x;
        temp->next = NULL;
        while(temp1->next != NULL)
        {
            temp1=temp1->next;
        }
        temp1->next= temp;
    }
}

void Insert_begin (int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(int));

        temp->data = x;
        temp->next = head;
        head = temp;
}

void Print()
{
    struct Node* temp = head;
    while( temp != NULL )
    {
        printf(" %d ",temp->data);
        temp = temp->next;

    }
    printf("\n");
}

void Insert_nth(int x, int n)
{
    if(n==0)
    {
        Insert_begin(x);
        return;
    }
    int i;

    struct Node* temp = (struct Node*)malloc(sizeof(int));
    struct Node* temp1 = (struct Node*)malloc(sizeof(int));
    temp1 = head;

    for (i=0 ; i < n-1 ; i++){
        temp1 = temp1->next;
        if((temp1==NULL) && (i == n-2))
        {
            printf("\nPosition");
            Insert_end(x);
            return;
        }
        else if ((temp1==NULL) & (i != n-2))
        {
            printf("\n Invalid element position");
            return;
        }
    }

    temp->data = x;
    temp->next = temp1->next;
    temp1->next = temp;

}

void Delete(int n)
{
    int i;
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    struct Node* temp1 = (struct Node*)malloc(sizeof(int));
    temp1 = head;

    if (n==0)
    {
        head = temp1->next;
        free(temp1);
        return;
    }

    for( i = 0 ; i< n-1 ; i++)
    {
        temp1=temp1->next;
    }
    temp = temp1->next;
    temp1->next=temp->next;
    free(temp);
}

void Reverse()
{

    struct Node* next;
    struct Node* previous = head;
    struct Node* current = NULL;
    while(head != NULL)
    {
        next = head->next;
        previous = head;
        previous->next = current;
        current = head;
        head = next;
    }
    head = previous;

}
void Reverse_rec(int x)
{
    x++;
    struct Node* new_value = head;
    struct Node* current_address = head->next;

    if (current_address == NULL)
    {
        head = new_value;
        return;
    }
    head = head->next;
    Reverse_rec(x);
    current_address->next = new_value;

    if (x == 1)
    {
            new_value->next = NULL;

    }
    return;
}
