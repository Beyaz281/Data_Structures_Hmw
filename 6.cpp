#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öðrenci bilgilerini saklamak için yapý (struct)
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

// Function that finds the student with the longest name and prints their information
void enUzunIsmiYazdir(struct Ogrenci* bas) {
    if (bas == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct Ogrenci* enUzunIsimli = bas;
    int enUzunIsimUzunluk = strlen(bas->isim);

    while (bas != NULL) {
        int isimUzunluk = strlen(bas->isim);
        if (isimUzunluk > enUzunIsimUzunluk) {
            enUzunIsimli = bas;
            enUzunIsimUzunluk = isimUzunluk;
        }
        bas = bas->sonraki;
    }

    printf("En uzun isme sahip ogrenci: No: %d, isim: %s, Yas: %d\n", enUzunIsimli->numara, enUzunIsimli->isim, enUzunIsimli->yas);
}

int main() {
    struct Ogrenci* liste = NULL;

    
    ogrenciEkle(&liste, 1, "Ali", 20);
    ogrenciEkle(&liste, 2, "Ayse", 22);
    ogrenciEkle(&liste, 3, "Mehmet", 21);
    ogrenciEkle(&liste, 4, "Beyza ozdemir", 24); // En uzun isimli öðrenci

    // Find and print the student with the longest name
    enUzunIsmiYazdir(liste);

    // Let's clear memory
    while (liste != NULL) {
        struct Ogrenci* sil = liste;
        liste = liste->sonraki;
        free(sil);
    }

    return 0;
}
