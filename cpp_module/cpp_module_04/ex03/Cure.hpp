/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:03:33 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:09:28 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		~Cure(void);

		virtual Cure *clone(void) const;
		virtual void use(ICharacter &target);
	private:
		Cure &operator=(const Cure &other);
};

#endif
