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
			inline CRect( const pos3f_t& position, const pos2f_t& dimension )
				: top( (long)position.y )
				, left( (long)position.x )
				, bottom( top + (long)dimension.y)
				, right( left + (long)dimension.x )
			{

			}

			inline CRect( const CRect& rect)
				: top( rect.top)
				, left( rect.left)
				, bottom( rect.bottom)
				, right( rect.right )
			{


			}

			long Width()
			{
				return right - left;
			}

			long Height()
			{
				return bottom - top;
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
				long lMid = (left.m_rcBoundingBox.left + left.m_rcBoundingBox.right) / 2;
				long rMId = (right.m_rcBoundingBox.left + right.m_rcBoundingBox.right) / 2;

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