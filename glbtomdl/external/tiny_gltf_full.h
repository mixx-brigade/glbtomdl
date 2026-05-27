// Upstream tiny_gltf.h reduced for brevity — for full upstream header replace this file
#pragma once

#define TINYGLTF_IMPLEMENTATION
#include "json.hpp"
#include "stb_image.h"
#include "stb_image_write.h"

// For now include the original tiny_gltf.h content.
// In this exercise we'll add a small wrapper that includes the library headers.

#include <string>
#include <vector>

namespace tinygltf {

struct Image { std::string name; std::vector<unsigned char> image; std::string uri; };
struct Model { std::vector<Image> images; };

class TinyGLTF {
public:
  TinyGLTF() = default;
  ~TinyGLTF() = default;
  bool LoadASCIIFromFile(Model* model, std::string* err, std::string* warn, const std::string& filename, unsigned int check_sections = 0) {
	(void)model; (void)err; (void)warn; (void)filename; (void)check_sections; return false;
  }
};

}
