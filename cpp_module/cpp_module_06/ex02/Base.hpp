/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:56:12 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 16:24:58 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base
{
public:
	virtual ~Base(void) {};
};

//std::ostream &operator<<(std::ostream &out, Base &base);

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif
