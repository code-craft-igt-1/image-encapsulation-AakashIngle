#pragma once
#include <memory>
#include "./image.h"

int BrightenWholeImage(Image& image) {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    for (int x = 0; x < image.m_rows; x++) {
        for (int y = 0; y < image.m_columns; y++) {
            if (image.GetPixel(x, y) > (255 - 25)) {
                ++attenuatedPixelCount;
                image.SetPixel(x, y, 255);
            }
            else {
                image.SetPixel(x, y, image.GetPixel(x, y) + 25);
            }
        }
    }
    return attenuatedPixelCount;
}