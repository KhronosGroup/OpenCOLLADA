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


#ifndef __COLLADASTREAMWRITER_IDLIST_H__
#define __COLLADASTREAMWRITER_IDLIST_H__

#include "COLLADAPrerequisites.h"

#include <set>

namespace COLLADA
{

    /** A class to generate and store unique and valid ids.*/

    class IDList
    {

    public:
        /** Constructor*/
        IDList() {}

        /** Destructor*/
        ~IDList() {}

        /** Takes the string @a newId, checks that it is a valid id, if necessary changes it to
        a valid id and adds it to the list of ids managed by IDList. If the id already exists a number
        is added to make it unique. The resulting string is returned*/
        String addId ( const String & newId );


    private:
        typedef std::set<String> IDSet;

        /** A map that stores ids that are already managed by this instance of IDList.*/
        IDSet mIdSet;

    };


}

#endif // #define __COLLADASTREAMWRITER_IDLIST_H__
