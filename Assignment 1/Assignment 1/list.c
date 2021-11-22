#include "list.h"
#include <stdlib.h>

static Node* head;

static Node* _findTail(Node head)
{
	if (!head->next)
	{
		return head;
	}
	else {
		return _findTail(head->next);
	}
}

static uint16_t _countToTail(Node head) {
    if (head == NULL)
    {
        return 0;
    }
    else if (head->next == NULL) 
    {
		return 1;
	}
	else {
		return _countToTail(head->next) + 1;
	}
}

static Node* _findNodeByIndex(Node head, uint16_t index) {
    if (index != 0 && head->next) {
        return _findNodeByIndex(head->next, index - 1);
    }
    else if (head) {
        return head;
    }
    else {
        return NULL;
    }
}

static Node* _findNodeByItem(Node head, void** itm) {
    if (head->item == *itm) {       //This works for ints
        return head;
    }
    else if (head->item == itm) {   //This if statement works for structs and strings
        return head;
    }
    else if (!head->next) {
        return NULL;
    }
    else {
        return _findNodeByItem(head->next, itm);
    }
}

static Node* _findParentNode(Node head, Node* childNode) {
    if (head->next == childNode) {
        return head;
    }
    else if (!head->next) {
        return NULL;
    }
    else {
        return _findParentNode(head->next, childNode);
    }
}

static ListReturnCode _deleteNodesCascade(Node head) {
    if (!head) {
        return OK;
    }
    else {
        if (head->next) {
            Node* next = head->next;
            free(head->item);
            free(head);
            return _deleteNodesCascade(next);
        }
        else {
            free(head->item);
            free(head);
            return OK;
        }
    }
}

void create() {
	head = NULL;
}

ListReturnCode destroy()
{
    return _deleteNodesCascade(head);
}

ListReturnCode addItem(void* itm)
{
    Node newNode = calloc(sizeof(Node), 1);
    newNode->item = itm;
    newNode->next = NULL;

    if (head != NULL)
    {
        Node tail = _findTail(head);
        tail->next = newNode;
        return OK;
    } 
    else if (head == NULL)
    {
        head = newNode;
        return OK;
    }
    else
    {
        return ERROR;
    }
    
}

static Node* _findNodeByIndex(Node head, uint16_t index) 
{
    Node tempList;

    for (uint16_t i = 0; i < index; i++)
    {
        tempList = _findNodeByIndex(head, i);
    }

    return tempList;
}

void* getItem(uint16_t index)
{
    Node tempNode = _findNodeByIndex(head, index);
    return tempNode->item;
}

static Node* _findNodeByItem(Node head, void** itm) {
    if (head->item == *itm) {       //This works for ints
        return head;
    }
    else if (head->item == itm) {   //This if statement works for structs and strings
        return head;
    }
    else if (!head->next) {
        return NULL;
    }
    else {
        return _findNodeByItem(head->next, itm);
    }
}

void* getItem(void** itm)
{
    Node data = findNodeByItem(head, itm);
    return data->item;
}

ListReturnCode removeItem(void* itm) {
    Node nodeToDelete = _findNodeByItem(head, itm);
    Node childNode = nodeToDelete->next;
    Node parentNode = _findParentNode(nodeToDelete, itm);

    if (head == NULL)
    {
        return ERROR;
    }
    else if (nodeToDelete == NULL)
    {
        return NOT_FOUND;
    }
    else if (childNode == NULL)
    {
        free(nodeToDelete);
        parentNode->next = NULL;
        free(parentNode);
        return OK;
    }
    else if (childNode == NULL && parentNode != )
    {
        free(nodeToDelete);
        parentNode->next = childNode;
        free(parentNode);
        free(childNode);
        return OK;
    }
}

uint16_t noOfitems()
{
    return countToTail(head);
}