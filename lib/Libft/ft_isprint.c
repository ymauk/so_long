/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:52:36 by ymauk             #+#    #+#             */
/*   Updated: 2024/03/21 11:46:05 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int value)
{
	if (value >= 32 && value <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
