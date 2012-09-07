#ifndef __APP_HPP__
#define __APP_HPP__

#include <SDL_events.h>
#include "GameObject.hpp"
#include "../include/amtengine.h"
#include <vector>
#include <algorithm>
using std::vector;

struct SDL_Surface;

namespace adamantengine {

	namespace collision {

		struct CRectF
		{
			inline CRectF( const pos3f_t& position, const pos2f_t& dimension )
				: top( position.y )
				, left( position.x )
				, bottom( top + dimension.y)
				, right( left + dimension.x )
			{

			}

			inline CRectF( const CRectF& rect)
				: top( rect.top)
				, left( rect.left)
				, bottom( rect.bottom)
				, right( rect.right )
			{


			}

			bool PtInRect( const pos3f_t& position ) const
			{
				if ( left <= position.x && right >= position.x &&
					 top <= position.y && bottom >= position.y )
				{
					return true;
				}

				return false;
			}

			struct vector2
			{
				vector2( float xx, float yy )
					:x(xx),y(yy)
				{
				}
				float x,y;
			};

			bool LineInRect( vector2 a, vector2 b, vector2 c, vector2 d ) const
			{
				float q = (a.y - b.y) * (c.x - d.x) - (a.x - b.x) * (c.y - d.y);

				if ( q == 0.0f ) return false;

				float t = (a.x * b.y - b.x * a.y + b.x * c.y - c.x * b.y + c.x * a.y - a.x * c.y) / q;

				if ( !(t > 0.0f && t < 1.0f ) ) return false;
				
				float s = (c.x * d.y - d.x * c.y + d.x * a.y - a.x * d.y + a.x * c.y - c.x * a.y) / q;
				return s > 0.0f && s < 1.0f;
			}

			bool LineInRect( const pos3f_t& p1, const pos3f_t& p2 ) const
			{
				vector2 c( p1.x,p1.y);
				vector2 d( p2.x,p2.y);

				if ( LineInRect( vector2( left, top), vector2( right, top), c , d ) )
					return true;

				if ( LineInRect( vector2( left, bottom), vector2( right, bottom), c , d ) )
					return true;

				if ( LineInRect( vector2( left, top), vector2( left, bottom), c , d ) )
					return true;

				if ( LineInRect( vector2( right, top), vector2( right, bottom), c , d ) )
					return true;

				return false;
			}

			float Width()
			{
				return right - left;
			}

			float Height()
			{
				return bottom - top;
			}

			float top;
			float left;
			float bottom;
			float right;
		};

		struct CCollisionItem
		{
			inline CCollisionItem( const CRectF& rect, size_t uIndex)
				: m_rcBoundingBox( rect )
				, m_uIndex( uIndex )
			{
			}

			CRectF m_rcBoundingBox;
			size_t m_uIndex;
		};

		struct CSortCollision
		{
			bool operator()(const CCollisionItem& left, const CCollisionItem& right)
			{
				float lMid = (left.m_rcBoundingBox.left + left.m_rcBoundingBox.right) / 2;
				float rMId = (right.m_rcBoundingBox.left + right.m_rcBoundingBox.right) / 2;

				return lMid < rMId;
			}
		};

		class CCollisionItemVector : public vector< CCollisionItem >
		{
			public:
			inline CCollisionItemVector(){}

			inline void Sort()
			{
				std::sort( begin(), end(), CSortCollision());
			}
		};
	}


class app_t
{
	DEFPROPERTY( DetectOffscreenCollision, bool, m_bDetectOffscreenCollision )

public:
	app_t();
	~app_t();
	
	bool Intialize();
	int Execute();
	void BindObject( gameobject_t* object );
private:
	
	void OnEvent(SDL_Event& anevent);
	void OnUpdate();
	void OnRender();
	void OnCleanup();  

	void CollisionDetection(collision::CCollisionItemVector& arItems);

	bool m_bRunning;
	gameobject_array_t m_arObjects;
	SDL_Surface* m_pSurfDisplay;
};


}


#endif