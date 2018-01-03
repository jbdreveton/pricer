#include "stdafx.h"
#include "Option.h"


Option::Option(float strike, float maturite, Action action) :_strike(strike), _maturite(maturite), _action(action) {
}

Option::Option(float maturite, Action action) : _maturite(maturite), _action(action) {
}

float Option::getStrike() {
	return _strike;
}

float Option::getMaturite() {
	return _maturite;
}

Action Option::getAction() {
	return _action;
}

float rand_normal(float mean, float stddev){   /* Génération d'une réalisation d'une loi normale N(mean, stddev) selon la méthode Box-Muller*/
	static float n2 = 0.0;
	static int n2_cached = 0;
	if (!n2_cached){
		float x, y, r;
		do{
			x = 2.0*rand() / RAND_MAX - 1;
			y = 2.0*rand() / RAND_MAX - 1;
			r = x * x + y * y;
		} 
		while (r == 0.0 || r > 1.0);{
			float d = sqrt(-2.0*log(r) / r);
			float n1 = x * d;
			n2 = y * d;
			float result = n1 * stddev + mean;
			n2_cached = 1;
			return result;
		}
	}
	else{
		n2_cached = 0;
		return n2 * stddev + mean;
	}
}

std::vector<float> Option::genererTrajectoire() {
	float r = 0.05;    /* Taux d'intérêt sans risque */
	std::vector<float> trajectoire;    /* Vecteur contenant l'évolution du prix de l'actif */
	trajectoire.push_back(_action.getValue());
	int nb_jour = floor(_maturite * 365);
	for (int i = 1; i<nb_jour; i++) {
		float epsilon = rand_normal(0, 1); /* Génération du terme aléatoire */
		trajectoire.push_back(trajectoire[i - 1] * exp((r - _action.getVolatilite()*_action.getVolatilite() / 2)*(1.0 / 365.0) - _action.getVolatilite()*epsilon*sqrt(1.0 / 365.0)));
	}
	return trajectoire;
}

