# TerrainRenderer
Not fully functional as of yet, having some issues with dependencies not resolving...
Inspiration for a substantial portion of this renderer taken from OpenGL's learnopengl tutorial.

## Overview
TerrainRenderer is a C++ application that renders a terrain from a height map image using OpenGL. The project demonstrates the following OpenGL Functionalities: loading height maps, 
generating vertex and index buffers, compiling shaders, and rendering 3D terrain scenes; thus providing a basic framework into Terrain Rendering techniques.

## Building and Running the Project
Dependencies: Need to have CMake, MinGW (GCC and G++), GLFW, and GLEW installed on your system. Initialize the build process by creating a build directory, running CMake, and compiling the project with make:

1. Clone the repository:
2. Install dependencies and set up your environment. Ensure MinGW is added to your system PATH through System Environmental Variables .
3. Create a build directory and compile the project
4. Run the application with the specified path to the heightmap.

Performance: Should be able to handle 1024x1024 heightmaps on mid-range cpus fairly smoothly. Vertex buffer objects and
element buffer objects were used for data management and rendering.
