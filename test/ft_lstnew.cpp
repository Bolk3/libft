/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:57:39 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 21:10:16 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <gtest/gtest.h>
#include <checks.hpp>

extern "C"
{
	#include <libft.h>
}

class	lstnewTest: public ::testing::Test {
	protected:
		t_list		*node;
		std::string	s = "bonjour";

	void	SetUp() override {
		malloc_fail_at = 0;
	}

	void	TearDown() override {
		if (node)
		{
			free(node -> content);
			free(node);
		}
		malloc_fail_at = 0;
	}
};

TEST_F(lstnewTest, TestLstNewFailCreation)
{
	malloc_fail_at = 1;
	node = ft_lstnew(const_cast<char *>(s.c_str()));
	ASSERT_EQ(node, nullptr);
}
