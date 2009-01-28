#ifndef __COLLADAMAYA_NODE_H__
#define __COLLADAMAYA_NODE_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"


namespace COLLADAMaya
{
	class MayaNode 	
    {
	private:
	
        /** The unique id of the object.*/
        COLLADAFW::UniqueId mUniqueId;

        /**
        * The name attribute is the text string name of the node.
        * The name has to be unique in maya.
        */
        String mName;

        /** The path of the current node. */
        String mPath;

        /**
         * The parent node.
         */
        MayaNode* mParent;

	public:

        MayaNode () : mParent (0), mName (""), mPath ("") {}
        MayaNode ( COLLADAFW::UniqueId uniqueId, const String name, MayaNode* parent = NULL ) 
            : mUniqueId ( uniqueId )
            , mName ( name )
            , mParent ( parent ) 
            , mPath ("")
        {}
        virtual ~MayaNode() {}

        /** Returns the unique id of the object.*/
        const COLLADAFW::UniqueId& getUniqueId() const { return mUniqueId; }

        /**
        * The parent node.
        */
        MayaNode* getParent () { return mParent; }
        const MayaNode* getParent () const { return mParent; }
        void setParent ( MayaNode* val ) 
        { 
            mParent = val; 
            mPath = "";
        }

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        const COLLADAMaya::String getName () const { return mName; }
        void setName ( COLLADAMaya::String val ) 
        { 
            mName = val; 
            mPath = "";
        }

        /**
         * Get's the node path of the current maya node.
         */
        const String getNodePath ();
        void setNodePath ( const COLLADAMaya::String& val ) { mPath = val; }

	};
} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_NODE_H__
