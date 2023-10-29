#include <stdio.h>
#include <stdlib.h>

// Comparison function
int karsilastir(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int liste[100];
    int boyut = 100;

    // Adding random numbers to our array
    for (int i = 0; i < boyut; i++) {
        liste[i] = rand() % 1000; // Random numbers between 0 and 999
    }

    // Sort array from largest to smallest
    qsort(liste, boyut, sizeof(int), karsilastir);

    
    printf("Siralanmis Liste: ");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", liste[i]);
        printf("->");
    }

    return 0;
}
