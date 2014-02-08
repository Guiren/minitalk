/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 15:17:20 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 15:44:19 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "libft.h"

typedef struct		s_c_info
{
	char	*str;
	char	c;
	int		n;
	char	mask;
	int		pid;
}					t_c_info;

t_c_info	*ft_get_client(t_list *c_list, int pid);
void		ft_init_client_infos(t_c_info *new_one, struct __siginfo *info);
int			ft_existing_pid(t_list *client_list, int pid);
int			print_usage(void);
char		*straddchar(char *str, char c);
void		remove_client(t_list **client_list, int pid);

#endif
