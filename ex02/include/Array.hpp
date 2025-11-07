/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:08:26 by sergio            #+#    #+#             */
/*   Updated: 2025/11/07 12:09:25 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;

public:
    // ----------------- OCF -----------------
    Array();                                // Default
    Array(unsigned int n);                  // Parametrizado
    Array(const Array& other);              // Copia
    Array& operator=(const Array& other);   // Asignación
    ~Array();                               // Destructor

    // ----------------- Métodos -----------------
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

# include "../include/Array.tpp"

#endif
