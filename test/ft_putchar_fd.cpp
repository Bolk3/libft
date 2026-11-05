/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 22:06:00 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 22:19:14 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

extern "C" {
#include <libft.h>
}

class	putcharFd: public ::testing::Test {
	protected:
		int		pipefd[2];
		char	buffer[500];
		ssize_t	read_size;

	void	SetUp() override {
		ASSERT_NE(pipe(pipefd), -1);
		bzero(buffer, 500);
	}

	void	TearDown() override {
		close(pipefd[0]);
	}
};

TEST_F(putcharFd, TestWritingSize)
{
	ft_putchar_fd('a', pipefd[1]);
	close(pipefd[1]);

	read_size = read(pipefd[0], buffer, 500);
	ASSERT_EQ(read_size, 1);
}

TEST_F(putcharFd, TestWritingCorrectChar)
{
	ft_putchar_fd('a', pipefd[1]);
	close(pipefd[1]);

	read(pipefd[0], buffer, 500);
	ASSERT_STREQ(buffer, "a");
}
