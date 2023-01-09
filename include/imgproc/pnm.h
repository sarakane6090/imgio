#ifndef IMGIO_PNM_H
#define IMGIO_PNM_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "core/types.h"

#define PNM_P1 1
#define PNM_P2 2
#define PNM_P3 3
#define PNM_P4 4
#define PNM_P5 5
#define PNM_P6 6

int WritePnmFile(char* filename, image_t* img, int type);

#endif /* IMGIO_PNM_H */
