// Supermarket.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Article
{
	char Nom[64];
	float Prix;
};

struct Achat
{
	Article ArticleAchete;
	int Quantite = 0;
};

void ChoixQuantite(int &quantite_, int & NombreArticles);
float AfficherPrixTotalArticle(float Prixarticle_, int Quantite_);
void AfficherPrixTotal(float prixTotal_,int NombreArticles_);
void Choix(int &choix_);
void AfficherBienvenue();
void AfficherMenu(Article *Articles);
int ChoixArticle(float &PrixArticle_, Article* Articles);
Article AjoutArticle(float Prix_, const char Nom_[64]);
int main()
{
    float PrixArticle,PrixTotal = 0;
	int ChoixAjoutArticle,NombreArticles=0;
	Article Articles[4];
	Articles[0] = AjoutArticle(12.56, "Poulet");
	Articles[1] = AjoutArticle(1.85, "Sel");
	Articles[2] = AjoutArticle(29.18, "Encre");
	Articles[3] = AjoutArticle(0.59, "Concombre");
	Achat Achats[256] = { 0 };
	AfficherBienvenue();
	do {
		int ChoixIsOK, quantite;
		

		AfficherMenu(Articles);
		do
		{
			ChoixIsOK = 1;
			printf("\nVotre choix ? ");
			
			ChoixIsOK = ChoixArticle(PrixArticle,Articles);
			
			printf("\n");
		} while (ChoixIsOK == 0);

		printf("\n");

		ChoixQuantite(quantite, NombreArticles);
		int i = 0;
		while(Achats[i].Quantite != 0)
		{
			i++;
		}
		Achat a;
		a.Quantite = quantite;
		Achats[i] = a;
		//Affichage du prix pour la quantite d'article choisi et le prix total actuel
		PrixTotal += AfficherPrixTotalArticle(PrixArticle, quantite);
		AfficherPrixTotal(PrixTotal, NombreArticles);
		
		printf("Voulez-vous acheter un autre article? \n1.oui \n2.Non \n");
		Choix(ChoixAjoutArticle);
	} while (ChoixAjoutArticle == 1);

	AfficherPrixTotal(PrixTotal, NombreArticles);
	int i = 0;
	while (Achats[i].Quantite != 0)
	{
		i++;
	}
	for (size_t a = 0; a < i; a++)
	{
		printf("%d", Achats[a].Quantite);
	}
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

void AfficherMenu(Article* Articles)
{
	printf("\n=== Produits ===\n\n");
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d. %s\n",i + 1, Articles[i].Nom);
	}
	printf("\n");
}

int ChoixArticle(float &PrixArticle_, Article* Articles)
{
	int choixArticle;
	Choix(choixArticle);
	int  ChoixIsOK = 1;
	if ((choixArticle > 0) && (choixArticle < 5))
	{
		PrixArticle_ = Articles[choixArticle - 1].Prix;
		printf("l'article %s vaut %.2f",Articles[choixArticle - 1].Nom, PrixArticle_);
	}
	else
	{
		printf("Cette article n'existe pas");
		ChoixIsOK = 0;
	}
	/*switch (choixArticle)
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
	}*/
	return ChoixIsOK;
}

Article AjoutArticle(float Prix_, const char Nom_[64])
{
	Article a;
	strcpy(a.Nom, Nom_);
	a.Prix = Prix_;
	return a;
}
