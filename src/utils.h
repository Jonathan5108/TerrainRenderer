#pragma once
#include <vector>

unsigned char* loadHeightMap(const char* filepath, int &width, int &height);
std::vector<float> generateVertices(unsigned char* heightMap, int width, int height);
std::vector<unsigned int> generateIndices(int width, int height);
