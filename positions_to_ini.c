#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile = fopen("positions.txt", "r");
    if (!inputFile) {
        perror("Erreur lors de l'ouverture du fichier positions.txt");
        return 1;
    }

    FILE *outputFile = fopen("positions.ini", "w");
    if (!outputFile) {
        perror("Erreur lors de la création du fichier positions.ini");
        fclose(inputFile);
        return 1;
    }

    int x, y;
    int nodeIndex = 0;
    char line[100];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        if (sscanf(line, "%d %d", &x, &y) != 2) {
            fprintf(stderr, "Erreur de format dans positions.txt à la ligne %d\n", nodeIndex + 1);
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }

        fprintf(outputFile, "*.nodes[%d].**. = %dm\n", nodeIndex, x);
        fprintf(outputFile, "*.nodes[%d].**. = %dm\n", nodeIndex, y);
        nodeIndex++;
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Les positions des nœuds ont été ajoutées dans positions.ini.\n");

    return 0;
}
