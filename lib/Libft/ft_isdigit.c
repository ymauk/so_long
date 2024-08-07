/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymauk <ymauk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:23:08 by ymauk             #+#    #+#             */
/*   Updated: 2024/03/21 11:32:05 by ymauk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int value)
{
	if (value >= 48 && value <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
