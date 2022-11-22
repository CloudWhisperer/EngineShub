#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

struct Player : Component
{
	Player() :
		m_count(0) { }

	void onTick()
	{
		++m_count;
		std::cout << "Ticking" << std::endl;

		if (m_count > 600)
		{
			//another way to stop the engine, preferred to get the core first then just getting the entity
			//getEntity()->kill();
			getEntity()->getCore()->stop();
		}
	}

private:
	int m_count;

};

int main(int argc, char* argv[])
{

std::cout << "hello world" << std::endl;

std::shared_ptr<Core> core = Core::initialize();

std::shared_ptr<Entity> e = core->addEntity();
e->addComponent<Player>();
e->addComponent<TriangleRenderer>();
e->addComponent<SoundSource>();

core->start();

return 0;

}