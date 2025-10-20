/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:00:30 by sergio            #+#    #+#             */
/*   Updated: 2025/10/20 13:21:55 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

// SOLO LECTURA: acepta const ref -> válido para arrays const y no-const
template <typename T>
void print_elem(T const& x) 
{
	std::cout << x << " ";
}

// MODIFICACIÓN: acepta ref no-const -> SOLO arrays no-const
void increment_int(int& x) 
{ 
	++x; 
}

// MODIFICACIÓN sobre std::string: convertir a mayúsculas
void to_upper(std::string& s) 
{
	for (std::size_t i = 0; i < s.size(); ++i) 
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = static_cast<char>(s[i] - 'a' + 'A');
	}
}

// Tipo propio
struct Point 
{ 
	int x;
	int y; 
};

// Mostrar punto (solo lectura)
void print_point(Point const& p) 
{
	std::cout << "(" << p.x << "," << p.y << ") ";
}

// Modificar punto -> mover a la derecha
void move_right(Point& p) 
{ 
	++p.x; 
}

int main() {
	std::cout << CYAN << "\n========== TESTS DE iter ==========\n" << RESET;

	// [1] int no-const: leer y modificar
	{
		std::cout << YELLOW << "\n[ITER 1] int no-const: print -> increment -> print\n" << RESET;
		int a[] = {1, 2, 3, 4};
		std::size_t n = sizeof(a)/sizeof(a[0]);

		std::cout << "Antes: ";
		iter(a, n, print_elem<int>);
		std::cout << "\n";

		iter(a, n, increment_int);
		std::cout << GREEN << "Después: " << RESET;
		iter(a, n, print_elem<int>);
		std::cout << "\n";
	}

	// [2] int const: solo lectura
	{
		std::cout << YELLOW << "\n[ITER 2] int const: print (no se puede modificar)\n" << RESET;
		const int a[] = {10, 20, 30};
		std::size_t n = sizeof(a)/sizeof(a[0]);

		std::cout << "Const array: ";
		iter(a, n, print_elem<int>);
		std::cout << "\n";
	}

	// [3] std::string no-const: to_upper
	{
		std::cout << YELLOW << "\n[ITER 3] std::string: to_upper\n" << RESET;
		std::string s[] = {"hola", "mundo", "cpp"};
		std::size_t n = sizeof(s)/sizeof(s[0]);

		std::cout << "Antes: ";
		iter(s, n, print_elem<std::string>);
		std::cout << "\n";

		iter(s, n, to_upper);
		std::cout << GREEN << "Después: " << RESET;
		iter(s, n, print_elem<std::string>);
		std::cout << "\n";
	}

	// [4] tipo propio: lectura y modificación
	{
		std::cout << YELLOW << "\n[ITER 4] tipo propio Point: move_right\n" << RESET;
		Point ps[] = {{0,0}, {1,1}, {2,2}};
		std::size_t n = sizeof(ps)/sizeof(ps[0]);

		std::cout << "Antes: ";
		iter(ps, n, print_point);
		std::cout << "\n";

		iter(ps, n, move_right);
		std::cout << GREEN << "Después: " << RESET;
		iter(ps, n, print_point);
		std::cout << "\n";
	}

	// [5] función template como callable
	{
		std::cout << YELLOW << "\n[ITER 5] funcion template como callable (print_elem<T>)\n" << RESET;
		double v[] = {1.5, -2.0, 3.25};
		std::size_t n = sizeof(v)/sizeof(v[0]);
		iter(v, n, print_elem<double>);
		std::cout << "\n";
	}

	// [6] casos borde: length=0 y array=nullptr
	{
		std::cout << YELLOW << "\n[ITER 6] casos borde (len=0, array=null)\n" << RESET;
		int* p = NULL;
		iter(p, 0, print_elem<int>);
		std::cout << GREEN << "OK (no crash)\n" << RESET;
	}

	std::cout << MAGENTA << "\niter probado con arrays const/no-const y varios tipos.\n" << RESET;
	std::cout << CYAN << "=====================================\n\n" << RESET;
	return 0;
}