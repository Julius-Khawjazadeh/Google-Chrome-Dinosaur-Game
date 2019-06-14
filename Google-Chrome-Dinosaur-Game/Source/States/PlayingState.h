#pragma once

#include "../Game.h"
#include "StateBase.h"
#include "../Util/Animation.h"

#include "../Mouse/MouseCollision.h"
#include "../Util/stdeng.h"


class PlayingState : public StateBase
{
public:
	PlayingState(Game* game);

	virtual void handleInput();
	virtual void update(float dt);
	virtual void render();
	virtual void renderGUI();

private:
	ImFont* default_font;
	ImGuiIO& io;
	Game* m_game;
	eng::stdeng mainEngine;
};
