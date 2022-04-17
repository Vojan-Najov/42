/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:00:28 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:03:18 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		~Ice(void);

		virtual Ice *clone(void) const;
		virtual void use(ICharacter &target);
	private:
		Ice &operator=(const Ice &other);
};

#endif
