#include <stdio.h>
#include <SimpleOS/colors.h>

#define push_line(n, x) printf(BLUE "(%d): %s" RESET "\n", n, x)

#define nocommand(reason) printf("E: No Command\n Reason: %s\n", reason)
