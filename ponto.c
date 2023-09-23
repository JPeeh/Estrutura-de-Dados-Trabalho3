#include <stdio.h>
#include <math.h>

typedef struct {
    float X;
    float Y;
} Ponto;

Ponto criarPonto(float x, float y) {
    Ponto ponto;
    ponto.X = x;
    ponto.Y = y;
    return ponto;
}

float calcularDistancia(Ponto p1, Ponto p2) {
    return sqrt(pow(p2.X - p1.X, 2) + pow(p2.Y - p1.Y, 2));
}

