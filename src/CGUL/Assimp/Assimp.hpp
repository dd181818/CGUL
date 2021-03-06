// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Assimp.hpp
 */

#pragma once
#include <CGUL/Config.hpp>
#include "../Utility/String.hpp"
#include "../External/Defines.hpp"

namespace CGUL
{
    /** @brief Assimp wrapper.
     */
    namespace Assimp
    {
        typedef UInt32 Enum;

        static const Enum PROCESS_CALC_TANGENT_SPACE = 0x1;
        static const Enum PROCESS_JOIN_IDENTICAL_VERTICES = 0x2;
        static const Enum PROCESS_MAKE_LEFT_HANDED = 0x4;
        static const Enum PROCESS_TRIANGULATE = 0x8;
        static const Enum PROCESS_REMOVE_COMPONENT = 0x10;
        static const Enum PROCESS_GEN_NORMALS = 0x20;
        static const Enum PROCESS_GEN_SMOOTH_NORMALS = 0x40;
        static const Enum PROCESS_SPLIT_LARGE_MESH = 0x80;
        static const Enum PROCESS_PRE_TRANSFORM_VERTICES = 0x100;
        static const Enum PROCESS_LIMIT_BONE_WEIGHTS = 0x200;
        static const Enum PROCESS_VALIDATE_DATA_STRUCTURE = 0x400;
        static const Enum PROCESS_IMPROVE_CACHE_LOCALITY = 0x800;
        static const Enum PROCESS_REMOVE_REDUNDANT_MATERIALS = 0x1000;
        static const Enum PROCESS_FIX_INFACING_NORMALS = 0x2000;
        static const Enum PROCESS_SORT_BY_PTYPE = 0x8000;
        static const Enum PROCESS_FIND_DEGENERATES = 0x10000;
        static const Enum PROCESS_FIND_INVALID_DATA = 0x20000;
        static const Enum PROCESS_GEN_UV_COORDS = 0x40000;
        static const Enum PROCESS_TRANSFORM_UV_COORDS = 0x80000;
        static const Enum PROCESS_FIND_INSTANCES = 0x100000;
        static const Enum PROCESS_OPTIMIZE_MESHES = 0x200000;
        static const Enum PROCESS_OPTIMIZE_GRAPH = 0x400000;
        static const Enum PROCESS_FLIP_UVS = 0x800000;
        static const Enum PROCESS_FLIP_WINDING_ORDER = 0x1000000;
        static const Enum PROCESS_SPLIT_BY_BONE_COUNT = 0x2000000;
        static const Enum PROCESS_DEBONE = 0x4000000;

        static const Enum TEXTURE_TYPE_NONE = 0x0;
        static const Enum TEXTURE_TYPE_DIFFUSE = 0x1;
        static const Enum TEXTURE_TYPE_SPECULAR = 0x2;
        static const Enum TEXTURE_TYPE_AMBIENT = 0x3;
        static const Enum TEXTURE_TYPE_EMISSIVE = 0x4;
        static const Enum TEXTURE_TYPE_HEIGHT = 0x5;
        static const Enum TEXTURE_TYPE_NORMALS = 0x6;
        static const Enum TEXTURE_TYPE_SHININESS = 0x7;
        static const Enum TEXTURE_TYPE_OPACITY = 0x8;
        static const Enum TEXTURE_TYPE_DISPLACEMENT = 0x9;
        static const Enum TEXTURE_TYPE_LIGHTMAP = 0xa;
        static const Enum TEXTURE_TYPE_REFLECTION = 0xb;
        static const Enum TEXTURE_TYPE_UNKNOWN = 0xc;

        static const Enum CFLAGS_SHARED = 0x1;
        static const Enum CFLAGS_STLPORT = 0x2;
        static const Enum CFLAGS_DEBUG = 0x4;
        static const Enum CFLAGS_NOBOOST = 0x8;
        static const Enum CFLAGS_SINGLETHREADED = 0x10;

        _CGUL_EXPORT String GetLegalString();
        _CGUL_EXPORT UInt32 GetVersionMinor();
        _CGUL_EXPORT UInt32 GetVersionMajor();
        _CGUL_EXPORT UInt32 GetVersionRevision();
        _CGUL_EXPORT UInt32 GetCompileFlags();
    }
}

#include "../External/Undefines.hpp"
