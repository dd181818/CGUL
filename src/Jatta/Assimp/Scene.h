/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_ASSIMP
#pragma once
#include "Assimp.h"
#include "../Utility/String.h"
#include "../External/Defines.h"

/* Assimp is an experimental namespace in Jatta! */
namespace Jatta
{
    namespace Assimp
    {
        class Camera;
        class Material;
        class Mesh;
        class Texture;

        // TODO: finish importing methods from aiScene
        class Scene
        {
            const _JATTA_AISCENE scene;
        public:
            _JATTA_EXPORT Scene();

            _JATTA_EXPORT void Import(const String& fileName, Enum flags);

            _JATTA_EXPORT Boolean HasAnimations() const;
            _JATTA_EXPORT Boolean HasCameras() const;
            _JATTA_EXPORT Boolean HasLights() const;
            _JATTA_EXPORT Boolean HasMaterials() const;
            _JATTA_EXPORT Boolean HasMeshes() const;
            _JATTA_EXPORT Boolean HasTextures() const;

            _JATTA_EXPORT UInt32 GetAnimationCount() const;
            _JATTA_EXPORT UInt32 GetCameraCount() const;
            _JATTA_EXPORT UInt32 GetLightCount() const;
            _JATTA_EXPORT UInt32 GetMaterialCount() const;
            _JATTA_EXPORT UInt32 GetMeshCount() const;
            _JATTA_EXPORT UInt32 GetTextureCount() const;

            // TODO: GetLight, GetAnimation
            _JATTA_EXPORT Camera GetCamera(UInt32 index) const;
            _JATTA_EXPORT Material GetMaterial(UInt32 index) const;
            _JATTA_EXPORT Mesh GetMesh(UInt32 index) const;
            _JATTA_EXPORT Texture GetTexture(UInt32 index) const;
        };
    }
}

#include "../External/Undefines.h"
#endif