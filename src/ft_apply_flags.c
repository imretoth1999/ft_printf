/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:16:25 by itoth             #+#    #+#             */
/*   Updated: 2017/04/05 14:24:08 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	pf_ft_precision_string(t_flag *f)
{
	if (f->fla[0] == -1)
	{
		f->arg = "\0";
	}
	else if (f->spe == 'S' || (f->spe == 's' && f->fla[10] == 1))
		f->arg = pf_ft_wstrsub(f->warg, 0, f->fla[0]);
	else if (f->spe == 's')
		f->arg = pf_ft_strsub(f->arg, 0, f->fla[0]);
}

void	pf_ft_sharp(t_flag *f)
{
	if ((f->fla[2] == 1 && f->arg[0] != '0' && f->fla[0] != -1)
		|| f->spe == 'p')
	{
		if (f->spe == 'o' || f->spe == 'O' || f->spe == 'x' || f->spe == 'X' ||
			f->spe == 'p')
		{
			if ((f->spe == 'x' && f->arg[0] != '0') || f->spe == 'p')
			{
				pf_ft_buf('0', f);
				pf_ft_buf('x', f);
			}
			else if (f->spe == 'X' && f->arg[0] != '0')
			{
				pf_ft_buf('0', f);
				pf_ft_buf('X', f);
			}
			else if ((f->spe == 'o' || f->spe == 'O') &&
				f->fla[0] <= pf_ft_strlen(f->arg))
				pf_ft_buf('0', f);
			else if ((f->spe == 'o' || f->spe == 'O') && f->fla[0] == -1)
				pf_ft_buf('0', f);
		}
	}
}

void	pf_ft_space_plus_sharp(t_flag *f)
{
	if (f->fla[5] == 1 || f->fla[6] == 1)
	{
		if (f->spe == 'd' || f->spe == 'D' || f->spe == 'i')
		{
			if (f->fla[6] == 1 && f->fla[5] == 0 && f->sign != '-')
				pf_ft_buf(' ', f);
			if (f->fla[5] == 1 && pf_ft_isdigit(f->arg[0]) && f->sign == '+')
				pf_ft_buf('+', f);
		}
	}
	if (f->sign == '-')
		pf_ft_buf('-', f);
	pf_ft_sharp(f);
}
