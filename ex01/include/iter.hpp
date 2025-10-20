/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:00:31 by sergio            #+#    #+#             */
/*   Updated: 2025/10/20 13:08:47 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define MAGENTA "\033[35m"
# define RESET   "\033[0m"

# include <iostream>
# include <cstddef>
# include <string>

// Versión no-const: permite modificar los elementos si F acepta T&
template <typename T, typename F>
void iter(T* array, std::size_t length, F f)
{
    if (!array) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]); // array[i] es T&
}

// Versión const: solo lectura; F debe aceptar T const&
template <typename T, typename F>
void iter(T const* array, std::size_t length, F f)
{
    if (!array) return;
    for (std::size_t i = 0; i < length; ++i)
        f(array[i]); // array[i] es const T&
}

#endif // ITER_HPP
