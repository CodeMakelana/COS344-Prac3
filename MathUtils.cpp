#include "MathUtils.h"

// ===========================================================================
//  Vector3 implementation
// ===========================================================================

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// ----- Getters -----
float Vector3::getX() const { return x; }
float Vector3::getY() const { return y; }
float Vector3::getZ() const { return z; }

// ----- Setters -----
void Vector3::setX(float x) { this->x = x; }
void Vector3::setY(float y) { this->y = y; }
void Vector3::setZ(float z) { this->z = z; }

// ----- Member operations -----

float Vector3::dot(const Vector3& other) const {
    // TODO: return the dot product  x*other.x + y*other.y + z*other.z
    return 0.0f;
}

float Vector3::length() const {
    // TODO: return sqrt(x*x + y*y + z*z)
    return 0.0f;
}

Vector3 Vector3::normalize() const {
    // TODO: compute len = this->length().
    //       If len is ~0, return Vector3(0,0,0) to avoid division by zero.
    //       Otherwise return Vector3(x/len, y/len, z/len).
    return Vector3();
}

Vector3 Vector3::cross(const Vector3& other) const {
    // TODO: return the cross product this x other
    //   result.x = y * other.z - z * other.y
    //   result.y = z * other.x - x * other.z
    //   result.z = x * other.y - y * other.x
    return Vector3();
}

Vector3 Vector3::add(const Vector3& other) const {
    // TODO: return Vector3(x + other.x, y + other.y, z + other.z)
    return Vector3();
}

Vector3 Vector3::subtract(const Vector3& other) const {
    // TODO: return Vector3(x - other.x, y - other.y, z - other.z)
    return Vector3();
}

Vector3 Vector3::scale(float s) const {
    // TODO: return Vector3(x * s, y * s, z * s)
    return Vector3();
}

// ===========================================================================
//  Matrix4 implementation
// ===========================================================================

Matrix4::Matrix4() {
    // Zero-initialise all 16 entries
    memset(m, 0, sizeof(m));
}

const float* Matrix4::getData() const {
    // Returns pointer to m[0][0]; the 16 floats are contiguous in row-major
    // order.  Pass to OpenGL with GL_TRUE to have the driver transpose.
    return &m[0][0];
}

float Matrix4::get(int row, int col) const {
    return m[row][col];
}

void Matrix4::set(int row, int col, float value) {
    m[row][col] = value;
}

