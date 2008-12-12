/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of MayaDataModel.

    Licensed under the MIT Open Source License,
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/
#ifndef __MayaDM_MOVIE_H__
#define __MayaDM_MOVIE_H__
#include "MayaDMTypes.h"
#include "MayaDMConnectables.h"
#include "MayaDMFile.h"
namespace MayaDM
{
/*
<b>Movie</b> textures allow you to use any movie file as a texture
        map.  The movie file can be any of the movie file types supported
        by Maya.
        <p/>
        Movie textures can be animated, using the different frames of the
        movie file.  To do this:
        <ul>
          <li>Set File Texture Name to the name of one of the movie file,
          <i>e.g.</i> "myMovie.qt"</li>
        <li>Turn on Use Frame Extension.</li>
        <li>Go to the first frame in your animation where you want the texture
        to show, set Frame Extension to the number of the movie frame that you
        want used at that animation frame, and keyframe it.</li>
        <li>Go to the last frame in your animation where you want the texture
        to show, set Frame Extension to the number of the movie frame that you
        want used at that animation frame, and keyframe it.</li>
        </ul>
        <p/>

        Movie Texture inherits all of its attributes from its parent <a href="file.html">File Texture</a>; it has no attributes of its
        own.  It does, however, treat those attributes slightly
        differently.  When Use Frame Extension is turned on, File Texture
        constructs an image file name from the File Texture Name attribute
        and the Frame Extension attribute.  The movie texture node, in
        contrast assumes that all the frames are stored in the single
        (movie) file referred to by File Texture Name and simply loads the
        correct frame from the file.

        For performance reasons, Movie Texture also does not support the
        various filter types that are available on to File Texture.  If
        any filter type is set, it is simply treated as if it were a Box
        filter.
*/
class Movie : public File
{
public:
public:
	Movie(FILE* file,const std::string& name,const std::string& parent=""):File(file, name, parent, "movie"){}
	virtual ~Movie(){}
protected:
	Movie(FILE* file,const std::string& name,const std::string& parent,const std::string& nodeType):File(file, name, parent, nodeType) {}
private:

};
}//namespace MayaDM
#endif//__MayaDM_MOVIE_H__
