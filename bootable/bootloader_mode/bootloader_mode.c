#include <stdio.h>
#include <SimpleOS/colors.h>
#include "/init/properties.def"
#include <SimpleOS/log.h>

extern void installrom(void);

void bootloadermode() {
  printf("========================================================================================================================================\n");
  printf(" **** *** *   * ****  *     *****  ***   ****    ****   ***   ***  ***** *      ***   ***  ****  ***** ****     *   *  ***  ****  ***** \n");
  printf("*      *  ** ** *   * *     *     *   * *        *   * *   * *   *   *   *     *   * *   * *   * *     *   *    ** ** *   * *   * *     \n");
  printf(" ***   *  * * * ****  *     ****  *   *  ***     ****  *   * *   *   *   *     *   * ***** *   * ****  ****     * * * *   * *   * ****  \n");
  printf("    *  *  *   * *     *     *     *   *     *    *   * *   * *   *   *   *     *   * *   * *   * *     *  *     *   * *   * *   * *     \n");
  printf("****  *** *   * *     ***** *****  ***  ****     ****   ***   ***    *   *****  ***  *   * ****  ***** *   *    *   *  ***  ****  ***** \n");
  printf("========================================================================================================================================\n");
  printf(GOLD "Bootloader Mode" RESET);
  printf(GOLD "%s/%s", MODEL, MANUFACTURER RESET);
  printf("1: boot in recovery");
  printf("2: boot in other ROM");
  int option;
  scanf("option:  %d", option); 

  if (option == 1){
    //not implemented 
  }
  else if (option == 2){
    installrom();
  }
  else {
    log_error("%d not exist"); 
  }
}
