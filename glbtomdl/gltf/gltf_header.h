#pragma once

#include<string>
#include<vector>

#include<tiny_gltf.h>
#include<glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 uv;
};

class GLTFLoader
{
public:
	bool Load(const std::string& path);

private:
	void ProcessMeshes();
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	tinygltf::Model model;
};
