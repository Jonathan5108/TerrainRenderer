#pragma once
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

bool initOpenGL();
GLFWwindow* createWindow(int width, int height, const char* title);
void setupBuffers(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
void renderScene();
void processInput(GLFWwindow* window);
void cleanup();

std::string loadShaderSource(const char* filePath);
unsigned int compileShader(const char* filePath, GLenum shaderType);
unsigned int createShaderProgram(const char* vertexPath, const char* fragmentPath);
