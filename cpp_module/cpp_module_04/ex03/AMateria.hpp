/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:51:31 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:48:52 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(const std::string &type_);
		AMateria(const AMateria &other);
		virtual ~AMateria(void);

		const std::string &getType(void) const;
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);	
	protected:
		std::string type;
	private:
		AMateria &operator=(const AMateria &other);
};

#endif
