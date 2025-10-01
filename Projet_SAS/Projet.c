#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int jour, mois, annee;

} date;

typedef struct
{
    int idClient;
    char nom[20];
    char prenom[20];
    char email[50];
    float solde;

} Clients;

typedef struct
{
    int idProduit;
    int stock;
    char nom[20];
    char categorie[20];
    char description[100];
    float prix;
    date Date;
} Produits;

Clients Client;
Produits Produit[5] = {
    {1, 5, "Ordinateur Portable", "Electronique", "PC portable puissant", 799},
    {2, 10, "Smartphone", "Electronique", "Telephone intelligent", 499},
    {3, 15, "Casque Audio", "Accessoires", "Casque avec micro", 89},
    {4, 20, "Souris", "Accessoires", "Souris optique", 25},
    {5, 12, "Clavier", "Accessoires", "Clavier mecanique", 45}};

int ClientCree = 0;
int choix3 = 0;
int found = 0;
int Calcul = 0;
float MontantDepense = 0;

char RechercheProd[20];
Produits Statistiques[100];

void CreerProfil();
void AfficherProfil();
void ModifyProfile();
void GestionSolde();
void AfficherProduits();
void RechercheProduits();
void AchatProduit();
void MesStatistiques();

int main()
{

    int choix = 0, choix2 = 0;
    ;
    do
    {
        printf("\n\033[0;90m=== SYSTEME D'ACHAT CLIENT ===\033[0m\n");

        printf("(1) Gestion du profil client.\n");
        printf("(2) Gestion du solde virtuel.\n");
        printf("(3) Consultation des produits.\n");
        printf("(4) Effectuer un achat.\n");
        printf("(5) Mes statistiques.\n");
        printf("(6) Quitter l'application.\n");

        printf("\nVeuillez entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:

            do
            {
                printf("\n\033[0;90m=== GESTION DU PROFIL CLIENT ===\033[0m\n");

                printf("\n(1) Creation de profil.\n");
                printf("(2) Consultation de profil.\n");
                printf("(3) Modification de profil.\n");
                printf("(4) Retourn au menu principal.\n");

                printf("\nVeuillez entrer votre choix: ");
                scanf("%d", &choix2);

                switch (choix2)
                {
                case 1:
                    CreerProfil();
                    break;

                case 2:
                    AfficherProfil();
                    break;

                case 3:
                    ModifyProfile();
                    break;
                case 4:
                    printf("\n\033[0;32mAu revoir !\033[0m\n");
                    break;

                default:
                    printf("\033[0;31mChoix invalide\033[0m\n");
                    break;
                }
            } while (choix2 != 4);

            break;

        case 2:
            GestionSolde();
            break;
        case 3:
            do
            {
                printf("\n\033[0;90m=== Consultation Des Produits ===\033[0m\n");

                printf("(1) Afficher Les Produits.\n");
                printf("(2) Recherche d'un produit.\n");
                printf("(3) Retourn au menu principal.\n");

                printf("\nVeuillez entrer votre choix: ");
                scanf("%d", &choix2);

                switch (choix2)
                {
                case 1:
                    AfficherProduits();
                    break;
                case 2:
                    RechercheProduits();
                    break;
                case 3:
                    printf("\n\033[0;32mAu revoir !\033[0m\n");
                    break;

                default:
                    printf("\033[0;31mChoix invalide\033[0m\n");
                    break;
                }
            } while (choix2 != 3);

            break;

        case 4:

            printf("\n\033[0;90m=== Achat d'un Produit ===\033[0m\n");
            AchatProduit();

            break;

        case 5:
            printf("\n\033[0;90m=== Mes Statistiques ===\033[0m\n");
            MesStatistiques();
            break;
        case 6:
            printf("\n\033[0;32mAu revoir !\033[0m\n");
            break;
        default:
            printf("\033[0;31mChoix invalide\033[0m\n");
            break;
        }
    } while (choix != 6);
}

// Création de profil

