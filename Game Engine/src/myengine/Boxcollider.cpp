#include "Boxcollider.h"
#include "Entity.h"
#include "Transform.h"
#include <vector>
#include <rend/rend.h>

namespace myengine
{
	bool BoxCollider::colliding(const BoxCollider& _other)
	{
		rend::vec3 a = getEntity()->getTransform()->getPosition();
		rend::vec3 b = getEntity()->getTransform()->getPosition(); // deleted the "other." because pointer was broken
		rend::vec3 ahs = m_size / 2.0f;
		rend::vec3 bhs = _other.m_size / 2.0f;

		//--x axis--
		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;
			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}

		//--y axis--
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}

		//--z axis--
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
			{
				return false;
			}
		}
	}
}

