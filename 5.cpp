#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Creates a new student node and returns
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Adds a new student node to the linked list
void ogrenciEkle(struct Ogrenci** bas, int numara, const char* isim, int yas) {
    struct Ogrenci* yeni = yeniOgrenci(numara, isim, yas);
    yeni->sonraki = *bas;
    *bas = yeni;
}

// Function that deletes the next node from the list with the searched student name
void ogrenciSil(struct Ogrenci** bas, const char* hedefIsim) {
    struct Ogrenci* temp;
    while (*bas != NULL && strcmp((*bas)->isim, hedefIsim) != 0) {
        temp = *bas;
        *bas = (*bas)->sonraki;
        free(temp);
    }
    if (*bas != NULL) {
        temp = (*bas)->sonraki;
        if (temp != NULL) {
            (*bas)->sonraki = temp->sonraki;
            free(temp);
        }
    }
}


void ogrencileriYazdir(struct Ogrenci* bas) {
    int sayac = 0;
    while (bas != NULL) {
        printf("Ogrenci No: %d, isim: %s, Yas: %d\n", bas->numara, bas->isim, bas->yas);
        bas = bas->sonraki;
        sayac++;
    }
    printf("Toplam ogrenci sayisi: %d\n", sayac);
}

int main() {
    struct Ogrenci* liste = NULL;

    
    ogrenciEkle(&liste, 1, "Ali", 20);
    ogrenciEkle(&liste, 2, "Ayse", 22);
    ogrenciEkle(&liste, 3, "Mehmet", 21);

    // Determine the name of the student to be deleted based on the student name
    const char* silinecekIsim = "Ayse";

    // Delete specified student
    ogrenciSil(&liste, silinecekIsim);

    // Printing student information on the screen
    ogrencileriYazdir(liste);

    // Let's clear memory
    while (liste != NULL) {
        struct Ogrenci* sil = liste;
        liste = liste->sonraki;
        free(sil);
    }

    return 0;
}
