#pragma once
#include <cstdint>
#include <iostream>
#include <memory>
#include <stdexcept>

class Image {
 public:
    Image(uint16_t rows, uint16_t columns): m_rows(rows), m_columns(columns) {
        if (!IsValid()) {
            throw std::invalid_argument("Image dimensions are too large.");
        }
        pixels = std::make_unique<uint8_t[]>(rows * columns);
    }
    ~Image() {
        std::cout << "Image destroyed. Pixel memory automatically freed.\n";
    }
    bool IsValid() const {
        return m_rows <= 1024 && m_columns <= 1024;
    }
    uint8_t GetPixel(uint16_t x, uint16_t y) const {
        return pixels[x * m_columns + y];
    }
    void SetPixel(uint16_t x, uint16_t y, uint8_t value) {
        pixels[x * m_columns + y] = value;
    }
    const uint16_t m_rows;
    const uint16_t m_columns;
    std::unique_ptr<uint8_t[]> pixels;  // max 1k x 1k image
};
