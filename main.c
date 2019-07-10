/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:21:39 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/10 09:56:56 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char *av[])
{
	int fd;
	int i = 1;
	//int k = 0;
	int ret_value = 0;
	char *output = NULL;
	
	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl("an error occured while trying to open your 'FILE DESCRIPTOR'.");
			return (-1);
		}
		if ((ret_value = get_next_line(fd, &output)) < 0)
		{
			ft_putendl("could not read from your 'FILE DESCRIPTOR'/error.");
			return(-1);
		}
		while ((ret_value = get_next_line(fd, &output)) > 0)
		{
			ft_putstr("line: ");
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putendl(output);
			i++;
		}
	}
	ft_putendl("FINISHED READING.");
	return (0);
}

/*int	main(int ac, char *av[])
{
	int fd1;
	int fd2;
	int fd1_ret;
	int fd2_ret;
	int fd1_counter = 1;
	int fd2_counter = 1;
	char *fd1_output;
	char *fd2_output;

	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		if (fd1 < 0)
		{
			ft_putendl("'FILE DESCRIPTOR 2' failed to open.");
			return (-1);
		}
		if ((fd1_ret = get_next_line(fd1, &fd1_output)) < 0)
		{
			ft_putendl("failed to read from 'FILE DESCRIPTOR 1'.");
			return (-1);
		}
		while ((fd1_ret = get_next_line(fd1, &fd1_output)) > 0)
		{
			ft_putstr("fd1 line: ");
			ft_putnbr(fd1_counter);
			ft_putchar('\n');
			ft_putendl(fd1_output);
			fd1_counter++;
		}
		ft_putchar('\n');
		ft_putendl("'FILE DESCRIPTOR 1' reading complete");
		ft_putchar('\n');

		fd2 = open(av[2], O_RDONLY);
		if (fd2 < 0)
		{
			ft_putendl("'FILE DESCRIPTOR 2' failed to open.");
			return (-1);
		}
		if ((fd2_ret = get_next_line(fd2, &fd2_output)) < 0)
		{
			ft_putendl("failed to read from 'FILE DESCRIPTOR'.");
			return (-1);
		}
		while ((fd2_ret = get_next_line(fd2, &fd2_output)) > 0)
		{
			ft_putstr("fd2_line: ");
			ft_putnbr(fd2_counter);
			ft_putchar('\n');
			ft_putendl(fd2_output);
			fd2_counter++;
		}
		ft_putchar('\n');
		ft_putendl("all 'FILE DESCRIPTORS' are read");
	}
	return (0);
}*/