// ---------------------------------------------------------------------------
//  multiply:  returns this * other
// ---------------------------------------------------------------------------
Matrix4 Matrix4::multiply(const Matrix4& other) const {
    // TODO: Standard 4x4 matrix multiplication.
    //   result.m[i][j] = sum over k of (this->m[i][k] * other.m[k][j])
    //   for i in 0..3, j in 0..3, k in 0..3.
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  identity
// ---------------------------------------------------------------------------
Matrix4 Matrix4::identity() {
    // TODO: Create a Matrix4 and set m[0][0]=m[1][1]=m[2][2]=m[3][3]=1.
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  translate(tx, ty, tz)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::translate(float tx, float ty, float tz) {
    // TODO: Start from identity, then set:
    //   m[0][3] = tx
    //   m[1][3] = ty
    //   m[2][3] = tz
    //
    //   [ 1  0  0  tx ]
    //   [ 0  1  0  ty ]
    //   [ 0  0  1  tz ]
    //   [ 0  0  0   1 ]
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  scaleMatrix(sx, sy, sz)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::scaleMatrix(float sx, float sy, float sz) {
    // TODO: Start from zero matrix, then set:
    //   m[0][0] = sx
    //   m[1][1] = sy
    //   m[2][2] = sz
    //   m[3][3] = 1
    //
    //   [ sx  0   0  0 ]
    //   [  0  sy  0  0 ]
    //   [  0  0  sz  0 ]
    //   [  0  0   0  1 ]
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  rotateX(deg)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::rotateX(float deg) {
    // TODO: Convert deg to radians using toRad(deg).
    //   float c = cos(rad), s = sin(rad);
    //   Start from identity, then set:
    //     m[1][1] =  c;   m[1][2] = -s;
    //     m[2][1] =  s;   m[2][2] =  c;
    //
    //   [ 1   0    0   0 ]
    //   [ 0   c   -s   0 ]
    //   [ 0   s    c   0 ]
    //   [ 0   0    0   1 ]
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  rotateY(deg)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::rotateY(float deg) {
    // TODO: Convert deg to radians.
    //   float c = cos(rad), s = sin(rad);
    //   Start from identity, then set:
    //     m[0][0] =  c;   m[0][2] =  s;
    //     m[2][0] = -s;   m[2][2] =  c;
    //
    //   [  c  0   s  0 ]
    //   [  0  1   0  0 ]
    //   [ -s  0   c  0 ]
    //   [  0  0   0  1 ]
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  rotateZ(deg)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::rotateZ(float deg) {
    // TODO: Convert deg to radians.
    //   float c = cos(rad), s = sin(rad);
    //   Start from identity, then set:
    //     m[0][0] =  c;   m[0][1] = -s;
    //     m[1][0] =  s;   m[1][1] =  c;
    //
    //   [ c  -s   0  0 ]
    //   [ s   c   0  0 ]
    //   [ 0   0   1  0 ]
    //   [ 0   0   0  1 ]
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  rotateArbitraryAxis (through the origin)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::rotateArbitraryAxis(const Vector3& axisDir, float deg) {
    // TODO: Rotation around an arbitrary axis that passes through the origin.
    //
    //   1. Normalize axisDir -> u = (ux, uy, uz).
    //
    //   2. Compute alignment angles:
    //        theta_x = atan2(uy, uz)
    //          -- This is the angle to rotate the axis into the XZ plane
    //             by rotating around the X axis.
    //
    //        d = sqrt(uy*uy + uz*uz)
    //        theta_y = atan2(ux, d)
    //          -- After Rx(theta_x), the axis lies in the XZ plane.
    //             This angle rotates it onto the +Z axis via Ry.
    //          -- NOTE the sign: we need Ry(-theta_y) to bring the axis
    //             FROM its XZ-plane direction ONTO +Z, so theta_y as
    //             computed here will be negated when building the Ry step.
    //
    //   3. Build the decomposition:
    //        R = Rx(-theta_x) * Ry(-theta_y) * Rz(deg) * Ry(theta_y) * Rx(theta_x)
    //
    //      Reading right-to-left (the order transformations are applied):
    //        a) Rx(theta_x):     rotate axis into XZ plane
    //        b) Ry(theta_y):     rotate axis onto +Z    (see sign note above)
    //        c) Rz(deg):         perform the actual rotation
    //        d) Ry(-theta_y):    undo step b
    //        e) Rx(-theta_x):    undo step a
    //
    //   4. Multiply the five matrices together using this->multiply()
    //      (or call the static/member multiply). Return the result.
    //
    //   IMPORTANT: Convert theta_x and theta_y to degrees before passing
    //   them to rotateX / rotateY, since those functions expect degrees.
    //   Use:  float theta_x_deg = theta_x * (180.0f / 3.14159265358979323846f);

    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  rotateArbitraryAxis (around axis through point P0)
// ---------------------------------------------------------------------------
Matrix4 Matrix4::rotateArbitraryAxis(const Vector3& axisPoint,
                                     const Vector3& axisDir,
                                     float deg) {
    // TODO: Rotation around an arbitrary axis defined by point P0 and direction.
    //
    //   Full decomposition:
    //     R = T(P0) * Rx(-theta_x) * Ry(-theta_y) * Rz(deg)
    //              * Ry(theta_y) * Rx(theta_x) * T(-P0)
    //
    //   Steps:
    //     1. Build T(-P0) = translate(-P0.x, -P0.y, -P0.z)
    //     2. Build Rx(theta_x) with theta_x = atan2(uy, uz)  (in degrees)
    //     3. Build Ry(theta_y) with theta_y = atan2(ux, d)   (in degrees)
    //        where d = sqrt(uy^2 + uz^2) and u = normalize(axisDir)
    //     4. Build Rz(deg)
    //     5. Build Ry(-theta_y)
    //     6. Build Rx(-theta_x)
    //     7. Build T(P0) = translate(P0.x, P0.y, P0.z)
    //
    //   Multiply all seven matrices right-to-left:
    //     result = T(P0) * Rx(-theta_x) * Ry(-theta_y) * Rz(deg)
    //                     * Ry(theta_y) * Rx(theta_x) * T(-P0)
    //
    //   Tip: chain the multiplications one at a time:
    //     Matrix4 temp = Rx_theta_x.multiply(T_neg_P0);
    //     temp = Ry_theta_y.multiply(temp);
    //     temp = Rz_deg.multiply(temp);
    //     temp = Ry_neg_theta_y.multiply(temp);
    //     temp = Rx_neg_theta_x.multiply(temp);
    //     result = T_P0.multiply(temp);

    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  perspective
// ---------------------------------------------------------------------------
Matrix4 Matrix4::perspective(float fovDeg, float aspect,
                             float near, float far) {
    // TODO: Symmetric perspective projection matrix.
    //
    //   float fovRad = toRad(fovDeg);
    //   float t = tan(fovRad / 2.0f);   // half-angle tangent
    //
    //   m[0][0] = 1.0f / (aspect * t);
    //   m[1][1] = 1.0f / t;
    //   m[2][2] = -(far + near) / (far - near);
    //   m[2][3] = -(2.0f * far * near) / (far - near);
    //   m[3][2] = -1.0f;
    //   m[3][3] =  0.0f;   (already 0 from default ctor)
    //
    //   All other entries remain 0.
    Matrix4 result;
    return result;
}

// ---------------------------------------------------------------------------
//  lookAt
// ---------------------------------------------------------------------------
Matrix4 Matrix4::lookAt(const Vector3& eye, const Vector3& center,
                        const Vector3& up) {
    // TODO: Construct the view matrix.
    //
    //   1. Compute forward direction: f = normalize(center - eye)
    //      (use center.subtract(eye).normalize())
    //
    //   2. Compute right direction:   r = normalize(f x up)
    //      (use f.cross(up).normalize())
    //
    //   3. Compute true up direction: u = r x f
    //      (use r.cross(f))
    //
    //   4. Build the matrix (row-major):
    //        [  r.x    r.y    r.z   -r.dot(eye) ]
    //        [  u.x    u.y    u.z   -u.dot(eye) ]
    //        [ -f.x   -f.y   -f.z    f.dot(eye) ]
    //        [   0      0      0        1        ]
    //
    //   Note: the third row uses -f because OpenGL looks down -Z.
    //   The translation column is the dot of each basis vector with -eye.
    Matrix4 result;
    return result;
}
