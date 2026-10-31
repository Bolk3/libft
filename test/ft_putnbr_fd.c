/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 14:10:55 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 14:34:32 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int	pipefd[2];

Test(ft_putnbr_fd, test_int_min)
{
	int		nbr = INT32_MIN;
	char	buff[500];
	ssize_t	read_size;

	cr_assert_neq(pipe(pipefd), -1, "could not pipe");
	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);
	bzero(buff, 500);
	read_size = read(pipefd[0], buff, 500);
	close(pipefd[0]);
	cr_assert_eq(read_size, 11, "size does not match");
	cr_assert_str_eq(buff, "-2147483648", "content does not match");
}

Test(ft_putnbr_fd, test_zero)
{
	int		nbr = 0;
	char	buff[500];
	ssize_t	read_size;

	cr_assert_neq(pipe(pipefd), -1, "could not pipe");
	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);
	bzero(buff, 500);
	read_size = read(pipefd[0], buff, 500);
	close(pipefd[0]);
	cr_assert_eq(read_size, 1, "size does not match");
	cr_assert_str_eq(buff, "0", "content does not match");
}

Test(ft_putnbr_fd, test_rand_int)
{
	srand(time(NULL));
	int		nbr = (rand() % INT32_MAX) + 1;
	char	buff[500];
	char	expected[500];
	ssize_t	read_size;

	sprintf(expected, "%i", nbr);
	cr_assert_neq(pipe(pipefd), -1, "could not pipe");
	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);
	bzero(buff, 500);
	read_size = read(pipefd[0], buff, 500);
	close(pipefd[0]);
	cr_assert_eq(read_size, strlen(expected), "size does not match");
	cr_assert_str_eq(buff, expected, "content does not match");
}
