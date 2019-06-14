#include "stdeng.h"

namespace eng
{
	float stdeng::getFPS()
	{
		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / currentTime;
		lastTime = currentTime;

		return fps;
	}

	void stdeng::showFPS()
	{
		ImGui::SetNextWindowPos({ 0, 0 });
		beginDefault();
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0, 0, 0, 255));
		ImGui::Begin("##FPS_SIGN", false, screenFlags);

		ImGui::Text("FPS: %d", (unsigned int)getFPS());
		ImGui::PopStyleColor();
		ImGui::End();
		endDefault();
	}

	float pixels(float value)
	{
		return value / 30.0f;
	}

	float scalarPixels(float value)
	{
		return value / 10.0f;
	}
}
