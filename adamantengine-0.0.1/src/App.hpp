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

		struct CRect
		{
			inline CRect( const pos3i_t& position, const pos2i_t& dimension )
				: top( position.y )
				, left( position.x )
				, bottom( top + dimension.y)
				, right( left + dimension.x )
			{

			}

			inline CRect( const CRect& rect)
				: top( rect.top)
				, left( rect.left)
				, bottom( rect.bottom)
				, right( rect.right )
			{


			}

			long top;
			long left;
			long bottom;
			long right;
		};

		struct CCollisionItem
		{
			inline CCollisionItem( const CRect& rect, size_t uIndex)
				: m_rcBoundingBox( rect )
				, m_uIndex( uIndex )
			{
			}

			CRect m_rcBoundingBox;
			size_t m_uIndex;
		};

		struct CSortCollision
		{
			bool operator()(const CCollisionItem& left, const CCollisionItem& right)
			{
				return left.m_rcBoundingBox.left < right.m_rcBoundingBox.left;
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