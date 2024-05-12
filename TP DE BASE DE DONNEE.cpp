#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct etu_info {
    char nom[30];
    char prenom[30];
    char groupe[3];
    char moyenne_generale[5];
} etu;

void afficheTout();
void ajouttezEtudiant(etu les_eleves[], int *counter);
void supprimerEtudiant(etu les_eleves[], etu etudiantASup, int *counter);
void recharcheEtudiant(etu les_eleves[], int choixR, etu etudiantARech, int *counter);
void trierEtudiant(etu les_eleves[], int choixT, int *counter);

int main() {
    int choix = 0, choix_2, choix_3, counter = 0;
    etu les_eleves[20];
    etu eSup, eRech;

    do {
        printf("1- Pour ajouter un nouveau etudiant\n2- Pour afficher les etudiants\n3- Supprimer un etudiant\n4- Rechercher un etudiant\n5- Trier les etudiants et les afficher\n6- Pour quitter\nCHOIX: ");
        scanf("%d", &choix);
        switch (choix) {

            case 1:
                ajouttezEtudiant(les_eleves, &counter);
                break;

            case 2:
                afficheTout();
                break;

            case 3:
                printf("Nom de l'etudiant a supprimer: ");
                scanf("%s", eSup.nom);
                printf("Prenom de l'etudiant a supprimer: ");
                scanf("%s", eSup.prenom);
                supprimerEtudiant(les_eleves, eSup, &counter);
                break;

            case 4:
                printf("VOUS VOULEZ CHERCHER AVEC: \n1- Nom\n2- Prenom\n3- Groupe\n4- Moyenne Generale\nCHOIX: ");
                scanf("%d", &choix_2);
                switch (choix_2) {
                    case 1:
                        printf("Nom de l'etudiant: ");
                        scanf("%s", eRech.nom);
                        recharcheEtudiant(les_eleves, 1, eRech, &counter);
                        break;

                    case 2:
                        printf("Prenom de l'etudiant: ");
                        scanf("%s", eRech.prenom);
                        recharcheEtudiant(les_eleves, 2, eRech, &counter);
                        break;

                    case 3:
                        printf("Groupe de l'etudiant: ");
                        scanf("%s", eRech.groupe);
                        recharcheEtudiant(les_eleves, 3, eRech, &counter);
                        break;

                    case 4:
                        printf("La Moyenne de l'etudiant: ");
                        scanf("%s", eRech.moyenne_generale);
                        recharcheEtudiant(les_eleves, 4, eRech, &counter);
                        break;

                    default:
                        printf("Choix de recherche invalide!");
                        break;
                }
                break;

            case 5:
                printf("VOUS VOULEZ TRIER AVEC: \n1- Nom\n2- Groupe\n3- Moyenne Generale\nCHOIX: ");
                scanf("%d", &choix_3);
                switch (choix_3) {
                    case 1:
                        trierEtudiant(les_eleves, 1, &counter);
                        break;

                    case 2:
                        trierEtudiant(les_eleves, 2, &counter);
                        break;

                    case 3:
                        trierEtudiant(les_eleves, 3, &counter);
                        break;

                    default:
                        printf("Choix de triage invalide !");
                        break;
                }
                break;

            case 6:
                printf("Au revoir!");
                break;

            default:
                printf("Choix invalide !");
        }
    } while (choix != 6);

    return 0;
}

