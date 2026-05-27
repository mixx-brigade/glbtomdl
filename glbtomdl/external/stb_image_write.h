// minimal placeholder for stb_image_write.h
#pragma once

extern "C" {
static inline int stbi_write_png_to_func(void(*)(void*, void*, int), void*, int, int, int, const void*, int) { return 1; }
static inline int stbi_write_jpg_to_func(void(*)(void*, void*, int), void*, int, int, int, const void*, int) { return 1; }
static inline int stbi_write_bmp_to_func(void(*)(void*, void*, int), void*, int, int, int, const void*) { return 1; }
}
