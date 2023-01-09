#ifndef IMGIO_TYPES_H
#define IMGIO_TYPES_H

#include <stdint.h>

/******************************************************************************/
/* Image type */
/******************************************************************************/

#define IMGIO_DEPTH_1U  1
#define IMGIO_DEPTH_8U  8
#define IMGIO_DEPTH_16U 16

typedef struct image_t {
    uint32_t nChannels;     // チャンネル数
    uint32_t depth;         // 1画素あたりのビット数
    uint32_t width;         // 画像の幅（画素数）
    uint32_t height;        // 画像の高さ（画素数）
    uint8_t  *imageData;    // 画像データ
} image_t;

#endif /* IMGIO_TYPES_H */
