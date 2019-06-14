#include "DefaultGuiSettings.h"

void beginDefault()
{
	ImGui::PushStyleColor(ImGuiCol_WindowBg, sf::Color::Transparent);
	ImGui::PushStyleColor(ImGuiCol_Border, sf::Color::Transparent);
	ImGui::PushStyleColor(ImGuiCol_MenuBarBg, sf::Color::Transparent);
}

void endDefault()
{
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
	ImGui::PopStyleColor();
}