/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 07:46:05 by danfern3          #+#    #+#             */
/*   Updated: 2025/10/10 08:28:34 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	letters;

	words = 0;
	letters = 0;
	while (*s)
	{
		if (*s != c)
			letters++;
		else
		{
			if (letters != 0)
				words++;
			letters = 0;
		}
		s++;
	}
	if (letters != 0)
		words++;
	return (words);
}

static char	**free_result(char **result, size_t w_counter)
{
	size_t	i;

	i = 0;
	while (i < w_counter)
	{
		free(result[i]);
		++i;
	}
	free(result);
	return (NULL);
}

static void	ft_init_counters(unsigned int *i, size_t *w_l_counters)
{
	*i = 0;
	w_l_counters[0] = 0;
	w_l_counters[1] = 0;
}

static char	**ft_inside_loop(const char *s, char **result, \
		unsigned int i, size_t *w_l_counters)
{
	result[w_l_counters[0]] = \
	ft_substr(s, i - w_l_counters[1], w_l_counters[1]);
	if (!result[w_l_counters[0]])
		return (free_result(result, w_l_counters[0]));
	++w_l_counters[0];
	return (result);
}

/* 
 * @var w_l_counters[0] stores nº of words of @param s
 * @var w_l_counters[1] stores nº of letter of every words of @param s
*/
// TODO: split w_l_counters into two separate variables for clarity
char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;
	size_t			w_l_counters[2];

	ft_init_counters(&i, w_l_counters);
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		if ((unsigned char) s[i] != (unsigned char) c)
			++w_l_counters[1];
		else
		{
			if (w_l_counters[1] != 0 && \
				!ft_inside_loop(s, result, i, w_l_counters))
				return (NULL);
			w_l_counters[1] = 0;
		}
		++i;
	}
	if (w_l_counters[1] != 0 && !ft_inside_loop(s, result, i, w_l_counters))
		return (NULL);
	result[w_l_counters[0]] = NULL;
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("count_words: %d\n", ft_count_words("xxxxxxxxhello!", 'x'));
// 	char **result = ft_split("xxxxxxxxhello!", 'x');
// 	int i = 0;
// 	while (result[i]) {
// 		printf("%s|\n", result[i]);
// 		++i;
// 	}
// 	free_result(result, i + 1);
// 	return (0);
// }
// // ccw ft_split.c ft_substr.c ft_strdup.c ft_strlen.c -o a.out && ./a.out