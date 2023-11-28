/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include "functions.h"

node_t *createList(FILE *input, node_t **head)
{
    node_t *current = NULL;
    while (!feof(input))
    {
        current = readNodeInfo(input);
        if (current != NULL)
        {
            add(&current, head);
        }
    }
    return *head;
}

node_t *readNodeInfo(FILE *input)
{
    node_t *node = malloc(sizeof(node_t));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Reading data using scanset conversion
    if (fscanf(input, "%19[^,],%19[^,],%9[^,],%d,%d,%6[^,],%11[^,],%29[^\n]\n",
            node->lastName, node->firstName, node->birthday.month,
            &node->birthday.day,&node->birthday.year, node->degree,
            node->classStanding, node->favoriteBook) == 8)
    {
        return node;
    }
    else
    {
        free(node);
        return NULL;
    }
}

void printList(FILE *out, node_t *head)
{
    if (head == NULL)
    {
        fprintf(stderr, "The list is empty\n");
        exit(1);
    }

    printBorder(out);
    fprintf(out, "LIST INFO:\n");

    node_t *current = head;
    while (current != NULL)
    {
        fprintf(out, "Name: %s %s\n", current->firstName, current->lastName);
        fprintf(out, "Date of Birth: %s %d, %d\n", current->birthday.month,
                current->birthday.day, current->birthday.year);
        fprintf(out, "Degree: %s\n", current->degree);
        fprintf(out, "Class Standing: %s\n", current->classStanding);
        fprintf(out, "Preferred Reading: %s\n\n", current->favoriteBook);
        current = current->next;
    }

    printBorder(out);
}

void add(node_t **node, node_t **head)
{
    if (*head == NULL)
    {
        *head = *node;
    }
    else
    {
        node_t *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = *node;
    }
    (*node)->next = NULL;
}
/*This function prints all node information. */

void printBorder(FILE *out)
{
    for (int i = 0; i < 80; i++)
    {
        fprintf(out, "*");
    }
    fprintf(out, "\n");
}

void deleteList(node_t **head)
{
    node_t *current = *head;
    node_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
