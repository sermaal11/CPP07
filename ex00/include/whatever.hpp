/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:19:00 by sergio            #+#    #+#             */
/*   Updated: 2025/10/20 12:39:12 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define MAGENTA "\033[35m"
# define RESET   "\033[0m"

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
const T & min(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
const T & max(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
}

#endif // WHATEVER_HPP