void CreerProfil()
{
    printf("\n\033[0;90m=== Creation de Profil Client ===\033[0m\n");

    Client.solde = 0;

    printf("\nEntrez votre prenom : ");
    scanf(" %[^\n]", Client.prenom);

    printf("Entrez votre nom : ");
    scanf(" %[^\n]", Client.nom);

    printf("Entrez votre solde (MAD): ");
    scanf("%f", &Client.solde);

    if (Client.solde < 0)
    {
        printf("\n\033[0;32mErreur!!\033[0m\n");
        printf("\nEntrez votre solde (MAD): ");
        scanf("%f", &Client.solde);
    }

    Client.idClient = rand() % 1000 + 1;

    strcpy(Client.email, Client.prenom);
    strcat(Client.email, ".");
    strcat(Client.email, Client.nom);
    strcat(Client.email, "@client.com");

    printf("\n\033[0;32mLe client a ete cree avec succes.\033[0m\n");
    ClientCree = 1;
}

// Consultation de profil

void AfficherProfil()
{
    if (!ClientCree)
    {
        printf("\n\033[0;31mAucun profil n'a ete cree. Veuillez d'abord en creer un.\033[0m\n");
        return;
    }

    printf("\n\033[0;90m=== Afficher de Profil Client ===\033[0m\n");

    printf("\nle prenom: %s\n", Client.prenom);
    printf("le nom: %s\n", Client.nom);
    printf("Id Client: %d\n", Client.idClient);
    printf("e-mail: %s\n", Client.email);
    printf("le solde %.2f MAD\n", Client.solde);

    printf("\033[0;32mLes informations du client ont ete affichees avec succes\033[0m\n");
}

// Modifay Profile

void ModifyProfile()
{
    if (!ClientCree)
    {
        printf("\n\033[0;31mAucun profil n'a ete cree. Veuillez d'abord en creer un.\033[0m\n");
        return;
    }

    printf("\n\033[0;90m=== Modification des informations du client ===\033[0m\n");

    printf("\n(1) changer le prenom.\n");
    printf("(2) changer le nom.\n");
    printf("(3) Tout Modifier.\n");

    printf("Que souhaiteriez-vous changer: ");
    scanf("%d", &choix3);

    while (choix3 != 1 && choix3 != 2 && choix3 != 3)
    {
        printf("\n\033[0;32mErreur!!\033[0m\n");
        printf("Que souhaiteriez-vous changer: ");
        scanf("%d", &choix3);
    }

    if (choix3 == 1)
    {
        printf("Entrez votre prenom : ");
        scanf(" %[^\n]", Client.prenom);
    }
    else if (choix3 == 2)
    {
        printf("Entrez votre nom : ");
        scanf(" %[^\n]", Client.nom);
    }
    else if (choix3 == 3)
    {
        printf("Entrez votre prenom : ");
        scanf(" %[^\n]", Client.prenom);
        printf("Entrez votre nom : ");
        scanf(" %[^\n]", Client.nom);
    }

    strcpy(Client.email, Client.prenom);
    strcat(Client.email, ".");
    strcat(Client.email, Client.nom);
    strcat(Client.email, "@client.com");

    printf("\033[0;32mLes informations ont ete modifiees avec succes.\033[0m\n");
}

// Gestion du solde virtuel

void GestionSolde()
{
    if (!ClientCree)
    {
        printf("\n\033[0;31mAucun profil n'a ete cree. Veuillez d'abord en creer un.\033[0m\n");
        return;
    }

    printf("\n\033[0;90m=== Gestion du Solde Virtuel ===\033[0m\n");

    printf("Votre solde actuel est: %.2f MAD", Client.solde);

    float dep = 0;

    printf("\n(1) Oui\n");
    printf("(2) Non\n");

    printf("\nVoulez-vous deposer de l'argent (1 ou 2): ");
    scanf("%d", &choix3);

    while (choix3 != 1 && choix3 != 2)
    {
        printf("\n\033[0;32mErreur!!\033[0m\n");
        printf("\nVoulez-vous deposer de l'argent (1 ou 2): ");
        scanf("%d", &choix3);
    }

    if (choix3 == 1)
    {
        printf("\nCombien d'argent souhaitez-vous deposer: ");
        scanf("%f", &dep);

        while (dep <= 0)
        {
            printf("\n\033[0;32mErreur!!\033[0m\n");
            printf("\nCombien d'argent souhaitez-vous deposer: ");
            scanf("%f", &dep);
        }
        Client.solde += dep;
        printf("\n\033[0;32mLe montant a ete depose avec succes.\033[0m\n");
        printf("\nVotre solde actuel est: %.2f MAD", Client.solde);
    }
    if (choix3 == 2)
        return;
}

