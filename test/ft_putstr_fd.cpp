/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 22:32:14 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 22:52:52 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include <strings.h>
#include <sys/types.h>
#include <time.h>
#include <gtest/gtest.h>
#include <unistd.h>

extern "C" {
#include <libft.h>
}

class	putstrFd: public ::testing::Test {
	private:
		char	*generate_msg(std::size_t str_size)
		{
			std::string	result;

			for (std::size_t i = 0; i < str_size; i++) {
				srand(time(NULL));
				result.insert(result.end(), (rand() % CHAR_MAX) + 1);
			}
			return (strdup(const_cast<char *>(result.c_str())));
		}

	protected:
		int		pipefd[2];
		char	buffer[500];
		char	*msg;

		void	SetUp() override {
			msg = generate_msg(30);
			ASSERT_NE(msg, nullptr);
			ASSERT_NE(pipe(pipefd), -1);
			bzero(buffer, 500);
		}

		void	TearDown() override {
			close(pipefd[0]);
			free(msg);
		}
};

TEST_F(putstrFd, TestWritingSize)
{
	ssize_t	read_size;

	ft_putstr_fd(msg, pipefd[1]);
	close(pipefd[1]);

	read_size = read(pipefd[0], buffer, 500);
	ASSERT_EQ(read_size, strlen(msg));
}

TEST_F(putstrFd, TestWrightingCorrectStr)
{
	ft_putstr_fd(msg, pipefd[1]);
	close(pipefd[1]);

	read(pipefd[0], buffer, 500);
	ASSERT_STREQ(buffer, msg);
}
