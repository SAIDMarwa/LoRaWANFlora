#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Position;

// Fonction pour vérifier que la nouvelle position respecte la distance minimale
int isValidPosition(Position positions[], int count, int x, int y, int min_distance) {
    for (int i = 0; i < count; i++) {
        int dx = x - positions[i].x;
        int dy = y - positions[i].y;
        if (sqrt(dx * dx + dy * dy) < min_distance) {
            return 0;
        }
    }
    return 1;
}

// Génération des positions des noeuds sans superposition
void generatePositions(Position positions[], int num_nodes, int x_limit, int y_limit, int min_distance) {
    int count = 0;
    while (count < num_nodes) {
        int x = rand() % x_limit;
        int y = rand() % y_limit;
        if (isValidPosition(positions, count, x, y, min_distance)) {
            positions[count].x = x;
            positions[count].y = y;
            count++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <num_nodes> <x_limit> <y_limit> <min_distance>\n", argv[0]);
        return 1;
    }

    int num_nodes = atoi(argv[1]);
    int x_limit = atoi(argv[2]);
    int y_limit = atoi(argv[3]);
    int min_distance = atoi(argv[4]);

    Position positions[num_nodes];
    srand(time(NULL));

    // Générer les positions
    generatePositions(positions, num_nodes, x_limit, y_limit, min_distance);

    // Sauvegarder dans un fichier texte
    FILE *file = fopen("positions.txt", "w");
    if (!file) {
        perror("Erreur lors de la création du fichier positions.txt");
        return 1;
    }

    for (int i = 0; i < num_nodes; i++) {
        fprintf(file, "%d %d\n", positions[i].x, positions[i].y);
    }

    fclose(file);
    printf("Positions générées dans le fichier positions.txt\n");

    return 0;
}
