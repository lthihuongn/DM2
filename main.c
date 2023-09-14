#include <stdio.h>

int devine_lettre(char lettre, char mot_secret[], char mot_affiche[], int longueur_mot) {
    int lettre_trouvee = 0;

    for (int i = 0; i < longueur_mot; i++) {
        if (lettre == mot_secret[i] && mot_affiche[i] == '_') {
            mot_affiche[i] = lettre;
            lettre_trouvee = 1;
        }
    }
    return lettre_trouvee;
}

int main() {
    char mot_Secret[7] = {'D', 'O', 'N', 'I', 'L', 'D', 'E'};
    char mot_Affiche[10] = "_______";
    int longueur_Mot = 7;
    int erreurs = 0;
    int lettres_Restantes = longueur_Mot;

    while (erreurs < 6 && lettres_Restantes > 0) {
        printf("Mot actuel : %s\n", mot_Affiche);
        printf("Il vous reste %d essais.\n", 6 - erreurs);
        char Lettre;
        printf("Entrez une lettre : \n");
        scanf(" %c", &Lettre);

        int lettre_Trouvee = devine_lettre(Lettre, mot_Secret, mot_Affiche, longueur_Mot);

        if (lettre_Trouvee == 0) {
            erreurs+=1;
        }

        lettres_Restantes = 0;
        for (int i = 0; i < longueur_Mot; i++) {
            if (mot_Affiche[i] == '_') {
                lettres_Restantes +=1;
            }
        }
    }

    if (lettres_Restantes == 0) {
        printf("Bravo, vous avez gagne !");
    } else {
        printf("Desole, vous avez perdu");
    }

    return 0;
}