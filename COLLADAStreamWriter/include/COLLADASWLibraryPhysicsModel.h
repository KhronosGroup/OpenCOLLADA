#ifndef __COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODEL_H__
#define __COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODEL_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWLibrary.h"


namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_physics_model\> and @a \<physics_model\>'s*/
    class LibraryPhysicsModel : public Library, public BaseExtraTechnique
    {

    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_physics_model\> and @a \<physics_model\>'s
        should be written to.
        */
        LibraryPhysicsModel ( StreamWriter* streamWriter );

        /** Destructor*/
        virtual ~LibraryPhysicsModel() {}

    //protected:
        /** Writes the opening @a \<physics_model\> tag and, if necessary the opening @a \<library_physics_model\> tag.
        closePhysicsModel() must be use to close the opened tags.
        @param id the id of the physics model*/
        void openPhysicsModel ( const String& modelId = EMPTY_STRING, const String& modelName = EMPTY_STRING );

        /** Closes the tag opened by openPhysicsModel()*/
        void closePhysicsModel();


	 private:
        TagCloser mCurrentPhysicsModelCloser;  //!< Used to close the current Physics Model

    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODEL_H__
