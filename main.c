#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


// Dimensions du plateau
#define LIGNES 6
#define COLONNES 8
// Taille de chaque case
#define LARGEUR 14
#define HAUTEUR 7



void positionner_curseur(int ligne, int colonne);
void color (int couleurDuTexte, int couleurDuFond);
void plein_ecran();
void afficherPlateau(int ligne, int colonne);
void affichage_caractere_speciaux();

void dessiner_legendaire(int ligne, int colonne, int couleur);
void dessiner_epic(int ligne, int colonne, int couleur);
void dessiner_basique(int ligne, int colonne, int couleur);



int main() {

    sleep(1);
    plein_ecran();
    sleep(1);

    // Afficher les plateaux des deux joueurs
    afficherPlateau(3,120);

    //dessiner_basique(3,120,1);

    //dessiner_epic(3, 120, 10);

    dessiner_legendaire(3, 120, 12);

    positionner_curseur(103,250);

    system("pause");
    return 0;
}


void dessiner_legendaire(int ligne, int colonne, int couleur) {
    positionner_curseur(ligne, colonne);
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 29; j++) {
            positionner_curseur(ligne+i+1,colonne+j+2);
            color(couleur,couleur);
            printf(" ");
        }
    }
}



void dessiner_epic(int ligne, int colonne, int couleur) {
    int i,j;

    for (i = 0; i < 3; i++) {
        positionner_curseur(ligne + 1, colonne + 7 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 7; i++) {
        positionner_curseur(ligne + 2, colonne + 5 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 11; i++) {
        for (j = 0; j <11; j++) {
            positionner_curseur(ligne + 3 + i, colonne + 3 + j);
            color(couleur, couleur);
            printf(" ");
        }
    }

    for (i = 0; i < 7; i++) {
        positionner_curseur(ligne + 14, colonne + 5 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 3; i++) {
        positionner_curseur(ligne + 15, colonne + 7 + i);
        color(couleur, couleur);
        printf(" ");
    }
}



void dessiner_basique(int ligne, int colonne, int couleur) {
    int i;
    for (i = 0; i < 6; i++) {
        positionner_curseur(ligne + 2, colonne + 5 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 10; i++) {
        positionner_curseur(ligne + 3, colonne + 3 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 12; i++) {
        positionner_curseur(ligne + 4, colonne + 2 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 10; i++) {
        positionner_curseur(ligne + 5, colonne + 3 + i);
        color(couleur, couleur);
        printf(" ");
    }

    for (i = 0; i < 6; i++) {
        positionner_curseur(ligne + 6, colonne + 5 + i);
        color(couleur, couleur);
        printf(" ");
    }


}



void afficherPlateau(int ligne, int colonne) {

    int i, j, k;

    //afficher lignes horizontales
    for(i=0 ; i<=LIGNES ; i++) {
        for(j=0 ; j<COLONNES ; j++) {
            for(k=0 ; k<(LARGEUR+1) ; k++) {
                positionner_curseur(ligne + i*(HAUTEUR+1), colonne + j*(LARGEUR+1) + k);
                printf("%c",196);
            }
        }
    }

    //afficher lignes verticales
    for(i=0 ; i<=COLONNES ; i++) {
        for(j=0 ; j<LIGNES ; j++) {
            for(k=0 ; k<HAUTEUR ; k++) {
                positionner_curseur(ligne + j*(HAUTEUR+1)+k+1, colonne + i*(LARGEUR+1));
                printf("%c",179);
            }
        }
    }

    // Afficher les coins
    positionner_curseur(ligne, colonne);
    printf("%c",218);
    positionner_curseur(ligne, colonne+COLONNES*(LARGEUR+1));
    printf("%c",191);
    positionner_curseur(ligne+LIGNES*(HAUTEUR+1), colonne);
    printf("%c",192);
    positionner_curseur(ligne+LIGNES*(HAUTEUR+1), colonne+COLONNES*(LARGEUR+1));
    printf("%c",217);

    // Afficher intersection haut
    for(i=0 ; i<COLONNES-1 ; i++) {
        positionner_curseur(ligne, colonne+1+LARGEUR+i*(LARGEUR+1));
        printf("%c",194);
    }

    // Afficher intersection bas
    for(i=0 ; i<COLONNES-1 ; i++) {
        positionner_curseur(ligne+LIGNES*(HAUTEUR+1), colonne+1+LARGEUR+i*(LARGEUR+1));
        printf("%c",193);
    }

    // Afficher intersection droit
    for(i=0 ; i<LIGNES-1 ; i++) {
        positionner_curseur(ligne+1+HAUTEUR+i*(HAUTEUR+1), colonne+COLONNES*(LARGEUR+1));
        printf("%c",180);
    }

    // Afficher intersection gauche
    for(i=0 ; i<LIGNES-1 ; i++) {
        positionner_curseur(ligne+1+HAUTEUR+i*(HAUTEUR+1), colonne);
        printf("%c",195);
    }


    //afficher intersections centre
    for(i=1 ; i<LIGNES ; i++) {
        for(j=1 ; j<COLONNES ; j++) {
            positionner_curseur(ligne+i*(HAUTEUR+1), colonne+j*(LARGEUR+1));
            printf("%c",197);
        }
    }





    // Ligne de séparation des plateaux
    for(i=0 ; i<((LARGEUR+1)*COLONNES)+1 ; i++) {
        positionner_curseur(ligne + (HAUTEUR-1)*COLONNES+1,colonne + i);
        printf("=");
    }
    for(i=0 ; i<((LARGEUR+1)*COLONNES)+1 ; i++) {
        positionner_curseur(ligne + (HAUTEUR-1)*COLONNES+2,colonne + i);
        printf("=");
    }






    //afficher lignes horizontales
    for(i=0 ; i<=LIGNES ; i++) {
        for(j=0 ; j<COLONNES ; j++) {
            for(k=0 ; k<(LARGEUR+1) ; k++) {
                positionner_curseur(ligne + LIGNES*HAUTEUR+9 + i*(HAUTEUR+1), colonne + j*(LARGEUR+1) + k);
                printf("%c",196);
            }
        }
    }

    //afficher lignes verticales
    for(i=0 ; i<=COLONNES ; i++) {
        for(j=0 ; j<LIGNES ; j++) {
            for(k=0 ; k<HAUTEUR ; k++) {
                positionner_curseur(ligne + LIGNES*HAUTEUR+9 + j*(HAUTEUR+1)+k+1, colonne + i*(LARGEUR+1));
                printf("%c",179);
            }
        }
    }

    // Afficher les coins
    positionner_curseur(ligne + LIGNES*HAUTEUR+9, colonne);
    printf("%c",218);
    positionner_curseur(ligne + LIGNES*HAUTEUR+9, colonne+COLONNES*(LARGEUR+1));
    printf("%c",191);
    positionner_curseur(ligne + LIGNES*HAUTEUR+9+LIGNES*(HAUTEUR+1), colonne);
    printf("%c",192);
    positionner_curseur(ligne + LIGNES*HAUTEUR+9+LIGNES*(HAUTEUR+1), colonne+COLONNES*(LARGEUR+1));
    printf("%c",217);

    // Afficher intersection haut
    for(i=0 ; i<COLONNES-1 ; i++) {
        positionner_curseur(ligne + LIGNES*HAUTEUR+9, colonne+1+LARGEUR+i*(LARGEUR+1));
        printf("%c",194);
    }

    // Afficher intersection bas
    for(i=0 ; i<COLONNES-1 ; i++) {
        positionner_curseur(ligne + LIGNES*HAUTEUR+9+LIGNES*(HAUTEUR+1), colonne+1+LARGEUR+i*(LARGEUR+1));
        printf("%c",193);
    }

    // Afficher intersection droit
    for(i=0 ; i<LIGNES-1 ; i++) {
        positionner_curseur(ligne + LIGNES*HAUTEUR+9+1+HAUTEUR+i*(HAUTEUR+1), colonne+COLONNES*(LARGEUR+1));
        printf("%c",180);
    }

    // Afficher intersection gauche
    for(i=0 ; i<LIGNES-1 ; i++) {
        positionner_curseur(ligne + LIGNES*HAUTEUR+9+1+HAUTEUR+i*(HAUTEUR+1), colonne);
        printf("%c",195);
    }


    //afficher intersections centre
    for(i=1 ; i<LIGNES ; i++) {
        for(j=1 ; j<COLONNES ; j++) {
            positionner_curseur(ligne + LIGNES*HAUTEUR+9+i*(HAUTEUR+1), colonne+j*(LARGEUR+1));
            printf("%c",197);
        }
    }



}



void positionner_curseur(int ligne, int colonne)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//permet de déclarer la variable "hstdout" qui fait référénce à la console
    COORD pos; // COORD est un type structuré défini dans la bibliothèque windows.h
    pos.X=colonne;// numéro de la colonne
    pos.Y=ligne;// numéro de la ligne
    SetConsoleCursorPosition(hStdout, pos);
}



void plein_ecran()
{
 keybd_event(VK_MENU, 0x38, 0, 0);
 keybd_event(VK_RETURN, 0x1c, 0, 0);
 keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
 keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

 for (int i = 0; i < 7; i++) {
 keybd_event(VK_CONTROL, 0x1d, 0, 0); // Press CTRL key
 keybd_event(0xBD, 0, 0, 0); // Press '-' key (VK_SUBTRACT)
 keybd_event(0xBD, 0, KEYEVENTF_KEYUP, 0); // Release '-' key
 keybd_event(VK_CONTROL, 0x1d, KEYEVENTF_KEYUP, 0); // Release CTRL key
 }
}




void color (int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}


void affichage_caractere_speciaux()
{
     printf("%c\n\n",218);
     printf("%c\n\n",196);
     printf("%c\n\n",191);
     printf("%c\n\n",179);
     printf("%c\n\n",195);
     printf("%c\n\n",180);
     printf("%c\n\n",192);
     printf("%c\n\n",217);

}


// 0.Noir
// 1.Bleu fonc�
// 2.Vert fonc�
// 3.Turquoise
// 4.Rouge fonc�
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc�
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc


