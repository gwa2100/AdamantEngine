#ifdef _WIN32
#include <Windows.h>
#endif

#include "amtengine.hpp"

class CBall : public adamantengine::CSprite
{
public:
	CBall() : adamantengine::CSprite( "test_ball.bmp" )
	{
		SetPosition( adamantengine::CPosition( 50.0f, 90.0f) );
		SetVelocity( adamantengine::CVelocity( 0.3f, 0.3f) );
		SetUseUpdate( true );
		SetUseCollision( true );
	}

	inline virtual void OnCollision( adamantengine::ECollisionType eCollisionType, float fXAmt, float fYAmt )
	{
		const pos2f_t* pVel = GetVelocity();
		adamantengine::CVelocity vel( pVel->x, pVel->y );

		if ( eCollisionType == adamantengine::eCOLLISION_TYPE_BOTTOM_X_CENTER)
		{
			vel.y = -0.3f;
		}
		else if ( eCollisionType == adamantengine::eCOLLISION_TYPE_Y_CENTER_RIGHT)
		{
			vel.x = -0.3f;
		}
		else if ( eCollisionType ==  adamantengine::eCOLLISION_TYPE_Y_CENTER_LEFT)
		{
			vel.x = 0.3f;
		}
		else if ( eCollisionType == adamantengine::eCOLLISION_TYPE_TOP_X_CENTER )
		{
			vel.y = 0.3f;
		}
		else if ( eCollisionType == adamantengine::eCOLLISION_TYPE_BOTTOM_RIGHT )
		{
			vel.y = -0.3f;
		}
		else if (eCollisionType == adamantengine::eCOLLISION_TYPE_TOP_LEFT )
		{
			vel.y = 0.4f;
		}
		else if (eCollisionType == adamantengine::eCOLLISION_TYPE_TOP_RIGHT )
		{
			vel.y = 0.4f;
		}
		else if ( eCollisionType == adamantengine::eCOLLISION_TYPE_BOTTOM_LEFT )
		{
			vel.y = -0.3f;
		}

		SetVelocity( vel );

		/*if ( eCollision & eCOLLISION_TOP )
		{
			m_position.y += fYAmt;
		}
		else if ( eCollision & eCOLLISION_BOTTOM )
		{
			m_position.y -= fYAmt;
		}
	
		if (  eCollision & eCOLLISION_LEFT )
		{
			m_position.x += fXAmt;
		}
		else if ( eCollision & eCOLLISION_RIGHT ) 
		{
			m_position.x -= fXAmt;
		}*/

	}
};


class CPaddle : public adamantengine::CSprite
{
public:
	CPaddle()
		: adamantengine::CSprite( "paddle.bmp" )
	{
		SetUseInput( true );
		SetPosition( adamantengine::CPosition( 2.0f, 565.0f ) );
		SetUseRender( true );
		SetUseUpdate( true );
	}

	inline virtual void OnInput( adamantengine::CVelocity& inputVelocity )
	{
		SetVelocity( adamantengine::CVelocity( inputVelocity.x, 0.0f ) );
	}
};

class CWall : public adamantengine::CGameObject
{
public:
	CWall(adamantengine::CPosition& pos, adamantengine::CDimension& dim)
		: adamantengine::CGameObject( pos, dim, adamantengine::CRectangle( pos.x, pos.y, dim.x, dim.y) ) 
	{
		
	}
};

class CBottomWall : public CWall
{
public:
	CBottomWall(CBall& ball) 
		: CWall( adamantengine::CPosition( 0.0f, 600.0f), adamantengine::CDimension( 800.0f, 50.0f ) )
		, theBall( ball )
	{
		SetUseCollision( true );
	}

	inline virtual void OnCollision( adamantengine::ECollisionType eCollisionType, float fXAmt, float fYAmt )
	{
		theBall.SetPosition( adamantengine::CPosition( 50.0f, 90.0f) );
		theBall.SetVelocity( adamantengine::CVelocity( 0.3f, 0.3f ) );
	}

private:

	CBall& theBall;
};

class CBrick : public adamantengine::CSprite
{
public:
	CBrick() : CSprite("brick1.bmp")
	{
		SetUseCollision( true );
		SetUseRender( true );
	}

	inline virtual void OnCollision( adamantengine::ECollisionType eCollisionType, float fXAmt, float fYAmt )
	{
		SetPosition( adamantengine::CPosition( -50.0f, -50.f ) );
	}
};


int main( int argc, char* argv[] )
{
//Remove the console..
#ifdef _WIN32
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
#endif
	adamantengine::CApp app;
	CBall Ball;
	CWall rSide( adamantengine::CPosition( 800.0f, 0.0f), adamantengine::CDimension( 50.0f, 599.0f) ),
		  lSide( adamantengine::CPosition( -50.0f, 0.0f), adamantengine::CDimension( 50.0f, 599.0f) ),
		  uSide( adamantengine::CPosition( 0.0f, -50.0f), adamantengine::CDimension( 800.0f, 50.0f) );
	CBottomWall bottom(Ball);
	CPaddle paddle;
	CBrick many[26];
	app.Bind( Ball );
	app.Bind( paddle );
	app.Bind( rSide );
	app.Bind( lSide );
	app.Bind( uSide );
	app.Bind( bottom );
	for(int n = 0; n < 26; n++ )
	{
		many[n].SetPosition( adamantengine::CPosition( 10.0f + (30.01f * n), 50.0f ) );
		app.Bind(many[n]);
	}
	return app.Execute();
}