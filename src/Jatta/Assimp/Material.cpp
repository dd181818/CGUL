/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#include "Material.h"

#include <iostream> // TODO: remove iostream

_JATTA_EXPORT Jatta::Assimp::Material::Material(aiMaterial* material)
{
    this->material = material;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::Assimp::Material::GetTextureCount(Enum type)
{
	material->GetTextureCount((aiTextureType)type);
}

_JATTA_EXPORT Jatta::String Jatta::Assimp::Material::GetTexturePath(Enum type, UInt32 index)
{
	aiString path;
	material->GetTexture((aiTextureType)type, index, &path);
	return String(path.C_Str());
}

#endif
