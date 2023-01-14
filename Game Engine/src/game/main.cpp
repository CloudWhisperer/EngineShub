//includes megaheader
#include <myengine/myengine.h>

//using the namespace myengine
using namespace myengine;

//allows the use of keyboard controls for the player
const Uint8* state = SDL_GetKeyboardState(NULL);

//player class, which is also a component
struct Player : Component
{
	Player() :
		m_angle(0),
		m_position(0),
		m_positiony(0)
	{ }

	//tick function for the player
	void onTick()
	{
		m_angle += 0.4f;

		//checks the arrow keys and moves the player accordingly
		if (state[SDL_SCANCODE_RIGHT])
		{
			std::cout << "right arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position += 0.2 , m_positiony, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_LEFT])
		{
			std::cout << "left arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position -= 0.2, m_positiony, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_UP])
		{
			std::cout << "up arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position, m_positiony += 0.2, -20));
			m_angle += 9.0f;
		}
		if (state[SDL_SCANCODE_DOWN])
		{
			std::cout << "up arrow key press" << std::endl;
			getEntity()->getTransform()->setPosition(rend::vec3(m_position, m_positiony -= 0.2, -20));
			m_angle += 9.0f;
		}

		//rotates the triangle slowly
		getEntity()->getTransform()->setRotation(rend::vec3(m_angle, m_angle, m_angle));
	}

	//private variables for the player
private:
	float m_angle;
	float m_position;
	float m_positiony;

};

struct Enemy : Component
{
	Enemy() :
		enemy_angle(0),
		enemy_position(3),
		enemy_positiony(5)
	{ }

	//tick function for the enemy
	void onTick()
	{
		enemy_angle += 2.0f;

		//rotates the enemy
		getEntity()->getTransform()->setRotation(rend::vec3(enemy_angle, enemy_angle, enemy_angle));

		//makes the enemy move down slowly
		getEntity()->getTransform()->setPosition(rend::vec3(enemy_position, enemy_positiony -= 0.01f, -20));

	}

	//enemy values
private:
	float enemy_angle;
	float enemy_position;
	float enemy_positiony;
		
};


//same as enemy 1 except in a different location
struct Enemy2 : Component
{
	Enemy2() :
		enemy_angle(0),
		enemy_position(-3),
		enemy_positiony(5)
	{ }

	void onTick()
	{
		enemy_angle += 2.0f;

		getEntity()->getTransform()->setRotation(rend::vec3(enemy_angle, enemy_angle, enemy_angle));

		getEntity()->getTransform()->setPosition(rend::vec3(enemy_position, enemy_positiony -= 0.01f, -20));

	}

private:
	float enemy_angle;
	float enemy_position;
	float enemy_positiony;

};

//main function
int main(int argc, char* argv[])
{
	//name of the engine
	std::cout << "SHUBENGINE LOADED SUCCESSFULLY" << std::endl;

	//initialises core
	std::shared_ptr<Core> core = Core::initialize();

	//adds the first entity to core as well as the components in it such as player audio etc.
	std::shared_ptr<Entity> e = core->addEntity();
	e->addComponent<Player>();
	e->addComponent<TriangleRenderer>();
	e->addComponent<SoundSource>();
	e->addComponent<irccomponent>();
	e->getTransform()->setPosition(rend::vec3(0, 0, -5));

	//loads resource for the player and the 3D curuthers models, i dont know how to load them into the world but they can load when the engine starts
	std::shared_ptr<Texture> cattexture = core->getResources()->load<Texture>("../Models/Whiskers_diffuse.png");
	std::shared_ptr<Model> Player = core->getResources()->load<Model>("../Models/curuthers.obj");


	//me testing how to make a loop to make lots of entities with enemies instead of copy pasting them lots of times, also learnt about the entity limit

	//srand(time(0));
	//for (int i = 0; i < 50; i++)
	//{
	//	std::shared_ptr<Entity> p = core->addEntity();
	//	p->addComponent<TriangleRenderer>();
	//	p->addComponent<Enemy>();
	//	std::cout << i << std::endl;

	//	struct Enemy : Component
	//	{
	//		Enemy() :
	//			enemy_angle(0),
	//			enemy_position(0 + (rand() % 10)),
	//			enemy_positiony(0+(rand() % 10))
	//		{ }

	//		void onTick()
	//		{
	//			enemy_angle += 2.0f + (rand() % 10);

	//			getEntity()->getTransform()->setRotation(rend::vec3(enemy_angle, enemy_angle, enemy_angle));

	//			getEntity()->getTransform()->setPosition(rend::vec3(enemy_position, enemy_positiony -= 0.01f, -20));

	//		}

	//	private:
	//		float enemy_angle;
	//		float enemy_position;
	//		float enemy_positiony;

	//	};
	//}

	//adding extra entities to add extra enemies
	std::shared_ptr<Entity> e2 = core->addEntity();
	e2->addComponent<TriangleRenderer>();
	e2->addComponent<Enemy>();

	
	//third entity added
	std::shared_ptr<Entity> e3 = core->addEntity();
	e3->addComponent<TriangleRenderer>();
	e3->addComponent<Enemy2>();

	//cant add more than 3 entities for some reason
	//std::shared_ptr<Entity> e4 = core->addEntity();
	//e3->addComponent<TriangleRenderer>();
	//e3->addComponent<Enemy3>();

	//starts core
	core->start();

	//returns 0 when exit
	return 0;

}