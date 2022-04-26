/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:43:17 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/26 17:22:58 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Number.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One argument is expected"  << std::endl;
		return 1;
	}

	Number num(argv[1]);
	num.print();
	return (0);
}
