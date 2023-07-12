#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;

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

Node *insert_at_tail(Node *head, int new_value) // INSERTING A NODE
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

Node *remove_at_head(Node *head)
{
    if (head == NULL)
        return NULL; // if theres not an head, return NULL
    else
    {
        Node *to_return = head->next; // Node to_return is the next one after the head.
        free(head);                   // frees the whole head Node, and then returns the new linked list with the updated values
        return to_return;
    }
}

Node *remove_at_tail(Node *head)
{
    if (head == NULL)
        return NULL;          head      // prev node is equal to the current node
            current = current->next; // point current node to the next one. meanwhile, the condition will break if current is NULL, so the prev node will be the previous node if this one is pointing to NULL
        }
        prev->next = NULL; // point our previous node to null, to discard the last node
        free(current);     // free the current node.
        return head;
    }
}

int recursive_length(Node *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + recursive_length(node->next); // returns the current node +rest (recursively)
}

int length(Node *head)
{
    Node *current;
    current = head;
    int length = 0;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

bool is_member(Node *node, int find_value)
{
    if (node == NULL)
        return false;
    else if (node->value == find_value)
        return true;
    else
        return is_member(node->next, find_value);
}

int count_matches(Node *node, int find_value)
{
    if (node == NULL)
        return 0;
    else if (node->value == find_value)
        return 1 + count_matches(node->next, find_value);
    else
        return count_matches(node->next, find_value);
}

void replace_matches(Node *node, int find_value, int replace_value)
{
    if (node != NULL)
    {
        if (node->value == find_value)
            node->value = replace_value;                        // if value of node is the same as the one we are looking for, replace it
        replace_matches(node->next, find_value, replace_value); // call the function again with the next node
    }
}

Node *delete_first_match(Node *head, int delete_value, bool *was_deleted)
{
    if (head == NULL)
    {
        *was_deleted = false;
        return NULL;
    }
    if (head->value == delete_value)
    {
        Node *temp = head->next;
        free(head);
        *was_deleted = true;
        return temp;
    }

    Node *current = head->next;
    Node *prev = head;

    while (current != NULL)
    {
        if (current->value == delete_value)
        {
            prev->next = current->next;
            free(current);
            *was_deleted = true;
            return head;
        }
        prev = current;
        current = current->next;
    }

    *was_deleted = false;
    return head;
}

int main(void)
{
    Node *list_head = NULL;
    list_head = insert_at_head(list_head, 7);
    list_head = insert_at_tail(list_head, 5);
    list_head = insert_at_tail(list_head, 5);
    list_head = insert_at_head(list_head, 6);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_head(list_head, 5);
    list_head = insert_at_tail(list_head, 23);
    list_head = insert_at_tail(list_head, 27);
    list_head = insert_at_tail(list_head, 5);
    printf("After inserting:\n");
    print_list(list_head);
    list_head = remove_at_head(list_head);
    printf("after removing head:\n");
    print_list(list_head);
    list_head = remove_at_tail(list_head);
    printf("after removing tail:\n");
    print_list(list_head);
    printf("Size of list: %d\n", length(list_head));
    printf("Size of list: %d\n", recursive_length(list_head));
    bool result = is_member(list_head, 23);
    printf("%s\n", result ? "True" : "False");
    int matches = count_matches(list_head, 5);
    printf("Number of matches: %d\n", matches);
    replace_matches(list_head, 5, 14);
    printf("Number of matches: %d\n", matches);
    print_list(list_head);
}