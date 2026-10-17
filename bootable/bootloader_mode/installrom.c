#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

void installrom(void) {
    ROMDriver *driver = &rom_driver;
    char path[256];
    void *image = NULL;
    void *verify = NULL;
    size_t size = 0;
    uint64_t offset = 0;

    printf("Arquivo da ROM: ");
    if (scanf("%255s", path) != 1)
        return;

    printf("Offset de destino: ");
    if (scanf("%llu", (unsigned long long *)&offset) != 1)
        return;

    FILE *file = fopen(path, "rb");

    if (file != NULL) {
        if (fseek(file, 0, SEEK_END) != 0) {
            fclose(file);
            return;
        }

        long length = ftell(file);

        if (length <= 0 || fseek(file, 0, SEEK_SET) != 0) {
            printf("ROM inválida\n");
            fclose(file);
            return;
        }

        size = (size_t)length;
        image = malloc(size);
        verify = malloc(size);

        if (image != NULL && verify != NULL &&
            fread(image, 1, size, file) == size) {
            if (rom_install(driver, image, size,
                            offset, verify, size) != 0)
                printf("Falha na instalação\n");
        } else {
            printf("Erro ao carregar ROM\n");
        }

        free(image);
        free(verify);
        fclose(file);
    } else {
        printf("Não foi possível abrir o arquivo\n");
    }
}
