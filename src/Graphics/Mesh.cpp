#include "Graphics/Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices)
    : vertices(vertices) {}

const std::vector<Vertex>& Mesh::getVertices() const {
    return vertices;
}
