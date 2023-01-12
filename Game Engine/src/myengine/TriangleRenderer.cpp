#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"

namespace myengine
{
	TriangleRenderer::TriangleRenderer() :
		m_shader("../data/shaders/basic.vert", "../data/shaders/basic.frag")
	{
		m_mesh.loadTriangle();
		m_enemy.loadTriangle();
	}
	void TriangleRenderer::onDisplay()
	{
		rend::vec2 ss = getEntity()->getCore()->getScreenSize();
		rend::Renderer r(ss.x, ss.y);
		r.shader(&m_shader);
		r.mesh(&m_mesh);
		r.mesh(&m_enemy);

		r.projection(rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));

		r.model(getEntity()->getTransform()->getModel());

		r.render();
	}
}