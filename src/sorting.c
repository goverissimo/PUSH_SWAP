#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index; //primeiro elemento na lista
	max_bits = 0;
	while (head)
	{
		if (head->index > max) //se o elemento atual for maior que o max, atualizar valor do max
			max = head->index;
		head = head->next;
	}
	//quando nao houver mais lista percorrida, calcular bits
	while ((max >> max_bits++) != 0);//right shift bitwise operator, 7>>3 = 0 logo parar o loop e dar return de 3.
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a); //numero de vezes que vai ser iterado
	max_bits = get_max_bits(stack_a); //obter o valor de bits maximo
	while (i < max_bits) //enquanto não percorrer o numero maximo de bits
	{
		j = 0;
		while (j++ < size) //percorrer cada elemento da lista
		{
			head_a = *stack_a; //head_a é inicializado de novo para a head do stack A
			if (((head_a->index >> i) & 1) == 1) //SE o Bit i estiver set (=1), 
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

/*
void radix_sort(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    int i, j, size, max_bits;
    int ra_count, pa_count;

    i = 0;
    head_a = *stack_a;
    size = ft_lstsize(head_a);
    max_bits = get_max_bits(stack_a);
    while (i < max_bits)
    {
        j = 0;
        ra_count = 0;  // Count of ra operations
        pa_count = 0;  // Count of pa operations

        while (j++ < size)
        {
            head_a = *stack_a;
            if (((head_a->index >> i) & 1) == 1)
            {
                ra(stack_a);
                ra_count++;
            }
            else
            {
                pb(stack_a, stack_b);
            }
        }

        // Move back elements from stack_b to stack_a in one go
        pa_count = ft_lstsize(*stack_b);
        while (pa_count-- > 0)
            pa(stack_a, stack_b);

        // Reverse the ra operations in one go if needed
        while (ra_count-- > 0)
            rra(stack_a);

        i++;
    }
}
*/



void sort_stacks(t_list **stack_a, t_list **stack_b)
{
	
    radix_sort(stack_a, stack_b);
    //reverse_stack(stack_a);
	
}