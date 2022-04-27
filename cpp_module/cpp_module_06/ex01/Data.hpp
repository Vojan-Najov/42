/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:54:51 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 14:11:26 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	Data(const std::string &content_);
	Data(const Data &copy);
	~Data(void);

	const std::string &getContent(void) const;

private:
	std::string content;
};

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif
