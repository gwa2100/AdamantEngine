#ifndef __AMTENGINE_HPP__
#define __AMTENGINE_HPP__

#include "amtengine.h"

namespace adamantengine {
	
class app_t
{
public:
	inline app_t()
	{
		m_app = amt_app_init();
	}
	
	inline ~app_t()
	{
		amt_app_destroy( m_app );
	}
	
	inline execute()
	{
		amt_app_execute( m_app );
	}

private:

	HAPP m_app;
};

class CGameObject
{
public:
	inline CGameObject(pos3i_t& position, pos2i_t& dimension, rect_t& box)
	{
		m_hObject = amt_gobj_init( &position, &dimension, &box );
	}
	
	inline ~CGameObject()
	{
		Destroy
	}
	
	inline void Destroy()
	{
		if ( m_hObject != NULL )
		{
			amt_gobj_destroy( m_hObject );
			m_hObject = NULL;
		}
	}
	
	inline bool UseCollision() const
	{
		return amt_gobj_get_use_collision( m_hObject ) == 1;
	}
	
	inline bool UseUpdate() const
	{
		return amt_gobj_get_use_update( m_hObject ) == 1;
	}
		
	inline bool UseRender() const
	{
		return amt_gobj_get_use_render( m_hObject ) == 1;
	}
	
	inline bool UseEvent() const
	{
		return amt_gobj_get_use_event( m_hObject) == 1;
	}

	inline bool UseCleanup() const
	{
		return amt_gobj_get_use_cleanup( m_hObject ) == 1;
	}
	
	inline bool UseTime() const
	{
		return amt_gobj_get_use_time( m_hObject ) == 1;
	}

	inline pos3i_t* GetPosition() const
	{
		return amt_gobj_get_position( m_hObject );
	}
	
	inline pos3i_t* GetVelocity() const
	{
		return amt_gobj_get_velocity( m_hObject );
	}
	
	inline pos2i_t* GetDimension() const
	{
		return amt_gobj_get_dimension( m_hObject );
	}

	
protected:

	HGAMEOBJECT m_hObject;
	
};

}
#endif