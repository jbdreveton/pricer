#include "stdafx.h"
#include "Option_Asian.h"

Option_Asian::Option_Asian(float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "Asian";
}

float Option_Asian::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_Asian::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_Asian::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		double sum = std::accumulate(simulation.begin(), simulation.end(), 0.0);
		double mean = sum / simulation.size();
		if (mean > getStrike()) {
			gain_call += mean - getStrike();
		}
		if (mean < getStrike()) {
			gain_put += getStrike() - mean;
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_Asian::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_Asian::getPrice_call() {
	return price_call;
}

float Option_Asian::getPrice_put() {
	return price_put;
}

void Option_Asian::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturite: " << getMaturite() << std::endl;
	std::cout << "Volatilite: " << getAction().getVariance() << std::endl;
	std::cout << "Prix du call: " << price_call << std::endl;
	std::cout << "Prix du put: " << price_put << std::endl;
	return;
}
