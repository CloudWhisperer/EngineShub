#include "Core.h"
#include "Entity.h"
#include "SDL.h"
#include <stdexcept>

namespace myengine 
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		int INITIAL_HEIGHT = 800;
		int INITIAL_WIDTH = 600;
		rtn->m_self = rtn;
		rtn->m_running = false;
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}
		if (!(rtn->m_window = SDL_CreateWindow("SDL2 Platform",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			INITIAL_WIDTH, INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create Window");
		}
		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}

		return rtn;
	}

	void Core::start()
	{
		m_running = true;

		while (m_running)
		{
			for (auto it = m_entities.begin();
				it != m_entities.end(); ++it)
			{
				(*it)->tick();
			}
		}
	}

	void Core::stop()
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		m_entities.push_back(rtn);

		return rtn;
	}

	Core::~Core()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}