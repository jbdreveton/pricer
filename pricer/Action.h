#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
#include <random>
#include <algorithm>
#include <cmath>
#include <iomanip>

class Action {
private:
	std::string name;
	float value;
	float volatilite;
public:
	Action(std::string name, float value, float volatilite);
	float getValue();
	float getVolatilite();
	std::string getName();
	void afficher();
};


