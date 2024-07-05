/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:59:26 by ymauk             #+#    #+#             */
/*   Updated: 2024/03/21 11:52:37 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *value)
{
	int	counter;

	counter = 0;
	while (*value != '\0')
	{
		counter += 1;
		value += 1;
	}
	return (counter);
}
