/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:24:05 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/16 15:04:32 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* Aloca (com malloc(3)) e retorna uma substring da string 's'.
 A substring começa no índice 'start' e é de tamanho máximo 'len'.*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	sub = malloc((sizeof(char) * len) + 1);
	if (!(sub))
		return (NULL);
	i = 0;
	if (s)
	{
		while (i + start < ft_strlen(s) && i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*sub;

// 	if (!s)
// 		return (NULL);

// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));

// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;

// 	sub = (char *)malloc((len + 1) * sizeof(char));
// 	if (!sub)
// 		return (NULL);

// 	i = 0;
// 	while (i < len)
// 	{
// 		sub[i] = s[start + i];
// 		i++;
// 	}
// 	sub[i] = '\0';

// 	return (sub);
// }
/*
int    main()
{
    char    *str;
    
    Everton Mota:
        s    = A string a partir da qual criar a substring.
    7:
        stsrt    = O índice inicial da substring na string.
    4:
        len    = O comprimento máximo da substring.
    
    str = ft_substr("PORTO", 2, 2);
    printf("%s", str);

    return (0);
}
*/
