/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "COLLADAIDList.h"
#include "COLLADAUtils.h"

namespace COLLADA
{



    String IDList::addId ( const String & newId )
    {
        String newIdChecked = Utils::checkID ( newId );

        IDSet::iterator it = mIdSet.find ( newIdChecked );

        if ( it == mIdSet.end() )
        {
            mIdSet.insert ( newIdChecked );
            return newIdChecked;
        }

        String idCanditate;

        size_t numberSuffix = 0;

        do
        {
            numberSuffix++;
            idCanditate = newIdChecked + Utils::toString ( numberSuffix );
        }

        while ( mIdSet.find ( idCanditate ) != mIdSet.end() );

        mIdSet.insert ( idCanditate );

        return idCanditate;

    }




}