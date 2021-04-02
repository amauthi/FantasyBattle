#include "stdafx.h"
#include "Orc.h"


Orc::Orc()
{
	PV_ = 60;
	previousCapaciteTour_ = 0;
	isStuned_ = false;
}


Orc::~Orc()
{
}



bool Orc::stun(int tour)
{
	std::cout << "Orc utilise stun " << std::endl;
	bool result = false;
	if (previousCapaciteTour_ == 0 || tour >= previousCapaciteTour_ + 5)
	{
		srand(time(NULL));
		if (rand() % 100 + 1 < 20)
		{
			std::cout << "Stun reussit ! " << std::endl;
			// mise a jour de previousCapaciteTour
			previousCapaciteTour_ = tour;
			result = true;
		}
		else
		{
			std::cout << "Stun a rate ! " << std::endl;
		}
	}
	else
	{
		std::cout << "Orc doit encore attendre avant d'utiliser stun " << std::endl;
	}

	return result;

}


void Orc::attaque()
{
	std::cout << "Orc attaque !" << std::endl;
}

