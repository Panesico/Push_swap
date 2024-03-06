/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:57:16 by panesico          #+#    #+#             */
/*   Updated: 2023/06/13 20:56:52 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

typedef struct s_lista
{
	int				content;
	struct s_lista	*next;
}					t_lista;

typedef struct s_stc
{
	t_lista	**hash;
	int a_s;
	int b_s;
	int ward;
	int max;
	int *lis;
	int l_s;
	int *tb_a;
	int tba_s;
	int *tmp;
	int *tmp2;
	int min;
	int min_pos;
	int max_num;
	int max_num_pos;
	int final_moves;
	t_lista *fna;
}	t_stc;

void	ft_sa(t_stc *stc, int boole);
void	ft_sb(t_stc *stc, int boole);
void	ft_ss(t_stc *stc);
void	ft_pa(t_stc *stc);
void	ft_pb(t_stc *stc);
void	ft_ra(t_stc *stc, int boole);
void	ft_rb(t_stc *stc, int boole);
void	ft_rr(t_stc *stc);
void	ft_rra(t_stc *stc, int boole);
void	ft_rrb(t_stc *stc, int boole);
void	ft_rrr(t_stc *stc);
int		*ft_parser(int argc, char **argv, int *size);
void	ft_del_content(void *content);
t_lista	**ft_fill_hash(t_lista **hash, int *tab, int size, t_lista **last);
t_lista	**ft_create_hash(int *tab, int size, t_lista **last);
t_stc	*ft_create_stc(int *tab, int size, int *lis, int lis_size);
void	ft_move_set_finder(t_stc *stc, int move_set);
void	ft_fill_lis(t_stc *stc);
void	ft_lis_to_b(t_stc *stc);
int		ft_solver(t_stc *stc);
int		*ft_parser(int argc, char **argv, int *size);
int		ft_final_validator(t_stc *stc);
void	ft_final_sort(t_stc *stc, int boole);
int		ft_moves_finder(t_stc *stc);
int		ft_lis(t_stc *stc);
void	ft_min_finder(t_stc *stc); //mirar si sirve
void	ft_max_finder(t_stc *stc); //mirar si sirve
void	ft_min_finder_list(t_stc *stc, int half);
void	ft_max_finder_list(t_stc *stc, int half);
void	ft_free_all(t_stc *stc);
int		ft_b_more_than_2(t_stc *stc);
void	ft_sort_3(t_stc *stc);
void	ft_sort_5(t_stc *stc);
void	ft_find_best_move(t_stc *stc);
int		ft_check_if_num_split(char **str);
int		ft_check_if_num_argv(int argc, char **argv);
int		ft_validate_if_dup(t_stc *stc);

#endif