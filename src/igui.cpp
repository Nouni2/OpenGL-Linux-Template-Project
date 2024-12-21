#include "igui.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui_render.h" 

IGui::IGui(GLFWwindow* window) {
    initialize(window);
}

IGui::~IGui() {
    cleanup();
}

void IGui::initialize(GLFWwindow* window) {
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    logger.log(LogLevel::INFO, "ImGui initialized successfully.");
}

void IGui::beginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void IGui::render() {
    renderImGui();
}

void IGui::endFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void IGui::cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    logger.log(LogLevel::INFO, "ImGui cleaned up successfully.");
}
