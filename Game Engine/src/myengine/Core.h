#include <memory>
#include <list>
#include <SDL2/SDL.h>
#include <vector>
#include <rend/rend.h>

/**
* Initialises the Core that creates a window with a height and width that is made by the developer.
* Also has exceptions incase something goes wrong and the program will stop and note the errors down.
* And finally it includes the quit functions for the window and application.
*/
namespace myengine
{

	///creates the struct for entity
	struct Entity;

	///creates the struct for component
	struct Component;

	struct Core
	{
		///intialises the core which makes the window, etc
		static std::shared_ptr<Core> initialize();

		///runs the engine
		void start();

		///stops the engine
		void stop();

		///deconstructs everything that needs to be removed to save memory leaks
		~Core();

		///runs the entity function
		std::shared_ptr<Entity> addEntity();
		rend::vec2 getScreenSize();

	private:
		///boolean to check if the engine is running
		bool m_running;
		std::vector<std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core>m_self;
		std::weak_ptr<Core>rtn;
		SDL_Window* m_window;
		SDL_GLContext m_context;
		SDL_Event e;
	};
}