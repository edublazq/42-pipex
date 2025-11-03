/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:34:30 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/25 23:34:31 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdint.h>

int		ft_print_string(char *str);
int		ft_print_unsigned(unsigned int nb);
void	ft_print_to_base(unsigned int nb, char *base, int *i);
int		ft_print_ptr(void *ptr);
int		ft_print_number(int nb);
void	ft_putunbr_fd(unsigned int nbr, int fd);
int		ft_printf(const char *str, ...);

#endif
