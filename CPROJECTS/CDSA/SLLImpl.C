#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct sllnode
{
    int val;
    struct sllnode *link;
};

struct sllnode *home, *first, *temp = 0;

int choice = 0;

void initLinkedList()
{
    while (choice)
    {
        home = (struct sllnode *)malloc(sizeof(struct sllnode));
        printf("\nEnter int Data: \n");
        scanf("%d", &(home->val));
        if (first != 0)
        {
            temp->link = home;
            temp = home;
        }
        else
        {
            first = temp = home;
        }
        fflush(stdin);
        printf("\nContinue? 0 or 1\n");
        scanf("%d", &choice);
    }
    temp->link = 0;
}

void displayLinkedList()
{
    temp = first;
    printf("\nLinkedList: ");
    int cnt = 0;
    while (temp != 0)
    {
        printf(" %d => ", temp->val);
        cnt++;
        temp = temp->link;
    }
    printf("NULL\n Count is: %d", cnt);
}