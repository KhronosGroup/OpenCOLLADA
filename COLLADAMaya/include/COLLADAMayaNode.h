#ifndef __COLLADAMAYA_NODE_H__
#define __COLLADAMAYA_NODE_H__

#include "COLLADAMayaPrerequisites.h"

#include "COLLADAFWUniqueId.h"


namespace COLLADAMaya
{
    /**
     * This class exist to have the node path for a node.
     */
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

        /**
         * The flag, if the node is positioned at the right place. Default is true.
         * But if a node from <library_nodes> is created, we have to move it later 
         * (the right position in the scene graph depends on the first implementation from there).
         */
        bool mIsCorrectPositioned;

	public:

        MayaNode ();

        /**
         * Constructor.
         * Copy the uniqueId!
         */
        MayaNode ( 
            const COLLADAFW::UniqueId uniqueId, 
            const String name, 
            MayaNode* parent = NULL, 
            const bool isCorrectPositioned=true );

        virtual ~MayaNode() {}

        /** 
         * Returns the unique id of the object.
         */
        const COLLADAFW::UniqueId& getUniqueId() const { return mUniqueId; }

        /**
        * The parent node.
        */
        MayaNode* getParent () { return mParent; }
        const MayaNode* getParent () const { return mParent; }
        void setParent ( MayaNode* val );

        /**
        * The name attribute is the text string name of this element. 
        * Optional attribute.
        */
        const COLLADAMaya::String getName () const { return mName; }
        void setName ( COLLADAMaya::String val );

        /**
         * Get's the node path of the current maya node.
         */
        const String getNodePath ();
        void setNodePath ( const COLLADAMaya::String& val ) { mPath = val; }

        /**
        * The flag, if the node is already created. Default is true;
        */
        const bool getIsCorrectPositioned () const { return mIsCorrectPositioned; }
        void setIsCorrectPositioned ( const bool val ) { mIsCorrectPositioned = val; }

	};
} // namespace COLLADAMAYA

#endif // __COLLADAMAYA_NODE_H__
