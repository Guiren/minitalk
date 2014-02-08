/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 13:54:08 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/07 14:02:31 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Received SIGUSR1!\n");
	if (signum == SIGUSR2)
		_exit(0);
}

int		main(int argc, char *argv[])
{
	printf("PID = %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (42)
		pause();
	return (0);
}
