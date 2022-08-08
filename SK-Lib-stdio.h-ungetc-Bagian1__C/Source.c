#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by CPlusPlus (https://www.cplusplus.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    FILE* pFile;
    int c;
    char buffer[256];

    pFile = fopen("myfile.txt", "rt");

    if (pFile == NULL) { 
        perror("Gagal membuka file!"); 
    }
    else {
        while (!feof(pFile)) {
            c = getc(pFile);

            if (c == EOF) {
                break;
            }

            if (c == '#') {
                ungetc('@', pFile);
            } else {
                ungetc(c, pFile);

                if (fgets(buffer, 255, pFile) != NULL) {
                    fputs(buffer, stdout);
                } else {
                    break;
                }
            }
        }
    }
    
    _getch();
    return 0;
}