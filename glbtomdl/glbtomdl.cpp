#include <iostream>

#include "gltf/gltf_header.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: gltftomdl.exe model.glb\n";
        return 1;
    }

    GLTFLoader loader;

    if (!loader.Load(argv[1]))
    {
        std::cout << "[ERROR] Failed to load GLB\n";
        return 1;
    }

    std::cout << "[SUCCESS] Done.\n";

    return 0;
}