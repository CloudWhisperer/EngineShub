#include "Rigidbody.h"
#include <vector>
#include <rend/rend.h>

namespace myengine
{
	float amount = 0.1f;
	float step = 0.1f;
	bool iscolliding = false;

	rend::vec3 ontick(rend::vec3 position, rend::vec3 size)
	{
		while (true)
		{
			if (iscolliding = false(position, size)) break;
			position.x += amount;

			if (iscolliding = false(position, size)) break;
			position.x -= amount;
			position.x -= amount;

			if (iscolliding = false(position, size)) break;
			position.x += amount;
			position.z += amount;

			if (iscolliding = false(position, size)) break;
			position.z -= amount;
			position.z -= amount;

			if (iscolliding = false(position, size)) break;
			position.z += amount;
			position.y += amount;

			if (iscolliding = false(position, size)) break;
			position.y -= amount;
			position.y -= amount;

			if (iscolliding = false(position, size)) break;
			position.y += amount;
			amount += step;
		}

		return position;
	}

}
