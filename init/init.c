/* PT-BR: EXECUTE ESSE ARQUIVO PRA O PROCESSO INIT
   EN-US: Execute this file for the init process. 
*/
#include <stdio.h> /* printf();, scanf(); */
#include <stdlib.h> /* system(); */
void __init__() {
   printf("[      SimpleOS      ]");
   printf("[                    ]");
   printf("[                    ]");
   printf("[        [OK]        ]");
   printf("[                    ]");
   printf("[(1): shell.         ]");
   printf("[(2): login.         ]");
   int opc;
   scanf("option: %d", &opc);
}
if (opc == 1) {
   system("clang shell.c -o shell && /shell");
}
if (opc == 2) {
   char[256] name;
   int password;
   scanf("name: %s", name);
   scanf("password: %d", password);
}
