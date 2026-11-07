/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resonnet <renald.sonnet@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 19:25:43 by resonnet          #+#    #+#             */
/*   Updated: 2026/11/07 19:29:36 by resonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <gtest/gtest.h>

extern "C" {
#include <libft.h>
}

class	isprint: public ::testing::Test {
	protected:
		bool	result;
		bool	expected;
};

TEST_F(isprint, TestSignedNegChar)
{
	for (int i = CHAR_MIN; i < 0; i++) {
		result = ft_isprint(i);
		expected = std::isprint(i);
		ASSERT_EQ(result, expected);
	}
}

TEST_F(isprint, TestSignedPosChar)
{
	for (int i = 0; i <= CHAR_MAX; i++) {
		result = ft_isprint(i);
		expected = std::isprint(i);
		ASSERT_EQ(result, expected);
	}
}
