#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>       /* time */

class Perso
{
public:
	Perso();
	~Perso();


	bool getStuned() { return isStuned_; }
	void setStuned(bool isStuned) { isStuned_ = isStuned; }

	int getPV() { return PV_; }

	void attaque();

	// fonction qui fait perdre au personnage le nbre de point de vie en argument
	void pertePV(int pv_perdus);



protected:

	int PV_;

	// garde en memoire le dernier tour pendant laquelle on a utilise capacite
	int previousCapaciteTour_;

	// si un perso est paralysé pendant un tour
	bool isStuned_;

};

