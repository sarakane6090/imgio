#include <stdio.h>
#include "imgio.h"
#include "test.h"

void test_write_ppm_bin()
{
    image_t *img = CreateImage(640, 480, IMGIO_DEPTH_8U, 3);

    ColorBar(img);

    // PPMフォーマット(binary)で画像を保存
    ImageWrite("./out/ppm_bin.ppm", img);

    ReleaseImage(&img);
}

void test_write_ppm_ascii()
{
    image_t *img = CreateImage(640, 480, IMGIO_DEPTH_8U, 3);

    ColorBar(img);

    // PPMフォーマット(ASCII)で画像を保存
    WritePnmFile("./out/ppm_ascii.ppm", img, PNM_P3);

    ReleaseImage(&img);
}

int main(int argc, char const *argv[])
{
    test_write_ppm_bin();
    test_write_ppm_ascii();

    return 0;
}
