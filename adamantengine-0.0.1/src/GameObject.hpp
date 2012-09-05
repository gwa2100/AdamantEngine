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
	DEFPROPERTY( Position, pos3f_t, m_position );
	DEFPROPERTY( Dimension, pos2f_t, m_dimension );
	DEFPROPERTY( Velocity, pos2f_t, m_velocity );

public:
	gameobject_t(pos3f_t* position, pos2f_t* dimension, rect_t* box);
	virtual ~gameobject_t();

	virtual void Render(SDL_Surface* pDestSurf);
	virtual void Cleanup();
	virtual void OnInput( pos2f_t& inputVelocity );
	virtual void Update();
	virtual void OnCollision( ECollision eCollision, float fXAmt, float fYAmt );

	void MovePosition( const pos3f_t& position );
	void MoveVelocity( const pos2f_t& velocity );

	void SetUserData( void* userdata ) { m_pUserData = userdata; }

	void SetOnRender( render_func pfnOnRender ) { m_OnRender = pfnOnRender; }
	void SetOnUpdate( update_func pfnOnUpdate ) { m_OnUpdate = pfnOnUpdate; }
	void SetOnInput( input_func pfnOnInput ) { m_OnInput = pfnOnInput; }
	void SetOnCleanup( cleanup_func pfnOnCleanup ) { m_OnCleanup = pfnOnCleanup; }
	void SetOnInit( init_func pfnOnInit ) { m_OnInit = pfnOnInit; }
	void SetOnCollision( collision_func pfnOnCollison ) { m_OnCollison = pfnOnCollison; }

protected:
	gameobject_t()
	: m_bUseCollision( false )
	, m_bUseUpdate( false )
	, m_bUseRender( false )
	, m_bUseEvent( false )
	, m_bUseCleanup( false )
	, m_bUseTime( false )
	, m_OnRender(NULL)
	, m_OnUpdate(NULL)
	, m_OnInput(NULL)
	, m_OnCleanup(NULL)
	, m_OnInit(NULL)
	, m_OnCollison( NULL )
	, m_pUserData( NULL )
	{
		m_velocity.x = m_velocity.y = 0;
		m_position.x = m_position.y = m_position.z = 0;
		m_dimension.x = m_dimension.y = 0;
	}

	render_func		m_OnRender;
	update_func		m_OnUpdate;
	input_func		m_OnInput;
	cleanup_func	m_OnCleanup;
	init_func		m_OnInit;
	collision_func	m_OnCollison;

	void*			m_pUserData;
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