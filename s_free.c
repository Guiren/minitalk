/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:35:50 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 15:46:31 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minitalk.h"

void	delete_client(t_list **node)
{
	free(*node);
	*node = NULL;
}

void	remove_client(t_list **client_list, int pid)
{
	t_c_info	*current;
	t_list		*lst;
	t_list		*prev;

	lst = *client_list;
	prev = NULL;
	while (lst != NULL)
	{
		current = (t_c_info *) lst->content;
		if (current->pid == pid)
		{
			if (prev == NULL)
				*client_list = lst;
			else
				prev->next = lst->next;
			delete_client(&lst);
			break ;
		}
		prev = lst;
		lst = lst->next;
	}
}
