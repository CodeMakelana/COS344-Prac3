#ifndef SHAPE_H
#define SHAPE_H

#include "MathUtils.h"
#include <GL/glew.h>
#include <vector>

class Shape {
private:
    std::vector<float>        vertices;  // interleaved: x, y, z, r, g, b
    std::vector<unsigned int> indices;
    GLuint VAO, VBO, EBO;

public:
    Shape();
    ~Shape();

    // Upload vertex/index data to the GPU and set up VAO/VBO/EBO
    void init();

    // Draw the shape as filled triangles
    void draw() const;

    // Draw the shape as a wireframe using GL_LINES
    void drawWireframe() const;

    // Data setters (call before init())
    void setVertices(const std::vector<float>& verts);
    void setIndices(const std::vector<unsigned int>& inds);

    // Data getters
    const std::vector<float>&        getVertices() const;
    const std::vector<unsigned int>& getIndices()  const;

    GLuint getVAO() const;
    GLuint getVBO() const;
    GLuint getEBO() const;
};

#endif // SHAPE_H