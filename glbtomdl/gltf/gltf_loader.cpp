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
        std::cout << "[INFO] Mesh: " << mesh.name << std::endl;

        for (const auto& primitive : mesh.primitives)
        {
            auto positionIt = primitive.attributes.find("POSITION");

            if (positionIt == primitive.attributes.end())
            {
                continue;
            }

            const tinygltf::Accessor& positionAccessor =
                model.accessors[positionIt->second];

            const tinygltf::BufferView& positionView =
                model.bufferViews[positionAccessor.bufferView];

            const tinygltf::Buffer& positionBuffer =
                model.buffers[positionView.buffer];

            const float* positions = reinterpret_cast<const float*>(
                &positionBuffer.data[
                    positionView.byteOffset +
                        positionAccessor.byteOffset
                ]
                );

            size_t vertexCount = positionAccessor.count;

            std::cout << "[INFO] Vertices: "
                << vertexCount
                << std::endl;

            for (size_t i = 0; i < vertexCount; i++)
            {
                Vertex vertex;

                vertex.position.x = positions[i * 3 + 0];
                vertex.position.y = positions[i * 3 + 1];
                vertex.position.z = positions[i * 3 + 2];

                vertices.push_back(vertex);
            }

            if (primitive.indices >= 0)
            {
                const tinygltf::Accessor& indexAccessor =
                    model.accessors[primitive.indices];

                const tinygltf::BufferView& indexView =
                    model.bufferViews[indexAccessor.bufferView];

                const tinygltf::Buffer& indexBuffer =
                    model.buffers[indexView.buffer];

                const unsigned short* bufferIndices =
                    reinterpret_cast<const unsigned short*>(
                        &indexBuffer.data[
                            indexView.byteOffset +
                                indexAccessor.byteOffset
                        ]
                        );

                for (size_t i = 0; i < indexAccessor.count; i++)
                {
                    indices.push_back(bufferIndices[i]);
                }

                std::cout << "[INFO] Indices: "
                    << indexAccessor.count
                    << std::endl;
            }
        }
    }
}