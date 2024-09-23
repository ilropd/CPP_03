/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:04:06 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/17 19:05:45 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "Named FragTrap constructor called" << std::endl;
    this->_hit_points = 100;
    this->_energy = 100;
    this->_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_hit_points = src._hit_points;
		this->_energy = src._energy;
		this->_attack_damage = src._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if ((this->_energy != 0) && (this->_hit_points != 0))
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
		this->_energy -= 1;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " can´t do anything, because doesn´t have enough ENERGY or HIT POINTS." << std::endl;
	}
}

void	FragTrap::printStat(void)
{
	std::cout << GREEN << "***" << YELLOW << "FRAG_STAT" << GREEN "***" << std::endl;
	std::cout << "Name:          " << this->_name << std::endl;
	std::cout << "Hit points:    " << this->_hit_points << std::endl;
	std::cout << "Energy:        " << this->_energy << std::endl;
	std::cout << "Attack damage: " << this->_attack_damage << std::endl;
	std::cout << "***************" << RESET << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << GREEN << "Wazzzzzaaaap, guys! High fives!" << RESET << std::endl;
}
