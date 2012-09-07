#include "GameObject.hpp"
#include <SDL_Video.h>

adamantengine::gameobject_t::gameobject_t(pos3f_t* position, pos2f_t* dimension, rect_t* box)
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
	m_velocity.x = m_velocity.y = 0.0f;
	if ( position == NULL )
	{
		m_position.x = m_position.y = m_position.z = 0.0f;
	}
	else
	{
		m_position.x = position->x;
		m_position.y = position->y;
		m_position.z = position->z;
	}

	if ( dimension == NULL )
	{
		m_dimension.x = m_dimension.y = 0.0f;
	}
	else
	{
		m_dimension.x = dimension->x;
		m_dimension.y = dimension->y;
	}
}

adamantengine::gameobject_t::~gameobject_t()
{

}

void adamantengine::gameobject_t::Render(SDL_Surface* pDestSurf)
{
	if ( m_OnRender != NULL )
	{
		m_OnRender( this, pDestSurf, m_pUserData );
		return;
	}
}

void adamantengine::gameobject_t::Cleanup()
{
	if ( m_OnCleanup != NULL )
	{
		m_OnCleanup( this, m_pUserData );
	}
}

void adamantengine::gameobject_t::OnInput( pos2f_t& inputVelocity )
{
	if ( m_OnInput != NULL )
	{
		m_OnInput( this, &inputVelocity, m_pUserData );
	}
}

void adamantengine::gameobject_t::Update()
{
	if ( m_OnUpdate != NULL )
	{
		m_OnUpdate( this, 0.0f, m_pUserData );
	}

	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;
}

void adamantengine::gameobject_t::OnCollision( ECollision eCollision, float fXAmt, float fYAmt )
{
	if ( m_OnCollison != NULL )
	{
		m_OnCollison( this, eCollision, fXAmt, fYAmt, m_pUserData );
	}
}

void adamantengine::gameobject_t::MovePosition( const pos3f_t& position )
{

}

void adamantengine::gameobject_t::MoveVelocity( const pos2f_t& velocity )
{

}
