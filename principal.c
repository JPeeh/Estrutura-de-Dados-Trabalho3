#include <stdio.h>
#include "ponto.c"

int main() {
    FILE *arquivo;
    arquivo = fopen("poligono.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    if (numVertices < 3) {
        printf("O número de vértices deve ser pelo menos 3.\n");
        fclose(arquivo);
        return 1;
    }

    Ponto vertices[numVertices];

    for (int i = 0; i < numVertices; i++) {
        float x, y;
        fscanf(arquivo, "%f %f", &x, &y);
        vertices[i] = criarPonto(x, y);
    }

    fclose(arquivo);

    float area = 0.0;
    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = fabs(area) / 2.0;

    printf("A area do poligono e: %.2f\n", area);

    return 0;
}
