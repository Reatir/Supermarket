// Supermarket.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ChoixQuantite();
void AfficherPrixTotal(float Prixarticle_, int Quantite_);
int main()
{
    float PrixArticle;
    printf("Bonjour!\n");
    printf("Bienvenue a ConsoLand!\n");
	int choix;
	printf("\n=== Produits ===\n\n");
	printf("1. Poulet\n");
	printf("2. Sel\n");
	printf("3. Encre\n");
	printf("4. Concombre\n");
	int ChoixIsOK;
	do
	{
		ChoixIsOK = 1;
		printf("\nVotre choix ? ");

		int retour = scanf("%d", &choix);
		if (retour == 0)
		{
			exit(0);
		}

		printf("\n");

		switch (choix)
		{
		case 1:
			PrixArticle = 12.54;
			printf("Le prix d'un poulet est de %.2f", PrixArticle);
			break;
		case 2:
			PrixArticle = 1.59;
			printf("Le prix du sel est de %.2f", PrixArticle);
			break;
		case 3:
			PrixArticle = 16.86;
			printf("Le prix de l'encre est de %.2f", PrixArticle);
			break;
		case 4:
			PrixArticle = 0.65;
			printf("Le prix d'un concombre est de %.2f", PrixArticle);
			break;
		default:
			printf("Cette article n'existe pass");
			ChoixIsOK = 0;
			break;
		}
		printf("\n");
	} while (ChoixIsOK == 0);

	printf("\n");
	int quantite = ChoixQuantite();
	AfficherPrixTotal(PrixArticle, quantite);
	printf("\n\n");

    return 0;
}


int ChoixQuantite()
{
	int quantite;
	printf("Veuillez-rentrer le nombre d'article voulu : ");
	int retour = scanf("%d",&quantite);
	if (retour == 0)
	{
		exit(0);
	}
	return quantite;
}

void AfficherPrixTotal(float Prixarticle_, int Quantite_)
{
	float PrixTotal = Prixarticle_ * Quantite_;
	printf("Le prix total est de %.2f", PrixTotal);
}
