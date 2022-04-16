/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:14:59 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/15 19:21:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
public:
	AAnimal(void);
	AAnimal(const std::string &type_);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal(void);

	AAnimal &operator=(const AAnimal &other);

	const std::string &getType(void) const;
	virtual	void makeSound(void) const = 0;

protected:
	std::string type;
};

#endif
