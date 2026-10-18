#include <stdio.h>
#include <SimpleOS/colors.h>


#define push_line(n, x) printf(BLUE "(%d): %s", n, x RESET)
#define nocommand(reason) printf("E: No Command\n"," Reason: %s", reason)
