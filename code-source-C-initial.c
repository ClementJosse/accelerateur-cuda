#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECT_SIZE 10000

int find_longest_match(int vect[], int size, int *index) {
    int longest_match_size = 0;
    int longest_match_index = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int match_size = 0;
            while (j + match_size < size && vect[i + match_size] == vect[j + match_size]) {
                match_size++;
            }
            if (match_size > longest_match_size) {
                longest_match_size = match_size;
                longest_match_index = i;
            }
        }
    }
    
    *index = longest_match_index;
    return longest_match_size;
}

int main() {
    int vect[VECT_SIZE];
    int longest_match_size = 0;
    int longest_match_index = 0;
    clock_t start, end;
    double cpu_time_used;
    
    // Initialisation de la génération aléatoire
    //srand(time(NULL));

    // Initialiser le vecteur avec des valeurs aléatoires
    for (int i = 0; i < VECT_SIZE; i++) {
        vect[i] = rand() % 10; // Nombre aléatoire entre 0 et 9 inclus
        printf("%d ", vect[i]); // Affichage du vecteur
    }
    printf("\n");

    // Rechercher le plus long motif en double et mesurer le temps d'exécution
    start = clock();
    longest_match_size = find_longest_match(vect, VECT_SIZE, &longest_match_index);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Afficher les résultats
    printf("Le plus long motif en double a une taille de %d et commence à l'index %d du vecteur.\n", longest_match_size, longest_match_index);
    printf("Le motif est : ");
    for (int i = 0; i < longest_match_size; i++) {
        printf("%d ", vect[longest_match_index + i]);
    }
    printf("\n");

    printf("Le temps d'exécution est de %f secondes.\n", cpu_time_used);
    
    return 0;
}