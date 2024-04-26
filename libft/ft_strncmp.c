/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:57:46 by evdos-sa          #+#    #+#             */
/*   Updated: 2022/11/20 13:55:48 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
		i++;
	}
	if (i != n)
		return ((((unsigned char *)s1)[i]) - (((unsigned char *)s2)[i]));
	return (0);
}
/*
A função strncmp em C é usada para comparar dois strings (cadeias de caracteres) 
de tamanho limitado, até um determinado número de caracteres ou até que um 
caractere nulo ('\0') seja encontrado em pelo menos um dos strings.

    str1: Ponteiro para o primeiro string a ser comparado.
    str2: Ponteiro para o segundo string a ser comparado.
    n: Número máximo de caracteres a serem comparados entre os dois strings.

Retorno:
	Retorno < 0: srt1 < srt2;
	Retorno == 0: strings são iguais nos primeiros n caracteres;
	Retorno > 0: srt1 > srt2;


include <stdio.h>
include <string.h>

int	main()
{
	char str1[] = "AGUA";
	char str2[] = "AGUAE";
	printf("%d\n", ft_strncmp(str1, str2, 999999999));
	printf("%d", strncmp(str1, str2, 5));
}*/