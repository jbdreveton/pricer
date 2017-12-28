#include "stdafx.h"
#include "Option_Binaire.h"

Option_Binaire::Option_Binaire(float gain_fixe, float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "Binaire";
	this->gain_fixe = gain_fixe;
}

float Option_Binaire::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_Binaire::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_Binaire::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		double max = *std::max_element(simulation.begin(), simulation.end());
		if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) {
			gain_call += gain_fixe;
		}
		else {
			gain_put += gain_fixe;
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_Binaire::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_Binaire::getPrice_call() {
	return price_call;
}

float Option_Binaire::getPrice_put() {
	return price_put;
}

void Option_Binaire::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Valeur en cas de gain: " << gain_fixe << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturite: " << getMaturite() << std::endl;
	std::cout << "Volatilite: " << getAction().getVariance() << std::endl;
	std::cout << "Prix du call: " << price_call << std::endl;
	std::cout << "Prix du put: " << price_put << std::endl;
	return;
}