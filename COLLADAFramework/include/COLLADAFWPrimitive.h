/*
    Copyright (c) 2008 NetAllied Systems GmbH

	This file is part of COLLADAFramework.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADAFW_PRIMITIVE_H__
#define __COLLADAFW_PRIMITIVE_H__

/**
 * The p element represents primitive data for the primitive types (lines,
 * linestrips, polygons,  polylist, triangles, trifans, tristrips). The p
 * element contains indices that reference into  the parent's source elements
 * referenced by the input elements.
 */
class Primitive
{

public:

    virtual COLLADA_TYPE::TypeEnum getElementType() const { return COLLADA_TYPE::P; }
	static daeInt ID() { return 617; }
	virtual daeInt typeID() const { return ID(); }

private:  

	/** The pointer to the value array of the text data of this element. */
	unsigned int* mValues;

    /** The size of the values array. */
    size_t mValuesCount;

public:	//Accessors and Mutators

    /**
    * Constructor
    */
    Primitive () : mValues() {}

    /**
    * Destructor
    */
    virtual ~Primitive() {}

    /**
	 * Gets the _value array.
	 * @return Returns a pointer to the _value array.
	 */
	unsigned int* getValues () { return mValues; }
	/**
	 * Gets the _value array.
	 * @return Returns a constant pointer to the _value array.
	 */
	const unsigned int* getValues () const { return mValues; }
	/**
	 * Sets the _value array.
	 * @param val The new value for the _value array.
	 */
	void setValues ( unsigned int* val ) { mValues = val; }

    /** The size of the values array. */
    const size_t getValuesCount () const { return mValuesCount; }
    void setValuesCount ( const size_t val ) { mValuesCount = val; }

	/**
	 * Overloaded assignment operator
	 */
	virtual Primitive &operator=( const Primitive &cpy ) { (void)cpy; return *this; }

};


#endif // __COLLADAFW_PRIMITIVE_H__
