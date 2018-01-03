#include "stdafx.h"
#include "Option_Lookback.h"


Option_Lookback::Option_Lookback(float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "Lookback";
}

float Option_Lookback::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_Lookback::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_Lookback::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		double max = *std::max_element(simulation.begin(), simulation.end()); /* valeurs extrêmes qui seront comparées au strike */
		double min = *std::min_element(simulation.begin(), simulation.end());
		if (max > getStrike()) {
			gain_put += max - getStrike(); /* le détenteur du put va vendre au prix maximal qu'a pris l'actif lors du contrat */
		}
		if (min < getStrike()) {
			gain_call += getStrike() - min; /* le détenteur du call va acheter au prix minimal qu'a pris l'actif lors du contrat */
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_Lookback::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_Lookback::getPrice_call() {
	return price_call;
}

float Option_Lookback::getPrice_put() {
	return price_put;
}

void Option_Lookback::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturit\x82: " << getMaturite() << std::endl;
	std::cout << "Volatilit\x82: " << getAction().getVolatilite() << std::endl;
	std::cout << "Prix initial du sous-jacent: " << getAction().getValue() << std::endl;
	std::cout << "Prix du call: " << price_call << std::endl;
	std::cout << "Prix du put: " << price_put << std::endl;
	return;
}
