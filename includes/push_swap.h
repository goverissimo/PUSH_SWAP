#ifndef push_swap
#define push_swap
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//#include "./printf_42/ft_printf.h"

typedef struct node
{
    int value;
    struct node *next;
} Node;

// Function prototypes
void sa(Node *node);
void sb(Node *node);
void ss(Node *stack_a, Node *stack_b);
void pa(Node *stack_a, Node *stack_b);
void pb(Node *stack_a, Node *stack_b);
Node    *ra(Node *node);
Node	*rb(Node *node);
Node	*rr(Node **stack_a, Node **stack_b);
Node	*rra(Node *node);
Node	*rrb(Node *node);
Node	*rrr(Node **stack_a, Node **stack_b);
void print_list(Node *head);
int recursive_length(Node *node);
Node *insert_at_head(Node *head, int new_value);
Node *remove_at_head(Node *head);
Node *insert_at_tail(Node *head, int new_value);
Node *delete_at_tail(Node *head);

#endif /* ALLOWED_FUNCTIONS_H */