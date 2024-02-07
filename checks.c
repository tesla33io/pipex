/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:19:16 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/07 12:44:22 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./pipex.h"

int	check_input(int argc, char **argv, t_pipex **data)
{
	if (argc < 5)
	{
		ft_printf(STDERR_FILENO, RED S_BOLD "[Stop programm execution.]\n" R
			RED "Error (check_input)" R ": invalid input.\n");
		print_usage();
		return (1);
	}
	if (access(argv[1], F_OK) != 0)
		return (print_error(RED "Error (check_input - F_not_OK)" R, -1));
	if (access(argv[1], R_OK) != 0)
		return (print_error(RED "Error (check_input - R_not_OK)" R, -1));
	(*data)->is_invalid_infile = false;
	return (0);
}
