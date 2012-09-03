
<<<<<<< HEAD
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "App.h"
//#include <iostream>
//using std::

void CApp::OnLoop()
{
    //TODO: Write code for sending events to object event processor.
    //Run Update
    size_t uSize = m_arObjectList.size();
    if ( uSize == 0 ) return;

    CGameObject** ppObjects = m_arObjectList.data();

    for (size_t x = 0; x < uSize; x++) {
        if (ppObjects[x]->GetUsesUpdate() )
        {
           ppObjects[x]->Update();
        }
    }
}
=======
>>>>>>> Changes to breakout and collision
