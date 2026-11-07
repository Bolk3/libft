/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 21:53:29 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/05 22:00:49 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <gtest/gtest.h>

extern "C" {
#include <libft.h>
}

class	isdigit: public ::testing::Test {
	protected:
		bool	result;
		bool	expected;
};

TEST_F(isdigit, TestSignedNegChar)
{
	for (int i = CHAR_MIN; i < 0; i++) {
		result = ft_isdigit(i);
		expected = std::isdigit(i);
		ASSERT_EQ(result, expected);
	}
}

TEST_F(isdigit, TestSignedPosChar)
{
	for (int i = 0; i <= CHAR_MAX; i++) {
		result = ft_isdigit(i);
		expected = std::isdigit(i);
		ASSERT_EQ(result, expected);
	}
}