void ajouttezEtudiant(etu les_eleves[], int *counter) {
    int i = *counter;
    etu eleve;
    FILE *les_etudiants;
    les_etudiants = fopen("les_etudiants.txt", "a");
    printf("\nEtudiant N %d\n", i + 1);
    printf("Veuillez entrer son Nom: ");
    scanf("%s", eleve.nom);
    printf("Veuillez entrer son Prenom: ");
    scanf("%s", eleve.prenom);
    printf("Veuillez entrer son Groupe: ");
    scanf("%s", eleve.groupe);
    printf("Veuillez entrer sa Moyenne Generale: ");
    scanf("%s", eleve.moyenne_generale);
    fprintf(les_etudiants, "-Nom: %s | Prenom: %s | Groupe: %s | Note generale: %s\n", eleve.nom, eleve.prenom, eleve.groupe, eleve.moyenne_generale);
    strcpy(les_eleves[i].nom, eleve.nom);
    strcpy(les_eleves[i].prenom, eleve.prenom);
    strcpy(les_eleves[i].groupe, eleve.groupe);
    strcpy(les_eleves[i].moyenne_generale, eleve.moyenne_generale);
    (*counter)++;
    fclose(les_etudiants);
}

void supprimerEtudiant(etu les_eleves[], etu etudiantASup, int *counter) {
    for (int j = 0; j < *counter; j++) {
        if (strcmp(les_eleves[j].nom, etudiantASup.nom) == 0 && strcmp(les_eleves[j].prenom, etudiantASup.prenom) == 0) {
            strcpy(les_eleves[j].nom, "404");
            strcpy(les_eleves[j].prenom, "404");
            printf("\n\nEtudiant supprimé\n\n");
            break;
        }
    }
    FILE *les_etudiants;
    les_etudiants = fopen("les_etudiants.txt", "w");
    int k = 0;
    while (k < *counter) {
        if (strcmp(les_eleves[k].nom, "404") != 0 && strcmp(les_eleves[k].prenom, "404") != 0) {
            fprintf(les_etudiants, "-Nom: %s | Prenom: %s | Groupe: %s | Note generale: %s\n", les_eleves[k].nom, les_eleves[k].prenom, les_eleves[k].groupe, les_eleves[k].moyenne_generale);
        }
        k++;
    }
    fclose(les_etudiants);
}

void recharcheEtudiant(etu les_eleves[], int choixR, etu etudiantARech, int *counter) {
    int status = 0;
    switch (choixR) {
        case 1:
            printf("Les etudiants trouvés avec le Nom de %s sont: \n", etudiantARech.nom);
            for (int k = 0; k < *counter; k++) {
            	if(les_eleves[k].nom != "404"&& les_eleves[k].prenom != "404"){
                if (strcmp(les_eleves[k].nom, etudiantARech.nom) == 0) {
                    printf("\n\n");
                    printf("Nom: %s\nPrenom: %s\nGroupe: %s\nMoyenne Generale: %s\n", les_eleves[k].nom, les_eleves[k].prenom, les_eleves[k].groupe, les_eleves[k].moyenne_generale);
                    status = 1;
                }}
            }
            if (status == 0)
                printf("Aucun étudiant trouvé !");
            break;

        case 2:
            printf("Les etudiants trouvés avec le Prenom de %s sont: \n", etudiantARech.prenom);
            for (int k = 0; k < *counter; k++) {
            	if(les_eleves[k].nom != "404"&& les_eleves[k].prenom != "404"){
                if (strcmp(les_eleves[k].prenom, etudiantARech.prenom) == 0) {
                    printf("\n\n");
                    printf("Nom: %s\nPrenom: %s\nGroupe: %s\nMoyenne Generale: %s\n", les_eleves[k].nom, les_eleves[k].prenom, les_eleves[k].groupe, les_eleves[k].moyenne_generale);
                    status = 1;
                }}
            }
            if (status == 0)
                printf("Aucun étudiant trouvé !");
            break;

        case 3:
            printf("Les etudiants trouvés dans le groupe %s sont: \n", etudiantARech.groupe);
            for (int k = 0; k < *counter; k++) {
            	if(les_eleves[k].nom != "404"&& les_eleves[k].prenom != "404"){
                if (strcmp(les_eleves[k].groupe, etudiantARech.groupe) == 0) {
                    printf("\n\n");
                    printf("Nom: %s\nPrenom: %s\nGroupe: %s\nMoyenne Generale: %s\n", les_eleves[k].nom, les_eleves[k].prenom, les_eleves[k].groupe, les_eleves[k].moyenne_generale);
                    status = 1;
                }}
            }
            if (status == 0)
                printf("Aucun étudiant trouvé !");
            break;

        case 4:
            printf("Les etudiants trouvés avec la moyenne de %s sont: \n", etudiantARech.moyenne_generale);
            for (int k = 0; k < *counter; k++) {
            	if(les_eleves[k].nom != "404"&& les_eleves[k].prenom != "404"){
				
                if (strcmp(les_eleves[k].moyenne_generale, etudiantARech.moyenne_generale) == 0) {
                    printf("\n\n");
                    printf("Nom: %s\nPrenom: %s\nGroupe: %s\nMoyenne Generale: %s\n", les_eleves[k].nom, les_eleves[k].prenom, les_eleves[k].groupe, les_eleves[k].moyenne_generale);
                    status = 1;
                }}
            }
            if (status == 0)
                printf("Aucun étudiant trouvé !");
            break;
    }
}

