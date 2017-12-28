#pragma once
#include "Option.h"

class Option_ForwardStart : public Option {
private:
	float begin;
	float coef;
	std::string _type;
	float gain_moyen_call;
	float gain_moyen_put;
	float price_call;
	float price_put;
public:
	Option_ForwardStart(float begin, float coef, float maturite, Action action);
	float getBegin();
	float getCoef();
	float getGain_moyen_call();
	float getGain_moyen_put();
	void setGain_moyen(int nb_simulation);
	void setPrice(int nb_simulation);
	float getPrice_call();
	float getPrice_put();
	void afficher();
};

