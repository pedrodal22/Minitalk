/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfranco- <pfranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:19:07 by pedro             #+#    #+#             */
/*   Updated: 2024/09/03 23:23:10 by pfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_banner(int pid)
{
	printf("\n\t%s███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗\
			%s\n", YELLOW, END);
	printf("\t%s██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\
			%s \n", YELLOW, END);
	printf("\t%s██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\
			%s \n", YELLOW, END);
	printf("\t%s██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\
			%s\n", YELLOW, END);
	printf("\t%s╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\
			%s\n", YELLOW, END);
	printf("%s\n\t\tPID: %d%s\t\t\t%sBy: pfranco-%s\n", RED, pid, END,
		YELLOW, END);
	printf("\t⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰\
			\n\n");
}

void	show_chr(int signal)
{
	char		chr;
	static int	bit_index;

	if (signal == SIGUSR1)
		chr += (1 << bit_index);
	if (bit_index++ == 7)
	{
		write(1, &chr, 1);
		bit_index = 0;
		chr = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	display_banner(pid);
	signal(SIGUSR1, show_chr);
	signal(SIGUSR2, show_chr);
	while (1)
		sleep(1);
}

/* char *store_bit_value(int signal)
{
   char *bit_values = (char *)malloc(sizeof(char) * 8);
   static int i;

   i = 0;
	while(i >= 0)
	{
         if (signal == SIGUSR1)
            bit_values[i] = (char)49;
         else
            bit_values[i] = (char)48;
        i--;
	}
   return(bit_values);
} */