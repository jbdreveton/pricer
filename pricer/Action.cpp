#include "stdafx.h"
#include "Action.h"


Action::Action(std::string name, float value, float volatilite) {
	this->name = name;
	this->value = value;
	this->volatilite = volatilite;
}

float Action::getValue() {
	return value;
}

float Action::getVolatilite() {
	return volatilite;
}

std::string Action::getName() {
	return name;
}

void Action::afficher() {
	std::cout << std::setw(50) << std::left << name << "| " << std::setw(25) << std::left << value << "| " << std::setw(8) << std::left << volatilite << std::endl;
	return;
}

