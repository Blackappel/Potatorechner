#include <stdio.h>
#include <math.h>

float theodorus_rec (int);
float theodorus_ite (int);

int main (void) {
    int input;
    printf("Gib eine Zahl ein: ");
    scanf("%d", &input);

    printf("Ergebnis rec ist: %f\n", theodorus_rec(input));
    printf("Ergebnis ire ist: %f\n", theodorus_ite(input));
    return 0;
}

float theodorus_rec (int interval) {
    if (interval <= 0) {
        return 0.0f;
    }
    if (interval == 1) {
        return sqrt(2);
    }

    float rec = theodorus_rec(interval - 1);
    return sqrt(rec*rec + 1);
}


float theodorus_ite (int interval) {
    if (interval <= 0) {
        return 0.0f;
    }

    int i;
    float ret = 1.0f;
    for (i = 0; i < interval; i++) {
        ret = sqrtf(ret*ret + 1.0f);
    }

    return ret;
}

