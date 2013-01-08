/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "Mesh.h"

_JATTA_EXPORT Jatta::Mesh Jatta::Mesh::MakeBox(Float2 size, Color color, Float2 uv1, Float2 uv2, Float2 uv3, Float2 uv4)
{
	return MakeBox(size, color, color, color, color, uv1, uv2, uv3, uv4);
}
_JATTA_EXPORT Jatta::Mesh Jatta::Mesh::MakeBox(Float2 size, Color color1, Color color2, Color color3, Color color4, Float2 uv1, Float2 uv2, Float2 uv3, Float2 uv4)
{
	Float2 vertices[] = {
	    Float2(-size.x, -size.y),
	    Float2(size.x, -size.y),
	    Float2(size.x, size.y),
	    Float2(-size.x, size.y)
	};

	Color colors[] = {
		color1, color2, color3, color4
	};

	Float2 uvs[] = {
			uv1, uv2, uv3, uv4
	};

	UInt32 elements[] = {
			0, 1, 2,
			2, 3, 0
	};

	SubMesh*mesh = new SubMesh();
	mesh->Setup(SubMesh::Type::TRIANGLES, 4);
	mesh->SetIndexBuffer(elements, 6);
	mesh->AddBuffer(vertices, Graphics::position1);
	mesh->AddBuffer(colors, Graphics::color1);
	mesh->AddBuffer(uvs, Graphics::texCoord1);

	Mesh ret;
	ret.AddMesh(mesh);
	return ret;
}

_JATTA_EXPORT Jatta::Mesh Jatta::Mesh::MakeCube(Float3 size)
{
	// Create the box mesh
	Float3 boxPositions[] = {
			Float3(size.x, -size.y, -size.z), Float3(size.x, size.y, -size.z), Float3(size.x, -size.y, size.z),
			Float3(size.x, size.y, size.z), Float3(size.x, -size.y, size.z), Float3(size.x, size.y, -size.z),
			Float3(-size.x, -size.y, -size.z), Float3(-size.x, -size.y, size.z), Float3(-size.x, size.y, -size.z),
			Float3(-size.x, size.y, size.z), Float3(-size.x, size.y, -size.z), Float3(-size.x, -size.y, size.z),
			Float3(-size.x, -size.y, size.z), Float3(size.x, -size.y, size.z), Float3(-size.x, size.y, size.z),
			Float3(size.x, size.y, size.z), Float3(-size.x, size.y, size.z), Float3(size.x, -size.y, size.z),
			Float3(-size.x, -size.y, -size.z), Float3(-size.x, size.y, -size.z), Float3(size.x, -size.y, -size.z),
			Float3(size.x, size.y, -size.z), Float3(size.x, -size.y, -size.z), Float3(-size.x, size.y, -size.z),
			Float3(-size.x, -size.y, -size.z), Float3(size.x, -size.y, -size.z), Float3(-size.x, -size.y, size.z),
			Float3(size.x, -size.y, size.z), Float3(-size.x, -size.y, size.z), Float3(size.x, -size.y, -size.z),
			Float3(-size.x, size.y, -size.z), Float3(-size.x, size.y, size.z), Float3(size.x, size.y, -size.z),
			Float3(size.x, size.y, size.z), Float3(size.x, size.y, -size.z), Float3(-size.x, size.y, size.z)
	};
	Float2 boxTexCoords[] = {
			Float2(1, 1), Float2(1, 0), Float2(0, 1),
			Float2(0, 0), Float2(0, 1), Float2(1, 0),
			Float2(1, 1), Float2(0, 1), Float2(1, 0),
			Float2(0, 0), Float2(1, 0), Float2(0, 1),
			Float2(1, 1), Float2(1, 0), Float2(0, 1),
			Float2(0, 0), Float2(0, 1), Float2(1, 0),
			Float2(1, 1), Float2(0, 1), Float2(1, 0),
			Float2(0, 0), Float2(1, 0), Float2(0, 1),
			Float2(1, 1), Float2(1, 0), Float2(0, 1),
			Float2(0, 0), Float2(0, 1), Float2(1, 0),
			Float2(1, 1), Float2(0, 1), Float2(1, 0),
			Float2(0, 0), Float2(1, 0), Float2(0, 1)
	};

	SubMesh*mesh = new SubMesh();
	mesh->Setup(SubMesh::Type::TRIANGLES, 36);
	mesh->AddBuffer(boxPositions, Graphics::position1);
	mesh->AddBuffer(boxTexCoords, Graphics::texCoord1);

	Mesh ret;
	ret.AddMesh(mesh);
	return ret;
}

_JATTA_EXPORT Jatta::Mesh Jatta::Mesh::MakeTeapot(Float3 size, Color color)
{
	//TODO: Make teapot...

	return MakeCube(Float3(1));
}

_JATTA_EXPORT Jatta::Mesh::Mesh()
{
	meshes.clear();
}

#include <fstream> // TODO: remove fstream
_JATTA_EXPORT void Jatta::Mesh::Create(const Model& model)
{
	std::ofstream file;
	file.open("test.txt");
	for (UInt32 i = 0; i < model.GetGroupCount(); i++)
	{
		Group group = model.GetGroup(i);
		file << group.name << std::endl;
		SubMesh* mesh = new SubMesh();
		mesh->Setup(SubMesh::Type::TRIANGLES, group.vertexCount);
		for (UInt32 j = 0; j < 16; j++)
		{
			VertexBuffer buffer = group.GetBuffer(j);
			if (buffer.index != -1)
			{
				file << "---" << j << "---" << std::endl;
				for (UInt32 k = 0; k < group.vertexCount * 3; k++)
				{
					file << ((float*)buffer.buffer)[k] << std::endl;
				}
				mesh->AddBuffer((float*)buffer.buffer, buffer.size, buffer.index);
			}
		}
		AddMesh(mesh);
	}
	file.close();
}

_JATTA_EXPORT void Jatta::Mesh::AddMesh(SubMesh*mesh)
{
	meshes.push_back(mesh);
}

_JATTA_EXPORT void Jatta::Mesh::Draw()
{
	for (auto i = meshes.begin(); i != meshes.end(); i++)
	{
		(*i)->Draw();
	}
}