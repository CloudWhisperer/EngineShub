#include "Core.h"
#include "Entity.h"
#include "SDL2/SDL.h"
#include "TriangleRenderer.h"
#include "Transform.h"
#include "Resources.h"

#include <stdexcept>
#include <AL/al.h>
#include <AL/alc.h>

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

		/*************************************************************************
		 * Initialization
		*************************************************************************/
		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		return rtn;
	}

	void Core::start()
	{
		m_running = true;

		while (m_running)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					m_running = false;
				}
			}

			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				m_entities.at(ei)->tick();
			}

			int x = 0;
			int y = 0;

			SDL_GetWindowSize(m_window, &x, &y);
			rend::Renderer r(x, y);
			r.clear();

			for (size_t ei = 0; ei < m_entities.size(); ei++)
			{
				m_entities.at(ei)->display();
			}



			SDL_GL_SwapWindow(m_window);
		}
	}

	rend::vec2 Core::getScreenSize()
	{
		int x = 0;
		int y = 0;

		SDL_GetWindowSize(m_window, &x, &y);

		return rend::vec2(x, y);
	}

	void Core::stop()
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;
		rtn->m_transform = rtn->addComponent<Transform>();


		m_entities.push_back(rtn);

		return rtn;
	}

	template <typename T>
	void find(std::vector<std::shared_ptr<T> >& _out)
	{
		// Go through each Entity in Core.
		for (size_t ei = 0; ei < m_entities.size(); ++ei)
		{
			std::shared_ptr<Entity> e = m_entities.at(ei);
			// Go through each Component in Entity.
			for (size_t ci = 0; ci < e->m_components.size(); ++ci)
			{
				std::shared_ptr<Component> c = e->m_components.at(ci);
				// Try to dynamic cast the Component to a T.
				std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);
				// If succeeds then add it to the output array.
				if (t)
				{
					_out.push_back(t);
				}
			}
		}
	}

	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// Search for previously loaded resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				std::cout << "searching for loaded resource" << std::endl;
				// Return it if found
				if (m_resources.at(i)->getPath() == _path)
				{
					std::cout << "found resource" << std::endl;
					return m_resources.at(i);
				}
			}
			// Create new instance, construct it and add to cache
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_path = _path;
			rtn->load();
			m_resources.push_back(rtn);
			return rtn;
		}

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};


	Core::~Core()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}