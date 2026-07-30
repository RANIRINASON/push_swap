/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aranirin <aranirin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 00:40:41 by aranirin          #+#    #+#             */
/*   Updated: 2026/05/07 20:34:40 by aranirin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_chunk
{
	int	nb_chunk;
	int	size;
	int	chunk_mid;
	int	chunk_max;
	int	pushed;
	int	chunk_size;
}	t_chunk;

typedef struct s_radix
{
	int	size;
	int	bit;
}	t_radix;

typedef struct s_content
{
	int		mode;
	int		bench;
	int		*count;
	int		mode_count;
	double	disorder;
	t_stack	*a;
	t_stack	*b;
}	t_context;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	op_count,
}	t_op;

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,	
}	t_mode;
t_context	init_global(void);
t_mode		parse_mode(int argc, char **argv);

t_stack		*new_node(int value);
void		add_back(t_stack **a, t_stack *new);
int			stack_size(t_stack *a);
int			is_sorted(t_stack *a);
void		free_stack(t_stack **stack);

int			is_valid_format(char *str);
long		l_atoi(const char *nptr);
int			is_flag(char *arg);
int			ft_check_duplicate(t_stack *a, int value);
void		parse_numbers(t_context *ct, int argc, char **argv);
void		parse_utils(char *arg, t_mode *mode, int *flag_count);

void		sa(t_stack **a, int *count);
void		sb(t_stack **b, int *count);
void		ss(t_stack **a, t_stack **b, int *count);
void		pb(t_stack **a, t_stack **b, int *count);
void		pa(t_stack **a, t_stack **b, int *count);
void		ra(t_stack **a, int *count);
void		rb(t_stack **b, int *count);
void		rr(t_stack **a, t_stack **b, int *count);
void		rra(t_stack **a, int *count);
void		rrb(t_stack **b, int *count);
void		rrr(t_stack **a, t_stack **b, int *count);

void		radix_sort(t_stack **a, t_stack **b, int *count);
void		simple_sort(t_stack **a, t_stack **b, int *count);
void		chunk_sort(t_stack **a, t_stack **b, int *count);
void		adaptive(t_stack **a, t_stack **b, int *count);

void		ft_min_sommet(t_stack **a, t_stack **b);
void		push_to_b(t_stack **a, t_stack **b, int *count);

void		error(void);
void		error_all(t_stack **a, char **split);
void		execute(t_stack **a, t_stack **b,
				t_mode mode, int *count);

void		ft_free_split(char **split);
void		handle_flag(char *arg, t_context *ct);

void		fill_tab(int *tab, t_stack *a);
void		set_index(t_stack *a, int *tab, int size);
void		ft_sort_int_tab(int *tab, int size);

void		ft_printf_fd(int fd, const char *format, ...);
void		printf_bench(t_mode mode, int *count, double disorder);
double		compute_disorder(t_stack *a);
#endif
