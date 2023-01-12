#include "Component.h"
#include <vector>
#include <rend/rend.h>

namespace myengine
{
/**
*struct for the box collider, contains a vec 3 for size and offset 
and a boolean which checks if its colliding with anything or not
*/
	struct BoxCollider : Component
	{
		bool colliding(const BoxCollider& _other);///bool to check if the collision is touching or not
	private:
		rend::vec3 m_size; ///size of the box collider
		rend::vec3 m_offset;///offset of the box collider
	};
}


