#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50

// Structures defined as given
struct movie
{
    char title[MAX_TITLE_LENGTH];
    float score;
};

typedef struct item
{
    struct movie mv;
    struct item *next;
} item;

// Function to create a new item
item *createItem(const char *title, float score)
{
    item *newItem = (item *)malloc(sizeof(item));
    strncpy(newItem->mv.title, title, MAX_TITLE_LENGTH);
    newItem->mv.score = score;
    newItem->next = NULL;
    return newItem;
}

// Function to add an item to the list
void addItem(item **head, const char *title, float score)
{
    item *newItem = createItem(title, score);
    newItem->next = *head;
    *head = newItem;
}

// Function to print the list
void printList(item *head)
{
    item *current = head;
    while (current != NULL)
    {
        printf("Title: %s, Score: %.2f\n", current->mv.title, current->mv.score);
        current = current->next;
    }
}

// Function to find and average duplicates
void processList(item **head)
{
    item *current = *head;
    item *prev = NULL;

    while (current != NULL)
    {
        item *runner = current->next;
        item *runnerPrev = current;
        float sum = current->mv.score;
        int count = 1;

        while (runner != NULL)
        {
            if (strcmp(current->mv.title, runner->mv.title) == 0)
            {
                sum += runner->mv.score;
                count++;
                // Remove the duplicate
                runnerPrev->next = runner->next;
                free(runner);
                runner = runnerPrev->next;
            }
            else
            {
                runnerPrev = runner;
                runner = runner->next;
            }
        }

        // Update the score to average
        if (count > 1)
        {
            current->mv.score = sum / count;
        }

        prev = current;
        current = current->next;
    }
}

int main()
{
    item *head = NULL;

    // Example list with duplicate entries
    addItem(&head, "Movie A", 8.0);
    addItem(&head, "Movie B", 7.5);
    addItem(&head, "Movie A", 9.0);
    addItem(&head, "Movie C", 6.5);
    addItem(&head, "Movie B", 8.5);

    printf("Original list:\n");
    printList(head);

    processList(&head);

    printf("\nProcessed list:\n");
    printList(head);

    // Free the list
    item *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
