//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "../External/Defines.h"

struct VertexBuffer
{
    enum Type
    {
        POSITION, TEXCOORD, NORMAL, COLOR
    } type;
    unsigned int size;
    float* buffer;
};

#include "../External/Undefines.h"