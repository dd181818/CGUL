/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#if 0
#pragma once
#include "../External/Defines.h"

namespace Jatta
{
    class DNS
    {
    public:
        enum class Filter
        {
            IPV4,
            IPV6,
            ANY
        };

        DNS();
        ~DNS();

        _JATTA_EXPORT static std::vector<std::string> Lookup(const std::string& host, Filter filter = Filter::ANY);
    };
}

#include "../External/Undefines.h"
#endif