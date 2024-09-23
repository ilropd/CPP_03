/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:33:09 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/17 16:28:20 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define RED    "\033[31m"
# define YELLOW "\033[33m"
# define GREEN  "\033[32m"
# define RESET  "\033[0m"

class ScavTrap: public ClapTrap
{
	private:
		bool	_guard_mode;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& copy);
		ScavTrap &operator=(const ScavTrap& src);
		virtual ~ScavTrap(void);

	bool	getGM(void)const;
	void	printStat(void);
	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif
