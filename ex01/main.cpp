/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:18:02 by irozhkov          #+#    #+#             */
/*   Updated: 2024/08/17 16:01:01 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main() {
	ClapTrap claps[3] = {
    	ClapTrap("Clapper A"),
		ClapTrap("Clapper B"),
		ClapTrap()
	};

	ScavTrap scav("Scaver");

	std::string attacks[10] = {
		"Clapper C",
		"Clapper A",
		"sOMETHING",
		"Clapper B",
		"Clapper A",
		"Clapper A",
		"Hello Kitty",
		"Clapper A",
		"Clapper A",
		"Clapper A"
	};

	for (int i = 0; i < 3; i++)
		claps[i].printStat();

	for (int i = 0; i < 10; i++)
	{
		int k = 0;
		int flag = 0;
		for (int j = 0; j < 3; j++)
			if (attacks[i] == claps[j].getName())
			{
				flag = 1;
				k = j;
				break ;
			}
		if (flag == 1)
			{
				claps[0].attack(attacks[i]);
				claps[k].takeDamage(claps[0].getAD());
			}
		else
			{
				std::cout << attacks[i] << " doesn´t exist. No damage occured." << std::endl;
			}
	}

	for (int i = 0; i < 5; i++)
		claps[0].beRepaired(claps[0].getEnergy());

	for (int i = 0; i < 3; i++)
        claps[i].printStat();

	scav.printStat();

	scav.attack(attacks[9]);
	claps[0].takeDamage(scav.getAD());

	scav.printStat();
	claps[0].printStat();

//	delete[] claps;
    return 0;
}
