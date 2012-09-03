#include "GameObject.hpp"

adamantengine::gameobject_t::gameobject_t(pos3i_t* position, pos2i_t* dimension, rect_t* box)
{
	if ( position == NULL )
	{
		m_position.x = m_position.y = m_position.z = 0;
	}
	else
	{
		m_position.x = position->x;
		m_position.y = position->y;
		m_position.z = position->z;
	}

	if ( dimension == NULL )
	{
		m_demension.x = m_demension.y = 0;
	}
	else
	{
		m_demension.x = dimension->x;
		m_demension.y = dimension->y;
	}
}

adamantengine::gameobject_t::~gameobject_t()
{

}

void adamantengine::gameobject_t::Render(SDL_Surface* pDestSurf)
{
}

void adamantengine::gameobject_t::Cleanup()
{
}

void adamantengine::gameobject_t::OnInput( const pos2i_t& inputVelocity )
{

}

void adamantengine::gameobject_t::Update()
{

}

void adamantengine::gameobject_t::OnCollision( ECollision eCollision )
{

}

void adamantengine::gameobject_t::MovePosition( const pos3i_t& position )
{

}

void adamantengine::gameobject_t::MoveVelocity( const pos2i_t& velocity )
{

}
