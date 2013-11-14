/* Jatta - General Utility Library
 * Copyright (C) 2012-2013, Joshua Brookover and Amber Thrall
 * All rights reserved.
 */

#pragma once
#include <Jatta/Config.h>
#include "../External/Defines.h"

namespace Jatta
{
    template< typename Type >
    struct Vector2T;
    template< typename Type >
    struct Vector3T;
    template< typename Type >
    struct QuaternionT;

    /** @brief A 4v4 matrix.
     *  @details At the moment the 4x4 matrix is the only matrix supported.  Variable sized
     *  matrices are not ideal for most applications and other NxN matrices can be mimicked with a
     *  4x4 matrix by setting the other elements to that of the identity matrix.
     *  @see Jatta::Matrix
     *  @see Jatta::MatrixD
     */
    template< typename Type >
    struct MatrixT
    {
        // Matrix stored in memory as:
        // +--         --+
        // | 00 04 08 12 |
        // | 01 05 09 13 |
        // | 02 06 10 14 |
        // | 03 07 11 15 |
        // +--         --+
        //
        // 2D matrix mapping (column, row):
        // +--                   --+
        // | 0,0   1,0   2,0   3,0 |
        // | 0,1   1,1   2,1   3,1 |
        // | 0,2   1,2   2,2   3,2 |
        // | 0,3   1,3   2,3   3,3 |
        // +--                   --+
        union
        {
            //! @brief Direct access to a two dimensional array containing the matrix.
            Type m[4][4];
            //! @brief Direct access to the internal values as a single array.
            Type data[16];
        };

        //! @brief The identity matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > Identity();

        //! @brief Creates a 2D rotation matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotation(Type angle);
        //! @brief Creates a 3D rotation matrix, rotating around the X axis.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationX(Type angle);
        //! @brief Creats a 3D rotation matrix, rotating around the Y axis.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationY(Type angle);
        //! @brief Creates a 3D rotation matrix, rotating around the Z axis.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotationZ(Type angle);
        //! @brief Creates a 3D rotation matrix converted from a quaternion.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeRotation(const QuaternionT< Type >& quaternion);
        //! @brief Creates a 2D scaling matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeScaling(const Vector2T< Type >& scale);
        //! @brief Creates a 3D scaling matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeScaling(const Vector3T< Type >& scale);
        //! @brief Creates a 2D translation matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeTranslation(const Vector2T< Type >& translation);
        //! @brief Creates a 3D translation matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeTranslation(const Vector3T< Type >& translation);

        //! @brief Creates a 3D perspective (projection) matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakePerspective(Type fovY, Type aspectRatio, Type zNear, Type zFar);
        //! @brief Creates a 3D look at (view) matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeLookAt(const Vector3T< Type >& eye, const Vector3T< Type >& at, const Vector3T< Type >& up);
        //! @brief Creates a 3D ortho (projection) matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeOrtho(Type left, Type right, Type bottom, Type top, Type zNear, Type nFar);
        //! @brief Creates a 2D ortho (projection) matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > MakeOrtho2D(Type left, Type right, Type bottom, Type top);

        //! @brief Calculates the inverse of a matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > Inverse(const MatrixT& matrix);
        //! @brief Gets the transpose of a matrix.
        _JATTA_INLINE_DEFINE static MatrixT< Type > Transpose(const MatrixT& matrix);

