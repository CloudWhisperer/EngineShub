#include "Resources.h"

std::string myengine::Resource::getPath() const
{
	return m_path;
}

void myengine::Resource::load()
{
	onLoad();
}
