#ifndef IMGIO_IMGPROC_H
#define IMGIO_IMGPROC_H

#include "core/core.h"
#include "core/utils.h"

#include "imgproc/pnm.h"

void ImageRead(char* filename, image_t* img);
void ImageWrite(char* filename, image_t* img);

void ColorBar(image_t *img);
void ColorBarLamp(image_t *img);

#endif /* IMGIO_IMGPROC_H */
