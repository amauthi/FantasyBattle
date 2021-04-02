#pragma once

#include "Perso.h"

class Orc:public Perso
{
public:
	Orc();
	~Orc();

	// peut etre utilise tous les cinq tours de jeu, empeche l'adversaire d'attaquer
	// si réussi, retourne true
	bool stun(int nb_tour);

	void attaque();


};

