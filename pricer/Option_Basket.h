#pragma once
#include "Option.h"

class Option_Basket : public Option {
private:
	std::string _type;
	int nb_actifs;
	std::vector<Option> vecteur_option;
	std::vector<float> poids;
	float gain_moyen_call;
	float gain_moyen_put;
	float price_call;
	float price_put;
public:
	Option_Basket(float strike, float maturite, std::vector<float> poids, std::vector<Action> action);
	float getGain_moyen_call();
	float getGain_moyen_put();
	void setGain_moyen(int nb_simulation);
	void setPrice(int nb_simulation);
	float getPrice_call();
	float getPrice_put();
	void afficher();
};