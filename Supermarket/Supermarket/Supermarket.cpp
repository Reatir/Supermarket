// Supermarket.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ChoixQuantite();
float AfficherPrixTotal(float Prixarticle_, int Quantite_);
int main()
{
    float PrixArticle,PrixTotal = 0;
    printf("Bonjour!\n");
    printf("Bienvenue a ConsoLand!\n");
	int ChoixAjoutArticle;
	do {
		printf("\n=== Produits ===\n\n");
		printf("1. Poulet\n");
		printf("2. Sel\n");
		printf("3. Encre\n");
		printf("4. Concombre\n");
		int ChoixIsOK;
		int choixArticle;
		do
		{
			ChoixIsOK = 1;
			printf("\nVotre choix ? ");
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			int retour = scanf("%d", &choixArticle);
			if (retour == 0)
			{
				printf("La valeur entre n'est pas bonne veuillez ressayer");
		
			}

			printf("\n");

			switch (choixArticle)
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
		PrixTotal += AfficherPrixTotal(PrixArticle, quantite);
		printf("\nLe prix total actuel est de %.2f",PrixTotal);
		printf("\n\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Voulez-vous acheter un autre article? \n1.oui \n2.Non ");
		scanf("%d", &ChoixAjoutArticle);
	} while (ChoixAjoutArticle == 1);

	printf("Le montant total est de %.2f", PrixTotal);
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
float AfficherPrixTotal(float Prixarticle_, int Quantite_)
{
	float PrixTotal = Prixarticle_ * Quantite_;
	printf("Le prix total est de %.2f", PrixTotal);
	return PrixTotal;
}
