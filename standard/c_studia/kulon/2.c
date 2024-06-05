#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *next;
};

void printList(struct Node *head);
void addToList(struct Node **head, int val, int index);
void removeOutsideRange(struct Node **head, int a, int b);

int main()
{
    struct Node *head = NULL;

    for (int i = 0; i < 5; i++)
    {
        addToList(&head, i, i);
    }
    printList(head);

    removeOutsideRange(&head, 2, 3);

    printList(head);

    return 0;
}

void addToList(struct Node **head, int val, int index)
{
    if (*head == NULL)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->value = val;
        newNode->next = NULL;
        *head = newNode;
        return;
    } // case when adding to an empty list

    int i = 0;
    struct Node *curr = *head;
    struct Node *prev = NULL;

    bool added = false;

    while (curr)
    {
        if (i == index)
        {
            struct Node *newNode = malloc(sizeof(struct Node));
            newNode->value = val;
            if (prev)
            {
                newNode->next = curr;
                prev->next = newNode;
                // normal add
            }
            else
            {
                struct Node *temp = malloc(sizeof(struct Node));
                temp->next = (*head)->next;
                temp->value = (*head)->value;

                newNode->next = temp;
                *head = newNode;
                // add at the start
            }
            added = true;
            break;
        }
        i++;
        prev = curr;
        curr = curr->next;
    }

    if (!added)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->value = val;
        newNode->next = NULL;

        prev->next = newNode;
    } // add to list if index not found -> means that we need to add at the back
}

void printList(struct Node *head)
{
    struct Node *curr = head;
    printf("[ ");
    while (curr)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("]\n");
}

void removeOutsideRange(struct Node **head, int a, int b)
{
    struct Node *current = *head;
    struct Node *prev = NULL;

    // Traverse the list and remove nodes outside the range
    while (current != NULL)
    {
        if (current->value < a || current->value > b)
        {
            if (prev == NULL)
            { // If removing the head of the list
                struct Node *temp = current;
                *head = current->next;
                current = current->next;
                free(temp);
            }
            else
            { // If removing an internal node
                struct Node *temp = current;
                prev->next = current->next;
                current = current->next;
                free(temp);
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}
