/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:17:06 by itoth             #+#    #+#             */
/*   Updated: 2017/04/05 14:17:07 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		pf_ft_display_arg(t_flag *f)
{
	int		i;
	size_t	len;

	if ((i = -1) && ((f->spe == 's' && f->fla[10] == 1) || f->spe == 'S' ||
		(f->spe == 'c' && f->fla[10] == 1) || f->spe == 'C'))
	{
		if (f->arg != NULL)
		{
			if (f->arg[0] == '\0' && (f->spe == 'C' ||
				(f->spe == 'c' && f->fla[10] == 1)))
				pf_ft_buf('\0', f);
			len = pf_ft_strlen(f->arg);
			while (len-- > 0)
				pf_ft_buf(f->arg[++i], f);
		}
		else if (f->fla[0] != -1)
			pf_ft_buf_null(f);
	}
	else
	{
		while (f->arg[++i] != '\0')
			pf_ft_buf(f->arg[i], f);
	}
	pf_ft_end(f);
}

void		pf_ft_zero_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - pf_ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	while (nb_space-- > 0)
	{
		if (f->fla[3] == 1 && f->fla[0] <= 0)
			pf_ft_buf('0', f);
		else
			pf_ft_buf(' ', f);
	}
	pf_ft_display_arg(f);
}

void		pf_ft_minus_char(t_flag *f)
{
	int		nb_space;

	nb_space = f->fla[1] - pf_ft_strlen(f->arg);
	if ((f->spe == 'c' && f->arg[0] == 0) || (f->spe == 'C' && f->arg[0] == 0))
		nb_space--;
	pf_ft_display_arg(f);
	while (nb_space-- > 0)
		pf_ft_buf(' ', f);
}

void		pf_ft_width_char(t_flag *f)
{
	int		i;

	i = 0;
	if (f->arg)
		i = pf_ft_strlen(f->arg);
	if (i < f->fla[1])
	{
		if (f->fla[4] == 1)
			pf_ft_minus_char(f);
		else
			pf_ft_zero_char(f);
	}
	else
		pf_ft_display_arg(f);
}
