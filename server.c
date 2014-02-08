/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:30:30 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 16:07:23 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "libft.h"

void	ft_dummy(void)
{
	while (0);
}

void	ft_render_str(t_c_info *current)
{
	ft_putstr("Client ");
	ft_putnbr(current->pid);
	ft_putendl(" said : ");
	ft_putendl(current->str);
	free(current->str);
}

int		ft_decoder(t_c_info *current, int signum)
{
	if (signum == SIGUSR1)
		current->c |= current->mask;
	if (signum == SIGUSR2)
		current->c |= 0;
	current->mask <<= 1;
	current->n += 1;
	if (current->n == 8)
	{
		current->str = straddchar(current->str, current->c);
		if (current->c == 0)
		{
			ft_render_str(current);
			return (1);
		}
		else
		{
			current->mask = 1;
			current->n = 0;
			current->c = 0;
		}
	}
	return (0);
}

void	handler_saction(int n, struct __siginfo *info, void *uap)
{
	static t_list	*client_list = NULL;
	t_c_info		new;
	t_c_info		*current;

	if (ft_existing_pid(client_list, (int)info->si_pid) == 0)
	{
		ft_init_client_infos(&new, info);
		if (client_list == NULL)
			client_list = ft_lstnew(&new, 0);
		else
			ft_lstaddend(&client_list, ft_lstnew(&new, 0));
	}
	current = ft_get_client(client_list, (int)info->si_pid);
	(void) n;
	if (ft_decoder(current, n) == 1)
		remove_client(&client_list, current->pid);
	(void) uap;
	if (kill(current->pid, SIGUSR1) == -1)
		ft_putendl("client died !");
}

int		main(void)
{
	int					i;
	struct sigaction	get_clientinfo;

	i = 0;
	get_clientinfo.sa_sigaction = handler_saction;
	get_clientinfo.sa_flags = SA_SIGINFO;
	get_clientinfo.sa_mask = SIGUSR1;
	sigaction(SIGUSR1, &get_clientinfo, NULL);
	sigaction(SIGUSR2, &get_clientinfo, NULL);
	ft_putstr("Welcome!\nPID = ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
	return (0);
}
