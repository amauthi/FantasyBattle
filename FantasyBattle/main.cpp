// main.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>


#include <string>

#include "Orc.h"
#include "Knight.h"

int main()
{

	bool isGameOver = false;
	int nb_tour = 1;

	std::cout << "hello" << std::endl;

	Orc orc;
	Knight knight;

	while (!isGameOver)
	{
		std::cout << "Tour " << nb_tour << std::endl;

		//
		// initialisation des capacites pour ce tour-ci
		//

		std::cout << "Choisissez votre capacite : " << std::endl;

		std::string capaciteOrc;
		std::string capaciteKnight;

		std::cout << "Orc :" << std::endl;
		std::cin >> capaciteOrc;
		std::cout << "Knight : " << std::endl;
		std::cin >> capaciteKnight;


		//
		// attaques
		//

		int degatOrc = 8;

		// attaque de l'orc
		if (capaciteOrc == "stun")
		{
			if (orc.stun(nb_tour))
			{
				std::cout << "Le chevalier est stuned " << std::endl;
				knight.setStuned(true);
			}
		}
		
		orc.attaque();
		if (knight.getBouclier() > 0)
		{
			knight.perteBouclier(degatOrc);
		}
		else
		{
			std::cout << "Pour le chevalier ";
			knight.pertePV(degatOrc);
		}

		int degatKnight = 5;

		// attaque du knight
		if (!knight.getStuned())
		{
			if (capaciteKnight == "charge")
			{
				// si la charge fonctionne, alors le chevalier fait 2 fois plus de degats
				if (knight.charge(nb_tour))
				{
					degatKnight = degatKnight * 2;
				}
			}

			knight.attaque();
			std::cout << "Pour l'orc ";
			orc.pertePV(degatKnight);

		}
		else
		{
			std::cout << "Le chevalier est stun, il ne peut pas attaquer" << std::endl;
		}

		//
		// verification des PV
		//


		if (orc.getPV() == 0)
		{
			std::cout << " Knight wins at tour = " << nb_tour << std::endl;
			std::cout << "PV Bouclier Chevalier : " << knight.getBouclier() << std::endl;
			std::cout << "PV Chevalier : " << knight.getPV() << std::endl;
			std::cout << "PV Orc : " << orc.getPV() << std::endl;
			isGameOver = true;
		}
		else if (knight.getPV() == 0)
		{
			std::cout << " Orc wins at tour = "<< nb_tour << std::endl;
			std::cout << "PV Bouclier Chevalier : " << knight.getBouclier() << std::endl;
			std::cout << "PV Chevalier : " << knight.getPV() << std::endl;
			std::cout << "PV Orc : " << orc.getPV() << std::endl;
			isGameOver = true;
		}
		else
		{
			// a chaque tour, on remet le stun par defaut
			knight.setStuned(false);

			nb_tour++;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "PV Bouclier Chevalier : " << knight.getBouclier() << std::endl;
			std::cout << "PV Chevalier : " << knight.getPV() << std::endl;
			std::cout << "PV Orc : " << orc.getPV() << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
		}

	}
    return 0;
}

