#include <stdio.h>

void ListeyiDuzenle(int liste[], int boyut) {
    int temp[boyut]; 
    int bas = 0;     // Add odd numbers to the beginning of the list
    int son = boyut - 1; // Adding even numbers to the end of a list

    for (int i = 0; i < boyut; i++) {
        if (liste[i] % 2 != 0) {
            temp[bas] = liste[i]; // Adds odd numbers to the beginning of the list
            bas++;
        } else {
            temp[son] = liste[i]; // Adds even numbers to the end of the list
            son--;
        }
    }

    // Copy temporary array to original array
    for (int i = 0; i < boyut; i++) {
        liste[i] = temp[i];
    }
}

int main() {
    int boyut;
    int liste[boyut];

    printf("Dizi boyutunu girin: ");
    scanf("%d", &boyut);

    printf("Dizi elemanlarini girin:\n");
    for (int i = 0; i < boyut; i++) {
        scanf("%d", &liste[i]);
    }

    printf("Orijinal Liste: ");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", liste[i]);
    }

    ListeyiDuzenle(liste, boyut);

    printf("\nDuzenlenmis Liste: ");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", liste[i]);
    }

    return 0;
}
