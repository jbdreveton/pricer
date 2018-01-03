#include "stdafx.h"
#include "Option_Chooser.h"


Option_Chooser::Option_Chooser(float strike, float maturite, int date_choix, Action action) : Option(strike, maturite, action) {
	_type = "Chooser";
	this->date_choix = date_choix;
}

float Option_Chooser::getGain_moyen() {
	return gain_moyen;
}

void Option_Chooser::setGain_moyen(int nb_simulation) {
	float gain=0;
	bool call;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		if (simulation[date_choix] > getStrike()) {  /* à la date du choix, on compare le prix de l'actif au strike */
			call = true;                             /* si on est au-dessus, on choisit un call, sinon un put */
		}
		else {
			call = false;
		}
		if (simulation[floor(getMaturite() * 365) - 1] > getStrike() and call==true) { /* si on a choisi call et qu'on est à la fin au-dessus du strike, on regarde les gains*/
			gain += simulation[floor(getMaturite() * 365) - 1] - getStrike();
		}
		if (simulation[floor(getMaturite() * 365) - 1] < getStrike() and call == false) { /* si on a choisi put et qu'on est à la fin en-dessous du strike, on regarde les gains*/
			gain += getStrike() - simulation[floor(getMaturite() * 365 - 1)];
		}
	}
	this->gain_moyen = gain / nb_simulation;
	return;
}

void Option_Chooser::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price = gain_moyen * exp(-r * getMaturite());
	return;
}

float Option_Chooser::getPrice() {
	return price;
}

void Option_Chooser::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Nombre de jours avant de choisir call ou put: " << date_choix << std::endl;
	std::cout << "Maturit\x82: " << getMaturite() << std::endl;
	std::cout << "Volatilit\x82: " << getAction().getVolatilite() << std::endl;
	std::cout << "Prix initial du sous-jacent: " << getAction().getValue() << std::endl;
	std::cout << "Prix: " << price << std::endl;
	return;
}
