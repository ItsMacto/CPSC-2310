/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    char month[10];
    int day;
    int year;
} Birthday;

typedef struct node {
    char firstName[20];
    char lastName[20];
    char degree[7];
    char classStanding[12];
    char favoriteBook[30];
    Birthday birthday;
    struct node *next;
} node_t;


/**
 * Adds a new node to the end of a linked list.
 * @param node The new node to be added.
 * @param head The head of the list.
 */
void add(node_t **node, node_t **head);

/**
 * Reads node information from a file.
 * @param input The file pointer to read from.
 * @return A pointer to the newly created node with the read information.
 */
node_t* readNodeInfo(FILE* input);

/**
 * Creates a linked list from file input.
 * @param input The file pointer to read from.
 * @param head Pointer to the head of the list.
 * @return A pointer to the head of the created list.
 */
node_t* createList(FILE*, node_t**);

/**
 * Prints the linked list to a specified file.
 * @param out The file pointer to write to.
 * @param head The head of the list to be printed.
 */
void printList(FILE*, node_t*);

/**
 * Prints a border of asterisks to a file.
 * @param out The file pointer to write the border to.
 */
void printBorder(FILE*);

/**
 * Deletes the entire linked list and frees memory.
 * @param head Pointer to the head of the list.
 */
void deleteList(node_t** );


#endif // FUNCTIONS_H


