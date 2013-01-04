/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#pragma once
#include "Input.h"
#include "WindowStyle.h"
#include "../Math/Float2.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Window
    {
#       ifdef WINDOWS
        _JATTA_HWND handle;
        _JATTA_DWORD style;

        char className[20];

        static long __stdcall WindowProcedure(_JATTA_HWND handle, unsigned int message, unsigned int wParam, long int lParam);
#       endif

#       ifdef LINUX
        _JATTA_DISPLAY display;
        _JATTA_WINDOW handle;

        static bool initialized;
#       endif

        Input input;

        _JATTA_EXPORT Window(const Window& copy);
        _JATTA_EXPORT Window(Window&& move);
    public:
        _JATTA_EXPORT Window();
        _JATTA_EXPORT ~Window();

#       ifdef WINDOWS
        _JATTA_EXPORT _JATTA_HWND _GetHandle();
#       endif

#       ifdef LINUX
        _JATTA_EXPORT _JATTA_DISPLAY _GetDisplay();
        _JATTA_EXPORT _JATTA_WINDOW _GetHandle();
#       endif

        _JATTA_EXPORT Input* GetInput();

        _JATTA_EXPORT void Create(const WindowStyle& style);
        _JATTA_EXPORT void Close();

        _JATTA_EXPORT void Update();

        _JATTA_EXPORT void SetTitle(String title);

        _JATTA_EXPORT bool IsOpen() const;

        _JATTA_EXPORT unsigned int GetWidth() const;
        _JATTA_EXPORT unsigned int GetHeight() const;
        _JATTA_EXPORT Float2 GetSize() const;
    };
}

#include "../External/Undefines.h"
