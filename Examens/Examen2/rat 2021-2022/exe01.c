#include <stdio.h>

typedef struct {
    float reel;
    float img;
} complex;

void produit_complex(complex *x, complex *y) {
    float reel = x->reel * y->reel - x->img * y->img;
    float img = x->reel * y->img + x->img * y->reel;
    printf("(%.1f + i%.1f) * (%.1f + i%.1f) = %.0f + i%.0f\n", x->reel, x->img, y->reel, y->img, reel, img);
}

int main() {
    complex a = {3.0, 2.0};
    complex b = {1.0, 7.0};
    produit_complex(&a, &b);
    return 0;
}