        //! @brief Default constructor, creates an identity matrix.
        _JATTA_INLINE_DEFINE MatrixT();
        //! @brief Copies another matrix.
        _JATTA_INLINE_DEFINE MatrixT(const MatrixT& copy);
#       ifdef CPP_HAS_MOVE_CONSTRUCTOR
        //! @brief Moves another matrix.
        _JATTA_INLINE_DEFINE MatrixT(MatrixT&& move);
#       endif
        //! @brief Constructs a matrix given 2x2 values.
        _JATTA_INLINE_DEFINE MatrixT(Type m00, Type m10, Type m01, Type m11);
        //! @brief Constructs a matrix given 3x3 values.
        _JATTA_INLINE_DEFINE MatrixT(Type m00, Type m10, Type m20, Type m01, Type m11, Type m21, Type m02, Type m12, Type m22);
        //! @brief Constructs a matrix given 4x4 values.
        _JATTA_INLINE_DEFINE MatrixT(Type m00, Type m10, Type m20, Type m30, Type m01, Type m11, Type m21, Type m31, Type m02, Type m12, Type m22, Type m32, Type m03, Type m13, Type m23, Type m33);
        //! @brief Constructs a matrix into a rotation matrix given a quaternion.
        _JATTA_INLINE_DEFINE MatrixT(const QuaternionT< Type >& quaternion);
        _JATTA_INLINE_DEFINE ~MatrixT();

        _JATTA_INLINE_DEFINE MatrixT& operator=(const MatrixT& operand);
        _JATTA_INLINE_DEFINE MatrixT& operator=(const QuaternionT< Type >& operand);
        _JATTA_INLINE_DEFINE Type* operator[](UInt32 index);
        _JATTA_INLINE_DEFINE const Type* operator[](UInt32 index) const;
        _JATTA_INLINE_DEFINE bool operator==(const MatrixT& operand);
        _JATTA_INLINE_DEFINE bool operator!=(const MatrixT& operand);
        _JATTA_INLINE_DEFINE MatrixT operator*(const MatrixT& operand) const;
        _JATTA_INLINE_DEFINE MatrixT operator*(Type operand) const;
        _JATTA_INLINE_DEFINE MatrixT& operator*=(Type operand);
        _JATTA_INLINE_DEFINE MatrixT& operator/=(Type operand);
        friend std::ostream& operator<<(std::ostream& stream, const MatrixT& matrix)
        {
            stream << "[" << matrix.data[0] << ", " << matrix.data[4] << ", " << matrix.data[ 8] << ", " << matrix.data[12] << "]" << std::endl;
            stream << "|" << matrix.data[1] << ", " << matrix.data[5] << ", " << matrix.data[ 9] << ", " << matrix.data[13] << "|" << std::endl;
            stream << "|" << matrix.data[2] << ", " << matrix.data[6] << ", " << matrix.data[10] << ", " << matrix.data[14] << "|" << std::endl;
            stream << "[" << matrix.data[3] << ", " << matrix.data[7] << ", " << matrix.data[11] << ", " << matrix.data[15] << "]";
            return stream;
        }

        _JATTA_INLINE_DEFINE void Set(Type m11, Type m12, Type m21, Type m22);
        _JATTA_INLINE_DEFINE void Set(Type m11, Type m12, Type m13, Type m21, Type m22, Type m23, Type m31, Type m32, Type m33);
        _JATTA_INLINE_DEFINE void Set(Type m11, Type m12, Type m13, Type m14, Type m21, Type m22, Type m23, Type m24, Type m31, Type m32, Type m33, Type m34, Type m41, Type m42, Type m43, Type m44);

        //! @brief Gets the raw data from the matrix as a Type pointer.
        _JATTA_INLINE_DEFINE Type* GetData() const;

        _JATTA_INLINE_DEFINE void Invert();
        _JATTA_INLINE_DEFINE void Transpose();

        _JATTA_INLINE_DEFINE MatrixT< Type > GetInverse() const;
        _JATTA_INLINE_DEFINE MatrixT< Type > GetTranspose() const;

        _JATTA_INLINE_DEFINE Type GetDeterminant() const;

        _JATTA_INLINE_DEFINE bool IsReflexive() const;
        _JATTA_INLINE_DEFINE bool IsSymmetric() const;
        _JATTA_INLINE_DEFINE bool IsAntisymmetric() const;

        // TODO: finish the matrix class, we're missing some important functionality here
    };

    /** @brief A 4x4 matrix with 32 bit float data types.
     */
    typedef MatrixT<Float32> Matrix;
    /** @brief A 4x4 matrix with 64 bit float data types.
     */
    typedef MatrixT<Float64> MatrixD;
}

#include "../External/Undefines.h"
#include "Matrix.ipp"
