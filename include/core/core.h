#ifndef IMGIO_CORE_H
#define IMGIO_CORE_H

#include "core/types.h"

image_t* CreateImage(uint32_t width, uint32_t height, uint32_t depth, uint32_t channels);
void ReleaseImage(image_t** img);

#endif /* IMGIO_CORE_H */
