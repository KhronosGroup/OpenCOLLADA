/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_RIGID_BODIES_H__
#define __COLLADASTREAMWRITER_INSTANCE_RIGID_BODIES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADABUURI.h"
#include "COLLADASWTechnique.h"

namespace COLLADASW
{

    /** A class that holds informations of an @a \<instance_rigid_bodies\> element and writes it to stream. */
    class InstanceRigidBody : public ElementWriter
    {

    private:

        /** The url to the rigid body information (library_physics_models) */
        URI mUrl;
        String mSid;
        String mName;
		URI mTarget;
		Technique *mTech;

    public:
        /** 
         * Constructor
         * @param url The url
         * @param sid The sid
         * @param name The name
        */
        InstanceRigidBody ( StreamWriter* streamWriter, const URI& url, const URI& target, String sid="", String name="" )  
        : ElementWriter ( streamWriter )
        , mUrl ( url )
		, mTarget ( target )
        , mSid ( sid ) 
        , mName ( name )
		{  
			mTech = new Technique( streamWriter );
		}

        /** Returns the url */
        const URI& getUrl() const
        {
            return mUrl;
        }

        /** Returns the sid */
        const String& getSid() const
        {
            return mSid;
        }

        /** Returns the name */
        const String& getName() const
        {
            return mName;
        }

        /** Write the instance rigid body to the stream*/
        void add();

    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_RIGID_BODY_H__
