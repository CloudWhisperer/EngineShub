#include <iostream>
#include <myengine/myengine.h>
#include <iostream>

using namespace myengine;

struct Player;

void controller()
{
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_RIGHT])
	{
		std::cout << "right arrow key press" << std::endl;
		
	}

	if (state[SDL_SCANCODE_LEFT])
	{
		std::cout << "left arrow key press" << std::endl;
	}

	if (state[SDL_SCANCODE_UP])
	{
		std::cout << "up arrow key press" << std::endl;
	}

	if (state[SDL_SCANCODE_DOWN])
	{
		std::cout << "down arrow key press" << std::endl;
	}
};

struct Player : Component
{
	Player() :
		m_angle(0),
		m_position(0)
	{ }

	void onTick()
	{
		m_angle += 4.0f;

		getEntity()->getTransform()->setRotation(rend::vec3(m_angle, m_angle, m_angle));

		getEntity()->getTransform()->setPosition(rend::vec3(m_position, 0, -20));

		controller();
	}

private:
	float m_angle;
	float m_position;

};

int main(int argc, char* argv[])
{

	std::cout << "SHUBENGINE LOADED SUCCESSFULLY" << std::endl;

	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->addComponent<SoundSource>();
	e->addComponent<irccomponent>();

	std::shared_ptr<Texture> cattext = core->getResources()->load<Texture>("Textures/cat.png");

	e->getTransform()->setPosition(rend::vec3(0, 0, -5));

	core->start();

	return 0;

}