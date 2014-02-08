/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:06:11 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 16:43:42 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "minitalk.h"

void	ft_do_nothing(int num)
{
	while (0)
		num = 1;
}

int		encode_char(char c, int server)
{
	int		i;

	i = 0;
	while (i++ < 8)
	{
		if ((c & 1) == 1)
			kill(server, SIGUSR1);
		else
			kill(server, SIGUSR2);
		c = c >> 1;
		pause();
	}
	return (0);
}

int		encode_str(char *str, int server)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		encode_char(str[i], server);
		++i;
	}
	encode_char('\0', server);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		server;

	if (argc < 3)
		return (print_usage());
	signal(SIGUSR1, ft_do_nothing);
	server = ft_atoi(argv[1]);
	encode_str(argv[2], server);
	usleep(200);
	return (0);
}
