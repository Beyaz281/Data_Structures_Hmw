#include <stdio.h>
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

// Function that searches for records by student name
struct Ogrenci* ogrenciAra(struct Ogrenci* bas, const char* hedefIsim) {
    while (bas != NULL) {
        if (strcmp(bas->isim, hedefIsim) == 0) {
            return bas; // Match found
        }
        bas = bas->sonraki;
    }
    return NULL; // No matches found
}

int main() {
    struct Ogrenci* liste = NULL;

    
    ogrenciEkle(&liste, 1, "Ali", 20);
    ogrenciEkle(&liste, 2, "Ayþe", 22);
    ogrenciEkle(&liste, 3, "Mehmet", 21);

    // Specify the name of the student to search for
    const char* arananIsim = "Ayþe";

    // Search record by student name
    struct Ogrenci* sonuc = ogrenciAra(liste, arananIsim);

    
    if (sonuc != NULL) {
        printf("Öðrenci bulundu: No: %d, Ýsim: %s, Yaþ: %d\n", sonuc->numara, sonuc->isim, sonuc->yas);
    } else {
        printf("Öðrenci bulunamadý.\n");
    }

    // Let's clear memory
    while (liste != NULL) {
        struct Ogrenci* sil = liste;
        liste = liste->sonraki;
        free(sil);
    }

    return 0;
}
