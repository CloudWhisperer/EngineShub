#include "Component.h"
#include <vector>
#include <rend/rend.h>

namespace myengine
{
	struct BoxCollider : Component
	{
		bool colliding(const BoxCollider& _other);
	private:
		rend::vec3 m_size;
		rend::vec3 m_offset;
	};
}


