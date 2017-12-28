#pragma once
#include "Option.h"

class Option_Rainbow : public Option {
private:
	std::string _type;
	int nb_actifs;
	std::vector<Option> vecteur_option;
	float gain_moyen_call_max;
	float gain_moyen_call_min;
	float gain_moyen_put_max;
	float gain_moyen_put_min;
	float price_call_max;
	float price_call_min;
	float price_put_max;
	float price_put_min;
public:
	Option_Rainbow(float strike, float maturite, std::vector<Action> action);
	float getGain_moyen_call_max();
	float getGain_moyen_call_min();
	float getGain_moyen_put_max();
	float getGain_moyen_put_min();
	void setGain_moyen(int nb_simulation);
	void setPrice(int nb_simulation);
	float getPrice_call_max();
	float getPrice_call_min();
	float getPrice_put_max();
	float getPrice_put_min();
	void afficher();
};