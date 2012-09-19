#ifndef __COLLISION_ITEM_HPP__
#define __COLLISION_ITEM_HPP__

#include "../include/PositionDataTypes.hpp"
#include <vector>
#include <stddef.h>

enum ECollision
{
    eCOLLISION_NONE             = 0x0,
    eCOLLISION_TOP              = 0x1,
    eCOLLISION_BOTTOM           = 0x2,
    eCOLLISION_LEFT             = 0x4,
    eCOLLISION_RIGHT            = 0x8,
    eCOLLISION_X_CENTER         = 0xC,
    eCOLLISION_Y_CENTER         = 0x3,
    eCOLLISION_LEFT_SIDE        = 0x40,
    eCOLLISION_RIGHT_SIDE       = 0x80,
    eCOLLISION_TOP_LEFT         = 0x5,  //Combination of eCOLLISION_TOP      | eCOLLISION_LEFT
    eCOLLISION_TOP_RIGHT        = 0x9,  //Combination of eCOLLISION_TOP      | eCOLLISION_RIGHT
    eCOLLISION_BOTTOM_LEFT      = 0x6,  //Combination of eCOLLISION_BOTTOM   | eCOLLISION_LEFT
    eCOLLISION_BOTTOM_RIGHT     = 0xA,  //Combination of eCOLLISION_BOTTOM   | eCOLLISION_RIGHT
    eCOLLISION_TOP_X_CENTER     = 0xD, //Combination of eCOLLISION_TOP      | eCOLLISION_X_CENTER
    eCOLLISION_BOTTOM_X_CENTER  = 0xE, //Combination of eCOLLISION_BOTTOM   | eCOLLISION_X_CENTER
    eCOLLISION_Y_CENTER_LEFT    = 0x7, //Combination of eCOLLISION_Y_CENTER | eCOLLISION_LEFT
    eCOLLISION_Y_CENTER_RIGHT   = 0xB  //Combination of eCOLLISION_Y_CENTER | eCOLLISION_RIGHT
};

struct CCollisionItem
{
    CCollisionItem( const CRect& rect, size_t uIndex)
        : m_rcBoundingBox( rect )
        , m_uIndex( uIndex )
    {
    }

    CRect m_rcBoundingBox;
    size_t m_uIndex;
};

struct CFindHit
{
	CFindHit(CRect& rect, size_t n)
		: nIndex(n)
		, toFind( rect )
	{

	}

	bool operator()(const CCollisionItem& item )
	{
		if ( nIndex == item.m_uIndex ) return false;

		if (toFind.bottom < item.m_rcBoundingBox.top) return false;
        if (toFind.top > item.m_rcBoundingBox.bottom) return false;

        if (toFind.right < item.m_rcBoundingBox.left) return false;
        if (toFind.left > item.m_rcBoundingBox.right) return false;

        return true;
	}

	size_t nIndex;
	CRect& toFind;
};

class CCollisionItemVector : public std::vector< CCollisionItem >
{
    public:
    CCollisionItemVector(){}
    ~CCollisionItemVector(){}
};


#endif
