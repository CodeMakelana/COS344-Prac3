#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <cmath>
#include <cstring>

// ---------------------------------------------------------------------------
// Degrees -> Radians helper
// ---------------------------------------------------------------------------
inline float toRad(float deg) {
    return deg * (3.14159265358979323846f / 180.0f);
}

// ---------------------------------------------------------------------------
// Vector3
// ---------------------------------------------------------------------------
struct Vector3 {
    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

// Vector3 operations
float   dot(const Vector3& a, const Vector3& b);
float   length(const Vector3& v);
Vector3 normalize(const Vector3& v);
Vector3 cross(const Vector3& a, const Vector3& b);
Vector3 add(const Vector3& a, const Vector3& b);
Vector3 subtract(const Vector3& a, const Vector3& b);
Vector3 scale(const Vector3& v, float s);

// ---------------------------------------------------------------------------
// Matrix4  (row-major storage)
//
//   m[row][col]
//
//   Upload to OpenGL with:  glUniformMatrix4fv(loc, 1, GL_TRUE, &mat.m[0][0]);
//   GL_TRUE tells the driver to transpose from our row-major layout into
//   OpenGL's expected column-major order.
// ---------------------------------------------------------------------------
struct Matrix4 {
    float m[4][4];

    // Default constructor: zero-initialise ALL 16 entries.
    // This is critical -- many matrices (perspective, rotations) rely on
    // un-set entries being exactly 0.
    Matrix4() { memset(m, 0, sizeof(m)); }
};

// Matrix4 construction helpers
Matrix4 identity();
Matrix4 multiply(const Matrix4& A, const Matrix4& B);

// Affine transforms (all angles in DEGREES)
Matrix4 translate(float tx, float ty, float tz);
Matrix4 scaleMatrix(float sx, float sy, float sz);
Matrix4 rotateX(float deg);
Matrix4 rotateY(float deg);
Matrix4 rotateZ(float deg);
Matrix4 rotateArbitraryAxis(const Vector3& axis, float deg);

// Projection & view
Matrix4 perspective(float fovDeg, float aspect, float near, float far);
Matrix4 lookAt(const Vector3& eye, const Vector3& center, const Vector3& up);

#endif // MATHUTILS_H