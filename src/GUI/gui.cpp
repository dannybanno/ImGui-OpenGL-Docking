#include "gui.h"
#include "../../include/ImGui/imgui.h"
#include "../../include/ImGui/imgui_impl_glfw.h"
#include "../../include/ImGui/imgui_impl_opengl3.h"
#include "../../include/imgui/imgui_internal.h"


void initImGui(GLFWwindow* window) {
    ImGui::CreateContext();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    //Optional to save the windows settings
    ImGui::LoadIniSettingsFromDisk("imgui.ini");
}

void renderWindow() {
    ImGui::Begin("Window 1");

    

    ImGui::End();
}

void renderAnotherWindow() {
    ImGui::Begin("Another Window");


    ImGui::End();
}

void renderImGui() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //renders windows
    renderWindow();
    renderAnotherWindow();  

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void shutdownImGui() {
    //optional to save the window stuff
    ImGui::SaveIniSettingsToDisk("imgui.ini");

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