void afficheTout() {
    FILE *les_etudiants;
    char first_name[30];
    char last_name[30];
    char gr[3];
    char mg[5];
    int k = 0;

    les_etudiants = fopen("les_etudiants.txt", "r");
    while (fscanf(les_etudiants, "-Nom: %s | Prenom: %s | Groupe: %s | Note generale: %s\n", first_name, last_name, gr, mg) == 4) {
    	if(first_name!="404"&&last_name!="404"){
		printf("\nEtudiant numero %d\n", k + 1);
        printf("Nom: %s\nPrenom: %s\nGroupe: %s\nMoyenne Generale: %s\n", first_name, last_name, gr, mg);
        k++;
		}
        
    }
    fclose(les_etudiants);
}

void trierEtudiant(etu les_eleves[], int choixT, int *counter) {
    int i, k;
    float valeur1, valeur2;
    etu tmp;

    switch (choixT) {
        case 1:
            for (i = 1; i < *counter; i++) {
                k = i;
                while (k > 0 && strcmp(les_eleves[k - 1].nom, les_eleves[k].nom) < 0) {
                    tmp = les_eleves[k];
                    les_eleves[k] = les_eleves[k - 1];
                    les_eleves[k - 1] = tmp;
                    k--;
                }
            }
            break;

        case 2:
            for (i = 1; i < *counter; i++) {
                k = i;
                valeur1 = atof(les_eleves[k - 1].groupe);
                valeur2 = atof(les_eleves[k].groupe);

                while (k > 0 && valeur1 < valeur2) {
                    tmp = les_eleves[k];
                    les_eleves[k] = les_eleves[k - 1];
                    les_eleves[k - 1] = tmp;
                    k--;
                }
            }
            break;

        case 3:
            for (i = 1; i < *counter; i++) {
                k = i;
                valeur1 = atof(les_eleves[k - 1].moyenne_generale);
                valeur2 = atof(les_eleves[k].moyenne_generale);

                while (k > 0 && valeur1 < valeur2) {
                    tmp = les_eleves[k];
                    les_eleves[k] = les_eleves[k - 1];
                    les_eleves[k - 1] = tmp;
                    k--;
                }
            }
            break;
    }

    FILE *les_etudiants;
    les_etudiants = fopen("les_etudiants.txt", "w");
    int j;
    for (j = 0; j < *counter; j++) {
    	if(les_eleves[j].nom != "404"&& les_eleves[j].prenom != "404")
        	fprintf(les_etudiants, "-Nom: %s | Prenom: %s | Groupe: %s | Note generale: %s\n", les_eleves[j].nom, les_eleves[j].prenom, les_eleves[j].groupe, les_eleves[j].moyenne_generale);
    }
    printf("** Les étudiants sont bien triés **\n\n*** Voir dans le fichier les_etudiants.txt ***");
    fclose(les_etudiants);
}

