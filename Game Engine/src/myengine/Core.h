#include <memory>
#include <list>
#include <SDL.h>

namespace myengine
{
	struct Entity;
	struct Component;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		void start();
		void stop();
		~Core();
		std::shared_ptr<Entity> addEntity();

	private:
		bool m_running;
		std::list<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core>m_self;
		std::weak_ptr<Core>rtn;
		SDL_Window* m_window;
		SDL_GLContext m_context;
	};
}