/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:19:16 by pedro             #+#    #+#             */
/*   Updated: 2024/09/03 23:20:32 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <stdint.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

int		pid_check(const char *str);
void	send_bits(char c, int pid);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	*ft_strchr(const char *str, int c);
int		ft_conv(char *str, int i, va_list args);
int		ft_printf(const char *str, ...);
void	show_chr(int signal);

#endif