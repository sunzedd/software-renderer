#pragma once
#include <string>
#include <memory>
#include <exception>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include "Graphics/RenderPipeline.h"
#include "Window.h"

namespace Core {

class App 
{
public:
	App();
	App(int width, int height, const std::string& title, bool fullscreen);
	virtual ~App();

	void run();

protected:
	virtual void update(unsigned int dtime) = 0;
	virtual void render(unsigned int dtime) = 0;

protected:
	Window m_window;
	const sf::Event& m_windowEvent;
	sf::Clock m_timer;
	RenderPipeline m_renderer;
};

} // namespace Core