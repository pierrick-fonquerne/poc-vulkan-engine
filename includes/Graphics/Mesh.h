#pragma once
#include <vector>
#include "Vertex.h"

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices);

    const std::vector<Vertex>& getVertices() const;

private:
    std::vector<Vertex> vertices;
};
