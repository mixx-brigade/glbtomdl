#include"gltf_header.h"

#include<iostream>


bool GLTFLoader::Load(const std::string& path)
{
	tinygltf::TinyGLTF loader;

	std::string err;
	std::string warn;

	bool result = loader.LoadBinaryFromFile(&model, &err, &warn, path);

	if (!warn.empty()) 
	{
		std::cout << "[WARN]" << warn << std::endl;
	}

	if (!err.empty())
	{
		std::cerr << "[ERR]" << err << std::endl;
	}

	if (!result)
	{
		std::cerr << "Failed to load glTF: " << path << std::endl;
		return false;
	}

	ProcessMeshes();
	
	return true;
}

void GLTFLoader::ProcessMeshes()
{
	for (const auto& mesh : model.meshes)
	{
		auto positionIt = mesh.primitives[0].attributes.find("POSITION");
	}
}