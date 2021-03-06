// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file ImageException.hpp
 */

#pragma once

// Configuration
#include <CGUL/Config.hpp>

// CGUL Includes
#include "../Exceptions/Exception.hpp"

// Defines
#include "../External/Defines.hpp"

namespace CGUL
{
    namespace ImageExceptionCode
    {
        enum
        {
            UNKNOWN,
            MIX_IMAGES,
            TRANSFORM,
            BMP,
            PNG,
            JPEG,
            BMP_WRITE,
            PNG_WRITE,
            JPEG_WRITE,
            PPM,
            PPM_WRITE,
            PPM_READ
        };
    }
    namespace ImageExceptionReason
    {
        enum
        {
            UNKNOWN,
            IMAGE_IS_NOT_VALID,
            NO_BASE_MIPMAP,
            INDEX_OUT_OF_RANGE,
            INVALID_DATA_FORMAT,
            INVALID_COLOR_PLANE_COUNT,
            NOT_A_BMP_FILE,
            UNSUPPORTED_FORMAT,
            NOT_A_PNG_FILE,
            PNG_CREATE_READ_STRUCT_FAILED,
            PNG_CREATE_INFO_STRUCT_FAILED,
            PNG_INIT_IO_ERROR,
            FAILED_TO_OPEN,
            PNG_READ_IMAGE_ERROR,
            NOT_A_JPEG_FILE,
            JPEG_FAILED_TO_START_DECOMPRESSOR,
            NULL_POINTER,
            FAILED_WRITE_HEADER,
            FAILED_WRITE_IMAGE,
            INVALID_MIXING_METHOD
        };
    }
    struct ImageException : public Exception
    {
        _CGUL_EXPORT ImageException(UInt8 code, UInt8 reason);

        _CGUL_EXPORT String GetString() const;
        _CGUL_EXPORT String GetReason() const;
    };
}

// Undefines
#include "../External/Undefines.hpp"
