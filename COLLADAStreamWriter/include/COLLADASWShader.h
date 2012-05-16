/*
    Copyright (c) 2008-2009 NetAllied Systems GmbH

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_SHADER_H__
#define __COLLADASTREAMWRITER_SHADER_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

    /** 
    Profile: CG, GLSL
    Introduction: Declares and prepares a shader for execution in the rendering pipeline of a <pass>. 
    Concepts:
    Executable shaders are small functions or programs that execute at a specific stage in the rendering
    pipeline. Shaders can be built from preloaded, precompiled binaries or dynamically generated at run time
    from embedded source code. The <shader> declaration holds all the settings necessary for compiling a
    shader and binding values or predefined parameters to the uniform inputs.
    COLLADASW FX allows declarations of both source code shaders and precompiled binaries, depending on
    support from the FX Runtime. Precompiled binary shaders already have the target profile specified for them
    at compile time, but to allow COLLADASW readers to validate declarations involving precompiled shaders
    without having to load and parse the binary headers, profile declarations are still required.
    Previously defined parameters, shader source, and binaries are considered merged into the same
    namespace / symbol table/source code string so that all symbols and functions are available to shader
    declarations, allowing common functions to be used in several shaders in a <technique>, for example,
    common lighting code. FX Runtimes that use the concept of "translation units" are allowed to name each
    source code block to break up the namespace.
    Shaders with uniform input parameters can bind either previously defined parameters or literal values to
    these values during shader declaration, allowing compilers to inline literal and constant values. 
    */
    class Shader : public ElementWriter
    {

    public:

        /** The different shader scope types. */
        enum Scope
        {
            SCOPE_CG,
            SCOPE_GLSL,
            SCOPE_UNDEFINED
        };

        /** In which pipeline stage this programmable shader is designed to execute. 
        Initial defined values in GLSL scope are VERTEXPROGRAM and FRAGMENTPROGRAM; 
        in CG scope, they are VERTEX and FRAGMENT. Optional. */
        enum Stage
        {
            STAGE_VERTEX,
            STAGE_FRAGMENT,
            STAGE_UNDEFINED
        };

    private:

        /** The tag closer for the shader. */
        TagCloser mShaderCloser;

        /** The scope of the current shader. */
        Scope mScope;

        /** In which pipeline stage this programmable shader is designed to execute. 
        Initial defined values in GLSL scope are VERTEXPROGRAM and FRAGMENTPROGRAM; 
        in CG scope, they are VERTEX and FRAGMENT. Optional. */
        Stage mStage;

    public:

        /** Constructor. */
        Shader ( StreamWriter* sw, const Scope& scope=SCOPE_UNDEFINED, const Stage& stage=STAGE_UNDEFINED );

        /** Destructor. */
        ~Shader () {}

        /** Returns the stage name depending on the scope and the stage. */
        const String& getStageNameByScopeAndStage ( const Scope& scope, const Stage& stage );

        /** Returns the initial defined stage depending on the given name. */
        static const Stage getStageTypeByName ( const String& stageName );

        /** Declares and prepares a shader for execution in the rendering pipeline of a <pass>. */
        void openShader ();

        /** Close the current shader element. */
        void closeShader ();

        /** Declares the profile or platform for which the compiler is targeting this shader.
        Some FX Runtime compilers can generate object code for several platforms or generations of hardware.
        This declaration specifies the compiler target profile as a string. 
        If you specify <compiler_options>, you must also specify this element.*/
        void addCompilerTarget ( const String& val );

        /** Contains command-line options for a shader compiler.
        The shader compiler is an external tool that accepts shader program source code and input and compiles
        it into machine executable object code. The shader compiler accepts command-line options that configure
        it to perform specific operations.
        If you specify <compiler_options>, you must also specify the <compiler_target> element.*/
        void addCompilerOptions ( const String& val );

        /** Provides the entry symbol for the shader function. 
        Shader compilers require the name of a function to compile into shader object or binary code. FX Runtimes
        that use the translation unit paradigm can optionally specify the translation unit or symbol table to search
        for the symbol inside. */
        void addName ( const String& name, const String& source="" );

    };
}

#endif // __COLLADASTREAMWRITER_SHADER_H__
