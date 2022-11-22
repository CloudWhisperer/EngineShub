#include "Transform.h"

namespace myengine
{
	Transform::Transform() : m_scale(1, 1, 1)
	{ }
		rend::mat4 Transform::getModel()
		{
			rend mat4 rtn = rtn::mat4(1.0f);
			rtn = rend::translate(rtn, rend::vec3(0, 0, -10));
			return rtn;
		}
}