/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:58:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/05/02 23:00:29 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Function to skip leading white spaces
 * 					in the string pointed to by `str`
 * 					and return a pointer to the first 
 * 					non-white space character.
 * 
 * @param str		The string to be checked.
 * @return char*	A pointer to the first non-white space character.
 */
char	*ft_skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
