#include "imgui_render.h"

void renderImGui() {
    ImGui::Begin("ImGui Test");
    ImGui::Text("If you see this, ImGui is working!");
    ImGui::End();
}
