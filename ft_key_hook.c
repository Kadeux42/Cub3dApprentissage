/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shlu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:55:01 by shlu              #+#    #+#             */
/*   Updated: 2021/02/17 19:21:35 by shlu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

static inline

int			is_in_list(int keycode, t_list *l)
{
	while (l)
	{
		if (*((int *)l->content) == keycode)
			return (1);
		l = l->next;
	}
	return (0);
}

int			ft_key_hook(int keycode, t_cub *c)
{
	(void)keycode;
	if (is_in_list(K_W, ((t_cub *)c)->lkeys) == 1)
		ft_move_front(c->s, c->r);
	if (is_in_list(K_S, ((t_cub *)c)->lkeys) == 1)
		ft_move_back(c->s, c->r);
	if (is_in_list(K_A, ((t_cub *)c)->lkeys) == 1)
		ft_move_l_front(c->s, c->r);
	if (is_in_list(K_D, ((t_cub *)c)->lkeys) == 1)
		ft_move_r_front(c->s, c->r);
	if (is_in_list(K_ARROW_L, ((t_cub *)c)->lkeys) == 1)
	{
		ft_rotate(K_ARROW_L, c->r);
		(c->r)->action = 1;
	}
	if (is_in_list(K_ARROW_R, ((t_cub *)c)->lkeys) == 1)
	{
		ft_rotate(K_ARROW_R, c->r);
		(c->r)->action = 1;
	}
	return (0);
}

int			ft_key_released(int keycode, void *c)
{
	t_list	*n;
	t_list	*tmp;

	n = ((t_cub *)c)->lkeys;
	while (n->next)
	{
		if (*((int *)n->next->content) == keycode)
		{
			tmp = n->next;
			n->next = n->next->next;
			ft_lstdelone(tmp, &free);
			return (keycode);
		}
		n = n->next;
	}
	return (keycode);
}

int			ft_key_pressed(int keycode, void *c)
{
	int		*new_key;

	if (keycode == K_ESC)
		ft_free_all_struct(c);
	if (is_in_list(keycode, ((t_cub *)c)->lkeys) == 0)
	{
		new_key = malloc(sizeof(int));
		*new_key = keycode;
		ft_lstadd_back(&((t_cub *)c)->lkeys, ft_lstnew(new_key));
	}
	return (keycode);
}
