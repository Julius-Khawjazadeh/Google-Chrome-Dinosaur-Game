#pragma once

class StateBase
{
public:
	virtual void handleInput() = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;
	virtual void renderGUI() = 0;
};