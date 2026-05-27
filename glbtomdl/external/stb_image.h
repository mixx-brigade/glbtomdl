// minimal placeholder for stb_image.h
#pragma once

extern "C" {
static inline int stbi_info_from_memory(const unsigned char*, int, int*, int*, int*) { return 0; }
static inline unsigned char* stbi_load_from_memory(const unsigned char*, int, int*, int*, int*, int) { return nullptr; }
static inline void stbi_image_free(void*) {}
static inline int stbi_is_16_bit_from_memory(const unsigned char*, int) { return 0; }
static inline unsigned short* stbi_load_16_from_memory(const unsigned char*, int, int*, int*, int*, int) { return nullptr; }
}
