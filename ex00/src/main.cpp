/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:18:54 by sergio            #+#    #+#             */
/*   Updated: 2025/10/20 12:47:11 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"

#include <string>
#include <iostream>

struct Point 
{
    int x;
	int y;
};

inline bool operator<(const Point& lhs, const Point& rhs) 
{
    if (lhs.x != rhs.x) 
		return lhs.x < rhs.x;
    return lhs.y < rhs.y;
}

bool operator>(const Point& a, const Point& b) 
{
    return b < a;
}

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    return os << "(" << p.x << ", " << p.y << ")";
}

int main(void)
{
	std::cout << CYAN << "\n========== TESTS DE SWAP ==========\n" << RESET;

    // [1] Tipos primitivos (int)
    {
        std::cout << YELLOW << "\n[TEST 1] int\n" << RESET;
        int a = 2;
		int b = 3;
        std::cout << "Antes: a=" << a << ", b=" << b << "\n";
        ::swap(a, b);
        std::cout << GREEN << "Despues: a=" << a << ", b=" << b << "\n" << RESET;
    }

	// [2] std::string
    {
        std::cout << YELLOW << "\n[TEST 2] std::string\n" << RESET;
        std::string s1 = "hola";
		std::string s2 = "mundo";
        std::cout << "Antes: s1=\"" << s1 << "\", s2=\"" << s2 << "\"\n";
        ::swap(s1, s2);
        std::cout << GREEN << "Despues: s1=\"" << s1 << "\", s2=\"" << s2 << "\"\n" << RESET;
    }

	// [3] Punteros
    {
        std::cout << YELLOW << "\n[TEST 3] punteros\n" << RESET;
        int x = 10;
		int y = 20;
        int* px = &x;
        int* py = &y;
        std::cout << "Antes: *px=" << *px << " (px=" << px << "), *py=" << *py << " (py=" << py << ")\n";
        ::swap(px, py);
        std::cout << GREEN << "Despues: *px=" << *px << " (px=" << px << "), *py=" << *py << " (py=" << py << ")\n" << RESET;
    }

	// [4] Tipo propio (Point)
    {
        std::cout << YELLOW << "\n[TEST 4] struct Point\n" << RESET;
        Point p1 = {1, 2};
        Point p2 = {9, 8};
        std::cout << "Antes: p1=" << p1 << ", p2=" << p2 << "\n";
        ::swap(p1, p2);
        std::cout << GREEN << "Despues: p1=" << p1 << ", p2=" << p2 << "\n" << RESET;
    }

	// [5] Mismo objeto
    {
        std::cout << YELLOW << "\n[TEST 5] mismo objeto\n" << RESET;
        int k = 42;
        std::cout << "Antes: k=" << k << "\n";
        ::swap(k, k);
        std::cout << GREEN << "Despues: k=" << k << "  (debe ser igual)\n" << RESET;
    }

	// [6] Objeto grande
    {
        std::cout << YELLOW << "\n[TEST 6] string grande\n" << RESET;
        std::string a(1000, 'A');
        std::string b(1000, 'B');
        std::cout << "Antes: a[0]=" << a[0] << ", b[0]=" << b[0] << "\n";
        ::swap(a, b);
        std::cout << GREEN << "Despues: a[0]=" << a[0] << ", b[0]=" << b[0] << "\n" << RESET;
    }

	// [7] Casos negativos (NO deben compilar)
    //
    // const-correctness:
    // const int c1 = 1, c2 = 2;
    // ::swap(c1, c2); // ERROR: no se puede modificar const
    //
    // temporales:
    // ::swap(1, 2); // ERROR: no se puede bindear a temporales
    //
    // tipos distintos:
    // int m = 5;
	// double n = 7.0;
    // ::swap(m, n); // ERROR: deducción de T incompatible

	std::cout << CYAN << "\n========== TESTS DE MIN ==========\n" << RESET;

    // [1] enteros básicos
    {
        std::cout << YELLOW << "\n[MIN 1] int\n" << RESET;
        int a = 2;
		int b = 3;
        const int& r = ::min(a, b);
        std::cout << "a=" << a << ", b=" << b << " -> min=" << r << "\n";
    }

	// [2] empate: debe devolver el segundo (comparando direcciones)
    {
        std::cout << YELLOW << "\n[MIN 2] empate int (gana el segundo)\n" << RESET;
        int a = 5;
		int b = 5;
        const int& r = ::min(a, b);
        std::cout << "a=" << a << ", b=" << b << " -> min=" << r << "\n";
        if (&r == &b)
            std::cout << GREEN << "Devuelve el segundo correctamente.\n" << RESET;
        else
            std::cout << RED << "Error: devuelve el primero.\n" << RESET;
    }

	// [3] strings (comparación lexicográfica)
    {
        std::cout << YELLOW << "\n[MIN 3] std::string\n" << RESET;
        std::string s1 = "chaine20";
        std::string s2 = "chaine10";
        const std::string& r = ::min(s1, s2);
        std::cout << "s1=\"" << s1 << "\", s2=\"" << s2 << "\" -> min=\"" << r << "\"\n";
    }

	// [4] tipo propio (Point)
    {
        std::cout << YELLOW << "\n[MIN 4] struct Point con operator<\n" << RESET;
        Point p1 = {1, 3};
        Point p2 = {1, 5};
        const Point& r = ::min(p1, p2);
        std::cout << "p1=" << p1 << ", p2=" << p2 << " -> min=" << r << "\n";
    }

	// [5] punteros (compara direcciones de memoria)
    {
        std::cout << YELLOW << "\n[MIN 5] punteros (compara direcciones)\n" << RESET;
        int x = 10, y = 20;
        int* px = &x;
        int* py = &y;
        int* const& r = ::min(px, py);
        std::cout << "px=" << px << ", py=" << py << " -> min=" << r << "\n";
        std::cout << MAGENTA << "Nota: compara las direcciones, no los valores apuntados.\n" << RESET;
    }

	// [6] temporales: válido, pero no guardes la referencia
    {
        std::cout << YELLOW << "\n[MIN 6] temporales (válido en uso inmediato)\n" << RESET;
        std::cout << "min(42, 21) = " << ::min(42, 21) << "\n";
        std::cout << "min(42, 42) = " << ::min(42, 42) << " (gana el segundo)\n";
    }

	// [7] Caso que NO deben compilar
    //
    // tipos distintos:
    // int m = 5;
	// double n = 7.0;
    // ::min(m, n); // ERROR: deducción de T incompatible

	std::cout << CYAN << "\n========== TESTS DE MAX ==========\n" << RESET;

	// [1] enteros básicos
	{
		std::cout << YELLOW << "\n[MAX 1] int\n" << RESET;
		int a = 2;
		int b = 3;
		const int& r = ::max(a, b);
		std::cout << "a=" << a << ", b=" << b << " -> max=" << r << "\n";
	}

	// [2] empate: debe devolver el segundo (comparando direcciones)
	{
		std::cout << YELLOW << "\n[MAX 2] empate int (gana el segundo)\n" << RESET;
		int a = 7;
		int b = 7;
		const int& r = ::max(a, b);
		std::cout << "a=" << a << ", b=" << b << " -> max=" << r << "\n";
		if (&r == &b)
			std::cout << GREEN << "Devuelve el segundo correctamente.\n" << RESET;
		else
			std::cout << RED << "Error: devuelve el primero.\n" << RESET;
	}

	// [3] strings (comparación lexicográfica)
    {
        std::cout << YELLOW << "\n[MAX 3] std::string\n" << RESET;
        std::string s1 = "chaine20";
        std::string s2 = "chaine10";
        const std::string& r = ::max(s1, s2);
        std::cout << "s1=\"" << s1 << "\", s2=\"" << s2 << "\" -> max=\"" << r << "\"\n";
    }

	// [4] tipo propio (Point)
	{
		std::cout << YELLOW << "\n[MAX 4] struct Point con operator>\n" << RESET;
		Point p1 = {1, 3};
		Point p2 = {1, 5};
		const Point& r = ::max(p1, p2);
		std::cout << "p1=" << p1 << ", p2=" << p2 << " -> max=" << r << "\n";
	}

	// [5] punteros (compara direcciones)
	{
		std::cout << YELLOW << "\n[MAX 5] punteros (compara direcciones)\n" << RESET;
		int x = 10, y = 20;
		int* px = &x;
		int* py = &y;
		int* const& r = ::max(px, py);
		std::cout << "px=" << px << ", py=" << py << " -> max=" << r << "\n";
		std::cout << MAGENTA << "Nota: compara DIRECCIONES de memoria, no valores.\n" << RESET;
	}

	// [6] temporales (válido solo para uso inmediato)
	{
		std::cout << YELLOW << "\n[MAX 6] temporales (válido en uso inmediato)\n" << RESET;
		std::cout << "max(42, 21) = " << ::max(42, 21) << "\n";
		std::cout << "max(42, 42) = " << ::max(42, 42) << " (gana el segundo)\n";
	}

	std::cout << MAGENTA << "\nTodos los tests ejecutados correctamente.\n" << RESET;
	std::cout << CYAN << "=========================================\n\n" << RESET;
	
	return 0;
}
