/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "String.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Regex
    {
        String expression;
    public:
        Regex();
        Regex(String expression);

        void SetExpression(String expression);
        String GetExpression();
    };
}

#include "../External/Undefines.h"
