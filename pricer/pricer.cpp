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
	std::vector<Action> cac40; /* création du vecteur contenant les actions du CAC 40 */
	Action actionFPPA("Total S.A.", 46.04, 0.1306);
	cac40.push_back(actionFPPA);
	Action actionENGIPA("ENGIE S.A.", 14.33, 0.1871);
	cac40.push_back(actionENGIPA);
	Action actionORAPA("Orange S.A.", 14.47, 0.1355);
	cac40.push_back(actionORAPA);
	Action actionCAPPA("Capgemini SE", 98.89, 0.1759);
	cac40.push_back(actionCAPPA);
	Action actionATOPA("Atos SE", 121.35, 0.1831);
	cac40.push_back(actionATOPA);
	Action actionEIPA("Essilor International", 114.95, 0.2069);
	cac40.push_back(actionEIPA);
	Action actionKERPA("Kering S.A.", 393.00, 0.2109);
	cac40.push_back(actionKERPA);
	Action actionSWPA("Sodexo S.A.", 112.05, 0.1598);
	cac40.push_back(actionSWPA);
	Action actionMLPA("Compagnie Generale des Etablissements Michelin", 119.50, 0.1657);
	cac40.push_back(actionMLPA);
	Action actionMCPA("LVMH", 245.40, 0.1667);
	cac40.push_back(actionMCPA);
	Action actionACPA("Accor SA", 43.00, 0.1620);
	cac40.push_back(actionACPA);
	Action actionORPA("L'Oreal SA", 184.95, 0.1389);
	cac40.push_back(actionORPA);
	Action actionVIEPA("Veolia", 21.27, 0.1648);
	cac40.push_back(actionVIEPA);
	Action actionGLEPA("Societe Generale", 43.04, 0.2531);
	cac40.push_back(actionGLEPA);
	Action actionACAPA("Credit Agricole S.A.", 13.08, 0.2284);
	cac40.push_back(actionACAPA);
	Action actionDGPA("VINCI SA", 85.15, 0.1661);
	cac40.push_back(actionDGPA);
	Action actionCAPA("Carrefour SA", 18.04, 0.2344);
	cac40.push_back(actionCAPA);
	Action actionBNPPA("BNP Paribas SA", 62.25, 0.2201);
	cac40.push_back(actionBNPPA);
	Action actionLHNPA("LafargeHolcim Ltd", 47.04, 0.1977);
	cac40.push_back(actionLHNPA);
	Action actionLRPA("Legrand SA", 64.19, 0.1367);
	cac40.push_back(actionLRPA);
	Action actionVIVPA("Vivendi SA", 22.42, 0.2164);
	cac40.push_back(actionVIVPA);
	Action actionBNPA("Danone", 69.95, 0.1438);
	cac40.push_back(actionBNPA);
	Action actionSUPA("Schneider Electric SE", 70.86, 0.1792);
	cac40.push_back(actionSUPA);
	Action actionENPA("Bouygues SA", 43.31, 0.1856);
	cac40.push_back(actionENPA);
	Action actionAIPA("Air Liquide", 105.05, 0.1729);
	cac40.push_back(actionAIPA);
	Action actionSGOPA("Compagnie de Saint-Gobain", 45.98, 0.1684);
	cac40.push_back(actionSGOPA);
	Action actionAIRPA("Airbus SE", 83.00, 0.2004);
	cac40.push_back(actionAIRPA);
	Action actionSANPA("Sanofi", 28.82, 0.0719);
	cac40.push_back(actionSANPA);
	Action actionUGPA("Peugeot SA", 16.95, 0.2216);
	cac40.push_back(actionUGPA);
	Action actionFRPA("Valeo SA", 62.27, 0.2041);
	cac40.push_back(actionFRPA);
	Action actionCSPA("Axa SA", 24.74, 0.1683);
	cac40.push_back(actionCSPA);
	Action actionRIPA("Pernod Ricard", 131.95, 0.1293);
	cac40.push_back(actionRIPA);
	Action actionSTM("STMicroelectronics", 21.9, 0.3303);
	cac40.push_back(actionSTM);
	Action actionFTIPA("TechnipFMC", 25.85, 0.2909);
	cac40.push_back(actionFTIPA);
	Action actionMT("ArcelorMittal", 32.31, 0.3462);
	cac40.push_back(actionMT);
	Action actionPUBPA("Publicis Groupe", 56.65, 0.1870);
	cac40.push_back(actionPUBPA);
	Action actionSOLF("Solvay SA", 116.40, 0.1672);
	cac40.push_back(actionSOLF);
	Action actionUBLF("Unibail-Rodamco SE", 212.22, 0.1370);
	cac40.push_back(actionUBLF);
	Action actionRNOPA("Renault SA", 83.91, 0.2007);
	cac40.push_back(actionRNOPA);
	Action actionSAFPA("Safran SA", 85.91, 0.1661);
	cac40.push_back(actionSAFPA);
	std::cout << "Que souhaitez-vous faire ?" << std::endl;
	int num_choix;
	int fin=0;
	while (fin == 0) {
		std::cout << "0 - Afficher la liste des actions du CAC40 et leurs caract\x82ristiques" << std::endl;
		std::cout << "1 - D\x82terminer le prix d'une option" << std::endl;
		std::cout << "2 - D\x82terminer le prix d'une strat\x82gie" << std::endl;
		std::cin >> num_choix;
		if (num_choix == 0) {
			std::cout << std::setw(15) << std::left << "Identifiant" << "| " << std::setw(50) << std::left << "Nom de l'entreprise" << "| " << std::setw(25) << std::left << "Prix actuel de l'action" << "| " << std::setw(8) << "Volatilit\x82 sur les 12 derniers mois" << std::endl;
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
			std::cout << "Voulez-vous \x82valuer le prix d'une option d'une action du CAC40 ou rentrer vous-m\x88mes les diff\x82rentes caract\x82ristiques ?" << std::endl;
			std::cout << "1 - Une action du CAC40" << std::endl;
			std::cout << "2 - Rentrer les caract\x82ristiques \x85 la main" << std::endl;
			std::cin >> mode;
			int num_opt;
			std::cout << "Quel est le type de l'option ?" << std::endl;
			std::cout << "1 - Option Vanille (European)" << std::endl;
			std::cout << "2 - Option Lookback" << std::endl;
			std::cout << "3 - Option Asiatique" << std::endl;
			std::cout << "4 - Option Chooser" << std::endl;
			std::cout << "5 - Option Barri\x8Are" << std::endl;
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_European optEUR(strike, maturite, actionTEST);
					optEUR.setPrice(20000);
					optEUR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Lookback optLOOK(strike, maturite, actionTEST);
					optLOOK.setPrice(20000);
					optLOOK.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Asian optASIA(strike, maturite, actionTEST);
					optASIA.setPrice(20000);
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Chooser optCHO(strike, maturite, date, actionTEST);
					optCHO.setPrice(20000);
					optCHO.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Barrier optBARR(barrier, strike, maturite, actionTEST);
					optBARR.setPrice(20000);
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Binaire optBIN(gain_fixe, strike, maturite, actionTEST);
					optBIN.setPrice(20000);
					optBIN.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 7) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la p\x82riode minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Parisian optPARI(barrier, periode, strike, maturite, actionTEST);
					optPARI.setPrice(20000);
					optPARI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 8) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la p\x82riode minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_Parasian optPARA(barrier, periode, strike, maturite, actionTEST);
					optPARA.setPrice(20000);
					optPARA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 9) {
					std::cout << "Quelle est la date de d" << "\x82" << "but ? " << std::endl;
					float begin;
					std::cin >> begin;
					std::cout << "Quel est le coefficient multiplicateur ? " << std::endl;
					float coef;
					std::cin >> coef;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ?" << std::endl;
					int identifiant;
					std::cin >> identifiant;
					Action actionTEST = cac40[identifiant];
					Option_ForwardStart optFOR(begin, coef, maturite, actionTEST);
					optFOR.setPrice(20000);
					optFOR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 10) {
					std::cout << "Quel est le nombre total d'actifs ? " << std::endl;
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					Option_Rainbow optRAI(strike, maturite, vecteur_action);
					optRAI.setPrice(1000);
					optRAI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 11) {
					std::cout << "Quel est le nombre total d'actifs ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<Action> vecteur_action;
					std::vector<float> poids;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est l'identifiant de l'actif " << i + 1 << " ? " << std::endl;
						int id;
						std::cin >> id;
						vecteur_action.push_back(cac40[id]);
						std::cout << "Quel est le poids accord\x82 au sous-jacent " << i + 1 << " ? " << std::endl;
						float w;
						std::cin >> w;
						poids.push_back(w);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR(strike, maturite, actionTEST);
					optEUR.setPrice(20000);
					optEUR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Lookback optLOOK(strike, maturite, actionTEST);
					optLOOK.setPrice(20000);
					optLOOK.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Asian optASIA(strike, maturite, actionTEST);
					optASIA.setPrice(20000);
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Chooser optCHO(strike, maturite, date, actionTEST);
					optCHO.setPrice(20000);
					optCHO.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Barrier optBARR(barrier, strike, maturite, actionTEST);
					optBARR.setPrice(20000);
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
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Binaire optBIN(gain_fixe, strike, maturite, actionTEST);
					optBIN.setPrice(20000);
					optBIN.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 7) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la p\x82riode minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Parisian optPARI(barrier, periode, strike, maturite, actionTEST);
					optPARI.setPrice(20000);
					optPARI.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 8) {
					std::cout << "Quelle est la valeur de la barri\x8Are d'activation ?" << std::endl;
					float barrier;
					std::cin >> barrier;
					std::cout << "Quelle est la p\x82riode minimale d'activation ?" << std::endl;
					float periode;
					std::cin >> periode;
					std::cout << "Quel est le strike ?" << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_Parasian optPARA(barrier, periode, strike, maturite, actionTEST);
					optPARA.setPrice(20000);
					optPARA.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 9) {
					std::cout << "Quelle est la date de d" << "\x82" << "but ? " << std::endl;
					float begin;
					std::cin >> begin;
					std::cout << "Quel est le coefficient multiplicateur ? " << std::endl;
					float coef;
					std::cin >> coef;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 du sous-jacent?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel du sous-jacent?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_ForwardStart optFOR(begin, coef, maturite, actionTEST);
					optFOR.setPrice(20000);
					optFOR.afficher();
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 10) {
					std::cout << "Quel est le nombre total d'actifs ? " << std::endl;
					float nb_sous_jacents;
					std::cin >> nb_sous_jacents;
					std::vector<float> prix_ini;
					std::vector<float> volatilite;
					for (int i = 0; i < nb_sous_jacents; i++) {
						std::cout << "Quel est le prix initial du sous-jacent " << i + 1 << " ? " << std::endl;
						float p;
						std::cin >> p;
						prix_ini.push_back(p);
						std::cout << "Quelle est la volatilit\x82 du sous-jacent " << i + 1 << " ? " << std::endl;
						float v;
						std::cin >> v;
						volatilite.push_back(v);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Quel est le nombre total d'actifs ? " << std::endl;
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
						std::cout << "Quelle est la volatilit\x82 du sous-jacent " << i + 1 << " ? " << std::endl;
						float v;
						std::cin >> v;
						volatilite.push_back(v);
						std::cout << "Quel est le poids accord\x82 au sous-jacent " << i + 1 << " ? " << std::endl;
						float w;
						std::cin >> w;
						poids.push_back(w);
					}
					std::cout << "Quel est le strike ? " << std::endl;
					float strike;
					std::cin >> strike;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
			std::cout << "Voulez-vous \x82valuer le prix d'une strat\x82gie d'une action du CAC40 ou rentrer vous-m\x88mes les diff\x82rentes caract\x82ristiques ?" << std::endl;
			std::cout << "1 - Une action du CAC40" << std::endl;
			std::cout << "2 - Rentrer les caract\x82ristiques \x85 la main" << std::endl;
			std::cin >> mode;
			int num_opt;
			std::cout << "Quel est le type de la strat\x82gie ?" << std::endl;
			std::cout << "1 - Call Spread" << std::endl;
			std::cout << "2 - Put Spread" << std::endl;
			std::cout << "3 - Butterfly" << std::endl;
			std::cout << "4 - Condor" << std::endl;
			std::cout << "5 - Straddle" << std::endl;
			std::cout << "6 - Strangle" << std::endl;
			std::cin >> num_opt;
			if (mode == 1) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike du call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du call vendu ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Call Spread" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du call achet\x82: " << K1 << std::endl;
					std::cout << "Strike du call vendu: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_call_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike du put vendu ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put achet\x82 ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Put Spread" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du put vendu: " << K1 << std::endl;
					std::cout << "Strike du put achet\x82: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_put_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le strike des deux calls vendus ?" << std::endl;
					float X;
					std::cin >> X;
					std::cout << "Quel est la diff\x82rence entre le strike du call vendu et du call achet\x82 ?" << std::endl;
					float a;
					std::cin >> a;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Butterfly" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike de vente: " << X << std::endl;
					std::cout << "Diff\x82rence entre les strikes de vente et d'achat: " << a << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_butterfly << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike du premier call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quelle est la diff\x82rence entre les strikes des achats et des ventes ?" << std::endl;
					float epsilon;
					std::cin >> epsilon;
					std::cout << "Quel est le strike du dernier call vendu ?" << std::endl;
					float K3;
					std::cin >> K3;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Condor" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strikes d'achat: " << K1 << " et " << K4 << std::endl;
					std::cout << "Strikes de vente: " << K2 << " et " << K3 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_condor << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quel est le strike du call et du put achet\x82s ?" << std::endl;
					float K;
					std::cin >> K;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quel est l'identifiant de l'actif ? " << std::endl;
					int id;
					std::cin >> id;
					Action actionTEST = cac40[id]; 
					Option_European optEUR(K, maturite, actionTEST);
					optEUR.setPrice(10000);
					float prix_straddle = optEUR.getPrice_call() + optEUR.getPrice_put();
					std::cout << "Type de strat\x82gie: Straddle" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strikes d'achat du call et du put: " << K << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_straddle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quel est le strike du call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put achet\x82 ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Strangle" << std::endl;
					std::cout << "Nom de l'actif: " << cac40[id].getName() << std::endl;
					std::cout << "Volatilit\x82: " << cac40[id].getVolatilite() << std::endl;
					std::cout << "Prix initial de l'actif: " << cac40[id].getValue() << std::endl;
					std::cout << "Strike du call: " << K1 << std::endl;
					std::cout << "Strike du put: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_strangle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
			if (mode == 2) {
				if (num_opt == 1) {
					std::cout << "Quel est le strike du call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du call vendu ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Call Spread" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du call achet\x82: " << K1 << std::endl;
					std::cout << "Strike du call vendu: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_call_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 2) {
					std::cout << "Quel est le strike du put vendu ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put achet\x82 ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Put Spread" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du put vendu: " << K1 << std::endl;
					std::cout << "Strike du put achet\x82: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_put_spread << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 3) {
					std::cout << "Quel est le Strike des deux calls vendus ?" << std::endl;
					float X;
					std::cin >> X;
					std::cout << "Quel est la diff\x82rence entre le strike du call vendu et du call achet\x82 ?" << std::endl;
					float a;
					std::cin >> a;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Butterfly" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike de vente: " << X << std::endl;
					std::cout << "Diff\x82rence entre les strikes de vente et d'achat: " << a << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_butterfly << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 4) {
					std::cout << "Quel est le strike du premier call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quelle est la diff\x82rence entre les strikes des achats et des ventes ?" << std::endl;
					float epsilon;
					std::cin >> epsilon;
					std::cout << "Quel est le strike du dernier call vendu ?" << std::endl;
					float K3;
					std::cin >> K3;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Condor" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strikes d'achat: " << K1 << " et " << K4 << std::endl;
					std::cout << "Strikes de vente: " << K2 << " et " << K3 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_condor << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 5) {
					std::cout << "Quel est le strike du call et du put achet\x82s ?" << std::endl;
					float K;
					std::cin >> K;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
					float volatilite;
					std::cin >> volatilite;
					std::cout << "Quel est le prix actuel ?" << std::endl;
					float prix_ini;
					std::cin >> prix_ini;
					Action actionTEST("unknown", prix_ini, volatilite);
					Option_European optEUR(K, maturite, actionTEST);
					optEUR.setPrice(10000);
					float prix_straddle = optEUR.getPrice_call() + optEUR.getPrice_put();
					std::cout << "Type de strat\x82gie: Straddle" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR.getAction().getName() << std::endl;
					std::cout << "Strikes d'achat du call et du put: " << K << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_straddle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
				if (num_opt == 6) {
					std::cout << "Quel est le strike du call achet\x82 ?" << std::endl;
					float K1;
					std::cin >> K1;
					std::cout << "Quel est le strike du put achet\x82 ?" << std::endl;
					float K2;
					std::cin >> K2;
					std::cout << "Quelle est la maturit\x82 ?" << std::endl;
					float maturite;
					std::cin >> maturite;
					std::cout << "Quelle est la volatilit\x82 ?" << std::endl;
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
					std::cout << "Type de strat\x82gie: Strangle" << std::endl;
					std::cout << "Nom de l'actif: " << optEUR1.getAction().getName() << std::endl;
					std::cout << "Strike du call: " << K1 << std::endl;
					std::cout << "Strike du put: " << K2 << std::endl;
					std::cout << "Maturit\x82: " << maturite << std::endl;
					std::cout << "Volatilit\x82: " << volatilite << std::endl;
					std::cout << "Prix initial de l'actif: " << prix_ini << std::endl;
					std::cout << "Prix de la strat\x82gie: " << prix_strangle << std::endl;
					std::cout << "Appuyez sur 0 pour revenir au menu initial" << std::endl;
					std::cin >> fin;
				}
			}
		}
	}
}