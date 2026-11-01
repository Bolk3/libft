/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:34:08 by resonnet          #+#    #+#             */
/*   Updated: 2026/10/29 13:52:59 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

static int	pipefd[2];

Test(ft_putstr_fd, test_putstr)
{
	char	*string = "omedeto, shinji";
	char	buffer[500];
	ssize_t	read_size;

	cr_assert(pipe(pipefd) != -1, "could not pipe");
	ft_putstr_fd(string, pipefd[1]);
	close(pipefd[1]);
	bzero(buffer, 500);
	read_size = read(pipefd[0], buffer, 500);
	close(pipefd[0]);
	cr_assert_eq(strlen(string), read_size, "size does not match");
	cr_assert_str_eq(string, buffer, "content does not match");
}
