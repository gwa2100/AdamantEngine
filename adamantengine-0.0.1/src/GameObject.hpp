#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include "defines.h"
#include <vector>
#include "../include/amtengine.h"

using std::vector;

struct SDL_Surface;

namespace adamantengine {

class gameobject_t
{
	DEFPROPERTY( UseCollision, bool, m_bUseCollision );
	DEFPROPERTY( UseUpdate, bool, m_bUseUpdate );
	DEFPROPERTY( UseRender, bool, m_bUseRender );
	DEFPROPERTY( UseEvent, bool, m_bUseEvent );
	DEFPROPERTY( UseCleanup, bool, m_bUseCleanup );
	DEFPROPERTY( UseTime, bool, m_bUseTime );
	DEFPROPERTY( Position, pos3i_t, m_position );
	DEFPROPERTY( Dimension, pos2i_t, m_demension );
	DEFPROPERTY( Velocity, pos2i_t, m_velocity );

public:
	gameobject_t(pos3i_t* position, pos2i_t* dimension, rect_t* box);
	virtual ~gameobject_t();

	virtual void Render(SDL_Surface* pDestSurf);
	virtual void Cleanup();
	virtual void OnInput( const pos2i_t& inputVelocity );
	virtual void Update();
	virtual void OnCollision( ECollision eCollision );

	void MovePosition( const pos3i_t& position );
	void MoveVelocity( const pos2i_t& velocity );
};


class gameobject_array_t : public vector< adamantengine::gameobject_t* >
{
public:
	gameobject_array_t()
	{
	}

	~gameobject_array_t()
	{
	}

	void ResetContent()
	{
		if ( size() == 0 ) return;

		gameobject_t** ppData = data();

		for( size_t n = 0;n < size(); n++ )
		{
			delete ppData[n];
		}

		clear();

		gameobject_array_t().swap( *this );
	}


};



}

#endif