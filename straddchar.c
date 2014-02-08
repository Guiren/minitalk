/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   straddchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnathana <cnathana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:44:23 by cnathana          #+#    #+#             */
/*   Updated: 2014/02/08 16:42:52 by cnathana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*straddchar(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (str == NULL)
	{
		str = (char *) malloc(sizeof(char));
		str[0] = c;
		return (str);
	}
	else
	{
		while (str[i] != 0)
			++i;
		new = (char *) malloc(sizeof(char) * ft_strlen(str) + 2);
		new = ft_strcpy(new, str);
		new[i] = c;
		new[i + 1] = 0;
	}
	return (new);
}
