#include <string.h>

#include "imgproc/imgproc.h"

// 画像ファイルの保存
void ImageWrite(char *filename, image_t *img)
{
    char format[4];

    DecodeFileExtensions(filename, format);

    // PPM(PNM P6)フォーマットで画像ファイルを保存
    if (strcmp(format, ".ppm")) {
        WritePnmFile(filename, img, PNM_P6);
    }
}
