#pragma once
#include <stdio.h>

#define ERROR "E: "
#define WARN "W: "
#define FATAL "F: "
#define OK "OK: "

#define LOG(a, b) printf(a "%s", b)
