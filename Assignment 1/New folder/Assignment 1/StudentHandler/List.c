#include "List.h"
#include <stdlib.h>

list_t create(void) {
    list_t head;
    head = calloc(sizeof(node_t), 1);
    head->item = NULL;
    head->next = NULL;
    return head;
}

ListReturnCode destroy(list_t list)
{
    list_t temp = list;

    while (temp != NULL) {
        free(&temp);
        temp = temp->next;
    }
    list->item = NULL;
    list->next = NULL;
}

ListReturnCode addItem(list_t list, void* itm)
{
    /*
    if (list == NULL) {
        list_t newNode = calloc(sizeof(node_t), 1);
        newNode->item = itm;
        newNode->next = NULL;
        list = newNode;
        return OK;
    }
    */
    if (list->item == NULL) {
        list->item = itm;
        return OK;
    }

    list_t currentNode = list;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    list_t newNode = calloc(sizeof(node_t), 1);
    newNode->item = itm;
    currentNode->next = newNode;

    return OK;
}

void* getItemByIndex(list_t list, uint16_t index)
{
    list_t temp = list;
    uint16_t i = 0;

    while (temp != NULL) {
        if (index == i) {
            return list->item;
        }
        i += 1;
        temp = temp->next;
    }
}

ListReturnCode removeItem(list_t nodeToDelete, void* itm) {
    list_t childNode = nodeToDelete->next;
    list_t parentNode = nodeToDelete;

    if (nodeToDelete == NULL)
    {
        return EMPTY;
    }

    if (nodeToDelete->item == itm) {
        nodeToDelete->item = NULL;
        return OK;
    }

    while (childNode != NULL) {
        if (childNode->item == itm) {
            parentNode->next = childNode->next;
            free(&childNode);
            return OK;
        }
        parentNode = childNode;
        childNode = childNode->next;
    }
    return NOT_FOUND;
}

uint16_t noOfitems(list_t list)
{
    list_t temp = list;
    uint16_t result = 0;

    while (temp != NULL && temp->item != NULL) {
        result += 1;
        temp = temp->next;
    }
    return result;
}

ListReturnCode contains(list_t list, void* item)
{
    list_t temp = list;

    while (temp != NULL) {
        if (item == temp->item) {
            return OK;
        }
        temp = temp->next;
    }
    return NOT_FOUND;
}