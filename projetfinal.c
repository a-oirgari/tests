#include <stdio.h>
#include <string.h>

int idAvion = 1;
int idAeroport = 1;


typedef struct {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct {
    int id;
    char model[100];
    int capacite;
    int statut;
    Date dateEntree;
}Avion;

typedef struct {
    int id;
    char nom[100];
    Avion flotte[100];
    int nbAvion;
}Aeroport;

Aeroport ajouterAeroport();
Avion ajouterAvion(Aeroport P);
Aeroport ajouterAvion_Aeroport(Aeroport P);
void afficherListeAvions(Aeroport P);
Avion rechercherAvion(Aeroport P, int id);
void modifierAvion(Aeroport P);
Aeroport supprimerAvion(Aeroport P, int id);

int main(){
    Aeroport P;
    //Avion tabAvion[100];
    int choix;
    P.nbAvion = 0;
    do{
        printf("========Menu========\n");
        printf("1 - Ajouter Aeroport \n");
        printf("2 - Ajouter Avion \n");
        printf("3 - Afficher la liste des avions \n");
        printf("4 - Rechercher un avion\n");
        printf("5 - Trier les avions\n");
        printf("6 - Modifier un avion\n");
        printf("7 - Supprimer un avion\n");
        printf("8 - Quitter\n");
        printf("votre choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                P = ajouterAeroport();
                break;
            case 2:
                P = ajouterAvion_Aeroport(P);
                break;
            case 3:
                afficherListeAvions(P);
                break;
            case 4:
            int id;
                printf("Entrer l'id de l'avion a rechercher : ");
                scanf("%d", &id);
                Avion A = rechercherAvion(P, id);
                if (A.id != -1) {
                    printf("ID: %d | Modele : %s | Capacite : %d | Statut : %d | Date d'entree : %d/%d/%d\n",
                            A.id,
                            A.model,
                            A.capacite,
                            A.statut,
                            A.dateEntree.jour,
                            A.dateEntree.mois,
                            A.dateEntree.annee);
                    
                } else {
                    printf("Avion introuvable.\n");
                }
                
                break;
            case 5:
                //trierAvions();
                break;
            case 6:
                modifierAvion(P);
                break;
            case 7:
                printf("Entrer l'id de l'avion a supprimer : ");
                scanf("%d", &id);
                P = supprimerAvion(P, id);

                break;
            case 8:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
        
    }while (choix != 8);


    return 0;
}

Aeroport ajouterAeroport() {
    Aeroport P;
    printf("Entrer le nom d'aeroport: ");
    scanf("%s", P.nom); 
    P.id = idAeroport++;
    P.nbAvion = 0; 
    printf("Aeroport a ete ajouter avec succes !\n");
    return P;
    
}



Avion ajouterAvion(Aeroport P) {
    Avion A;
    A.id = idAvion++;
    printf("Entrer le model de l'avion: ");
    scanf("%s", A.model);
    printf("Entrer la capacite de l'avion: ");
    scanf("%d", &A.capacite);
    printf("Quel est le statut de l'avion ? (1.Disponible, 2.En maintenance, 3.En vol): ");
    scanf("%d", &A.statut);
    printf("La date d'entree (jour mois annee) :");
    scanf("%d %d %d", &A.dateEntree.jour, &A.dateEntree.mois, &A.dateEntree.annee);
    printf("Avion ajoute avec succes !\n");
    return A;
}

Aeroport ajouterAvion_Aeroport(Aeroport P) {
    
    P.flotte[P.nbAvion] = ajouterAvion(P);
    P.nbAvion++;
    
    return P;
}


void afficherListeAvions(Aeroport P) {
    printf("=============================================\n");
    printf("Aeroport : %s (d'id : %d)\n", P.nom, P.id);
    printf("------------- Liste des Avions -------------\n");

    if (P.nbAvion == 0) {
        printf("Aucun avion dans cet aeroport.\n");
        return;
    }

    for (int i = 0; i < P.nbAvion; i++) {
        printf("Avion %d : ====================================== \n", i + 1);
        printf("ID: %d | Modele : %s | Capacite : %d | Statut : %d | Date d'entree : %d/%d/%d\n",
            P.flotte[i].id,
            P.flotte[i].model,
            P.flotte[i].capacite,
            P.flotte[i].statut,
            P.flotte[i].dateEntree.jour,
            P.flotte[i].dateEntree.mois,
            P.flotte[i].dateEntree.annee
        );
    }
    printf("=============================================\n");
}


Avion rechercherAvion(Aeroport P, int id) {
    for (int i = 0; i < P.nbAvion; i++) {
        if (P.flotte[i].id == id) {
            return P.flotte[i];
        }
    }
    Avion A;
    A.id = -1; 
    return A;

}

void modifierAvion(Aeroport P) {
    int id, choix;
    printf("Entrer l'id de l'avion à modifier : ");
    scanf("%d", &id);

    Avion A = rechercherAvion(P, id);
    if (A.id != -1) {
        printf("Avion trouve. Que voulez-vous modifier ?\n");
        printf("1. Model\n");
        printf("2. Capacite\n");
        printf("3. Statut\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                printf("Modifier le model de l'avion: ");
                scanf("%s", A.model);
                break;
            case 2:
                printf("Modifier la capacite de l'avion: ");
                scanf("%d", &A.capacite);
                break;
            case 3:
                printf("Modifier le statut de l'avion ? (1.Disponible, 2.En maintenance, 3.En vol): ");
                scanf("%d", &A.statut);
                break;
            case 4:
                printf("Quitter la modification.\n");
                return;
            default:
                printf("Choix invalide.\n");
                return;
        }
        printf("Avion modifie avec succes !\n");
        // Mettre à jour l'avion dans l'aéroport   



        

        for (int i = 0; i < P.nbAvion; i++) {
             if (P.flotte[i].id == id) {
                P.flotte[i] = A;
                break;
            }
         }
    } else {
        printf("Avion introuvable.\n");
    }

    
}


Aeroport supprimerAvion(Aeroport P, int id) {
    int index = -1;

    
    for (int i = 0; i < P.nbAvion; i++) {
        if (P.flotte[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Avion avec ID %d introuvable.\n", id);
        return P;
    }

    
    for (int i = index; i < P.nbAvion - 1; i++) {
        P.flotte[i] = P.flotte[i + 1];
    }

    P.nbAvion--; 

    printf(" Avion avec ID %d supprimé avec succès.\n", id);
    return P;
}
