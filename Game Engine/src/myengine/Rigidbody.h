#include "Component.h"
#include <rend/rend.h>
#include <vector>

namespace myengine
{
	struct RigidBody : Component
	{
		rend::vec3 onTick(rend::vec3 position, rend::vec3 size);
	};
}