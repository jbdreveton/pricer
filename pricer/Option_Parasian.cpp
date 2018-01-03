#include "stdafx.h"
#include "Option_Parasian.h"


Option_Parasian::Option_Parasian(float barrier, float periode, float strike, float maturite, Action action) : Option(strike, maturite, action) {
	_type = "Parasian";
	this->barrier = barrier;
	this->periode = periode;
}

float Option_Parasian::getGain_moyen_call_up_and_in() {
	return gain_moyen_call_up_and_in;
}

float Option_Parasian::getGain_moyen_call_up_and_out() {
	return gain_moyen_call_up_and_out;
}

float Option_Parasian::getGain_moyen_call_down_and_in() {
	return gain_moyen_call_down_and_in;
}

float Option_Parasian::getGain_moyen_call_down_and_out() {
	return gain_moyen_call_down_and_out;
}

float Option_Parasian::getGain_moyen_put_up_and_in() {
	return gain_moyen_put_up_and_in;
}

float Option_Parasian::getGain_moyen_put_up_and_out() {
	return gain_moyen_put_up_and_out;
}

float Option_Parasian::getGain_moyen_put_down_and_in() {
	return gain_moyen_put_down_and_in;
}

float Option_Parasian::getGain_moyen_put_down_and_out() {
	return gain_moyen_put_down_and_out;
}

void Option_Parasian::setActivation(std::vector<float> simulation) {
	int compteur_up = 0;
	int compteur_down = 0;
	for (int i = 0; i < simulation.size(); i++) {
		if (simulation[i] > barrier) { /* on compte combien de jours on est au-dessus de la barri�re */
			compteur_up += 1;
		}
		else { /* on compte combien de jours on est en-dessous de la barri�re */
			compteur_down += 1;
		}
	}
	if (compteur_up > periode) {
		activation_up = true;
	}
	if (compteur_down > periode) {
		activation_down = true;
	}
	return;
}

void Option_Parasian::setGain_moyen(int nb_simulation) {
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
		if (activation_up==true) {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) { /* cas o� le call up-and-in rapporte */
				gain_call_up_and_in += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else { /* cas o� le put up-and-in rapporte */
				gain_put_up_and_in += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		else { 
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) { /* cas o� le call up-and-out rapporte */
				gain_call_up_and_out += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else { /*cas o� le put up-and-out rapporte */
				gain_put_up_and_out += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		if (activation_down==true) {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) { /*cas o� le call down-and-in rapporte */
				gain_call_down_and_in += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else { /* cas o� le put down-and-in rapporte */
				gain_put_down_and_in += getStrike() - simulation[floor(getMaturite() * 365) - 1];
			}
		}
		else {
			if (simulation[floor(getMaturite() * 365) - 1] > getStrike()) { /* cas o� le call down-and-out rapporte */
				gain_call_down_and_out += simulation[floor(getMaturite() * 365) - 1] - getStrike();
			}
			else { /* cas o� le put down-and-out rapporte */
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

void Option_Parasian::setPrice(int nb_simulation) {
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

float Option_Parasian::getPrice_call_up_and_in() {
	return price_call_up_and_in;
}

float Option_Parasian::getPrice_call_up_and_out() {
	return price_call_up_and_out;
}

float Option_Parasian::getPrice_call_down_and_in() {
	return price_call_down_and_in;
}

float Option_Parasian::getPrice_call_down_and_out() {
	return price_call_down_and_out;
}

float Option_Parasian::getPrice_put_up_and_in() {
	return price_put_up_and_in;
}

float Option_Parasian::getPrice_put_up_and_out() {
	return price_put_up_and_out;
}

float Option_Parasian::getPrice_put_down_and_in() {
	return price_put_down_and_in;
}

float Option_Parasian::getPrice_put_down_and_out() {
	return price_put_down_and_out;
}

void Option_Parasian::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Barri\x8Are: " << barrier << std::endl;
	std::cout << "P\x82riode d'activation: " << periode << std::endl;
	std::cout << "Strike: " << getStrike() << std::endl;
	std::cout << "Maturit\x82: " << getMaturite() << std::endl;
	std::cout << "Volatilit\x82: " << getAction().getVolatilite() << std::endl;
	std::cout << "Prix initial du sous-jacent: " << getAction().getValue() << std::endl;
	std::cout << "Prix du call up-and-in: " << price_call_up_and_in << std::endl;
	std::cout << "Prix du call up-and-out: " << price_call_up_and_out << std::endl;
	std::cout << "Prix du call down-and-in: " << price_call_down_and_in << std::endl;
	std::cout << "Prix du call down-and-out: " << price_call_down_and_out << std::endl;
	std::cout << "Prix du put up-and-in: " << price_put_up_and_in << std::endl;
	std::cout << "Prix du put up-and-out: " << price_put_up_and_out << std::endl;
	std::cout << "Prix du put down-and-in: " << price_put_down_and_in << std::endl;
	std::cout << "Prix du put down-and-out: " << price_put_down_and_out << std::endl;
	return;
}