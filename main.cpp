#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"
#include "MathUtils.h"

using namespace glm;
using namespace std;

const char *getError()
{
    const char *errorDescription;
    glfwGetError(&errorDescription);
    return errorDescription;
}

inline void startUpGLFW()
{
    glewExperimental = true; // Needed for core profile
    if (!glfwInit())
    {
        throw getError();
    }
}

inline void startUpGLEW()
{
    glewExperimental = true; // Needed in core profile
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw getError();
    }
}

inline GLFWwindow *setUp()
{
    startUpGLFW();
    glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    GLFWwindow *window;                                            // (In the accompanying source code, this variable is global for simplicity)
    window = glfwCreateWindow(1000, 1000, "u23588579", NULL, NULL);
    if (window == NULL)
    {
        cout << getError() << endl;
        glfwTerminate();
        throw "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    startUpGLEW();
    return window;
}

int main()
{
    GLFWwindow *window;
    try
    {
        window = setUp();
    }
    catch (const char *e)
    {
        cout << e << endl;
        throw;
    }

    //Add code here

    //testing the vector and matrix classes
    Vector3 v1(1.0f, 2.0f, 3.0f);
    Vector3 v2(4.0f, 5.0f, 6.0f);
    Vector3 v3 = v1.add(v2);
    Vector3 v4 = v1.cross(v2);
    float V1_dot_V2 = v1.dot(v2);
    float V1_length = v1.length();
    Vector3 v5 = v1.normalize();
    Vector3 v6 = v1.scale(2);
    cout << "v1 + v2 = (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << endl;
    cout << "v1 * v2 = (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << endl;
    cout << V1_dot_V2 << endl;
    cout << V1_length << endl;
    cout << "Norm of V1 = (" << v5.getX() << ", " << v5.getY() << ", " << v5.getZ() << ")" << endl;
    cout << "V1 scaled by 2 = (" << v6.getX() << ", " << v6.getY() << ", " << v6.getZ() << ")" << endl;
}
