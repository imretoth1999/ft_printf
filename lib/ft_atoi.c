/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:08:08 by itoth             #+#    #+#             */
/*   Updated: 2017/04/05 14:27:24 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

long	pf_ft_atoi(const char *str)
{
	long	sign;
	long	nbr;

	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' ||
			*str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nbr = 0;
	while (pf_ft_isdigit((int)*str))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (sign * nbr);
}
