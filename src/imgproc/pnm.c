#include <stdio.h>
#include <stdlib.h>

#include "core/types.h"
#include "imgproc/pnm.h"

static int write_pnm_stream(FILE *fp, image_t *img, int type);
static int write_pnm_header(FILE *fp, image_t *img, int type);
static int write_pnm_p1(FILE *fp, image_t *img);
static int write_pnm_p2(FILE *fp, image_t *img);
static int write_pnm_p3(FILE *fp, image_t *img);
static int write_pnm_p4(FILE *fp, image_t *img);
static int write_pnm_p5(FILE *fp, image_t *img);
static int write_pnm_p6(FILE *fp, image_t *img);

int WritePnmFile(char *filename, image_t *img, int type)
{
    if (img == NULL) return 1;

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) return 1;

    write_pnm_stream(fp, img, type);

    fclose(fp);

    return 0;
}

static int write_pnm_stream(FILE *fp, image_t *img, int type)
{
    if (type == PNM_P1 || type == PNM_P4) {
        printf("[Error] It's the type that doesn't exist.\r\n");
        return 1;
    }

    write_pnm_header(fp, img, type);

    // [TODO] 異なるチャンネル数の画像を変換後出力する機能
    switch (type) {
        case PNM_P1:
            if (img->nChannels != 1) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p1(fp, img);
            break;
        case PNM_P2:
            if (img->nChannels != 1) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p2(fp, img);
            break;
        case PNM_P3:
            if (img->nChannels != 3) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p3(fp, img);
            break;
        case PNM_P4:
            if (img->nChannels != 1) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p4(fp, img);
            break;
        case PNM_P5:
            if (img->nChannels != 1) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p5(fp, img);
            break;
        case PNM_P6:
            if (img->nChannels != 3) {
                printf("Image imageData not supported.\r\n");
            }
            write_pnm_p6(fp, img);
            break;
    }

    return 0;
}

static int write_pnm_header(FILE *fp, image_t *img, int type)
{
    fprintf(fp, "P%d\n", type);
    fprintf(fp, "%u %u\n", img->width, img->height);
    if (
        type != PNM_P1 &&
        type != PNM_P4
    ) {
        fprintf(fp, "255\n");
    }

    return 0;
}

// Save image in PNM P1(PBM ASCII) format.
static int write_pnm_p1(FILE *fp, image_t *img)
{
    // [TODO]
    return 0;
}

// Save image in PNM P2(PGM ASCII) format.
static int write_pnm_p2(FILE *fp, image_t *img)
{
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            fprintf(fp, "%u\n", img->imageData[(img->width * y + x)]);
        }
    }

    return 0;
}

// Save image in PNM P3(PPM ASCII) format.
static int write_pnm_p3(FILE *fp, image_t *img)
{
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            fprintf(fp, "%u %u %u\n",
                img->imageData[(img->width * y + x) * 3 + 2], // Red
                img->imageData[(img->width * y + x) * 3 + 1], // Green
                img->imageData[(img->width * y + x) * 3 + 0]  // Blue
            );
        }
    }

    return 0;
}

// Save image in PNM P4(PBM binary) format.
static int write_pnm_p4(FILE *fp, image_t *img)
{
    // [TODO]
    return 0;
}

// Save image in PNM P5(PGM binary) format.
static int write_pnm_p5(FILE *fp, image_t *img)
{
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            putc(img->imageData[(img->width * y + x)], fp);
        }
    }

    return 0;
}

// Save image in PNM P6(PPM binary) format.
static int write_pnm_p6(FILE *fp, image_t *img)
{
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            putc(img->imageData[(img->width * y + x) * 3 + 2], fp); // Red
            putc(img->imageData[(img->width * y + x) * 3 + 1], fp); // Green
            putc(img->imageData[(img->width * y + x) * 3 + 0], fp); // Blue
        }
    }

    return 0;
}
