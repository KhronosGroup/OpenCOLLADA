/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWStreamWriter.h"
#include "COLLADASWTechnique.h"
#include "COLLADASWConstants.h"

#include "COLLADASWParamBase.h"
#include "COLLADASWParamTemplate.h"

namespace COLLADASW
{
    //---------------------------------------------------------------
    void Technique::openTechnique ( const String &profile, const String &xmlns )
    {
        mTechniqueCloser = mSW->openElement ( CSWC::CSW_ELEMENT_TECHNIQUE );

        mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_PROFILE, profile );

        if ( !xmlns.empty() )
            mSW->appendAttribute ( CSWC::CSW_ATTRIBUTE_XMLNS, xmlns );
    }

    //---------------------------------------------------------------
    void Technique::addChildElement ( const String &childElementName )
    {
        TagCloser childElementCloser = mSW->openElement ( childElementName );

        mOpenChildElements[childElementName] = childElementCloser;
    }

	//---------------------------------------------------------------
	void Technique::addCustomChildElement(const String &childElementName, const String& attributeName, const String& attributeValue)
	{
		TagCloser childElementCloser = mSW->openElement(childElementName);

		if (!attributeName.empty())
		{
			mSW->appendAttribute(attributeName, attributeValue);
		}

		mOpenChildElements[childElementName] = childElementCloser;
	}

    //---------------------------------------------------------------
    void Technique::closeChildElement ( const String &childElementName )
    {
        TagCloser& childElementCloser = mOpenChildElements[childElementName];

        childElementCloser.close();
    }

    //---------------------------------------------------------------
    void Technique::addValue ( const String& value )
    {
        if ( !value.empty() )
            mSW->appendTextBlock ( value );
    }

    //---------------------------------------------------------------
    void Technique::addElement(const String & tagName, const String & attributeName, const String & attributeValue)
    {
        mSW->openElement(tagName);

        if (!attributeName.empty())
        {
            mSW->appendAttribute(attributeName, attributeValue);
        }

		mSW->closeElement();
    }

	//---------------------------------------------------------------
	void Technique::addElement(const String & tagName, const float & attributeValue)
	{
		mSW->openElement(tagName);

		mSW->appendValues(attributeValue);

		mSW->closeElement();
	}

	//---------------------------------------------------------------
	void Technique::addElement(const String & tagName, const String & attributeValue)
	{
		mSW->openElement(tagName);

		mSW->appendValues(attributeValue);

		mSW->closeElement();
	}


	void Technique::addParameterURL(const String &paramName, const String &url)
	{
		mSW->openElement(paramName);
		if (!url.empty())
			mSW->appendURIAttribute(CSWC::CSW_ATTRIBUTE_URL, url);
			//mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_URL, url);
		mSW->closeElement();
	}

	//---------------------------------------------------------------
	void Technique::addParameter(const String &paramName, const String &value, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
	void Technique::addParameter(const String &paramName, const bool &value, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
	void Technique::addParameter(const String &paramName, const int &value, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const int &value0, const int &value1, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const int &value0, const int &value1, const int &value2, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		int values[] = { value0, value1, value2 };
		mSW->appendValues(values, 3);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
	void Technique::addParameter(const String &paramName, const double &value, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const double &value0, const double &value1, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const double &value0, const double &value1, const double &value2, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1, value2);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const double &value0, const double &value1, const double &value2, const double &value3, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1, value2, value3);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
	void Technique::addParameter(const String &paramName, const float &value, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const float &value0, const float &value1, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::addParameter(const String &paramName, const float &value0, const float &value1, const float &value2, const String &sid, const String &type, const String& tagName)
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(value0, value1, value2);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
	void Technique::addMatrixParameter(const String &paramName, const double matrix[][4], const String &sid, const String &type, const String& tagName) const
    {
		mSW->openElement(tagName == "" ? paramName : tagName);
		if (!sid.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, sid);
		else if (!paramName.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_SID, paramName);
		if (!type.empty())
			mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_TYPE, type);
		mSW->appendValues(matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3]);
		mSW->appendValues(matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3]);
		mSW->appendValues(matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3]);
		mSW->appendValues(matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]);
		mSW->closeElement();
    }

    //---------------------------------------------------------------
    void Technique::closeTechnique()
    {
        mTechniqueCloser.close();
    }

} //namespace COLLADASW
