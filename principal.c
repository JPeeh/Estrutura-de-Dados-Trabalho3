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

    for (int a = 0; a < numVertices; a++) {
        float x, y;
        fscanf(arquivo, "%f %f", &x, &y);
        vertices[a] = criarPonto(x, y);
    }

    fclose(arquivo);

    float area = 0.0;
    for (int a = 0; a < numVertices; a++) {
        int b = (a + 1) % numVertices;
        area += (vertices[a].X * vertices[b].Y) - (vertices[b].X * vertices[a].Y);
    }

    area = fabs(area) / 2.0;

    printf("A área do polígono é %.2f\n", area);

    return 0;
}
