#include <iostream>
#include <iomanip>
#include <string>
#include <termios.h> //Nécessaire pour réécrire la fonction getch() pour l'utiliser sur Mac/Linux.

using namespace std;
typedef string GNOMBRE;


// Nécessaire pour utiliser la fonction "system(clear)" Win/Linux/Mac.
void nettoyageEcran();
const char* clear; 


// Nécessaires pour réécrire la fonction getch() pour l'utiliser sur Mac/Linux.
void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char _getch(void);
char _getche(void);
struct termios old, current;


// DÉCLARATION DES FONCTIONS

GNOMBRE somme(GNOMBRE, GNOMBRE); //Faire la somme de 2 GNOMBRES.
GNOMBRE difference(GNOMBRE, GNOMBRE); //Faire la soustraction de 2 GNOMBRES.
GNOMBRE produit(GNOMBRE, GNOMBRE); //Faire la multiplication de 2 GNOMBRES.
GNOMBRE div(GNOMBRE, GNOMBRE); //Faire la division de 2 GNOMBRES.
GNOMBRE minimum2Nombre(GNOMBRE, GNOMBRE); //Affiche  le  plus  petit  des  2 GNOMBRES.
bool estInferieur(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est inférieure à la seconde.
bool estSuperieur(GNOMBRE, GNOMBRE); //Compare deux valeurs en renvoyant la valeur true si la première valeur est supérieure à la seconde.
bool estSEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est égale à la seconde.
bool estInferieurOuEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est égale ou inférieure à la seconde.
bool estSuperieurOuEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est supérieure ou égale à la seconde.
GNOMBRE saisirGn(); //Capture uniquement des nombres ou le signe '-' à stocker dans une variable.
GNOMBRE afficherGn(GNOMBRE);
void programme1(); //Demande à l’utilisateur de donner 10 nombres et affiche leur somme, leur produit et leur moyenne à l’écran. Menu inclus.


bool estNegatif(GNOMBRE); //Vérifie un nombre en retournant vrai si sa valeur est négative.
GNOMBRE nombreSansOperateur(GNOMBRE); // Returne le nombre sens le signal '-'.
GNOMBRE equivalenceChiffre(GNOMBRE, GNOMBRE); //Prenez deux nombres, en considérant que n1 est supérieur à n2 et renvoyez n2 avec le même nombre de chiffres, ces chiffres étant '0'.
GNOMBRE nombreSansZeroGauche(GNOMBRE); // Supprime les zéros non significatifs jusqu'à ce qu'une valeur > '0' soit trouvée.


void menuGeneral(); //Affiche le menu principal avec des options à choisir.
void menuAddition2Nombres(); //Affiche le menu addition pour faire la somme de 2 GNOMBRES.
void menuSoustraction2Nombres(); //Affiche le menu soustration pour faire la soustration de 2 GNOMBRES.
void menuMultiplication2Nombres(); //Affiche le menu multiplication pour faire la multiplication de 2 GNOMBRES.
void menuDivision2Nombres(); //Affiche le menu division pour faire la division de 2 GNOMBRES.
void menuMinimum2Nombre(); //Affiche le menu minimum de 2 nombre pour affiche  le  plus  petit  des  2 GNOMBRES.
void menuProgrammePasPret(); //Affiche une message pour les programmes que ne sont pas prêt.
int menuQuitter(); //Affiche le menu de sortir.


int main() 
{
	nettoyageEcran(); //Nécessaire pour utiliser la fonction "system(clear)" Win/Linux/Mac.
	system(clear);

	menuGeneral();

	cout << endl << endl;
	return 0;
}


//LISTE DES FONCTIONS
GNOMBRE somme(GNOMBRE gn1, GNOMBRE gn2)
{
	GNOMBRE resultat;
	int temp, reste = 0;
	bool gn1Negatif = false, gn2Negatif = false, resultatNegatif = false;

	if (estNegatif(gn1) && !estNegatif(gn2))
	{
		gn1Negatif = true;
		gn1 = nombreSansOperateur(gn1);
		resultat = resultat + difference(gn1, gn2);
		estSuperieur(gn1, gn2) ? resultat = '-' + resultat : resultat = nombreSansOperateur(resultat);

		if (resultat == "" || resultat == "-")
		{
			resultat = "0";
		}
		return resultat;
	}
	else if (estNegatif(gn1) && estNegatif(gn2))
	{
		gn1Negatif = true;
		gn1 = nombreSansOperateur(gn1);
		gn2Negatif = true;
		gn2 = nombreSansOperateur(gn2);
		resultatNegatif = true;
	}
	else if (!estNegatif(gn1) && estNegatif(gn2))
	{
		gn2Negatif = true;
		gn2 = nombreSansOperateur(gn2);
		resultat = resultat + difference(gn1, gn2);
		return resultat;
	}

	if (gn1.size() > gn2.size())
	{
		gn2 = equivalenceChiffre(gn1, gn2);
	}
	else if (gn1.size() < gn2.size())
	{
		gn1 = equivalenceChiffre(gn2, gn1);
	}

	for (int i = 0; i < gn1.size(); i++)
	{
		temp = (gn1[gn1.size() -1 -i] - 48) + (gn2[gn2.size() -1 -i] -48) + reste;

		if (temp > 9)
		{
			temp = temp -10;
			reste = 1;
		}
		else
		{
			reste = 0;
		}

		resultat = to_string(temp) + resultat;
	}

	if (reste)
	{
		resultat = "1" + resultat;
	}

	resultat = nombreSansZeroGauche(resultat);

	if (resultat == "" || resultat == "-")
	{
		resultat = "0";
	}

	if ((resultatNegatif && resultat[0] != '-') && resultat != "0")
	{
		resultat = "-" + resultat;
	}

	return resultat;
}

GNOMBRE difference(GNOMBRE gn1, GNOMBRE gn2)
{
	GNOMBRE temp2, resultat;
	int temp;
	bool gn1Negatif = false, gn2Negatif = false, resultatNegatif = false;

	if (estNegatif(gn1) && !estNegatif(gn2))
	{
		gn1Negatif = true;
		gn1 = nombreSansOperateur(gn1);
		resultat = "-" + somme(gn1, gn2);
		if (resultat == "" || resultat == "-")
		{
			resultat = "0";
		}
		return resultat;
	}
	else if (estNegatif(gn1) && estNegatif(gn2))
	{
		gn1Negatif = true;
		nombreSansOperateur(gn1);
		gn2Negatif = true;
		nombreSansOperateur(gn2);
	}
	else if (!estNegatif(gn1) && estNegatif(gn2))
	{
		gn2Negatif = true;
		gn2 = nombreSansOperateur(gn2);
		resultat = somme(gn1, gn2);
		if (resultat == "" || resultat == "-")
		{
			resultat = "0";
		}
		return resultat;
	}

	if (gn1.size() > gn2.size())
	{
		gn2 = equivalenceChiffre(gn1, gn2);
	}
	else
	{
		gn1 = equivalenceChiffre(gn2, gn1);
	}

	if (estInferieurOuEgal(gn1, gn2))
	{
		temp2 = gn1;
		gn1 = gn2;
		gn2 = temp2;
		resultatNegatif = true;
	}

	for (int i = 0; i < gn1.size(); i++)
	{
		temp = 0;

		if ((gn1[gn1.size() -1 -i] - 48) < (gn2[gn2.size() -1 -i] -48))
		{
			temp = 10;
			gn1[gn1.size() -2 -i] = gn1[gn1.size() -2 -i] - 1;
		}

		temp = temp + (gn1[gn1.size() -1 -i] - 48) - (gn2[gn2.size() -1 -i] -48);
		resultat = to_string(temp) + resultat;
	}

	resultat = nombreSansZeroGauche(resultat);

	if (resultat == "" || resultat == "-")
	{
		resultat = "0";
	}

	if ((resultatNegatif && resultat[0] != '-') && resultat != "0")
	{
		resultat = "-" + resultat;
	}

	return resultat;
}

GNOMBRE produit(GNOMBRE gn1, GNOMBRE gn2)
{
	int resultatPartiel, n1, n2, n3,n4 = 0, temp;
	GNOMBRE ligne1 = "", zero = "00", echange, resultat, temp1, temp2;
	int z = 0, y = 0;
	bool gn1Negatif = false, gn2Negatif = false;

	if (estNegatif(gn1)) 
	{
		gn1Negatif = true;
		gn1 = nombreSansOperateur(gn1);
	}

	if (estNegatif(gn2)) 
	{
		gn2Negatif = true;
		gn2 = nombreSansOperateur(gn2);
	}

	if (gn1.size() > gn2.size())
	{
		echange = gn1;
		gn1 = gn2;
		gn2 = echange;
	}

	for (int p1 = gn2.size() - 1;  p1 >= 0; p1--)
	{
		if (n4 != 0) 
		{
			resultat = std::to_string(n4) + resultat;
		}

		if (p1 == gn2.size() - 3) 
		{
			ligne1 = '0' + ligne1;
			resultat = resultat + '0';
			somme(ligne1, resultat);
		}

		if (p1 == gn2.size() - 4 - y) 
		{
			y++;
			ligne1 = '0' + ligne1;
			z++;
			
			if (z > 1) 
			{
				zero = zero + '0';
			}

			resultat = resultat + zero;
			somme(ligne1, resultat);
		}

		ligne1 = resultat;
		resultat = "";
		n4 = 0;
		
		for (int p2 = gn1.size() - 1; p2 >= 0; p2--)
		{
			temp1 = "";
			temp2 = "";
			temp1 = temp1 + gn1[p2];
			n1 = stoi(temp1);
			temp2 = temp2 + gn2[p1];
			n2 = stoi(temp2);

			if (n2 == 0 || n1 == 0) 
			{
				resultatPartiel = 0 + n4;
			}

			else 
			{
				resultatPartiel = n2 * n1 + n4;
			}

			if (resultatPartiel >= 10) 
			{
				temp1 = std::to_string(resultatPartiel);
				temp = temp1[0];
				n4 = (int)temp - 48;
				resultat = temp1[1] + resultat;
			}

			else 
			{
				n3 = resultatPartiel;
				resultat = std::to_string(n3) + resultat;
				n4 = 0;
			}
		}
	} 
	
	if (gn2.size() == 1) 
	{
		if (n4 != 0) 
		{
			resultat = std::to_string(n4) + resultat;
		}
	}

	if (gn2.size() == 2) 
	{
		if (n4 != 0) 
		{
			resultat = std::to_string(n4) + resultat;
		}
		
		ligne1 = '0' + ligne1;
		resultat = resultat + "0";
		somme(ligne1, resultat);
	}

	if (gn2.size() >=3)
	{
		if (n4 != 0)
		{
			resultat = std::to_string(n4) + resultat;
		}

		ligne1 = '0' + ligne1;

		if (z > 1) 
		{
			zero = zero + '0';
		}

		resultat = resultat + zero;
		somme(ligne1, resultat);
	}

	if ((gn1Negatif == true && gn2Negatif == false) || (gn1Negatif == false && gn2Negatif == true)) 
	{
		resultat = '-' + resultat;
	}

	return resultat;
}

GNOMBRE div(GNOMBRE gn1, GNOMBRE gn2)
{
	int compteur = 0;
    string temp, resultat;
	bool gn1Negatif = false, gn2Negatif = false;

	if (estNegatif(gn1)) 
	{
		gn1Negatif = true;
		gn1 = nombreSansOperateur(gn1);
	}

	if (estNegatif(gn2)) 
	{
		gn2Negatif = true;
		gn2 = nombreSansOperateur(gn2);
	}

	if (gn1 == "0")
	{
		resultat = "0";
		return resultat;
	}

	if (gn2 == "0") 
	{
		resultat = " Erreur! Le diviseur ne peut pas etre 0.";
		return resultat;
	}

	for (int i = 0; i < gn1.size(); i++)
	{
        temp += gn1[i];

        if (estSuperieurOuEgal(temp, gn2))
		{
            while (estSuperieurOuEgal(temp, gn2))
			{
           		temp = difference(temp, gn2);
                compteur += 1;
            }
        }
        resultat += to_string(compteur);
        compteur = 0;
    }
	resultat = nombreSansZeroGauche(resultat);

	if (gn1Negatif != gn2Negatif)
	{
		resultat = "-" + resultat;
	}
    return resultat;
}

GNOMBRE minimum2Nombre(GNOMBRE gn1, GNOMBRE gn2) 
{
	GNOMBRE resultat;

	if (estInferieurOuEgal(gn1, gn2))
	{
		resultat = gn1;
	}
	else
	{
		resultat = gn2;
	}
	return resultat;
}
	
bool estInferieur(GNOMBRE gn1, GNOMBRE gn2)
{
	bool temp;

	if (!estNegatif(gn1) && !estNegatif(gn2))
	{
		if (gn1.size() < gn2.size())
		{
			return true;
		} 
		else if (gn1.size() == gn2.size())
		{
			for (int i = 0; i < gn1.size(); i++)
			{
				if (gn1[i] < gn2[i])
				{
					return true;
				}
                else if (gn1[i] == gn2[i])
                {
                   continue;
                }
				else
				{
					return false;
				}			
			}
			return false;
		}
		else
		{
			return false;
		}
	} 
	else if (estNegatif(gn1) && estNegatif(gn2))
	{
		if (gn1.size() < gn2.size())
		{
			return true;
		} 
		else if (gn1.size() == gn2.size())
		{
			for (int i = 1; i < gn1.size(); i++)
			{
			if (gn1[i] > gn2[i])
				{
					return true;
				}
                else if (gn1[i] == gn2[i])
                {
                   continue;
                }
				else
				{
					return false;
				}			
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else if (!estNegatif(gn1) && estNegatif(gn2))
	{
		return false;
	}
	else if (estNegatif(gn1) && !estNegatif(gn2))
	{
		return true;
	}
}

bool estSuperieur(GNOMBRE gn1, GNOMBRE gn2)
{
	bool temp;

	if (!estNegatif(gn1) && !estNegatif(gn2))
	{
		if (gn1.size() > gn2.size())
		{
			return true;
		} 
		else if (gn1.size() == gn2.size())
		{
			for (int i = 0; i < gn1.size(); i++)
			{
				if (gn1[i] > gn2[i])
				{
					return true;
				}
                else if (gn1[i] == gn2[i])
                {
                   continue;
                }
				else
				{
					return false;
				}			
			}
			return false;
		}
		else
		{
			return false;
		}
	} 
	else if (estNegatif(gn1) && estNegatif(gn2))
	{
		if (gn1.size() > gn2.size())
		{
			return true;
		} 
		else if (gn1.size() == gn2.size())
		{
			for (int i = 1; i < gn1.size(); i++)
			{
			if (gn1[i] < gn2[i])
				{
					return true;
				}
                else if (gn1[i] == gn2[i])
                {
                   continue;
                }
				else
				{
					return false;
				}			
			}
			return false;
		}
		else
		{
			return false;
		}
	}
	else if (!estNegatif(gn1) && estNegatif(gn2))
	{
		return true;
	}
	else if (estNegatif(gn1) && !estNegatif(gn2))
	{
		return false;
	}
}

bool estEgal(GNOMBRE gn1, GNOMBRE gn2)
{
    if (gn1 == gn2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool estInferieurOuEgal(GNOMBRE gn1, GNOMBRE gn2)
{
    if (estInferieur(gn1, gn2) || estEgal(gn1, gn2))
	{
        return true;
    }
    else 
	{
        return false;
    }
}

bool estSuperieurOuEgal(GNOMBRE gn1, GNOMBRE gn2)
{
    if (estSuperieur(gn1, gn2) || estEgal(gn1, gn2))
	{
        return true;
    }
    else
	{
        return false;
    }
}

GNOMBRE saisirGn()
{
	char c;
	GNOMBRE n;
	GNOMBRE nPropre;
	int compteur = 0;
	bool zeroGauche = true, signe = false;
	cout << "   Donnez un Grand Nombre: ";
	
	while (c != '\n')
	{
		c = _getch();

		if (isdigit(c) || c == '-' || c == '+')
		{
			if ((c == '-' || c == '+') && !signe) 
			{
				signe = true;
				n = n + c;
				cout << c;
			} 
			else if (c == '0' && zeroGauche == true)
			{
				continue;
			}	
			else if (isdigit(c))
			{
				signe = true;
				zeroGauche = false;
				n = n + c;
				cout << c;
			} 
		}
	}

	if (n[0] == '+') 
	{
		n = nombreSansOperateur(n);
	}
	return n;
}

GNOMBRE afficherGn(GNOMBRE n)
{
	cout << n;
	return n;
}

void programme1()
{
	GNOMBRE som = "0", prod = "1", moyenne;
	GNOMBRE tGN[10];

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "6) Programme1: Somme Produit Moyenne" << endl;

	for (int i = 0; i < 10; i++)
	{
		tGN[i] = saisirGn();
		cout << endl;
	}
	
    for(int i=0; i < 10; i++)
	{
        som = somme(som,tGN[i]);
        prod = produit(prod,tGN[i]);
    }

	moyenne = div(som, "10");

	cout << endl;
    cout << "   Somme " << setfill('.') << setw(15) << (": ") << som << endl;
    cout << "   Produit " << setfill('.') << setw(13) << (": ") << prod << endl;
    cout << "   Moyenne " << setfill('.') << setw(13) << (": ") << moyenne << endl;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

bool estNegatif(GNOMBRE gn1)
{
	if (gn1[0] == '-')
	{
		return true;
	}
	else
	{
		return false;
	}
}

GNOMBRE nombreSansOperateur(GNOMBRE gn1)
{
	GNOMBRE temp;
	for (int i = 1; i < gn1.size(); i++)
	{
		temp = temp + gn1[i];
	}

	return temp;
}

GNOMBRE equivalenceChiffre(GNOMBRE plusGrandTaille, GNOMBRE moinsGrandTaille)
{
	int j;
	j = plusGrandTaille.size() - moinsGrandTaille.size();
		for (int i = 0; i < j; i++)
		{
			moinsGrandTaille = "0" + moinsGrandTaille;
		}
		return moinsGrandTaille;
}

GNOMBRE nombreSansZeroGauche(GNOMBRE n)
{
	GNOMBRE nPropre;
	bool zeroGauche = true;

	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == '0' && zeroGauche == true)
		{
			continue;
		}
		else
		{
			zeroGauche = false;
			nPropre = nPropre + n[i];
		}
	}
	return nPropre;
}

void menuGeneral()
{
	char choixMenuGeneral;

	do{
		system(clear);
		cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
		cout << setfill('-') << setw(37) << ("-") << endl;
		cout << "MENU GENERAL" << endl;
		cout << "  1) Addition de 2 nombres" << endl;
		cout << "  2) Soustraction de 2 nombres" << endl;
		cout << "  3) Multiplication de 2 nombres" << endl;
		cout << "  4) Division de 2 nombres" << endl;
		cout << "  5) Minimum de 2 nombres" << endl;
		cout << "  6) Programme 1" << endl;
		cout << "  7) Programme 2" << endl;
		cout << "  8) Programme 3" << endl;
		cout << "  Q) Quitter le logiciel" << endl;
		choixMenuGeneral = _getch();

		switch (choixMenuGeneral)
		{
			case '1':
				menuAddition2Nombres();
				break;
			case '2':
				menuSoustraction2Nombres();
				break;
			case '3':
				menuMultiplication2Nombres();
				break;
			case '4':
				menuDivision2Nombres();
				break;
			case '5':
				menuMinimum2Nombre();
				break;
			case '6':
				programme1();
				break;
			case '7':
				menuProgrammePasPret();
				break;
			case '8':
				menuProgrammePasPret();
				break;
			case 'Q':
				menuQuitter();
				break;
			case 'q':
				menuQuitter();
				break;
			default:
				system(clear);
				break;
		}
	}while(choixMenuGeneral != 'Q' && choixMenuGeneral != 'q');
}

void menuAddition2Nombres()
{
	GNOMBRE n1;
	GNOMBRE n2;
	GNOMBRE resultat;

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "1) Addition de 2 nombres" << endl;
	n1 = saisirGn();
	cout << endl;
	n2 = saisirGn();
	cout << endl;
	resultat = somme(n1, n2);
	cout << "   Resultat " << setfill('.') << setw(15) << (": ") << resultat;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuSoustraction2Nombres()
{
	GNOMBRE n1;
	GNOMBRE n2;
	GNOMBRE resultat;

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "2) Soustraction de 2 nombres" << endl;
	n1 = saisirGn();
	cout << endl;
	n2 = saisirGn();
	cout << endl;
	resultat = difference(n1, n2);
	cout << "   Resultat " << setfill('.') << setw(15) << (": ")  << resultat;
	cout << endl;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuMultiplication2Nombres()
{
	GNOMBRE n1;
	GNOMBRE n2;
	GNOMBRE resultat;

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "3) Multiplication de 2 nombres" << endl;
	n1 = saisirGn();
	cout << endl;
	n2 = saisirGn();
	cout << endl;
	resultat = produit(n1, n2);
	cout << "   Resultat " << setfill('.') << setw(15) << (": ")  << resultat;
	cout << endl;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuDivision2Nombres()
{
	GNOMBRE n1;
	GNOMBRE n2;
	GNOMBRE resultat;

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "4) Division de 2 nombres" << endl;
	n1 = saisirGn();
	cout << endl;
	n2 = saisirGn();
	cout << endl;
	resultat = div(n1, n2);
	cout << "   Resultat " << setfill('.') << setw(15) << (": ")  << resultat;
	cout << endl;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuMinimum2Nombre()
{
	GNOMBRE n1;
	GNOMBRE n2;
	GNOMBRE resultat;

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "5) Minimum de 2 nombres" << endl;
	n1 = saisirGn();
	cout << endl;
	n2 = saisirGn();
	cout << endl;
	resultat = minimum2Nombre(n1, n2);
	cout << "   Resultat " << setfill('.') << setw(15) << (": ")  << resultat;
	cout << endl;
	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}


void menuProgrammePasPret()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(58) << ("-") << endl;
	cout << "Bien vouloir attendre la version d\x27hivers 2020 du logiciel\n";
	cout << setfill('-') << setw(58) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

int menuQuitter()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "FIN DU PROGRAMME\n";
	cout << "Merci d'avoir utilise la Gestion des Grands Nombres\n";
	cout << setfill('-') << setw(51) << "-" << endl;
	cout << "Appuyez sur une touche pour finir\n";
	cout << endl << endl << endl;
	_getch();
	return 0;
}


// Fonctions nécessaires pour réécrire la fonction getch() pour l'utiliser sur Mac/Linux.
void initTermios(int echo) //Retirer le buffer.
{
  tcgetattr(0, &old); 
  current = old;
  current.c_lflag &= ~ICANON; 
  if (echo) {
      current.c_lflag |= ECHO; 
  } else {
      current.c_lflag &= ~ECHO; 
  }
  tcsetattr(0, TCSANOW, &current); 
}

void resetTermios(void) //Retourner à la configuration du terminal.
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) //Fonction qui exécute le commande "_getch".
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char _getch(void) //Fonction qui ne montre pas les caractères.
{
  return getch_(0);
}

char _getche(void) //Fonction qui montre les caractères.
{
  return getch_(1);
}

void nettoyageEcran() //Nettoyage d'écran pour Win/Linux/Mac en conjonction avec le pointeur global 'clear'.
{
	#if defined(_WIN32) || defined(__CYGWIN__)
		clear = "cls";
	#else
		clear = "clear";
	#endif
}