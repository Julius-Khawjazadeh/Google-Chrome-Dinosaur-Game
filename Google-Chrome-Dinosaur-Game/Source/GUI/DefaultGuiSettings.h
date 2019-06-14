#pragma once

#include "imgui.h"

constexpr int screenFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
							ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse |
							ImGuiWindowFlags_NoSavedSettings;

void beginDefault();
void endDefault();