#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define APP_ADMIN      1
#define APP_SISTEMA    2
#define APP_SISTEMA_UI 3
#define APP_NORMAL     4

int execapp(const char *caminho_app, int tipoapp)
{
    FILE *f;
    unsigned char hex[1048576];
    char json[524289];
    size_t n;

    if (!caminho_app || caminho_app[0] != '/') {
        puts("Erro: use caminho absoluto");
        return -1;
    }

    if (tipoapp < APP_ADMIN || tipoapp > APP_NORMAL) {
        puts("Erro: tipo invalido");
        return -1;
    }

    f = fopen(caminho_app, "rb");
    if (!f) {
        puts("Erro: arquivo nao encontrado");
        return -1;
    }

    n = fread(hex, 1, sizeof(hex), f);
    fclose(f);

    if (n % 2 != 0 || n / 2 >= sizeof(json)) {
        puts("Erro: tamanho hexadecimal invalido");
        return -1;
    }

    for (size_t i = 0; i < n; i += 2) {
        unsigned int byte;

        if (sscanf((char[]){hex[i], hex[i+1], 0},
                   "%2x", &byte) != 1) {
            puts("Erro: hexadecimal invalido");
            return -1;
        }

        json[i / 2] = (char)byte;
    }

    json[n / 2] = '\0';

    printf("JSON decodificado:\n%s\n", json);

    switch (tipoapp) {
        case APP_ADMIN:     puts("Tipo: ADMIN"); break;
        case APP_SISTEMA:   puts("Tipo: SISTEMA (oculto)"); break;
        case APP_SISTEMA_UI:puts("Tipo: SISTEMA visivel"); break;
        case APP_NORMAL:    puts("Tipo: NORMAL"); break;
    }

    return 0;
}
