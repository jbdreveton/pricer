#pragma once
#include "Action.h"
class Option {
private:
	float _strike;
	float _maturite;
protected:
	Action _action;
public:
	Option(float strike, float maturite, Action action);
	Option(float maturite, Action action);
	float getStrike();
	float getMaturite();
	Action getAction();
	std::vector<float> genererTrajectoire();
};


