/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:08:22 by sergio            #+#    #+#             */
/*   Updated: 2025/11/07 12:10:09 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        Array<int> b = a; // copia
        b[2] = 999;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\nArray b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Tamaño: " << a.size() << std::endl;
        std::cout << "Elemento fuera de rango: ";
        std::cout << a[10] << std::endl; // debería lanzar excepción
    }
    catch (std::exception &e)
    {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}


