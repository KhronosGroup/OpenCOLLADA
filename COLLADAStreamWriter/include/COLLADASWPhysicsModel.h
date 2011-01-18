/* * Contributor(s): Prabhath Jayathilake.*/

#ifndef __COLLADASTREAMWRITER_PHYSICS_MODEL_H__
#define __COLLADASTREAMWRITER_PHYSICS_MODEL_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class that hold all information about an @a \<Physics_model\> element.*/
    class PhysicsModel : public ElementWriter, public BaseExtraTechnique
    {

    private:

        // LibraryPhysicsModel should be able to call the add() method.
        friend class LibraryPhysicsModel;

        /** The id of the model.*/
        String mModelId;

        /** The name of the model.*/
        String mModelName;

		/** Closer to close the model*/
        TagCloser mModelCloser;

    public:

        

        /**
        * Constructor
        * @param modelId The id of the PhysicsModel.
        * @param modelName The name of the PhysicsModel.
        */
        PhysicsModel (
            StreamWriter* streamWriter,
            const String& modelId = ElementWriter::EMPTY_STRING,
            const String& modelName = ElementWriter::EMPTY_STRING );

        /** Destructor */
        virtual ~PhysicsModel()
        { }

        /** Returns a reference to the model id */
        const String& getModelId() const { return mModelId; }

        /** Returns a reference to the model name */
        const String& getModelName() const { return mModelName; }
        
		/** Opens the model tag
        It should be closed using close()*/
        void start();

		/** Closes the physics Model
        It must have been opened using open()*/
        void end() ;
    
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_PHYSICS_MODEL_H__
