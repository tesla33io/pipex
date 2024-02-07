/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:09:49 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/07 12:45:15 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "./pipex.h"

// Open `INFILE` and `OUTFILE` saving the fd's in `t_pipex` structure.
int	parse_fd(int argc, char **argv, t_pipex **data)
{
	(*data)->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if ((*data)->out_fd < 0)
	{
		ft_printf(STDERR_FILENO, RED S_BOLD "[Stop programm execution.]\n" R);
		return (print_error(RED "Error (parse_fd - outfile)" R, 1));
	}
	(*data)->in_fd = open(argv[1], O_RDONLY);
	if ((*data)->in_fd < 0)
		return (print_error(RED "Error (parse_fd - infile)" R, -1));
	return (0);
}
