#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
	// si les paramètres entrés ne correspondent pas au type demandé,
	//le programme plante.Rajouter des conditions pour vérifier si les paramètres sont bien des nombres et 
	//si les paramètres 3, 4 et 5 sont bien des chaines de caractères non nulles.
	if (isdigit(*argv[1])==false || isdigit(*argv[1]) == false)
	{
		return -1;
	}
	if (argv[3] == nullptr || argv[4] == nullptr || argv[5] == nullptr) {
		return -6;
	}
	int pansDeCloture{ stoi(argv[1]) };
	float montantAPayer{ stof(argv[2]) };

	// si pansDeCloture =0 le programme plante.
	// si montantAPayer <=0 le programme fait des erreurs.
	//rajouter des conditions pour eviter ces erreurs.
	if (pansDeCloture == 0 || montantAPayer <= 0)
	{
		return -2;
	}
	float coutParPan{ montantAPayer / pansDeCloture };

	// Poteaux n�cessaires pour faire une cl�ture en ligne droite
	int poteaux{ pansDeCloture };
	montantAPayer += poteaux * 5;

	// taille limiter du nom du fichier
	//rempalcer par string et adapter le code
	//char nomFichier[10];
	//strcpy(nomFichier, argv[3]);
	//strcat(nomFichier, ".exe");
	string nomFichier;
	nomFichier = argv[3];
	nomFichier += ".exe"g;
	ofstream fichier{ nomFichier };
	fichier << argv[4];

	const char* msg{ argv[4] };
	printf(msg, pansDeCloture, coutParPan);

	// si la commande en entrée n'existe pas le programme ne fonctionne pas
	//solution il est mieux de supprimer cette partie du code car elle donne une ouverture sur le system
	//const char* commande{ argv[5] };
	//system(commande);
}