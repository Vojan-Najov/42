/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:18:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/17 15:22:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource(void);

		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria *m);
		virtual AMateria* createMateria(std::string const &type);
	private:
		AMateria *slot[4];
		int slotCount;
};

#endif
