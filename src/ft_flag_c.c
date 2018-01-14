/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:17:29 by itoth             #+#    #+#             */
/*   Updated: 2017/04/05 14:17:30 by itoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		pf_ft_modifier_wc(t_flag *f, va_list *ap)
{
	wchar_t		wc;
	wchar_t		ws[2];

	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = '\0';
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
	{
		f->ret = -1;
		return (0);
	}
	f->warg = ws;
	pf_ft_handler_char(f);
	return (0);
}

int		pf_ft_handler_c(t_flag *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2};
	char		c;
	char		s[2];

	pf_ft_apply_mask(f, mask_c);
	if (f->fla[10] == 1)
		return (pf_ft_modifier_wc(f, ap));
	else
	{
		c = (char)va_arg(*ap, int);
		if (c == 0 && f->fla[0] == -1)
			f->fla[0] = 0;
		s[0] = c;
		s[1] = '\0';
		f->arg = s;
		pf_ft_handler_char(f);
	}
	if (f->arg[0] == 0)
		pf_ft_buf('\0', f);
	return (0);
}

int		pf_ft_handler_wc(t_flag *f, va_list *ap)
{
	static int	mask_c[13] = {0, 0, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};

	pf_ft_apply_mask(f, mask_c);
	return (pf_ft_modifier_wc(f, ap));
}
