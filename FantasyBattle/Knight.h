#pragma once

#include "Perso.h"

class Knight: public Perso
{
public:
	Knight();
	~Knight();


	int getBouclier() { return bouclier_; }

	void perteBouclier(int pv_perdus);

	// tous les 3 tours, on peut utiliser cette capacité, elle n'a que 60% de chance de marcher
	// si charge fonctionne, renvoie true
	bool charge(int tour);

	void attaque();

private:

	int bouclier_;


};

