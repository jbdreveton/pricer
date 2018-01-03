#include "stdafx.h"
#include "Option_Basket.h"


Option_Basket::Option_Basket(float strike, float maturite, std::vector<float> poids, std::vector<Action> action) : Option(strike, maturite, action[0]) {
	for (int unsigned i = 0; i<action.size(); i++) {
		vecteur_option.push_back(Option(strike, maturite, action[i]));
	}
	_type = "Basket";
	this->poids = poids;
	nb_actifs = action.size();
}


float Option_Basket::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_Basket::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_Basket::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	std::vector<float> resultat_final;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> resultat_final;
		for (int j = 0; j < nb_actifs; j++) { /* i-ième simulation de l'actif j */
			resultat_final.push_back(vecteur_option[j].genererTrajectoire()[vecteur_option[j].genererTrajectoire().size() - 1]); /* valeur finale de la i-ième simulation de l'actif j*/
		}
		double final = 0;
		for (int l = 0; l < nb_actifs; l++) {
			final += resultat_final[l] * poids[l]; /* calcul de la valeur finale pondérée qui sera comparée au strike */
		}
		if (final - getStrike() > 0) {
			gain_call += final - getStrike();
		}
		else {
			gain_put += getStrike() - final;
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_Basket::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_Basket::getPrice_call() {
	return price_call;
}

float Option_Basket::getPrice_put() {
	return price_put;
}

void Option_Basket::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	for (int i = 0; i < nb_actifs; i++) {
		std::cout << "Nom de l'actif " << i + 1 << " : " << vecteur_option[i].getAction().getName() << std::endl;
		std::cout << "Prix initial de l'actif " << i + 1 << " : " << vecteur_option[i].getAction().getValue() << std::endl;
		std::cout << "Volatilit\x82 de l'actif " << i + 1 << " : " << vecteur_option[i].getAction().getVolatilite() << std::endl;
		std::cout << "Poids de l'actif " << i + 1 << " : " << poids[i] << std::endl;
	}
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturit\x82: " << getMaturite() << std::endl;
	std::cout << "Prix du call : " << price_call << std::endl;
	std::cout << "Prix du put : " << price_put << std::endl;
	return;
}
