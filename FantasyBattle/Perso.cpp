#include "stdafx.h"
#include "Perso.h"



Perso::Perso()
{
}


Perso::~Perso()
{
}


void Perso::attaque() 
{
	std::cout << "Attaque !" << std::endl;
}

void Perso::pertePV(int pv_perdus) 
{
	std::cout << "perte de " << pv_perdus << " PV" << std::endl;
	if (PV_ > pv_perdus)
	{
		PV_ = PV_ - pv_perdus;
	}
	else
	{
		PV_ = 0;
		std::cout << "PV a 0 !" << std::endl;
	}

}

