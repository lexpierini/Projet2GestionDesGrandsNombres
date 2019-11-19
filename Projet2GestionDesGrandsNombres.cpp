#include <iostream>
#include <iomanip>
#include <string>
#include <termios.h> //Nécessaire pour réécrire la fonction getch() pour l'utiliser sur Mac/Linux.

using namespace std;
typedef string GNOMBRE;


//Variables Globales.
GNOMBRE n1;
GNOMBRE n2;
GNOMBRE resultat;


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
void menuGeneral();
void menuAddition2Nombres();
void addition2Nombres();
void menuSoustraction2Nombres();
void soustraction2Nombres();
void menuMultiplication2Nombres();
void menuDivision2Nombres();
void menuMinimum2Nombre();
void menuProgramme1();
int menuQuitter();

GNOMBRE saisirGN();


int main() 
{
	nettoyageEcran(); // Nécessaire pour utiliser la fonction "system(clear)" Win/Linux/Mac.
	system(clear);

	addition2Nombres();
	
	//menuGeneral();
	cout << endl << endl;
	return 0;
}


//LISTE DES FONCTIONS

GNOMBRE saisirGN()
{
	GNOMBRE n;
	GNOMBRE nPropre;
	bool zeroGauche = true;
	bool estNegatif = false;
	//cout << "Donnez 1 Grand Nombre: ";
	getline(cin, n);

	for (int i = 0; i < n.size(); i++)
	{
		if ((n[i] == '0' || n[i] == '-')  && zeroGauche || isalpha(n[i]) )
		{
			if (n[i] == '-')
			{
				estNegatif = true;
			}

			continue;
		} 
		else
		{
			zeroGauche = false;
			nPropre = nPropre + n[i];
		}	
	}

	if (estNegatif == true)
	{
		nPropre = '-' + nPropre;
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
		cout << "  Q) menuQuitter le logiciel" << endl;
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
				menuProgramme1();
				break;
			case '7':
				menuProgramme1();
				break;
			case '8':
				menuProgramme1();
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

	system(clear);
	cout << "PROJET 2 - GESTION DES GRANDS NOMBRES" << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "1) Addition de 2 nombres" << endl;
	cout << "   Donner le Nombre 1: ";
	n1 = saisirGN();
	cout << "   Donner le Nombre 2: ";
	n2 = saisirGN();
	cout << "   Resultat " << setfill('.') << setw(11) << (": ");

	cout << endl;
	cout << setfill('-') << setw(51) << ("-") << endl;
	cout << "Appuyez sur une touche pour revenir au menu g\x82n\x82ral\n";
	_getch();
}

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

void addition2Nombres()
{
	n1 = "9999";
	n2 = "111";
	resultat = "";
	int temp;
	bool reste = false;
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
		if (n1EstPlusGrand = true)
		{
			if (n2[n2.size() -1 - i] == '\0')
			{
				n2 = '0' + n2;
			}

			temp = (n1[n1.size() - 1 - i] - 48) + (n2[n2.size() - 1 - i] - 48) + reste;
		} 
		else
		{
			if (n1[n1.size() -1 - i] == '\0')
			{
				n1 = '0' + n1;
			}

			temp = (n2[n2.size() - 1 - i] - 48) + (n1[n1.size() - 1 - i] - 48) + reste;
		}
				
		if (temp > 9) {
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

	if (reste = true)
	{
		resultat = "1" + resultat; 
	}
	
	cout << resultat;
}

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
		if (n1EstPlusGrand = true)
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