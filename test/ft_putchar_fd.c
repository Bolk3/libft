/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:15:56 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 13:48:04 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

static int	pipefd[2];

Test(ft_putchar_fd, test_putchar)
{
	char	buffer[42];
	ssize_t	read_size;

	cr_assert(pipe(pipefd) != -1, "could not pipe");
	ft_putchar_fd('a', pipefd[1]);
	close(pipefd[1]);
	bzero(buffer, 42);
	read_size = read(pipefd[0], buffer, 42);
	close(pipefd[0]);
	cr_assert_eq(read_size, 1, "size differ");
	cr_assert(!strcmp(buffer, "a"), "content differ");
}
