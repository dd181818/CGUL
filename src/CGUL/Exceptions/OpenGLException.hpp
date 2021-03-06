// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file OpenGLException.hpp
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
    namespace OpenGLExceptionCode
    {
        enum
        {
            UNKNOWN,
            FAILED_CREATE_SHADER
        };
    }
    namespace OpenGLExceptionReason
    {
        enum
        {
            UNKNOWN
        };
    }
    struct OpenGLException : public Exception
    {
        _CGUL_EXPORT OpenGLException(UInt8 code, UInt8 reason);

        _CGUL_EXPORT String GetString() const;
        _CGUL_EXPORT String GetReason() const;
    };
}

// Undefines
#include "../External/Undefines.hpp"
