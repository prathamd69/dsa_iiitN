/*
237. Delete Node in a Linked List

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node.
You will not be given access to the first node of head.

All the values of the linked list are unique, and it is
guaranteed that the given node node is not the last node in the linked list.


Sol - Understanding the constraints and the standard operations on a 
linked list is key to solving this problem. 
Given that we cannot directly remove the target node by changing its 
previous node's next pointer (because we don't have access to it), 
we can use a clever trick: copy the value from the next node into the target node, 
and then remove the next node instead. 
This effectively overwrites the target node's value with its successor's value, 
and then deleting the successor (which we have access to) 
achieves the goal of removing the target node's value from the list. 
The key realization here is that we're not actually deleting the given node, 
but rather, we're making it a clone of the next node in terms of value, 
then skipping over the next node, effectively removing its presence from the list.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{

    while (node->next->next != NULL)
    {

        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = NULL;
}