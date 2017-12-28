#include "stdafx.h"
#include "Option_Parisian.h"


Option_Parisian::Option_Parisian(float barrier, float periode, float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "Parisian";
	this->barrier = barrier;
	this->periode = periode;
}

float Option_Parisian::getGain_moyen_call_up_and_in() {
	return gain_moyen_call_up_and_in;
}

float Option_Parisian::getGain_moyen_call_up_and_out() {
	return gain_moyen_call_up_and_out;
}

float Option_Parisian::getGain_moyen_call_down_and_in() {
	return gain_moyen_call_down_and_in;
}

float Option_Parisian::getGain_moyen_call_down_and_out() {
	return gain_moyen_call_down_and_out;
}

float Option_Parisian::getGain_moyen_put_up_and_in() {
	return gain_moyen_put_up_and_in;
}

float Option_Parisian::getGain_moyen_put_up_and_out() {
	return gain_moyen_put_up_and_out;
}

float Option_Parisian::getGain_moyen_put_down_and_in() {
	return gain_moyen_put_down_and_in;
}

float Option_Parisian::getGain_moyen_put_down_and_out() {
	return gain_moyen_put_down_and_out;
}

void Option_Parisian::setActivation(std::vector<float> simulation) {
	activation_up = false;
	activation_down = false;
	int compteur_up = 0;
	int compteur_down = 0;
	for (int i = 0; i < simulation.size() - periode; i++) {
		if (simulation[i] > barrier) {
			int consecutif_up = 1;
			int j = i + 1;
			while (simulation[j] > barrier & j<=periode) {
				j += 1;
				consecutif_up += 1;
			}
			if (consecutif_up > compteur_up) {
				compteur_up = consecutif_up;
			}
		}
		else {
			int consecutif_down = 1;
			int j = i + 1;
			while (simulation[j] < barrier & j <= periode) {
				j += 1;
				consecutif_down += 1;
			}
			if (consecutif_down > compteur_down) {
				compteur_down = consecutif_down;
			}
		}
	}
	if (compteur_up >= periode) {
		activation_up = true;
	}
	if (compteur_down >= periode) {
		activation_down = true;
	}
	return;
}

void Option_Parisian::setGain_moyen(int nb_simulation) {
	float gain_call_up_and_in = 0;
	float gain_call_up_and_out = 0;
	float gain_call_down_and_in = 0;
	float gain_call_down_and_out = 0;
	float gain_put_up_and_in = 0;
	float gain_put_up_and_out = 0;
	float gain_put_down_and_in = 0;
	float gain_put_down_and_out = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		setActivation(simulation);
		if (activation_up == true) {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) {
				gain_call_up_and_in += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else {
				gain_put_up_and_in += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		else {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) {
				gain_call_up_and_out += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else {
				gain_put_up_and_out += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		if (activation_down == true) {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) {
				gain_call_down_and_in += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else {
				gain_put_down_and_in += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		else {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) {
				gain_call_down_and_out += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else {
				gain_put_down_and_out += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
	}
	this->gain_moyen_call_up_and_in = gain_call_up_and_in / nb_simulation;
	this->gain_moyen_call_up_and_out = gain_call_up_and_out / nb_simulation;
	this->gain_moyen_call_down_and_in = gain_call_down_and_in / nb_simulation;
	this->gain_moyen_call_down_and_out = gain_call_down_and_out / nb_simulation;
	this->gain_moyen_put_up_and_in = gain_put_up_and_in / nb_simulation;
	this->gain_moyen_put_up_and_out = gain_put_up_and_out / nb_simulation;
	this->gain_moyen_put_down_and_in = gain_put_down_and_in / nb_simulation;
	this->gain_moyen_put_down_and_out = gain_put_down_and_out / nb_simulation;
	return;
}

void Option_Parisian::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call_up_and_in = gain_moyen_call_up_and_in * exp(-r * getMaturite());
	price_call_up_and_out = gain_moyen_call_up_and_out * exp(-r * getMaturite());
	price_call_down_and_in = gain_moyen_call_down_and_in * exp(-r * getMaturite());
	price_call_down_and_out = gain_moyen_call_down_and_out * exp(-r * getMaturite());
	price_put_up_and_in = gain_moyen_put_up_and_in * exp(-r * getMaturite());
	price_put_up_and_out = gain_moyen_put_up_and_out * exp(-r * getMaturite());
	price_put_down_and_in = gain_moyen_put_down_and_in * exp(-r * getMaturite());
	price_put_down_and_out = gain_moyen_put_down_and_out * exp(-r * getMaturite());
	return;
}

float Option_Parisian::getPrice_call_up_and_in() {
	return price_call_up_and_in;
}

float Option_Parisian::getPrice_call_up_and_out() {
	return price_call_up_and_out;
}

float Option_Parisian::getPrice_call_down_and_in() {
	return price_call_down_and_in;
}

float Option_Parisian::getPrice_call_down_and_out() {
	return price_call_down_and_out;
}

float Option_Parisian::getPrice_put_up_and_in() {
	return price_put_up_and_in;
}

float Option_Parisian::getPrice_put_up_and_out() {
	return price_put_up_and_out;
}

float Option_Parisian::getPrice_put_down_and_in() {
	return price_put_down_and_in;
}

float Option_Parisian::getPrice_put_down_and_out() {
	return price_put_down_and_out;
}

void Option_Parisian::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Barrière: " << barrier << std::endl;
	std::cout << "Période d'activation: " << periode << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturite: " << getMaturite() << std::endl;
	std::cout << "Volatilite: " << getAction().getVariance() << std::endl;
	std::cout << "Prix du call up and in: " << price_call_up_and_in << std::endl;
	std::cout << "Prix du call up and out: " << price_call_up_and_out << std::endl;
	std::cout << "Prix du call down and in: " << price_call_down_and_in << std::endl;
	std::cout << "Prix du call down and out: " << price_call_down_and_out << std::endl;
	std::cout << "Prix du put up and in: " << price_put_up_and_in << std::endl;
	std::cout << "Prix du put up and out: " << price_put_up_and_out << std::endl;
	std::cout << "Prix du put down and in: " << price_put_down_and_in << std::endl;
	std::cout << "Prix du put down and out: " << price_put_down_and_out << std::endl;
	return;
}