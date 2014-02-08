/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_usage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:15:52 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/07 15:17:13 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_usage(void)
{
	ft_putendl_fd("usage: ./client <server_pid> <string to send>", 2);
	return (2);
}
