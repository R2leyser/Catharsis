#include <raylib-cpp.hpp>
#include <vector>
#include "include/types.hpp"
#include "raylib.h"

const int g_screenWidth = 800;
const int g_screenHeight = 450;
const int g_pointCount = 30;

std::vector<Point> createRandomPoints() {
    std::vector<Point> vec = std::vector<Point>();
    for (int i = 0 ; i < g_pointCount; i++) {
        vec.push_back((Point){
            GetRandomValue(0, g_screenWidth),
            GetRandomValue(0, g_screenHeight)
        });
    }
    return vec;
}

int main() {
    

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(g_screenWidth, g_screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    return 0;
}
