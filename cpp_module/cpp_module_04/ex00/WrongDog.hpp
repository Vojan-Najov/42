/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:40:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 18:53:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog(void);
	WrongDog(const WrongDog &other);
	~WrongDog(void);

	WrongDog &operator=(const WrongDog &other);

	void makeSound(void) const;
};

#endif
