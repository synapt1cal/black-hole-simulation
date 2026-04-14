#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <glm/vec2.hpp>
#include <glm/gtc/constants.hpp>
#include <vector>
#include <chrono>
#include <iostream>
using Clock = std::chrono::high_resolution_clock;

int worldScale = 100; // When G=c=1, we will multiply by 100 to make the black hole visibly massive.

struct Engine {
    GLFWwindow* window;
    int width = 800;
    int height = 600;
    float widthWorld = 1e11;
    float heightWorld = 7.5e10;
    bool glfwInitialized = false;

    Engine(int w = 800, int h = 600) : width(w), height(h) {
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwInitialized = true;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, "Simulation Engine", NULL, NULL);
        if (!window) {
            std::cerr << "Failed to create window" << std::endl;
            if (glfwInitialized) {
                glfwTerminate();
                glfwInitialized = false;
            }
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            exit(EXIT_FAILURE);
        }

        glViewport(0, 0, width, height);
    }

    void run() {
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    ~Engine() {
        if (window) {
            glfwDestroyWindow(window);
        }
        if (glfwInitialized) {
            glfwTerminate();
        }
    }
};

struct BlackHole {
    unsigned int VAO, VBO;
    glm::vec2 position;
    double mass;
    double r_s;
    int vertexCount;

    BlackHole (glm::vec2 pos, double m) : position(pos), mass(m) {
        r_s = (2 * mass) * worldScale; 
        std::vector<glm::vec2> vertices;
        int segments = 72;

        vertices.push_back(glm::vec2(0.0f, 0.0f));

        for (int i = 0; i <= segments; i++) {
            float angle = i * 2.0f * glm::pi<float>() / segments;
            vertices.push_back(glm::vec2(
                cos(angle) * r_s,
                sin(angle) * r_s
            ));
        }

        vertexCount = static_cast<int>(vertices.size());

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec2), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Draw() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
        glBindVertexArray(0);
    }
    
    ~BlackHole() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
};

// struct LightRay {

// };

int main() {
    Engine engine(800, 600);
    engine.run();
    return 0;
}
