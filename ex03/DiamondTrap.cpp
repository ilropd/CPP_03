/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:00:13 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/18 18:29:50 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_name")
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_name = "defaultDT";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << "Named DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy),  FragTrap(copy), ScavTrap(copy)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "Assignation operator DiamondTrap called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name + "_clap_name";
		this->_hit_points = src._hit_points;
		this->_energy = src._energy;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor DiamondTrap called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << YELLOW << "To be honest, it's DiamondTrap attack, inherited from ScavTrap..." << std::endl;
	std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << RESET << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::printStat(void)
{
	std::cout << YELLOW << "To be honest, it's DiamondTrap stat, inherited from FragTrap..." << std::endl;
	std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << RESET << std::endl;
	FragTrap::printStat();
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Hi! I'm DiamondTrap named " << YELLOW << this->_name << RESET << " and my ClapTrap's name is " << YELLOW << ClapTrap::_name << RESET << std::endl;
}
