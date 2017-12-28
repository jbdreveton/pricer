#include "stdafx.h"
#include "Option_Rainbow.h"


Option_Rainbow::Option_Rainbow(float strike, float maturite, std::vector<Action> action) : Option(strike,maturite,action[0]) {
	for (int unsigned i = 0; i<action.size(); i++) {
		vecteur_option.push_back(Option(strike,maturite,action[i]));
	}
	_type = "Rainbow";
	nb_actifs = action.size();
}


float Option_Rainbow::getGain_moyen_call_max() {
	return gain_moyen_call_max;
}

float Option_Rainbow::getGain_moyen_call_min() {
	return gain_moyen_call_min;
}

float Option_Rainbow::getGain_moyen_put_max() {
	return gain_moyen_put_max;
}

float Option_Rainbow::getGain_moyen_put_min() {
	return gain_moyen_put_min;
}

void Option_Rainbow::setGain_moyen(int nb_simulation) {
	float gain_call_max = 0;
	float gain_call_min = 0;
	float gain_put_max = 0;
	float gain_put_min = 0;
	std::vector<float> resultat_final;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> resultat_final;
		for (int j = 0; j < nb_actifs; j++) {
			resultat_final.push_back(vecteur_option[j].genererTrajectoire()[vecteur_option[j].genererTrajectoire().size()-1]);	
		}
		double max = *std::max_element(resultat_final.begin(), resultat_final.end());
		double min = *std::min_element(resultat_final.begin(), resultat_final.end());
		if (max - getStrike() > 0) {
			gain_call_max += max-getStrike();
		}
		else {
			gain_put_max += getStrike() - max;
		}
		if (min - getStrike() > 0) {
			gain_call_min += min - getStrike();
		}
		else {
			gain_put_min += getStrike() - min;
		}
	}
	this->gain_moyen_call_max = gain_call_max / nb_simulation;
	this->gain_moyen_call_min = gain_call_min / nb_simulation;
	this->gain_moyen_put_max = gain_put_max / nb_simulation;
	this->gain_moyen_put_min = gain_put_min / nb_simulation;
	return;
}

void Option_Rainbow::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call_max = gain_moyen_call_max * exp(-r * getMaturite());
	price_call_min = gain_moyen_call_min * exp(-r * getMaturite());
	price_put_max = gain_moyen_put_max * exp(-r * getMaturite());
	price_put_min = gain_moyen_put_min * exp(-r * getMaturite());
	return;
}

float Option_Rainbow::getPrice_call_max() {
	return price_call_max;
}

float Option_Rainbow::getPrice_call_min() {
	return price_call_min;
}

float Option_Rainbow::getPrice_put_max() {
	return price_put_max;
}

float Option_Rainbow::getPrice_put_min() {
	return price_put_min;
}

void Option_Rainbow::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	for (int i = 0; i < nb_actifs; i++) {
		std::cout << "Nom de l'actif " << i + 1 << " : " << vecteur_option[i].getAction().getName() << std::endl;
		std::cout << "Prix initial de l'actif " << i+1 << " : " << vecteur_option[i].getAction().getValue() << std::endl;
		std::cout << "Volatilité de l'actif " << i+1 << " : " << vecteur_option[i].getAction().getVariance() << std::endl;
	}
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturite: " << getMaturite() << std::endl;
	std::cout << "Prix du call max : " << price_call_max << std::endl;
	std::cout << "Prix du call min : " << price_call_min << std::endl;
	std::cout << "Prix du put max : " << price_put_max << std::endl;
	std::cout << "Prix du put min : " << price_put_min << std::endl;
	return;
}
