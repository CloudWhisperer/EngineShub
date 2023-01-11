#include <string>
#include "Component.h"
#include "rend/rend.h"
//#include "SoundSource.h"

//dont have a audiofile or a textfile yet, will add them later

struct Resource
{
	virtual void onLoad() = 0;
	std::string getPath() const;
private:
	std::string m_path;
	void load();
};

struct Model : Resource
{
	void onLoad();
private:
	std::shared_ptr<rend::Model> m_model;
};

struct Texture : Resource
{
	void onLoad();
private:
	std::shared_ptr<rend::Texture> m_texture;
};

//struct Shader : Resource
//{
//	void onLoad();
//private:
//	std::shared_ptr<rend::Shader> m_shader;
//};

//struct SoundSource : Resource
//{
//	void onLoadsound();
//private:
//	std::shared_ptr<myengine::SoundSource> m_soundsource;
//};

