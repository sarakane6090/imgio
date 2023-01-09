#include <stdio.h>
#include <stdlib.h>
#include "core/core.h"

// ヘッダの作成とデータ領域の確保
image_t* CreateImage(uint32_t width, uint32_t height, uint32_t depth, uint32_t channels)
{
    image_t *img = 0;

    if ((img = (image_t*)calloc(1, sizeof(image_t))) == NULL) {
        return NULL;
    }

    img->depth      = depth;
    img->width      = width;
    img->height     = height;
    img->nChannels  = channels;

    img->imageData
        = (uint8_t *)malloc(img->width * img->height * img->nChannels);

    return img;
}

// ヘッダと画像データを解放する
void ReleaseImage(image_t** img)
{
    image_t* img_tmp = *img;
    uint8_t* imgdat = img_tmp->imageData;
    *img = 0;

    free(imgdat);
    free(*img);
}
