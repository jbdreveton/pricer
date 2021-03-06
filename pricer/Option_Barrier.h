#pragma once
#include "Option.h"

class Option_Barrier : public Option {
private:
	std::string _type;
	float barrier;
	float gain_moyen_call_up_and_in;
	float gain_moyen_call_up_and_out;
	float gain_moyen_call_down_and_in;
	float gain_moyen_call_down_and_out;
	float gain_moyen_put_up_and_in;
	float gain_moyen_put_up_and_out;
	float gain_moyen_put_down_and_in;
	float gain_moyen_put_down_and_out;
	float price_call_up_and_in;
	float price_call_up_and_out;
	float price_call_down_and_in;
	float price_call_down_and_out;
	float price_put_up_and_in;
	float price_put_up_and_out;
	float price_put_down_and_in;
	float price_put_down_and_out;
public:
	Option_Barrier(float barrier, float strike, float maturite, Action action);
	float getGain_moyen_call_up_and_in();
	float getGain_moyen_call_up_and_out();
	float getGain_moyen_call_down_and_in();
	float getGain_moyen_call_down_and_out();
	float getGain_moyen_put_up_and_in();
	float getGain_moyen_put_up_and_out();
	float getGain_moyen_put_down_and_in();
	float getGain_moyen_put_down_and_out();
	void setGain_moyen(int nb_simulation);
	void setPrice(int nb_simulation);
	float getPrice_call_up_and_in();
	float getPrice_call_up_and_out();
	float getPrice_call_down_and_in();
	float getPrice_call_down_and_out();
	float getPrice_put_up_and_in();
	float getPrice_put_up_and_out();
	float getPrice_put_down_and_in();
	float getPrice_put_down_and_out();
	void afficher();
};


