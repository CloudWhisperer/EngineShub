#include "Component.h"

#include <AL/al.h>

namespace myengine
{

	struct SoundSource : Component
	{
		SoundSource();

		void onTick();

	private:
		ALuint sourceId;
	};

}