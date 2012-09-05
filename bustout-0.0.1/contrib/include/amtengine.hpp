#ifndef __AMTENGINE_HPP__
#define __AMTENGINE_HPP__

#include "amtengine.h"
#include <string>
using std::string;

namespace adamantengine {

class CVelocity : public pos2f_t
{
public:
	CVelocity( float xSpeed, float ySpeed )
	{
		x = xSpeed;
		y = ySpeed;
	}
};

class CPosition : public pos3f_t
{
public:
	CPosition( float xPos, float yPos )
	{
		x = xPos;
		y = yPos;
		z = 0.0f;
	}
};

class CDimension : public pos2f_t
{
public:
	CDimension( float xDim, float yDim )
	{
		x = xDim;
		y = yDim;
	}
};

class CRectangle : public rect_t
{
public:
	CRectangle( int x, int y, int w, int h )
	{
		top = y;
		left = x;
		width = w;
		height = h;
	}

	CRectangle( float x, float y, float w, float h )
	{
		top = (int)y;
		left = (int)x;
		width = (int)w;
		height = (int)h;
	}
	
	CRectangle( CPosition& pos, CDimension& dim )
	{
		top = (int)pos.y;
		left = (int)pos.x;
		width = (int)dim.x;
		height = (int)dim.y;
	}
};

class CGameObject
{
	friend class CApp;
	
public:
	inline CGameObject(CPosition& position, CDimension& dimension, rect_t& box)
	{
		m_hObject = amt_gobj_init( &position, &dimension, &box );
	}
	
	inline ~CGameObject()
	{
		Destroy();
	}
	
	inline void Destroy()
	{
		if ( m_hObject != 0 )
		{
			amt_gobj_destroy( m_hObject );
			m_hObject = 0;
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

	inline pos3f_t* GetPosition() const
	{
		return amt_gobj_get_position( m_hObject );
	}
	
	inline pos2f_t* GetVelocity() const
	{
		return amt_gobj_get_velocity( m_hObject );
	}
	
	inline pos2f_t* GetDimension() const
	{
		return amt_gobj_get_dimension( m_hObject );
	}

	inline void SetUseRender( bool bValue )
	{
		amt_gobj_set_use_render( m_hObject, bValue ? 1 : 0 );
	}
	
	inline void SetUseUpdate( bool bValue )
	{
		amt_gobj_set_use_update( m_hObject, bValue ? 1 : 0 );
	}

	inline void SetUseCollision( bool bValue )
	{
		amt_gobj_set_use_collision( m_hObject, bValue ? 1 : 0 );
	}
	
	inline void SetVelocity( CVelocity& velocity )
	{
		amt_gobj_set_velocity( m_hObject, &velocity );
	}
	
	inline void SetPosition( CPosition& position )
	{
		amt_gobj_set_position( m_hObject, &position );
	}
protected:
	inline CGameObject()
	{
	}


	HGAMEOBJECT m_hObject;
	
};

class CSprite : public CGameObject
{
public:
	inline CSprite(const string& sFilename)
	{
		m_hObject = amt_spr_create( sFilename.c_str() );
		SetUseRender( true );
		amt_gobj_set_userdata( m_hObject, this );
		amt_gobj_on_render( m_hObject, &CSprite::InternalRender );
	}

	inline virtual void Render( void* pDestSurface )
	{
		pos3f_t* pos = GetPosition();
		pos2f_t* dim = GetDimension();
		rect_t dest_rc = {0};
		dest_rc.left = (int)pos->x;
		dest_rc.top = (int)pos->y;
		dest_rc.width = (int)dim->x;
		dest_rc.height = (int)dim->y;
		amt_blit( m_hObject, NULL, pDestSurface, &dest_rc );
	}
	
protected:

	
private:
	static void __stdcall InternalRender( HGAMEOBJECT hObj, void* pDestSurface, void* userdata )
	{
		CSprite* This = (CSprite*)userdata;
		This->Render( pDestSurface );
	}
};

class CApp
{
public:
	inline CApp()
	{
		m_app = amt_app_init();
	}
	
	inline ~CApp()
	{
		amt_app_destroy( m_app );
	}
	
	inline int Execute()
	{
		return amt_app_execute( m_app );
	}
	
	inline void Bind( CGameObject& object )
	{
		amt_app_object_bind( m_app, object.m_hObject );
	}

private:

	HAPP m_app;
};


}
#endif