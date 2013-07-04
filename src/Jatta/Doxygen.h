#ifdef JATTA_DOXYGEN
/** @mainpage Jatta
 *
 *  @section intro Introduction
 *  Jatta is an object oriented General Utility Library.  Jatta simplifies the process of creating
 *  windows, working with OpenGL, networking, loading in images and models, and much more.
 *
 *  The library does not depend on OpenGL, and optionally it can be disabled when building Jatta.
 *  All tools included can be used in any project for any purpose, including commercial.  Please see
 *  the @ref license for more information.
 */

/** @page downloads Downloads
 *  While Jatta is in development we do not have binary releases and require that you build the
 *  library form source.  You can grab the source from Github: @n
 *  https://github.com/Zethes/Jatta
 *
 *  You can grab the pre-built libraries that Jatta relies on below.
 *
 *  <b>Windows (Visual Studio) 32bit</b> @n
 *  COMING EVENTUALLY
 *
 *  <b>Windows (Visual Studio) @b 64bit</b> @n
 *  COMING EVENTUALLY
 *
 *  <b>MinGW 32bit</b> @n
 *  <a href="http://sourceforge.net/projects/jatta/files/Dependencies/mingw32_dep.zip/download">mingw32_dep.zip</a>
 *
 *  <b>MinGW 64bit</b> @n
 *  COMING EVENTUALLY
 *
 *  <b>Linux 32bit</b> @n
 *  COMING EVENTUALLY
 *
 *  <b>Linux 64bit</b> @n
 *  <a href="http://sourceforge.net/projects/jatta/files/Dependencies/linux64_dep.tar.gz/download">linux64_dep.tar.gz</a>
 *
 *  <b>MacOS 32bit</b> @n
 *  COMING EVENTUALLY
 *
 *  <b>MacOS 64bit</b> @n
 *  COMING EVENTUALLY
 */

/** @page license License
 *  The GitHub page contains the most up-to-date disclaimer and license.
 *
 *  https://github.com/Zethes/Jatta/blob/master/license.md
 */

/** @page acknowledgements Acknowledgements
 *  Jatta utilizes the following fantastic libraries.  This project would not be possible without
 *  them!
 *
 *  @b libpng http://www.libpng.org/ @n
 *  Copyright (C) 1998-2012, Glenn Randers-Pehrson@n
 *  Copyright (C) 1996-1997, Andreas Dilger@n
 *  Copyright (C) 1995-1996, Guy Eric Schalnat, Group 42, Inc.@n
 *
 *  @b zlib http://www.zlib.net/ @n
 *  Copyright (C) 1995-2012, Jean-loup Gailly and Mark Adler
 *
 *  @b The @b OpenGL @b Extension @b Wrangler @b Library http://glew.sourceforge.net/ @n
 *  Copyright (C) 2002-2007, Milan Ikits <milan ikits[]ieee org>@n
 *  Copyright (C) 2002-2007, Marcelo E. Magallon <mmagallo[]debian org>@n
 *  Copyright (C) 2002, Lev Povalahev@n
 *  All rights reserved.
 *
 *  @b libjpeg http://libjpeg.sourceforge.net/ @n
 *  Copyright (C) 1991-2012, Thomas G. Lane, Guido Vollbeding.
 *
 *  @b FreeType http://www.freetype.org/ @n
 *  Copyright (C) 1996-2002, David Turner, Robert Wilhelm, and Werner Lemberg
 *
 *  @b Open @b Asset @b Import @b Library http://assimp.sourceforge.net/ @n
 *  Copyright (C) 2006-2012 assimp team@n
 *  All rights reserved.
 *
 *  @b PortAudio @b Portable @b Real-Time @b Audio @b Library http://www.portaudio.com/ @n
 *  Copyright (C) 1999-2011 Ross Bencina, Phil Burk
 *
 *  @n This HTML help page was generated by Doxygen.  Check it out!@n
 *  http://www.stack.nl/~dimitri/doxygen/
 */

/** @page howtouse How to Use
 *  Jatta is currently undergoing a lot of development and has no official builds,
 *  and the following is subject to change and only covers rather broad setup instructions.
 * 
 *  <b>Building and installing Jatta</b>
 * 
 *  First we need to obtain the latest source code from github (some functionality may be missing)
 *  <code>
 *  git clone https://github.com/Zethes/Jatta
 *  cd Jatta
 *  </code>
 * 
 *  Jatta's build process is powered by CMake and we recommend you build outside of the source directory.
 *  <code>
 *  mkdir build && cd build
 *  cmake -G <BUILD_TYPE> ..
 *  make && make install
 *  </code>
 * 
 *  CMake provides an easy way to provide cross-compilation on many machines without having to write individual
 *  build files.  For more information on what to put in for <BUILD_TYPE> see 
 *  http://www.cmake.org/Wiki/CMake_Generator_Specific_Information for more information.
 * 
 *  <b>Building the examples</b>
 *  
 *  <b>YOU MUST HAVE BUILT AND INSTALLED JATTA TO BUILD THE EXAMPLES</b>
 * 
 *  At the moment, each example must be built seperately.  These steps are the same for all examples and are very
 *  similar to building Jatta itself.
 * 
 *  Begin by simply navigating to the desired example's directory inside the terminal of your choosing.  
 *  For this example we'll be using the window example.
 *  <code>
 *  git clone https://github.com/Zethes/Jatta
 *  cd Jatta/examples
 *  cd Graphics/window
 *  </code>
 * 
 *  Similar to building Jatta, we recommend building outside of the source directory.
 *  <code>
 *  mkdir build && cd build
 *  cmake -G <BUILD_TYPE> ..
 *  make
 *  </code>
 * 
 *  You should now have an executable file inside your current work directory for the example.
 * 
*/
#endif
