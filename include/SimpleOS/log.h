#ifndef SIMPLEOS_LOG_H
#define SIMPLEOS_LOG_H

#include <stdio.h>
#include <SimpleOS/colors.h>



#define log_error(x) \
printf(RED "[ ERROR ]" RESET " %s", x)
#define log_warning(x) \
printf(GOLD "[ WARNING ]" RESET " %s", x)
#define log_kernel(x) \
printf(BLUE "[ KERNEL ]" RESET " %s", x)
#define log(x) \
printf(GREEN "[ I/O ] RESET "%s", x)

#endif
