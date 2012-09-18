#ifndef __GAMEOBJECTPTRVECTOR_HPP__
#define __GAMEOBJECTPTRVECTOR_HPP__

#include <vector>
using std::vector;

#include "../include/GameObject.hpp"

class CGameObjectPtrVector : public vector< CGameObject* >
{
    public:
    CGameObjectPtrVector() {}
    ~CGameObjectPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        CGameObject** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        CGameObjectPtrVector().swap( *this );
    }

};



#endif
