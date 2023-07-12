/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:39:11 by gverissi          #+#    #+#             */
/*   Updated: 2023/07/12 20:30:06 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
int recursive_length(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + recursive_length(node->next); // returns the current node +rest (recursively)
}

Node *insert_at_head(Node *head, int new_value) // INSERTING A NODE
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;

    if (head == NULL)
        return new_node; // If there are not any nodes, create the head node.
    else
    {
        new_node->next = head; // if the heads exists, point the node to it
        return new_node;
    }
}

Node *remove_at_head(Node *head)
{
    Node *to_return;
    if (head == NULL)
        return NULL; // if theres not an head, return NULL
    else
    {
        to_return = head->next; // Node to_return is the next one after the head.
        //free(head);                   // frees the whole head Node, and then returns the new linked list with the updated values
        return to_return;
    }
}

Node *delete_at_tail(Node *head)
{
  if (head == NULL) return NULL; 
  else if (head->next == NULL)
  {
    free(head);
    return NULL;
  }
  else 
  {
    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL)
    {
      prev = current;
      current = current->next;
    }

    prev->next = NULL;
    free(current);
    return head;
  }
}

Node *insert_at_tail(Node *head, int new_value) 
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->value = new_value;

    if (head == NULL)
        return new_node; // If there are not any nodes, create the head node.
    else
    {
        Node *current = head; // current = head
        while (current->next != NULL)
            current = current->next; // While the next node is not NULL, keep iterating through
        current->next = new_node;    // assuming that right now the last node is pointing to a NULL node, change its pointer to our freshly created node;
        return head;                 // return head of node.
    }
}
void print_list(Node *head) // recieves HEAD pointer;
{
    Node *current;  // create a pointer to a node
    current = head; // set it equal to the head node
    int counter = 0;

    while (current != NULL)
    {
        printf("Node %d: %d\n", counter, current->value); // iterate through the existing nodes
        counter++;
        current = current->next;
    }
}