// Afficher Produits

void AfficherProduits()
{
    printf("\n\033[0;90m=== Afficher Les Produits ===\033[0m\n");

    printf("\n(1) prix\n");
    printf("(2) nom\n");

    printf("\nComment souhaitez-vous afficher les produits: ");
    scanf("%d", &choix3);

    while (choix3 != 1 && choix3 != 2)
    {
        printf("\n\033[0;32mErreur!!\033[0m\n");
        printf("Comment souhaitez-vous afficher les produits: ");
        scanf("%d", &choix3);
    }

    if (choix3 == 1)
    {
        for (int j = 0; j < 5 - 1; j++)
        {
            for (int i = 0; i < 5 - j - 1; i++)
            {
                if (Produit[i].prix > Produit[i + 1].prix)
                {
                    Produits temp = Produit[i];
                    Produit[i] = Produit[i + 1];
                    Produit[i + 1] = temp;
                }
            }
        }
    }
    else if (choix3 == 2)
    {
        for (int j = 0; j < 5 - 1; j++)
        {
            for (int i = 0; i < 5 - j - 1; i++)
            {
                if (strcmp(Produit[i].nom, Produit[i + 1].nom) > 0)
                {
                    Produits temp = Produit[i];
                    Produit[i] = Produit[i + 1];
                    Produit[i + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\n(%d). %s - %.2f MAD - Stock:%d\n", i + 1, Produit[i].nom, Produit[i].prix, Produit[i].stock);
    }
}

// Recherche Produits
void RechercheProduits()
{
    int ProduitCree = 0;

    do
    {
        printf("S'il vous plait, donnez-moi le nom ou le type du produit: ");
        scanf(" %[^\n]", RechercheProd);

        for (int i = 0; i < 5; i++)
        {
            if (strcmp(RechercheProd, Produit[i].nom) == 0 ||
                strcmp(RechercheProd, Produit[i].categorie) == 0)
            {
                printf("\n\033[0;33m=== Produit[%d] ===\033[0m\n", i + 1);
                printf("nom: %s\n", Produit[i].nom);
                printf("categorie: %s\n", Produit[i].categorie);
                printf("prix: %.2f\n", Produit[i].prix);
                printf("stock: %d\n", Produit[i].stock);
                printf("idProduit: %d\n", Produit[i].idProduit);
                printf("description: %s\n", Produit[i].description);

                ProduitCree = 1;
            }
        }
        if (!ProduitCree)
            printf("\n\033[0;31mLe Produit n'existe Pas.\033[0m\n");
    } while (ProduitCree != 1);
}

// Achat d’un produit

void AchatProduit()
{
    if (!ClientCree)
    {
        printf("\n\033[0;31mAucun profil n'a ete cree. Veuillez d'abord en creer un.\033[0m\n");
        return;
    }

    AfficherProduits();

    int ProduitCree = 0;
    int quantite = 0;
    int newquantite = 0;
    int an = 0, mo = 0, jo = 0;
    float montant;

    do
    {
        printf("\n(1) Recherche d'un produit.\n");
        printf("(2) Achat d'un produit\n");
        printf("(3) Retourn au menu principal.\n");

        printf("\nEntrez votre choix: ");
        scanf("%d", &choix3);

        while (choix3 != 1 && choix3 != 2 && choix3 != 3)
        {
            printf("\n\033[0;31mErreur!!\033[0m\n");
            printf("\nEntrez votre choix: ");
            scanf("%d", &choix3);
        }

        if (choix3 == 1)
        {
            RechercheProduits();
            ProduitCree = 1;
        }
        else if (choix3 == 2)
        {
            ProduitCree = 0;
            do
            {
                printf("\nEntrez le nom du produit: ");
                scanf(" %[^\n]", RechercheProd);

                for (int i = 0; i < 5; i++)
                {
                    if (strcmp(RechercheProd, Produit[i].nom) == 0)
                    {
                        ProduitCree = 1;
                        found = i;
                    }
                }

                if (!ProduitCree)
                    printf("\n\033[0;31mLe Produit n'existe Pas.\033[0m\n");

            } while (ProduitCree != 1);

            printf("\n\033[0;34mLa quantite disponible est : %d\033[0m\n", Produit[found].stock);

            printf("\nS'il vous plait, entrez la quantite que vous souhaitez: ");
            scanf("%d", &quantite);

            while (quantite > Produit[found].stock)
            {
                printf("\n\033[0;31mErreur!!\033[0m\n");
                printf("\nS'il vous plait, entrez la quantite que vous souhaitez: ");
                scanf("%d", &quantite);
            }

            montant = quantite * Produit[found].prix;

            while (montant > Client.solde)
            {
                ProduitCree = 0;

                printf("\n\033[0;31mLe montant est insuffisan\033[0m\n");

                printf("\n(1) Reduire la quantite.\n");
                printf("(2) Recharger le solde.\n");

                printf("\nEntrez votre choix: ");
                scanf("%d", &choix3);

                while (choix3 != 1 && choix3 != 2)
                {
                    printf("\n\033[0;32mErreur!!\033[0m\n");
                    printf("\nEntrez votre choix: ");
                    scanf("%d", &choix3);
                }

                if (choix3 == 1)
                {
                    printf("\nS'il vous plait, entrez la nouvelle quantite: ");
                    scanf("%d", &newquantite);

                    quantite = newquantite;
                    montant = quantite * Produit[found].prix;
                }
                else if (choix3 == 2)
                    GestionSolde();
            }

            MontantDepense = Client.solde;
            Produit[found].stock -= quantite;
            Client.solde -= montant;

            printf("\nEntrez le jour: ");
            scanf("%d", &jo);

            while (jo > 31 || jo <= 0)
            {
                printf("\n\033[0;31mErreur!!\033[0m\n");
                printf("\nEntrez le jour: ");
                scanf("%d", &jo);
            }

            printf("\nEntrez le mois: ");
            scanf("%d", &mo);

            while (mo > 12 || mo <= 0)
            {
                printf("\n\033[0;31mErreur!!\033[0m\n");
                printf("\nEntrez le mois: ");
                scanf("%d", &mo);
            }

            printf("\nEntrez l'annee: ");
            scanf("%d", &an);

            while (an > 2026 || an < 2025)
            {
                printf("\n\033[0;31mErreur!!\033[0m\n");
                printf("\nEntrez l'annee: ");
                scanf("%d", &an);
            }

            printf("\n\033[0;32mL'achat a ete effectue avec succes\033[0m\n");

            ProduitCree = 1;
            Calcul++;
            Statistiques[Calcul] = Produit[found];
            Statistiques[Calcul].Date.jour = jo;
            Statistiques[Calcul].Date.mois = mo;
            Statistiques[Calcul].Date.annee = an;
            MontantDepense -= Client.solde;
        }

        if (!ProduitCree)
            printf("\n\033[0;31mL'achat a echoue.\033[0m\n");

    } while (choix3 != 3);
}

// Mes Statistiques

void MesStatistiques()
{
    if (!ClientCree)
    {
        printf("\n\033[0;31mAucun profil n'a ete cree. Veuillez d'abord en creer un.\033[0m\n");
        return;
    }

    printf("\n\033[0;34m=== Informations du clien ===\033[0m\n");

    printf("\nLe nom: %s\n", Client.nom);
    printf("Montant depense:\033[0;31m %.2f\033[0m\n", MontantDepense);
    printf("Votre solde actuel est: %.2f MAD\n", Client.solde);

    printf("\n\033[0;34m=== Les produits achetes ===\033[0m\n");

    printf("Nombre de produits achetes: %d\n", Calcul);
    for (int i = 1; i <= Calcul; i++)
    {
        printf("\n\033[0;33m=== Produit[%d] ===\033[0m\n", i + 1);

        printf("nom: %s\n", Statistiques[i].nom);
        printf("prix: %.2f\n", Statistiques[i].prix);
        printf("stock: %d\n", Statistiques[i].stock);
        printf("Date:%d / %d / %d\n", Statistiques[i].Date.mois, Statistiques[i].Date.jour, Statistiques[i].Date.annee);
    }
}