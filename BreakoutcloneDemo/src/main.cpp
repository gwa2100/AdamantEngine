#include <adamantengine.hpp>

class CBall : public CSprite
{
public:
	CBall()
	{
	    CreateFromFile("test_ball.bmp");
		SetPosition( Pos3f( 50.0f, 90.0f) );
		SetVelocity( Pos2f( 0.3f, 0.3f) );
		SetUpdate( true );
		SetCollision( true );
		SetRender(true);
	}

protected:

	inline virtual void OnCollision( ECollision eCollisionType, float fXAmt, float fYAmt )
	{
		const Pos3f& pVel = GetVelocity();
		Pos2f vel( pVel.x, pVel.y );

		if ( eCollisionType == eCOLLISION_BOTTOM_X_CENTER)
		{
			vel.y = -0.3f;
		}
		else if ( eCollisionType == eCOLLISION_Y_CENTER_RIGHT)
		{
			vel.x = -0.3f;
		}
		else if ( eCollisionType ==  eCOLLISION_Y_CENTER_LEFT)
		{
			vel.x = 0.3f;
		}
		else if ( eCollisionType == eCOLLISION_TOP_X_CENTER )
		{
			vel.y = 0.3f;
		}
		else if ( eCollisionType == eCOLLISION_BOTTOM_RIGHT )
		{
			vel.y = -0.3f;
		}
		else if (eCollisionType == eCOLLISION_TOP_LEFT )
		{
			vel.y = 0.4f;
		}
		else if (eCollisionType == eCOLLISION_TOP_RIGHT )
		{
			vel.y = 0.4f;
		}
		else if ( eCollisionType == eCOLLISION_BOTTOM_LEFT )
		{
			vel.y = -0.3f;
		}

		SetVelocity( vel );
	}
};


class CPaddle : public CSprite
{
public:
	CPaddle()
	{
	    CreateFromFile("paddle.bmp");
		SetEvent( true );
		SetPosition( Pos3f( 2.0f, 565.0f ) );
		SetRender( true );
		SetUpdate( true );
	}

protected:

	inline virtual void Event( const Pos3f& inputVelocity )
	{
		SetVelocity( Pos2f( inputVelocity.x, 0.0f ) );
	}
};

class CWall : public CGameObject
{
public:
	CWall(const Pos3f& pos, const Pos2f& dim)
		: CGameObject( pos, dim, CRect( pos.x, pos.y, dim.x, dim.y) )
	{

	}
};

class CBottomWall : public CWall
{
public:
	CBottomWall(CBall& ball)
		: CWall( Pos3f( 0.0f, 600.0f), Pos2f( 800.0f, 50.0f ) )
		, theBall( ball )
	{
		SetCollision( true );
	}

protected:

	inline virtual void OnCollision( ECollision eCollisionType, float fXAmt, float fYAmt )
	{
		theBall.SetPosition( Pos3f( 50.0f, 90.0f) );
		theBall.SetVelocity( Pos2f( 0.3f, 0.3f ) );
	}

private:

	CBall& theBall;
};

class CBrick : public CSprite
{
public:
	CBrick()
	{
	    CreateFromFile("brick1.bmp");
		SetCollision( true );
		SetRender( true );
	}

protected:

	inline virtual void OnCollision( ECollision eCollisionType, float fXAmt, float fYAmt )
	{
		SetPosition( Pos3f( -50.0f, -50.f ) );
	}
};


int main( int argc, char* argv[])
{
    IEngine* app = GetEngine();
    app->Initialize();

	CBall* Ball = new CBall;
	CWall *rSide = new CWall( Pos3f( 800.0f, 0.0f), Pos2f( 50.0f, 599.0f) ),
		  *lSide = new CWall( Pos3f( -50.0f, 0.0f), Pos2f( 50.0f, 599.0f) ),
		  *uSide = new CWall( Pos3f( 0.0f, -50.0f), Pos2f( 800.0f, 50.0f) );
	CBottomWall* bottom = new CBottomWall(*Ball);
	CPaddle* paddle = new CPaddle;
	CBrick* many[26];
	app->Bind( Ball );
	app->Bind( paddle );
	app->Bind( rSide );
	app->Bind( lSide );
	app->Bind( uSide );
	app->Bind( bottom );
	for(int n = 0; n < 26; n++ )
	{
	    many[n] = new CBrick;
		many[n]->SetPosition( Pos3f( 10.0f + (30.01f * n), 50.0f ) );
		app->Bind(many[n]);
	}

    int nRetval = app->Execute();

    delete app;

    return nRetval;
}
