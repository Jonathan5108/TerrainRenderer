#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>
#include <vector>
#include "utils.h"
#include "gl_utils.h"

// Shader program ID
unsigned int shaderProgram;

int main(int argc, char** argv) {
    // Check if the path to the height map image is provided
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path to height map>" << std::endl;
        return -1;
    }
    // Load the height map image
    int width, height;
    unsigned char* heightMap = loadHeightMap(argv[1], width, height);
    // Initialize OpenGL
    if (!initOpenGL()) {
        std::cerr << "Failed to initialize OpenGL" << std::endl;
        return -1;
    }
    // Create GLFW window
    GLFWwindow* window = createWindow(800, 600, "Terrain Renderer");
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // Generate vertices and indices from the height map
    std::vector<float> vertices = generateVertices(heightMap, width, height);
    std::vector<unsigned int> indices = generateIndices(width, height);
    setupBuffers(vertices, indices);
    shaderProgram = createShaderProgram("../shaders/vertex_shader.glsl", "../shaders/fragment_shader.glsl");
    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Use the shader program
        glUseProgram(shaderProgram);
        // Render the scene
        renderScene();
        // Swap the front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }
    // Clean up 
    cleanup();
    glfwDestroyWindow(window);
    glfwTerminate();
    stbi_image_free(heightMap);
    return 0;
}
