#ifndef __COLLADASTREAMWRITER_RIGIDBODY_SHAPE_H__
#define __COLLADASTREAMWRITER_RIGIDBODY_SHAPE_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWStreamWriter.h"
#include "COLLADASWExtraTechnique.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** A class that hold all information about an @a \<camera\> element.*/
    class Shape : public ElementWriter, public BaseExtraTechnique
    {

    private:

		// Rigid Body should be able to call the add() method.
        friend class RigidBody;

	protected:

		/* Flags */
		bool mHasDensity;
		bool mHasMass;
		bool mHasHollow;

		/** The density of the shape. */
        float mDensity;
        String mDensitySid;

        /** The Mass of the Shape */
        float mMass;
        String mMassSid;

		/** Whether the Shape is Hollow, i.e the mass is distributed 
		    along the surface of the Shape */
        bool mHollow;
        String mHollowSid;

		/** Adds the shapes information. */
        void add() const;

        /** Adds the shape type specific information. */
        virtual void addTypeSpecificInfos () const = 0;

    public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Shape ( StreamWriter* streamWriter );

        /** Destructor */
        virtual ~Shape() {}

		 /** The Density of the shape */
        void setDensity ( float val, const String& sid="" ) { mDensity = val; mDensitySid = sid; mHasDensity = true; }
		void setDnesity( const float val, const bool useDefaultSid, const String& sid=""  );
		/** Returns the default sid used for the density element*/ 
		static const String& getDensityDefaultSid() { return CSWC::CSW_ELEMENT_DENSITY; }


		 /** The Mass of the shape */
        void setMass ( float val, const String& sid="" ) { mMass = val; mMassSid = sid; mHasMass = true; }
		void setMass( const float val, const bool useDefaultSid, const String& sid=""  );
		/** Returns the default sid used for the density element*/ 
		static const String& getMassDefaultSid() { return CSWC::CSW_ELEMENT_MASS; }

		 /** Is the shape hollow.  */
        void setHollow ( bool val, const String& sid="" ) { mHollow = val; mMassSid = sid; mIsHollow = true; }
		void setHollow( const float val, const bool useDefaultSid, const String& sid=""  );
		/** Returns the default sid used for the density element*/ 
		static const String& getMassDefaultSid() { return CSWC::CSW_ELEMENT_HOLLOW; }

	};

	class Box : public Shape
	{
	public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Box ( StreamWriter* streamWriter )
        : Shape ( streamWriter )
        {}

        virtual ~Box() {}

    protected:

        /** Adds the shape type specific information. */
        void addTypeSpecificInfos () const;

    };

	class Sphere : public Shape
	{
	public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Sphere ( StreamWriter* streamWriter )
        : Shape ( streamWriter )
        {}

        virtual ~Sphere() {}

    protected:

        /** Adds the shape type specific information. */
        void addTypeSpecificInfos () const;

    };

	class Cylinder : public Shape
	{
	public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Cylinder ( StreamWriter* streamWriter )
        : Shape ( streamWriter )
        {}

        virtual ~Cylinder() {}

    protected:

        /** Adds the shape type specific information. */
        void addTypeSpecificInfos () const;

    };


	class Capsule : public Shape
	{
	public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Capsule ( StreamWriter* streamWriter )
        : Shape ( streamWriter )
        {}

        virtual ~Capsule() {}

    protected:

        /** Adds the shape type specific information. */
        void addTypeSpecificInfos () const;

    };

    class Plane : public Shape
	{
	public:

        /** 
        * Constructor
        * @param shapeId The id of the shape.
        * @param shapeName The name of the shape.
        */
        Plane ( StreamWriter* streamWriter )
        : Shape ( streamWriter )
        {}

        virtual ~Plane() {}

    protected:

        /** Adds the shape type specific information. */
        void addTypeSpecificInfos () const;

    };


}//namespace COLLADASW

#endif __COLLADASTREAMWRITER_RIGIDBODY_SHAPE_H__