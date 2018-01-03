#include "stdafx.h"
#include "Option_European.h"


Option_European::Option_European(float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "European";
}

float Option_European::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_European::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_European::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) { /* cas où le call rapporte*/
			gain_call += simulation[floor(getMaturite() * 365) - 1] - getStrike();
		}
		else { /* cas où le put rapporte */
			gain_put += getStrike() - simulation[floor(getMaturite() * 365) - 1];
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_European::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_European::getPrice_call() {
	return price_call;
}

float Option_European::getPrice_put() {
	return price_put;
}

void Option_European::afficher() {
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
