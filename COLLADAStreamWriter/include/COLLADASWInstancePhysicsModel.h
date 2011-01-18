/* * Contributor(s): Prabhath Jayathilake.
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__
#define __COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
//#include "COLLADASWBindMaterial.h"
#include "COLLADABUURI.h"


#include <string>

namespace COLLADASW
{

    /** Class to write an @a \<instance_Physics_Model\> element to the stream*/
	class InstancePhysicsModel : public ElementWriter
    {

    private:
    
        /** The URL of the location of the object to instantiate.*/
        URI pmUrl,parentUrl;
		
		String mSid;
        
		String mName;

		 /** Flag, if it is an node instance. */
        bool mIsInstanceModel;


    public:

		 /** 
         * Constructor
         * @param url The url
         * @param sid The sid
         * @param name The name
        */
        InstancePhysicsModel ( StreamWriter* streamWriter, const URI& url, const URI& parent, const String &sid="", const String &name="")  
        : ElementWriter ( streamWriter )
        , pmUrl ( url )
        , mSid ( sid ) 
        , mName ( name )
		, parentUrl (parent)
        {}

		/** Destructor*/
		~InstancePhysicsModel(){}

        /** Sets the url of the instance Physics Model*/
        void setUrl ( const URI& url )
        {
            pmUrl=url;
        }

        /** Returns the url of the instance Physics Model*/
        const URI& getUrl()
        {
            return pmUrl;
        }
        
		const URI& getParent()
        {
            return parentUrl;
		}
        /** Closer to close the node*/
        TagCloser mIModelCloser;

	    /** Opens the model tag
        It should be closed using close()*/
        void start();

		/** Closes the node
        It must have been opened using open()*/
        void end() ;
    };


} //namespace COLLADASW




#endif //__COLLADASTREAMWRITER_INSTANCE_PHYSICS_MODEL_H__

