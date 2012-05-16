/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	  This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASW_CONTROLVERTICES_H__
#define __COLLADASW_CONTROLVERTICES_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWInputList.h"


namespace COLLADASW
{

    /** TODO Documentation */
	class ControlVertices : public ElementWriter 
	{
	private:
		/** List of all the inputs*/
		InputList mInputList;

	public:

        /** Constructor. */
		ControlVertices(StreamWriter* streamWriter);

        /** Destructor. */
		virtual ~ControlVertices();

		/** Add the control vertices element.*/
		void add();

		/** Returns a reference to the list of all the inputs*/
		InputList& getInputList() {	return mInputList;	}

	private:

        /** Disable default copy ctor. */
		ControlVertices( const ControlVertices& pre );

        /** Disable default assignment operator. */
		const ControlVertices& operator= ( const ControlVertices& pre );

	};

} // namespace COLLADASW

#endif // __COLLADASW_CONTROLVERTICES_H__
