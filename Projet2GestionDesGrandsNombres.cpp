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

GNOMBRE somme(GNOMBRE, GNOMBRE);


bool estInferieur(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est inférieure à la seconde.
bool estSuperieur(GNOMBRE, GNOMBRE); //Compare deux valeurs en renvoyant la valeur true si la première valeur est supérieure à la seconde.
bool estSEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est égale à la seconde.
bool estInferieurOuEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est égale ou inférieure à la seconde.
bool estSuperieurOuEgal(GNOMBRE, GNOMBRE); //Compare deux valeurs en retournant true si la première valeur est supérieure ou égale à la seconde.
GNOMBRE saisirGn(); //Capture uniquement des nombres ou le signe '-' à stocker dans une variable.
GNOMBRE afficherGn(GNOMBRE);
bool estNegatif(GNOMBRE); //Vérifie un nombre en retournant vrai si sa valeur est négative.
bool taillePlusGrand(GNOMBRE, GNOMBRE);


void menuGeneral(); //Affiche le menu principal avec des options à choisir.
void menuAddition2Nombres();
void menuSoustraction2Nombres();
void soustraction2Nombres();
void menuMultiplication2Nombres();
void menuDivision2Nombres();
void menuMinimum2Nombre();
void menuProgramme1();
int menuQuitter();


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
	int temp, i, j;
	bool reste = false;
	bool n1PlusGrandTaille;

	n1PlusGrandTaille = gn1.size() >= gn2.size();
	
	if (estNegatif(gn1) && estNegatif(gn2))
	{
		gn1[0] = '0';
		gn2[0] = '0';
	}
	
	for (i = 0; i < (n1PlusGrandTaille ? gn1.size():gn2.size()); i++)
	{
		if (n1PlusGrandTaille)
		{
			if (i > gn2[gn2.size() -1 - i])
			{
				temp = (gn1[gn1.size() - 1 - i] - 48) + reste;
			}
			else
			{
				temp = (gn1[gn1.size() - 1 - i] - 48) + (gn2[gn2.size() - 1 - i] - 48) + reste;
			}
		}
		else
		{
			if (i > gn1[gn1.size() -1 - i])
			{
				temp = (gn2[gn2.size() - 1 - i] - 48) + reste;
			}
			else
			{
				temp = (gn1[gn1.size() - 1 - i] - 48) + (gn2[gn2.size() - 1 - i] - 48) + reste;
			}
		}
				
		if (temp > 9) 
		{
			temp = temp - 10;
			resultat = to_string(temp) + resultat;
			reste = true;
			temp = 0;
		} 
		else
		{
			resultat = to_string(temp) + resultat;
			reste = false;
			temp = 0;
		}
	}

	if (reste == true)
	{
		resultat = "1" + resultat; 
	}

	if (resultat[0] == '0')
	{
		resultat[0] == '-';
	} 
	else if (gn1[0] == '0' && gn2[0] == '0')
	{
		resultat = "-" + resultat; 
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
	bool zeroGauche = true;
	bool signeMoins = false;
	cout << "   Donnez un Grand Nombre: ";
	
	while (c != '\n')
	{
		c = _getch();

		if (isdigit(c) || c == '-')
		{
			if (c == '-' && !signeMoins) 
			{
				signeMoins = true;
				n = n + c;
				cout << c;
			} 
			else if (c == '0' && zeroGauche == true)
			{
				continue;
			}	
			else if (isdigit(c))
			{
				signeMoins = true;
				zeroGauche = false;
				n = n + c;
				cout << c;
			} 
		}
	}
	return n;
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

/*
bool taillePlusGrand(GNOMBRE gn1, GNOMBRE gn2)
{

}

GNOMBRE afficherGn(GNOMBRE n)
{
	cout << n;
	return n;
}
*/

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
			//	menuSoustraction2Nombres();
				break;
			case '3':
			//	menuMultiplication2Nombres();
				break;
			case '4':
			//	menuDivision2Nombres();
				break;
			case '5':
			//	menuMinimum2Nombre();
				break;
			case '6':
			//	menuProgramme1();
				break;
			case '7':
			//	menuProgramme1();
				break;
			case '8':
			//	menuProgramme1();
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

/*
void menuSoustraction2Nombres()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "2) Soustraction de 2 nombres" << endl;
	cout << "   Donner le Nombre 1: " << endl;
	cout << "   Donner le Nombre 2: " << endl;
	cout << "   Resultat " << setfill('.') << setw(11) << (": ");

	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuMultiplication2Nombres()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "3) Multiplication de 2 nombres" << endl;
	cout << "   Donner le Nombre 1: " << endl;
	cout << "   Donner le Nombre 2: " << endl;

	cout << "   Resultat " << setfill('.') << setw(11) << (": ");

	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuDivision2Nombres()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "4) Division de 2 nombres" << endl;
	cout << "   Donner le Nombre 1: " << endl;
	cout << "   Donner le Nombre 2: " << endl;
	cout << "   Resultat " << setfill('.') << setw(11) << (": ");

	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuMinimum2Nombre()
{
	
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "5) Minimum de 2 nombres" << endl;
	cout << "   Donner le Nombre 1: " << endl;
	cout << "   Donner le Nombre 2: " << endl;
	cout << "   Resultat " << setfill('.') << setw(11) << (": ");

	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

void menuProgramme1()
{
	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(58) << ("-") << endl;
	cout << "Bien vouloir attendre la version d\x27hivers 2020 du logiciel\n";
	cout << setfill('-') << setw(58) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}*/

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


/*
void soustraction2Nombres()
{
	GNOMBRE n1 = "1111";
	GNOMBRE n2 = "999";
	GNOMBRE resultat;
	int temp;
	bool emprunt = false;
	bool n1EstPlusGrand;
	bool n1EstNegatif;
	bool n2EstNegatif;

	if (n1[0] == '-')
	{
		n1[0] = '0';
		n1EstNegatif = true;
	} 
	else
	{
		n1EstNegatif = false;
	}

	if (n2[0] == '-')
	{
		n2[0] = '0';
		n2EstNegatif = true;
	}
	else
	{
		n2EstNegatif = false;
	}
	
	n1EstPlusGrand = n1.size() >= n2.size();

	for (int i = 0; i < (n1EstPlusGrand ? n1.size():n2.size()); i++)
	{
		if (n1EstPlusGrand == true)
		{
			if (n2[n2.size() -1 - i] == '\0')
			{
				n2 = '0' + n2;
			}
		} 
		else
		{
			if (n1[n1.size() -1 - i] == '\0')
			{
				n1 = '0' + n1;
			}
		}

		if ((n1[n1.size() -1 - i]) > (n2[n2.size() -1 - i]))
			{
				temp = (n1[n1.size() - 1 - i] - 48) - (n2[n2.size() - 1 - i] - 48);
			}
			else
			{
				temp = (10 + (n1[n1.size() - 1 - i] - 48)) - (n2[n2.size() - 1 - i] - 48);
				emprunt = true;
			}
	}
	cout << resultat;
}
*/



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