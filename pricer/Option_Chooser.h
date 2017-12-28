#pragma once
#include "Option.h"
class Option_Chooser : public Option {
private:
	std::string _type;
	float gain_moyen;
	float price;
	int date_choix;
public:
	Option_Chooser(float strike, float maturite, int date_choix, Action action);
	float getGain_moyen();
	void setGain_moyen(int nb_simulation);
	void setPrice(int nb_simulation);
	float getPrice();
	void afficher();
};


