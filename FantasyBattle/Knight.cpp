#include "stdafx.h"
#include "Knight.h"


Knight::Knight()
{
	bouclier_ = 50;
	PV_ = 20;
	previousCapaciteTour_ = 0;
	isStuned_ = false;
}


Knight::~Knight()
{
}


void Knight::perteBouclier(int pv_perdus)
{
	std::cout << "Pour le bouclier du chevalier, perte de "<< pv_perdus << " PV "<< std::endl;
	if (bouclier_ > pv_perdus)
	{
		bouclier_ = bouclier_ - pv_perdus;
	}
	else
	{
		bouclier_ = 0;
	}
}

bool Knight::charge(int tour)
{
	std::cout << "Knight utilise charge" << std::endl;
	bool result = false;
	if (previousCapaciteTour_ == 0 || tour >= previousCapaciteTour_ + 3)
	{
		srand(time(NULL));
		if (rand() % 100 + 1 < 60)
		{
			std::cout << "Charge reussit ! " << std::endl;
			// mise a jour de previousCapaciteTour
			previousCapaciteTour_ = tour;
			result = true;
		}
		else
		{
			std::cout << "Charge a rate ! " << std::endl;
		}
	}
	else
	{
		std::cout << "Knight doit encore attendre avant d'utiliser charge" << std::endl;
	}



	return result;
}


void Knight::attaque()
{
	std::cout << "Chevalier attaque !" << std::endl;
}

