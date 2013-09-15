/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#include "ImageException.h"

Jatta::ImageException::ImageException(UInt8 code, UInt8 reason) : Exception(code, reason, ExceptionType::IMAGE)
{
}

Jatta::String Jatta::ImageException::GetString() const
{
    switch (code)
    {
        case ImageExceptionCode::GENERATE_MIPMAPS:
        return U8("Failed to generate mipmaps.");
        case ImageExceptionCode::GET_MIPMAP:
        return U8("Failed to get mipmap.");
        case ImageExceptionCode::BMP:
        return U8("Failed to load BMP file.");
        case ImageExceptionCode::UNKNOWN:
        default:
        return U8("Unknown error occurred.");
    }
}

Jatta::String Jatta::ImageException::GetReason() const
{
    switch (reason)
    {
        case ImageExceptionReason::IMAGE_IS_NOT_VALID:
        return U8("Image is invalid/not loaded.");
        case ImageExceptionReason::NO_BASE_MIPMAP:
        return U8("No base mipmap found.");
        case ImageExceptionReason::INDEX_OUT_OF_RANGE:
        return U8("Index is out of range.");
        case ImageExceptionReason::INVALID_DATA_FORMAT:
        return U8("Data is in an invalid format."); 
        case ImageExceptionReason::INVALID_COLOR_PLANE_COUNT:
        return U8("Invalid number of color planes being used. (Must be one)");
        case ImageExceptionReason::NOT_A_BMP_FILE:
        return U8("File is not a BMP file.");
        case ImageExceptionReason::UNKNOWN:
        default:
        return U8("Unknown.");
    }
}
