#include "Component.h"
#include <rend/rend.h>
#include <vector>

namespace myengine
{
	struct RigidBody : Component
	{
		/// @brief ontick function for rigidbody
		/// @param position 
		/// @param size 
		/// @return vector3
		rend::vec3 onTick(rend::vec3 position, rend::vec3 size);
	};
}