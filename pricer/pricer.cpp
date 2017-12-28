// pricer.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <math.h>
#include <random>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include "Action.h"
#include "Option.h"
#include "Option_European.h"
#include "Option_Lookback.h"
#include "Option_Asian.h"
#include "Option_Barrier.h"
#include "Option_Binaire.h"
#include "Option_Parasian.h"
#include "Option_Parisian.h"
#include "Option_ForwardStart.h"
#include "Option_Rainbow.h"
#include "Option_Basket.h"
#include "Option_Chooser.h"

int main()
{
	std::vector<Action> cac40;
	Action actionFPPA("Total S.A.", 47.395, 0.0557);
	cac40.push_back(actionFPPA);
	Action actionENGIPA("ENGIE S.A.", 14.69, 0.2748);
	cac40.push_back(actionENGIPA);
	Action actionORAPA("Orange S.A.", 14.45, 0.0806);
	cac40.push_back(actionORAPA);
	Action actionCAPPA("Capgemini SE", 96.66, 0.3335);
	cac40.push_back(actionCAPPA);
	Action actionATOPA("Atos SE", 123.95, 0.3082);
	cac40.push_back(actionATOPA);
	Action actionEIPA("Essilor International", 107.70, 0.1029);
	cac40.push_back(actionEIPA);
	Action actionKERPA("Kering S.A.", 374.00, 0.8458);
	cac40.push_back(actionKERPA);
	Action actionSWPA("Sodexo S.A.", 109.30, 0.0802);
	cac40.push_back(actionSWPA);
	Action actionMLPA("Compagnie Generale des Etablissements Michelin", 121.30, 0.2064);
	cac40.push_back(actionMLPA);
	Action actionMCPA("LVMH", 243.30, 0.4455);
	cac40.push_back(actionMCPA);
	Action actionACPA("Accor SA", 42.38, 0.2741);
	cac40.push_back(actionACPA);
	Action actionORPA("L'Oreal SA", 184.60, 0.1697);
	cac40.push_back(actionORPA);
	Action actionVIEPA("Veolia", 21.08, 0.3603);
	cac40.push_back(actionVIEPA);
	Action actionGLEPA("Societe Generale", 41.96, 0.0522);
	cac40.push_back(actionGLEPA);
	Action actionACAPA("Credit Agricole S.A.", 14.03, 0.3354);
	cac40.push_back(actionACAPA);
	Action actionDGPA("VINCI SA", 84.92, 0.4226);
	cac40.push_back(actionDGPA);
	Action actionCAPA("Carrefour SA", 17.845, 1); /* Voir volatilite */
	cac40.push_back(actionCAPA);
	Action actionBNPPA("BNP Paribas SA", 62.85, 0.1647);
	cac40.push_back(actionBNPPA);
	Action actionLHNPA("LafargeHolcim Ltd", 45.39, 0.0604);
	cac40.push_back(actionLHNPA);
	Action actionLRPA("Legrand SA", 62.14, 0.2101);
	cac40.push_back(actionLRPA);
	Action actionVIVPA("Vivendi SA", 22.05, 0.2693);
	cac40.push_back(actionVIVPA);
	Action actionBNPA("Danone", 69.79, 0.2146);
	cac40.push_back(actionBNPA);
	Action actionSUPA("Schneider Electric SE", 70.99, 0.1543);
	cac40.push_back(actionSUPA);
	Action actionENPA("Bouygues SA", 42.67, 0.3766);
	cac40.push_back(actionENPA);
	Action actionAIPA("Air Liquide", 103.20, 0.1032);
	cac40.push_back(actionAIPA);
	Action actionSGOPA("Compagnie de Saint-Gobain", 46.81, 0.1898);
	cac40.push_back(actionSGOPA);
	Action actionAIRPA("Airbus SE", 85.31, 0.4797);
	cac40.push_back(actionAIRPA);
	Action actionSANPA("Sanofi", 74.82, 2.5606);
	cac40.push_back(actionSANPA);
	Action actionUGPA("Peugeot SA", 16.90, 0.2464);
	cac40.push_back(actionUGPA);
	Action actionFRPA("Valeo SA", 59.31, 0.1684);
	cac40.push_back(actionFRPA);
	/*  Action actionTEST("TEST",prix_ini,volatilite);
	Action actionORPA("unknown",prix_ini,volatilite);
	Action actionVIEPA("unknown",prix_ini,volatilite);
	Action actionGLEPA("unknown",prix_ini,volatilite);
	Action actionACAPA("unknown",prix_ini,volatilite);
	Action actionDGPA("unknown",prix_ini,volatilite);
	Action actionCAPA("unknown",prix_ini,volatilite);
	Action actionBNPPA("unknown",prix_ini,volatilite);
	Action actionLHNPA("unknown",prix_ini,volatilite);
	Action actionLRPA("unknown",prix_ini,volatilite); */
	std::cout << "Que souhaitez-vous faire ?" << std::endl;
	int num_choix;
	int fin=0;
	while (fin == 0) {
		std::cout << "0 - Afficher la liste des actions du CAC40 et leurs caracteristiques" << std::endl;
		std::cout << "1 - Déterminer le prix d'une option" << std::endl;
		std::cout << "2 - Déterminer le prix d'une stratégie" << std::endl;
		std::cin >> num_choix;
		if (num_choix == 0) {
			std::cout << std::setw(15) << std::left << "Identifiant" << "| " << std::setw(50) << std::left << "Nom de l'entreprise" << "| " << std::setw(25) << std::left << "Prix actuel de l'action" << "| " << std::setw(8) << "Volatilite sur les 12 derniers mois" << std::endl;
			std::cout << "-----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			for (unsigned int i = 0; i<cac40.size(); i++) {
				std::cout << std::setw(15) << std::left << i << "| ";
				cac40[i].afficher();
			}
			std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
			std::cin >> fin;
		}
		if (num_choix == 1) {
			int mode;
			std::cout << "Voulez-vous évaluer le prix d'une option d'une action du CAC40 ou rentrer vous-mêmes les différentes caractéristiques ?" << std::endl;
			std::cout << "1 - Une action du CAC40" << std::endl;
			std::cout << "2 - Rentrer les caractéristiques à la main" << std::endl;
			std::cin >> mode;
			int num_opt;
			std::cout << "Quel est le type de l'option ?" << std::endl;
			std::cout << "1 - Option Vanille (European)" << std::endl;
			std::cout << "2 - Option Lookback" << std::endl;
			std::cout << "3 - Option Asiatique" << std::endl;
			std::cout << "4 - Option Chooser" << std::endl;
			std::cout << "5 - Option Barriere" << std::endl;
			std::cout << "6 - Option Binaire" << std::endl;
			std::cout << "7 - Option Parisienne" << std::endl;
			std::cout << "8 - Option Parasian" << std::endl;
			std::cout << "9 - Option Forward Start" << std::endl;
			std::cout << "10 - Option Rainbow" << std::endl;
			std::cout << "11 - Option Basket" << std::endl;
			std::cin >> num_opt;
			if (mode == 1) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_European optEUR(strike, maturite, actionTEST);
					optEUR.setPrice(50000);
					optEUR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Lookback optLOOK(strike, maturite, actionTEST);
					optLOOK.setPrice(50000);
					optLOOK.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Asian optASIA(strike, maturite, actionTEST);
					optASIA.setPrice(50000);
					optASIA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Combien de jours avant de choisir si c'est un call ou un put ? " << std::endl;
					int date;
					std::cin >> date;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Chooser optCHO(strike, maturite, date, actionTEST);
					optCHO.setPrice(50000);
					optCHO.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Barrier optBARR(barrier, strike, maturite, actionTEST);
					optBARR.setPrice(50000);
					optBARR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quelle est la valeur du gain fixe ?" << std::endl;
					float gain_fixe;
					std::cin >> gain_fixe;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Binaire optBIN(gain_fixe, strike, maturite, actionTEST);
					optBIN.setPrice(50000);
					optBIN.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 7) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la période minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Parisian optPARI(barrier, periode, strike, maturite, actionTEST);
					optPARI.setPrice(50000);
					optPARI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 8) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la période minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Parasian optPARA(barrier, periode, strike, maturite, actionTEST);
					optPARA.setPrice(50000);
					optPARA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 9) {
					std::cout << "Quelle est la date de début ? " << std::endl;
					float begin;
					std::cin >> begin;
					std::cout << "Quel est le coefficient multiplicateur ? " << std::endl;
					float coef;
					std::cin >> coef;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_ForwardStart optFOR(begin, coef, maturite, actionTEST);
					optFOR.setPrice(50000);
					optFOR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 10) {
					std::cout << "Quel est le nombre d'actif total ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<Action> vecteur_action;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est l'identifiant de l'actif " << i + 1 << " ? " << std::endl;
						int id;
						std::cin >> id;
						vecteur_action.push_back(cac40[id]);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					Option_Rainbow optRAI(strike, maturite, vecteur_action);
					optRAI.setPrice(1000);
					optRAI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 11) {
					std::cout << "Quel est le nombre d'actif total ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<Action> vecteur_action;
					std::vector<float> poids;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est l'identifiant de l'actif " << i + 1 << " ? " << std::endl;
						int id;
						std::cin >> id;
						vecteur_action.push_back(cac40[id]);
						std::cout << "Quel est le poids accordé au sous-jacent " << i + 1 << " ? " << std::endl;
						float w;
						std::cin >> w;
						poids.push_back(w);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					Option_Basket optBAS(strike, maturite, poids, vecteur_action);
					optBAS.setPrice(1000);
					optBAS.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
			if (mode == 2) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR(strike, maturite, actionTEST);
					optEUR.setPrice(50000);
					optEUR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Lookback optLOOK(strike, maturite, actionTEST);
					optLOOK.setPrice(50000);
					optLOOK.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Asian optASIA(strike, maturite, actionTEST);
					optASIA.setPrice(50000);
					optASIA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Combien de jours avant de choisir si c'est un call ou un put ? " << std::endl;
					int date;
					std::cin >> date;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Chooser optCHO(strike, maturite, date, actionTEST);
					optCHO.setPrice(50000);
					optCHO.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Barrier optBARR(barrier, strike, maturite, actionTEST);
					optBARR.setPrice(50000);
					optBARR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quelle est la valeur du gain fixe ?" << std::endl;
					float gain_fixe;
					std::cin >> gain_fixe;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Binaire optBIN(gain_fixe, strike, maturite, actionTEST);
					optBIN.setPrice(50000);
					optBIN.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 7) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la période minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Parisian optPARI(barrier, periode, strike, maturite, actionTEST);
					optPARI.setPrice(50000);
					optPARI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 8) {
					std::cout << "Quelle est la valeur de la barrière d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la période minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Parasian optPARA(barrier, periode, strike, maturite, actionTEST);
					optPARA.setPrice(50000);
					optPARA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 9) {
					std::cout << "Quelle est la date de début ? " << std::endl;
					float begin;
					std::cin >> begin;
					std::cout << "Quel est le coefficient multiplicateur ? " << std::endl;
					float coef;
					std::cin >> coef;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilite du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_ForwardStart optFOR(begin, coef, maturite, actionTEST);
					optFOR.setPrice(50000);
					optFOR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 10) {
					std::cout << "Quel est le nombre d'actif total ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<float> prix_ini;
					std::vector<float> volatilite;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est le prix initial du sous-jacent " << i + 1 << " ? " << std::endl;
						float p;
						std::cin >> p;
						prix_ini.push_back(p);
						std::cout << "Quelle est la volatilité du sous-jacent " << i + 1 << " ? " << std::endl;
						float v;
						std::cin >> v;
						volatilite.push_back(v);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::vector<Action> vecteur_action;
					for (int i = 0; i < nb_sous_jacents;i++) {
						vecteur_action.push_back(Action("unknown", prix_ini[i], volatilite[i]));
					}
					Option_Rainbow optRAI(strike, maturite, vecteur_action);
					optRAI.setPrice(1000);
					optRAI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 11) {
					std::cout << "Quel est le nombre d'actif total ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<float> prix_ini;
					std::vector<float> volatilite;
					std::vector<float> poids;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est le prix initial du sous-jacent " << i + 1 << " ? " << std::endl;
						float p;
						std::cin >> p;
						prix_ini.push_back(p);
						std::cout << "Quelle est la volatilité du sous-jacent " << i + 1 << " ? " << std::endl;
						float v;
						std::cin >> v;
						volatilite.push_back(v);
						std::cout << "Quel est le poids accordé au sous-jacent " << i + 1 << " ? " << std::endl;
						float w;
						std::cin >> w;
						poids.push_back(w);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturite ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::vector<Action> vecteur_action;
					for (int i = 0; i < nb_sous_jacents; i++) {
						vecteur_action.push_back(Action("unknown", prix_ini[i], volatilite[i]));
					}
					Option_Basket optBAS(strike, maturite, poids, vecteur_action);
					optBAS.setPrice(1000);
					optBAS.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
		}
		if (num_choix == 2) {
			int mode;
			std::cout << "Voulez-vous évaluer le prix d'une stratégie d'une action du CAC40 ou rentrer vous-mêmes les différentes caractéristiques ?" << std::endl;
			std::cout << "1 - Une action du CAC40" << std::endl;
			std::cout << "2 - Rentrer les caractéristiques à la main" << std::endl;
			std::cin >> mode;
			int num_opt;
			std::cout << "Quel est le type de la stratégie ?" << std::endl;
			std::cout << "1 - Call Spread" << std::endl;
			std::cout << "2 - Put Spread" << std::endl;
			std::cout << "3 - Butterfly" << std::endl;
			std::cout << "4 - Condor" << std::endl;
			std::cout << "5 - Straddle" << std::endl;
			std::cout << "6 - Strangle" << std::endl;
			std::cin >> num_opt;
			if (mode == 1) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike du call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du call vendu ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id];
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_call_spread = optEUR1.getPrice_call() - optEUR2.getPrice_call();
					std::cout << "Type de stratégie: Call Spread" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du call acheté: " << K1 << std::endl;
					std::cout << "Strike du call vendu: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_call_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike du put vendu ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put acheté ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id];
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_put_spread = -optEUR1.getPrice_put() + optEUR2.getPrice_put();
					std::cout << "Type de stratégie: Put Spread" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du put vendu: " << K1 << std::endl;
					std::cout << "Strike du put acheté: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_put_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le Strike des deux calls vendus ?" << std::endl;
					float X;
					std::cin >> X;
					std::cout << "Quel est la différence entre le strike du call vendu et du call acheté ?" << std::endl;
					float a;
					std::cin >> a;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id];
					Option_European optEUR1(X - a, maturite, actionTEST);
					Option_European optEUR2(X, maturite, actionTEST);
					Option_European optEUR3(X + a, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					optEUR3.setPrice(10000);
					float prix_butterfly = optEUR1.getPrice_call() - 2 * optEUR2.getPrice_call() + optEUR3.getPrice_call();
					std::cout << "Type de stratégie: Butterfly" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike de vente: " << X << std::endl;
					std::cout << "Différence entre les strikes de vente et d'achat: " << a << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_butterfly << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike du premier call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quelle est la différence entre les strikes des achats et des ventes ?" << std::endl;
					float epsilon;
					std::cin >> epsilon;
					std::cout << "Quel est le strike du dernier call vendu ?" << std::endl;
					float K3;
					std::cin >> K3;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id];
					float K2 = K1 + epsilon;
					float K4 = K3 + epsilon;
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					Option_European optEUR3(K3, maturite, actionTEST);
					Option_European optEUR4(K4, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					optEUR3.setPrice(10000);
					optEUR4.setPrice(10000);
					float prix_condor = optEUR1.getPrice_call() - optEUR2.getPrice_call() - optEUR3.getPrice_call() + optEUR4.getPrice_call();
					std::cout << "Type de stratégie: Condor" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strikes d'achat: " << K1 << " et " << K4 << std::endl;
					std::cout << "Strikes de vente: " << K2 << " et " << K3 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_condor << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quel est le strike du call et du put achetés ?" << std::endl;
					float K;
					std::cin >> K;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id]; 
					Option_European optEUR(K, maturite, actionTEST);
					optEUR.setPrice(10000);
					float prix_straddle = optEUR.getPrice_call() + optEUR.getPrice_put();
					std::cout << "Type de stratégie: Straddle" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strikes d'achat du call et du put: " << K << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_straddle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quel est le strike du call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put acheté ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id];
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_strangle = optEUR1.getPrice_call() + optEUR2.getPrice_put();
					std::cout << "Type de stratégie: Strangle" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilite: " << cac40[id].getVariance() << std::endl;
					std::cout << "Prix de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du call: " << K1 << std::endl;
					std::cout << "Strike du put: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_strangle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
			if (mode == 2) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike du call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du call vendu ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_call_spread = optEUR1.getPrice_call() - optEUR2.getPrice_call();
					std::cout << "Type de stratégie: Call Spread" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du call acheté: " << K1 << std::endl;
					std::cout << "Strike du call vendu: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_call_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike du put vendu ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put acheté ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_put_spread = -optEUR1.getPrice_put() + optEUR2.getPrice_put();
					std::cout << "Type de stratégie: Put Spread" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du put vendu: " << K1 << std::endl;
					std::cout << "Strike du put acheté: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_put_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le Strike des deux calls vendus ?" << std::endl;
					float X;
					std::cin >> X;
					std::cout << "Quel est la différence entre le strike du call vendu et du call acheté ?" << std::endl;
					float a;
					std::cin >> a;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR1(X - a, maturite, actionTEST);
					Option_European optEUR2(X, maturite, actionTEST);
					Option_European optEUR3(X + a, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					optEUR3.setPrice(10000);
					float prix_butterfly = optEUR1.getPrice_call() - 2 * optEUR2.getPrice_call() + optEUR3.getPrice_call();
					std::cout << "Type de stratégie: Butterfly" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike de vente: " << X << std::endl;
					std::cout << "Différence entre les strikes de vente et d'achat: " << a << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_butterfly << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike du premier call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quelle est la différence entre les strikes des achats et des ventes ?" << std::endl;
					float epsilon;
					std::cin >> epsilon;
					std::cout << "Quel est le strike du dernier call vendu ?" << std::endl;
					float K3;
					std::cin >> K3;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					float K2 = K1 + epsilon;
					float K4 = K3 + epsilon;
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					Option_European optEUR3(K3, maturite, actionTEST);
					Option_European optEUR4(K4, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					optEUR3.setPrice(10000);
					optEUR4.setPrice(10000);
					float prix_condor = optEUR1.getPrice_call() - optEUR2.getPrice_call() - optEUR3.getPrice_call() + optEUR4.getPrice_call();
					std::cout << "Type de stratégie: Condor" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strikes d'achat: " << K1 << " et " << K4 << std::endl;
					std::cout << "Strikes de vente: " << K2 << " et " << K3 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_condor << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quel est le strike du call et du put achetés ?" << std::endl;
					float K;
					std::cin >> K;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR(K, maturite, actionTEST);
					optEUR.setPrice(10000);
					float prix_straddle = optEUR.getPrice_call() + optEUR.getPrice_put();
					std::cout << "Type de stratégie: Straddle" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR.getAction().getName() << std::endl;
					std::cout << "Strikes d'achat du call et du put: " << K << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_straddle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quel est le strike du call acheté ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put acheté ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturité ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilité ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR1(K1, maturite, actionTEST);
					Option_European optEUR2(K2, maturite, actionTEST);
					optEUR1.setPrice(10000);
					optEUR2.setPrice(10000);
					float prix_strangle = optEUR1.getPrice_call() + optEUR2.getPrice_put();
					std::cout << "Type de stratégie: Strangle" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du call: " << K1 << std::endl;
					std::cout << "Strike du put: " << K2 << std::endl;
					std::cout << "Maturite: " << maturite << std::endl;
					std::cout << "Volatilite: " << volatilite << std::endl;
					std::cout << "Prix de la stratégie: " << prix_strangle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
		}
	}
}