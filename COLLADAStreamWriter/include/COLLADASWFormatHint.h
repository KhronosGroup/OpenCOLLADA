/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_FORMAT_HINT_H__
#define __COLLADASTREAMWRITER_FORMAT_HINT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWExtraTechnique.h"

namespace COLLADASW
{

    /** <format_hint> is a child element of <surface>.
    An application uses <format_hint> if <format> does
    not exist or is not understood by the application and
    <format_hint> exists. This element describes the
    important features intended by the author so that the
    application can pick a format that best represents what
    the author wanted. */
    class FormatHint : public ElementWriter, public BaseExtraTechnique
    {

    public:

        /** Contains an enumeration value that describes the per-texel
        layout of the format. The length of the enumeration string
        indicates how many channels there are and each letter
        represents the name of a channel. There are typically 1 to 4
        channels. This element has no attributes.
        Valid enumeration values are:
        � RGB: Red/Green/Blue color map.
        � RGBA: Red/Green/Blue/Alpha map, often used
        for color and transparency or other things packed
        into channel A, such as specular power.
        � L: Luminance map, often used for light mapping.
        � LA: Luminance/Alpha map, often used for light
        mapping.
        � D: Depth map, often used for displacement,
        parallax, relief, or shadow mapping.
        � XYZ: Typically used for normal maps or threecomponent
        displacement maps.
        � XYZW: Typically used for normal maps, where W
        is the depth for relief or parallax mapping. */
        enum Channels
        {
            RGB, 
            RGBA,
            L,
            LA,
            D,
            XYZ,
            XYZW,
            UNKNOWN_CHANNEL
        };

        /** Contains an enumeration that describes the range of texel
        channel values. Each channel represents a range of values.
        Some example ranges are signed or unsigned integers, or
        are within a clamped range such as 0.0f to 1.0f, or are a
        high dynamic range via floating point. This element has no
        attributes.
        Valid enumeration values are:
        � SNORM: Format represents a decimal value that
        remains within the -1 to 1 range. Implementation
        could be integer, fixed-point, or float.
        � UNORM: Format represents a decimal value that
        remains within the 0 to 1 range. Implementation
        could be integer, fixed-point, or float.
        � SINT: Format represents signed integer numbers;
        for example, 8 bits can represent -128 to 127.
        � UINT: Format represents unsigned integer
        numbers. For example, 8 bits can represent 0 to
        255.
        � FLOAT: Format should support full floating-point
        ranges typically used for high dynamic range. */
        enum Range
        {
            SNORM, 
            UNORM, 
            SINT, 
            UINT,
            FLOAT,
            UNKNOWN_RANGE
        };

        /** Contains an enumeration that identifies the precision of the
        texel channel value.Each channel of the texel has a
        precision. Typically, channels have the same precision. An
        exact format may lower the precision of an individual
        channel but applying a higher precision by linking the
        channels may still convey the same information. This
        element has no attributes.
        Valid enumeration values are:
        � LOW: For integers, this typically represents 8 bits.
        For floats, typically 16 bits.
        � MID: For integers, this typically represents 8 to 24
        bits. For floats, typically 16 to 32 bits.
        � HIGH: For integers, this typically represents 16 to
        32 bits. For floats, typically 24 to 32 bits. */
        enum Precision
        {
            LOW, 
            MID, 
            HIGH, 
            UNKNOWN_PRECISION
        };

        /** Contains additional hints about data relationships and other
        things to help an application pick the best format. This
        element has no attributes.
        Valid enumeration values are:
        � SRGB_GAMMA: Colors are stored with respect
        to the sRGB 2.2 gamma curve rather than linear.
        � NORMALIZED3: The texel�s XYZ/RGB should be
        normalized such as in a normal map.
        � NORMALIZED4: The texel�s XYZW/RGBA should
        be normalized such as in a normal map.
        � COMPRESSABLE: The surface may use run-time
        compression. Consider the best compression
        based on desired <channels>, <range>,
        <precision>, and <option>s. */
        enum Option
        {
            SRGB_GAMMA, 
            NORMALIZED3, 
            NORMALIZED4, 
            COMPRESSABLE, 
            UNKNOWN_OPTIONS
        };

    private:
        
        /** Contains an enumeration value that describes the per-texel
        layout of the format. The length of the enumeration string
        indicates how many channels there are and each letter
        represents the name of a channel. There are typically 1 to 4
        channels. */
        Channels mChannels;

        /** Contains an enumeration that describes the range of texel
        channel values. Each channel represents a range of values.
        Some example ranges are signed or unsigned integers, or
        are within a clamped range such as 0.0f to 1.0f, or are a
        high dynamic range via floating point.  */
        Range mRange;

        /** Contains an enumeration that identifies the precision of the
        texel channel value.Each channel of the texel has a
        precision. Typically, channels have the same precision. An
        exact format may lower the precision of an individual
        channel but applying a higher precision by linking the
        channels may still convey the same information. */
        Precision mPrecision;

        /** Contains additional hints about data relationships and other
        things to help an application pick the best format. */
        std::vector<Option> mOptions;

        /** Flag, if the format hint is initialized. */
        bool mIsInitialized;

    public:

        /** Constructor. */
        FormatHint ();

        /** Constructor. */
        FormatHint ( StreamWriter* streamWriter, Channels channels, Range range );

        /** Destructor. */
        virtual ~FormatHint () {}

        /** Flag, if the format hint is initialized. */
        const bool getIsInitialized () const { return mIsInitialized; }

        /** Flag, if the format hint is initialized. */
        void setIsInitialized ( const bool val ) { mIsInitialized = val; }

        /** Set the current precision. */
        void setPrecision ( Precision precision );

        /** Set the current options. */
        void addOption ( Option option );

        /** Returns the string value of the current channel. */
        static const String& getChannelsString ( Channels channel );

        /** Returns the string value of the current range. */
        static const String& getRangeString ( Range range );

        /** Returns the string value of the current precision. */
        static const String& getPrecisionString ( Precision precision );

        /** Returns the string value of the current option. */
        static const String& getOptionString ( Option option );

        /** Write the <format_hint> element to the collada stream. */
        void add () const;
    };

}

#endif // __COLLADASTREAMWRITER_FORMAT_HINT_H__
