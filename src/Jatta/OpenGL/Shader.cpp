/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#ifndef JATTA_NO_OPENGL
#include "Shader.h"

 #define GLCHECK(str) if (glGetError() != GL_NO_ERROR) { throw std::runtime_error(str); }

_JATTA_EXPORT Jatta::OpenGL::Shader::Shader()
{
    shader = 0;
}

_JATTA_EXPORT Jatta::OpenGL::Shader::~Shader()
{
}

/** @brief Equivalent to <a href="http://www.opengl.org/sdk/docs/man/xhtml/glCreateShader.xml">glCreateShader()</a>.
 *  @param type An enumeration type which can be OpenGL::GL::VERTEX_SHADER, OpenGL::GL::TESS_CONTROL_SHADER, OpenGL::GL::TESS_EVALUATION_SHADER, OpenGL::GL::GEOMETRY_SHADER, or GL::FRAGMENT_SHADER.
 */
_JATTA_EXPORT void Jatta::OpenGL::Shader::Create(Enum type)
{
    shader = glCreateShader((GLenum)type);
    GLCHECK("Failed to create shader.");
}

/** @brief Equivalent to <a href="http://www.opengl.org/sdk/docs/man/xhtml/glDeleteShader.xml">glDeleteShader()</a>.
 */
_JATTA_EXPORT void Jatta::OpenGL::Shader::Delete()
{
    glDeleteShader((GLuint)shader);
    GLCHECK("Failed to delete shader.");
    shader = 0;
}

_JATTA_EXPORT Jatta::UInt32 Jatta::OpenGL::Shader::GetID() const
{
    return shader;
}

_JATTA_EXPORT void Jatta::OpenGL::Shader::Source(const Jatta::String& source)
{
    const char* characters = source.GetData().c_str();
    const GLchar** data = &characters;
    GLint count = (GLint)source.GetSize();
    glShaderSource((GLuint)shader, (GLsizei)1, data, &count);
    GLCHECK("Failed to set shader source.");
}

_JATTA_EXPORT void Jatta::OpenGL::Shader::Compile()
{
    glCompileShader(shader);
    GLCHECK("Failed to compile shader.");
}

_JATTA_EXPORT Jatta::OpenGL::Enum Jatta::OpenGL::Shader::GetShaderType()
{
    // TODO: this
    return 0;
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Shader::GetDeleteStatus()
{
    GLint status;
    glGetShaderiv(shader, GL_DELETE_STATUS, &status);
    GLCHECK("Failed to get delete status of shader.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::Boolean Jatta::OpenGL::Shader::GetCompileStatus()
{
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    GLCHECK("Failed to get compile status of shader.");
    return status == GL_TRUE;
}

_JATTA_EXPORT Jatta::String Jatta::OpenGL::Shader::GetInfoLog()
{
    GLint size;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
    GLCHECK("Failed to get shader info log length.");
    GLsizei length;
    GLchar* buffer = new GLchar[size];
    glGetShaderInfoLog(shader, (GLsizei)size, &length, buffer);
    GLCHECK("Failed to get shader info log.");
    String log((char*)buffer);
    delete[] buffer;
    return log;
}

_JATTA_EXPORT Jatta::String Jatta::OpenGL::Shader::GetSource()
{
    GLint size;
    glGetShaderiv(shader, GL_SHADER_SOURCE_LENGTH, &size);
    GLCHECK("Failed to get shader source length.");
    GLsizei length;
    GLchar* buffer = new GLchar[size];
    glGetShaderSource(shader, (GLsizei)size, &length, buffer);
    GLCHECK("Failed to get shader source.");
    String source((char*)buffer);
    delete[] buffer;
    return source;
}

#endif
