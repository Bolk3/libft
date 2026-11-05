/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:18:42 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 23:38:29 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <gtest/gtest.h>
#include <strings.h>
#include <unistd.h>

extern "C" {
#include <libft.h>
}

class	putnbrFd: public ::testing::Test {
	public:
		void	setNumber(int nbr)
		{
			this->nbr = nbr;
			bzero(msg, 500);
			sprintf(msg, "%d", nbr);
		}
	protected:
		int		nbr;
		char	msg[500];
		char	buffer[500];
		int		pipefd[2];

		void	SetUp(void) override {
			ASSERT_NE(pipe(pipefd), -1);
			bzero(buffer, 500);
		}

		void	TearDown(void) override {
			close(pipefd[0]);
		}
};

TEST_F(putnbrFd, TestWritingSize)
{
	ssize_t	read_size;
	srand(time(NULL));
	setNumber(rand() % INT32_MAX);

	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);

	read_size = read(pipefd[0], buffer, 500);
	ASSERT_EQ(read_size, strlen(msg));
}

TEST_F(putnbrFd, TestWritingCorrectInt)
{
	srand(time(NULL));
	setNumber(rand() % INT32_MAX);

	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);

	read(pipefd[0], buffer, 500);
	ASSERT_EQ(std::atoi(buffer), nbr);
}

TEST_F(putnbrFd, TestWritingCorrectIntMin)
{
	setNumber(INT32_MIN);

	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);

	read(pipefd[0], buffer, 500);
	ASSERT_EQ(std::atoi(buffer), INT32_MIN);
}

TEST_F(putnbrFd, TestWritingCorrectIntZero)
{
	setNumber(0);

	ft_putnbr_fd(nbr, pipefd[1]);
	close(pipefd[1]);

	read(pipefd[0], buffer, 500);
	ASSERT_EQ(std::atoi(buffer), 0);
}
