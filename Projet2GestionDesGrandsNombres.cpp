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
void menuGeneral();
void menuAddition2Nombres();
void addition2Nombres();
void menuSoustraction2Nombres();
void menuMultiplication2Nombres();
void menuDivision2Nombres();
void menuMinimum2Nombre();
void menuProgramme1();
int menuQuitter();

void saisirGN();


int main() 
{
	nettoyageEcran(); // Nécessaire pour utiliser la fonction "system(clear)" Win/Linux/Mac.
	system(clear);

	saisirGN();

	//addition2Nombres();
	cout << endl << endl;
	return 0;
	
	menuGeneral();
}


//LISTE DES FONCTIONS

void saisirGN()
{
	GNOMBRE n1 = "0";
	GNOMBRE n1Propre;
	bool zeroGauche = true;
	bool estNegatif = false;
	cout << "Donnez 1 Grand Nombre: ";
	getline(cin, n1);

	for (int i = 0; i < n1.size(); i++)
	{
		if (isdigit(n1[i])) {

			if ((n1[i] == '0' || n1[i] == '-')  && zeroGauche)
			{
				if (n1[i] == '-')
				{
					estNegatif = true;
				}
				continue;
			} 
			else
			{
				zeroGauche = false;
				n1Propre = n1Propre + n1[i];
			}
		}
	}

	if (estNegatif == true)
	{
		n1Propre = '-' + n1Propre;
	}
	 
	cout << n1Propre;
	cout << endl << endl;

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
	cout << "   Donner le Nombre 1: " << endl;
	cout << "   Donner le Nombre 2: " << endl;
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
	GNOMBRE n1 = "9999";
	GNOMBRE n2 = "111";
	GNOMBRE resultat = "";
	GNOMBRE tailPlusGrand = "";
	GNOMBRE tailPlusPetit = "";
	int temp;
	
	/*bool reste = false;
	bool estPlusGrand = n1.size() > n2.size();
	estPlusGrand = n1.size() > n2.size();*/
	
	/*if (n1.size() > n2.size())
	{
		tailPlusGrand = n1;
	} else
	{
		tailPlusPetit = n2;
	}

	for (int i = 0; i < tailPlusGrand.size(); i++)
	{
		temp = (tailPlusGrand[tailPlusGrand.size() - 1 - i] - 48) + (tailPlusPetit[tailPlusPetit.size() - 1 - i])
	}
	
	
	for (int i = 0; i < (estPlusGrand ? n1.size():n2.size()); i++)
	{
	
		temp = (n1[n1.size() - 1 - i] - 48) + (n2[n2.size() - 1 - i] - 48) + reste;
		
		if (temp > 9)
		{
			temp = temp - 10;
			resultat = to_string(temp) + resultat;
			reste = true;
			temp = 0;
		} else
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
	
	
	
	
	/*for (int i = 0 ; i < (estPlusGrand ? n1.size():n2.size()); i++){
		if ((n2.size() - 1 - i) > 0) {
			return;
		}

		temp = ((char)(n1[n1.size() - 1 - i]) - '0') + ((char)(n2[n2.size() - 1 - i]) - '0');
		cout << temp << endl;
		if (temp > 10)
		{
			
		}
	}*/
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