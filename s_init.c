/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:01:32 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 14:39:08 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "minitalk.h"

t_c_info	*ft_get_client(t_list *c_list, int pid)
{
	t_c_info	*current;

	while (c_list != NULL)
	{
		current = (t_c_info *) c_list->content;
		if (current->pid == pid)
			return (current);
		c_list = c_list->next;
	}
	return (NULL);
}

void		ft_init_client_infos(t_c_info *new, struct __siginfo *info)
{
	new->pid = (int)info->si_pid;
	new->str = NULL;
	new->c = 0;
	new->n = 0;
	new->mask = 1;
}

int			ft_existing_pid(t_list *client_list, int pid)
{
	t_c_info	*current;

	if (client_list != NULL)
	{
		while (client_list != NULL)
		{
			current = (t_c_info *) client_list->content;
			if (current->pid == pid)
				return (1);
			client_list = client_list->next;
		}
	}
	return (0);
}
