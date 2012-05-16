/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_INPUT_SHARED_H__
#define __COLLADASAXFWL_INPUT_SHARED_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADASaxFWLInputUnshared.h"

// TODO
#include "COLLADAFWConstants.h"

#include <COLLADABUURI.h>


namespace COLLADASaxFWL
{

    /** 
     * Declares the input semantics of a data source and connects a consumer to that source.
     * Note: There are two <input> variants; see also "<input> (unshared)."
     * The <input> element declares the input connections to a data source that a consumer requires. 
     * A data source is a container of raw data that lacks semantic meaning so that the data can be 
     * reused within the document. To use the data, a consumer declares a connection to it with the 
     * desired semantic information.
     * The <source> and <input> elements are part of the COLLADA dataflow model. This model is also
     * known as stream processing, pipe, or producer-consumer. An input connection is the dataflow 
     * path from a <source> to a sink (the dataflow consumers, which are <input>�s parents, such as 
     * <polylist>).
     * In COLLADA, all inputs are driven by index values. A consumer samples an input by supplying 
     * an index value to an input. Some consumers have multiple inputs that can share the same 
     * index values. Inputs that have the same offset attribute value are driven by the same index 
     * value from the consumer. This is an optimization that reduces the total number of indexes 
     * that the consumer must store. These inputs are described in this section as shared inputs but 
     * otherwise operate in the same manner as unshared inputs.
     */
    class InputShared : public InputUnshared
    {

    private:

        /** The offset into the list of indices defined by the parent element�s <p> or
        <v> subelement. If two <input> elements share the same offset, they are
        indexed the same. This is a simple form of compression for the list of
        indices and also defines the order in which the inputs are used. Required. */
        unsigned long long mOffset;

        /** Which inputs to group as a single set. This is helpful when multiple inputs
        share the same semantics. Optional. */
        unsigned long long mSet;

    public:

        /**
         * Default-Constructor.
         */
        InputShared () : 
          InputUnshared ()
        , mOffset ( 0 )
        , mSet ( 0 ) 
        {}

        /** 
         * Constructor.
         * @param semantic The semantic of the @a \<input\> element.
         * @param source The source of the @a \<input\> element.
         * @param offset The offset of the @a \<input\> element.
         * @param set The set of the @a \<input\> element.
         */
        InputShared ( InputSemantic::Semantic semantic, const COLLADABU::URI& source, unsigned long long offset = 0, unsigned long long set = 0 )
            : InputUnshared ( semantic, source )
            , mOffset ( offset )
            , mSet ( set ) 
        {}

		/** 
		* Constructor.
		* @param semantic The semantic of the @a \<input\> element.
		* @param source The source of the @a \<input\> element.
		* @param offset The offset of the @a \<input\> element.
		* @param set The set of the @a \<input\> element.
		*/
		InputShared ( const String& semantic, const String& source, unsigned long long offset = 0, unsigned long long set = 0 )
			: InputUnshared ( semantic, source )
			, mOffset ( offset )
			, mSet ( set ) 
		{}


        /** Destructor. */
        virtual ~InputShared() {}

        /** The offset into the list of indices defined by the parent element�s <p> or
        <v> subelement. If two <input> elements share the same offset, they are
        indexed the same. This is a simple form of compression for the list of
        indices and also defines the order in which the inputs are used. Required. */
        unsigned long long getOffset () const { return mOffset; }
        void setOffset ( unsigned long long val ) { mOffset = val; }

        /** Which inputs to group as a single set. This is helpful when multiple inputs
        share the same semantics. Optional. */
        unsigned long long getSet () const { return mSet; }
        void setSet ( unsigned long long val ) { mSet = val; }

    };

    /** Pointer to an array of input elements. */
    typedef COLLADAFW::ArrayPrimitiveType<InputShared*> InputSharedArray;

}

#endif // __COLLADASAXFWL_INPUT_SHARED_H__
