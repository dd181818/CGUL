//        JATTA        //
// by Joshua Brookover //

#pragma once
#include "Model.h"
#include "../External/Defines.h"

namespace Jatta
{
    class Obj : public Model
    {
        static void cleanLine(std::string* line);
        static bool getParameters(const std::string& parameters, float* data, unsigned int* size);
        static bool getParameters(const std::string& parameters);//, std::vector<std::pair<float*, unsigned int>>* data);
    public:
        Obj();

        bool load(const std::string& fileName);
    };
}

#include "../External/Undefines.h"