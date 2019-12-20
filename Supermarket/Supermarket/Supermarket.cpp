// Supermarket.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ChoixQuantite(int &quantite_, int & NombreArticles);
float AfficherPrixTotalArticle(float Prixarticle_, int Quantite_);
void AfficherPrixTotal(float prixTotal_,int NombreArticles_);
void Choix(int &choix_);
void AfficherBienvenue();
void AfficherMenu();
int ChoixArticle(float &PrixArticle_);
int main()
{
    float PrixArticle,PrixTotal = 0;
	int ChoixAjoutArticle,NombreArticles=0;

	AfficherBienvenue();
	do {
		int ChoixIsOK, quantite;
		

		AfficherMenu();
		do
		{
			ChoixIsOK = 1;
			printf("\nVotre choix ? ");
			
			ChoixIsOK = ChoixArticle(PrixArticle);
			
			printf("\n");
		} while (ChoixIsOK == 0);

		printf("\n");

		ChoixQuantite(quantite, NombreArticles);
		
		//Affichage du prix pour la quantite d'article choisi et le prix total actuel
		PrixTotal += AfficherPrixTotalArticle(PrixArticle, quantite);
		AfficherPrixTotal(PrixTotal, NombreArticles);
		
		printf("Voulez-vous acheter un autre article? \n1.oui \n2.Non \n");
		Choix(ChoixAjoutArticle);
	} while (ChoixAjoutArticle == 1);

	AfficherPrixTotal(PrixTotal, NombreArticles);
    return 0;
}


void ChoixQuantite(int &quantite_,int &NombreArticles)
{
	printf("Veuillez-rentrer le nombre d'article voulu : ");
	Choix(quantite_);
	NombreArticles += quantite_;
}

float AfficherPrixTotalArticle(float Prixarticle_, int Quantite_)
{
	float PrixTotal = Prixarticle_ * Quantite_;
	printf("Le prix total est de %.2f pour %d", PrixTotal, Quantite_);
	return PrixTotal;
}

void AfficherPrixTotal(float prixTotal_,int NombreArticles_)
{
	printf("\nLe prix total est de %.2f pour %d articles", prixTotal_,NombreArticles_);
	printf("\n\n");
}

void Choix(int &choix_)
{
	int c;
	int retour;
	do
	{
		retour = scanf("%d", &choix_);
		while ((c = getchar()) != '\n' && c != EOF) {}
		if (retour == 1)
		{
			continue;
		}
		printf("La valeur entre n'est pas bonne veuillez ressayer\n");
	} while (retour == 0);
	printf("\n");

}

void AfficherBienvenue()
{
	printf("Bonjour!\n");
	printf("Bienvenue a ConsoLand!\n");
}

void AfficherMenu()
{
	printf("\n=== Produits ===\n\n");
	printf("1. Poulet\n");
	printf("2. Sel\n");
	printf("3. Encre\n");
	printf("4. Concombre\n");
}

int ChoixArticle(float &PrixArticle_)
{
	int choixArticle;
	Choix(choixArticle);
	int  ChoixIsOK = 1;
	switch (choixArticle)
	{
	case 1:
		PrixArticle_ = 12.54;
		printf("Le prix d'un poulet est de %.2f", PrixArticle_);
		break;
	case 2:
		PrixArticle_ = 1.59;
		printf("Le prix du sel est de %.2f", PrixArticle_);
		break;
	case 3:
		PrixArticle_ = 16.86;
		printf("Le prix de l'encre est de %.2f", PrixArticle_);
		break;
	case 4:
		PrixArticle_ = 0.65;
		printf("Le prix d'un concombre est de %.2f", PrixArticle_);
		break;
	default:
		printf("Cette article n'existe pass");
		ChoixIsOK = 0;
		break;
	}
	return ChoixIsOK;
}
