/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:26:10 by mrolain           #+#    #+#             */
/*   Updated: 2024/08/05 10:36:19 by mrolain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	toomanyc(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	return (i);
}

size_t	strlendefou(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

char	*mallocator(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	else
	{
		str = ft_memcpy(str, s, i);
		str[i] = '\0';
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		nb;

	i = 0;
	if (s != NULL)
	{
		nb = count_words(s, c);
		tab = (char **)malloc(sizeof(char *) * (nb + 1));
		if (!tab)
			return (NULL);
		while (i < nb)
		{
			s = (s + toomanyc(s, c));
			tab[i] = mallocator(s, c);
			s = (s + strlendefou(tab[i], c));
			s = (s + toomanyc(s, c));
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
	else
		return (NULL);
}

// int	main()
// {
// 	char	**tab = ft_split();
// 	int 	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }
