/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:54:45 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 14:09:28 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

static int	pipefd[2];

Test(ft_putendl_fd, test_putendl)
{
	char	*string = "omedeto, shinji";
	char	buffer[500];
	ssize_t	read_size;

	cr_assert_neq(pipe(pipefd), -1, "could not pipe");
	ft_putendl_fd(string, pipefd[1]);
	close(pipefd[1]);
	bzero(buffer, 500);
	read_size = read(pipefd[0], buffer, 500);
	close(pipefd[0]);
	cr_assert_eq(strlen(string) + 1, read_size, "size differ");
	cr_assert_eq(strncmp(string, buffer, strlen(string)), 0, "content differ");
	cr_assert_eq(buffer[strlen(string)], '\n', "newline is not the last char");
}
