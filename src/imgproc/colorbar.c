#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "imgproc/imgproc.h"

void ColorBar(image_t *img)
{
    uint8_t cr, cg, cb;
    double color_step = pow(2, img->depth) / img->width;

    for (int y = 0; y < img->height; y++) {
        cr = cg = cb = 0;

        for (int x = 0; x < img->width; x++) {
            if (y < img->height / 8 * 4) {
                // 75% White
                if (x == 0) {
                    cr = 0xC0;
                    cg = 0xC0;
                    cb = 0xC0;
                }
                // 75% Yellow
                if (x == img->width / 8 * 1) {
                    cr = 0xC0;
                    cg = 0xC0;
                    cb = 0x00;
                }
                // 75% Cyan
                if (x == img->width / 8 * 2) {
                    cr = 0x00;
                    cg = 0xC0;
                    cb = 0xC0;
                }
                // 75% Green
                if (x == img->width / 8 * 3) {
                    cr = 0x00;
                    cg = 0xC0;
                    cb = 0x00;
                }
                // 75% Magenta
                if (x == img->width / 8 * 4) {
                    cr = 0xC0;
                    cg = 0x00;
                    cb = 0xC0;
                }
                // 75% Red
                if (x == img->width / 8 * 5) {
                    cr = 0xC0;
                    cg = 0x00;
                    cb = 0x00;
                }
                // 75% Blue
                if (x == img->width / 8 * 6) {
                    cr = 0x00;
                    cg = 0x00;
                    cb = 0xC0;
                }
                // Gray
                if (x == img->width / 8 * 7) {
                    cr = 0x82;
                    cg = 0x82;
                    cb = 0x82;
                }
            }
            // White lamp
            else if (y < (img->height / 8 * 5)) {
                cr = (uint8_t)(color_step * x);
                cg = (uint8_t)(color_step * x);
                cb = (uint8_t)(color_step * x);
            }
            // Red lamp
            else if (y < (img->height / 8 * 6)) {
                cr = (uint8_t)(color_step * x);
                cg = 0;
                cb = 0;
            }
            // Green lamp
            else if (y < (img->height / 8 * 7)) {
                cr = 0;
                cg = (uint8_t)(color_step * x);
                cb = 0;
            }
            // Blue lamp
            else {
                cr = 0;
                cg = 0;
                cb = (uint8_t)(color_step * x);
            }

            img->imageData[(y * img->width + x) * 3 + 0] = cb;
            img->imageData[(y * img->width + x) * 3 + 1] = cg;
            img->imageData[(y * img->width + x) * 3 + 2] = cr;
        }
    }
}

void ColorBarLamp(image_t *img)
{
    uint8_t cr, cg, cb;
    double color_step = pow(2, img->depth) / img->width;

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            cr = cg = cb = 0;

            // White
            if (y < (img->height / 4 * 1)) {
                cr = (uint8_t)(color_step * x);
                cg = (uint8_t)(color_step * x);
                cb = (uint8_t)(color_step * x);
            }
            // Red
            else if (y < (img->height / 4 * 2)) {
                cr = (uint8_t)(color_step * x);
                cg = 0;
                cb = 0;
            }
            // Green
            else if (y < (img->height / 4 * 3)) {
                cr = 0;
                cg = (uint8_t)(color_step * x);
                cb = 0;
            }
            // Blue
            else {
                cr = 0;
                cg = 0;
                cb = (uint8_t)(color_step * x);
            }

            img->imageData[(y * img->width + x) * 3 + 0] = cb;
            img->imageData[(y * img->width + x) * 3 + 1] = cg;
            img->imageData[(y * img->width + x) * 3 + 2] = cr;
        }
    }
}
