// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Loader.cpp
 */

#include "Loader.hpp"
#include "../Exceptions/ImageException.hpp"

_CGUL_EXPORT CGUL::ImageLoader::ImageLoader()
{
}

_CGUL_EXPORT CGUL::ImageLoader::ImageLoader(const String& name, const String& extension)
{
    this->name = name;
    this->extension = extension;
}

_CGUL_EXPORT CGUL::ImageLoader::~ImageLoader()
{

}

_CGUL_EXPORT CGUL::String CGUL::ImageLoader::GetName()
{
    return this->name;
}

_CGUL_EXPORT CGUL::String CGUL::ImageLoader::GetExtension()
{
    return this->extension;
}
