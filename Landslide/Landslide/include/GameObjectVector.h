//Vector used for holding the GameObjects...will be used for the Object Managers.

#include <vector>
#include <GameObject.h>
using std::vector;

class GameObjectPtrVector : public vector< GameObject* >
{
public:
	GameObjectPtrVector() {}
	~GameObjectPtrVector()
	{
		ResetContent();
	}

	void ResetContent()
	{
		if (size() == 0) return;

		GameObject** ppObjects = data();
		for (size_t n = 0; n < size(); n++)
		{
			delete ppObjects[n];
		}

		clear();

		GameObjectPtrVector().swap(*this);
	}

};