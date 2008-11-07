/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADADomHelper.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_DOCUMENT_UTIL_H__
#define __COLLADA_DOCUMENT_UTIL_H__

#include "HelperPrerequisites.h"
#include "COLLADANodeTraverser.h"
#include <dae/daeDocument.h>

namespace COLLADADomHelper
{
    class DocumentUtil
    {
    public:
        /** Retrieves the meter attribute of the &lt;unit&gt; element for the given docuemnt.
            If no unit is set, the given default unit will be returned
        	@param doc The doc to get the unit from.
        	@param defaultUnitMeter A default value if there is no unit declaration.
        	@return The declared unit meter or default.
        */
        static domFloat getUnitMeter(daeDocument* doc, domFloat defaultUnitMeter);
		
		static domUpAxisType getUpAxis(daeDocument* doc);

		/** Creates a new daeDocument with the given ID or retrieves the existing document
			@param data, the database
			@param id, the id of the document
			@param the created or existing document.
			@return the result code.
		*/
		static daeInt createNewDocument(DAE* data, const std::string& id, daeDocument** document);

		static void loadReferencedDocuments(daeDocument* doc);
    };

	class ReferencedDocumentsLoader : public NodeTraverser::TraverserListener
	{
	public:
		ReferencedDocumentsLoader( void );
		virtual ~ReferencedDocumentsLoader( void );
		virtual void load( daeDocument* doc );

		virtual bool preDetectedNode(domNode& node, int level);
		virtual bool postDetectedNode(domNode& node, int level);
		virtual bool detectedInstanceNode(domInstance_node& instance, int level);
		virtual bool detectedInstanceGeometry(domInstance_geometry& instance, int level);
		virtual bool detectedInstanceLight(domInstance_light& instance, int level);
		virtual bool detectedInstanceCamera(domInstance_camera& instance, int level);
		virtual bool detectedNodeExtra(domExtra& extra, int level);

	};
}

#endif // __COLLADA_DOCUMENT_UTIL_H__
