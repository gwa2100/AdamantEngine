#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include "GameObject.hpp"
#include <string>
using std::string;

struct SDL_Surface;

namespace adamantengine {

class sprite_t : public gameobject_t
{
public:

	sprite_t(const string& sFilename );
	virtual ~sprite_t();
	virtual void Render( SDL_Surface* pDisplaySurface );
	SDL_Surface* GetSurface() const { return m_pSurf; }

private:

	void Create();

	SDL_Surface* m_pSurf;
	string m_sName;
};


}
#endif