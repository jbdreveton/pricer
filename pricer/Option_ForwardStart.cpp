#include "stdafx.h"
#include "Option_ForwardStart.h"


Option_ForwardStart::Option_ForwardStart(float begin, float coef, float maturite, Action action) : Option(maturite, action) {
	_type = "ForwardStart";
	this->begin =  begin;
	this->coef = coef;
}

float Option_ForwardStart::getBegin() {
	return begin;
}

float Option_ForwardStart::getCoef() {
	return coef;
}

float Option_ForwardStart::getGain_moyen_call() {
	return gain_moyen_call;
}

float Option_ForwardStart::getGain_moyen_put() {
	return gain_moyen_put;
}

void Option_ForwardStart::setGain_moyen(int nb_simulation) {
	float gain_call = 0;
	float gain_put = 0;
	for (int i = 0; i<nb_simulation; i++) {
		std::vector<float> simulation = genererTrajectoire();
		float prix_begin = simulation[floor(getBegin() * 365)-1]; /* le prix final de l'actif sera comparé au prix à la date begin */
		if (simulation[floor(getMaturite()*365)-1] > getCoef()*prix_begin) { /* cas où le call rapporte */
			gain_call += simulation[floor(getMaturite()*365)-1] - getCoef()*prix_begin;
		}
		else { /* cas où le put rapporte */
			gain_put += getCoef() * prix_begin - simulation[floor(getMaturite() * 365)-1];
		}
	}
	this->gain_moyen_call = gain_call / nb_simulation;
	this->gain_moyen_put = gain_put / nb_simulation;
	return;
}

void Option_ForwardStart::setPrice(int nb_simulation) {
	float r = 0.05;
	setGain_moyen(nb_simulation);
	price_call = gain_moyen_call * exp(-r * getMaturite());
	price_put = gain_moyen_put * exp(-r * getMaturite());
	return;
}

float Option_ForwardStart::getPrice_call() {
	return price_call;
}

float Option_ForwardStart::getPrice_put() {
	return price_put;
}

void Option_ForwardStart::afficher() {
	std::cout << "Type de l'option: " << _type << std::endl;
	std::cout << "Nom de l'actif: " << getAction().getName() << std::endl;
	std::cout << "Date de d" <<"\x82" << "but: " << begin << std::endl;
	std::cout << "Coefficient: " << coef << std::endl;
	std::cout << "Maturit\x82: " << getMaturite() << std::endl;
	std::cout << "Volatilit\x82: " << getAction().getVolatilite() << std::endl;
	std::cout << "Prix initial du sous-jacent: " << getAction().getValue() << std::endl;
	std::cout << "Prix du call: " << price_call << std::endl;
	std::cout << "Prix du put: " << price_put << std::endl;
	return;
}
