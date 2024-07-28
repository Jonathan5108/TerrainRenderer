#include "utils.h"
#include <stb_image.h>
#include <iostream>

// Loads a height map image from a file
// Parameters: file path, width, and height (passed by reference)
// Returns: a pointer to the loaded image data
unsigned char* loadHeightMap(const char* filepath, int &width, int &height) {
    int channels;
    unsigned char* data = stbi_load(filepath, &width, &height, &channels, 1);
    if (!data) {
        std::cerr << "Failed to load height map" << std::endl;
        exit(1);
    }
    return data;
}

// Geneates vertex data from the height map
// Parameters: pointer to height map data, width, and height
// Returns: a vector of vertex positions
std::vector<float> generateVertices(unsigned char* heightMap, int width, int height) {
    std::vector<float> vertices;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float h = heightMap[y * width + x] / 255.0f;
            vertices.push_back((float)x);
            vertices.push_back(h);
            vertices.push_back((float)y);
        }
    }
    return vertices;
}

// Generates indices for the vertices
// Parameters: width and height of the height map
// Returns: a vector of indices
std::vector<unsigned int> generateIndices(int width, int height) {
    std::vector<unsigned int> indices;
    for (int y = 0; y < height - 1; ++y) {
        for (int x = 0; x < width - 1; ++x) {
            int topLeft = y * width + x;
            int topRight = topLeft + 1;
            int bottomLeft = topLeft + width;
            int bottomRight = bottomLeft + 1;
            
            indices.push_back(topLeft);
            indices.push_back(bottomLeft);
            indices.push_back(topRight);
            
            indices.push_back(topRight);
            indices.push_back(bottomLeft);
            indices.push_back(bottomRight);
        }
    }
    return indices;
}
