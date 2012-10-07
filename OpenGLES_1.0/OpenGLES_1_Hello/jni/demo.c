//    Created by Powen Ko on 2012-09-06.
//    Copyright © 2012 Powen Ko. All rights reserved.
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights to
//    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//    of the Software, and to permit persons to whom the Software is furnished to
//    do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//


#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <GLES/gl.h>
#include <GLES/glext.h>
/*
OpenGL ES 2.0:
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
*/

#include "importgl.h"

#include "app.h"
//#include "shapes.h"
//#include "cams.h"


// Total run length is 20 * camera track base unit length (see cams.h).
#define RUN_LENGTH  (20 * CAMTRACK_LEN)
#undef PI
#define PI 3.1415926535897932f
#define RANDOM_UINT_MAX 65535


static unsigned long sRandomSeed = 0;

///////////////////////////
// Called from the app framework.
void appInit()
{
	// Set the background color to black ( rgba ).
		glClearColor(1.0f, 0.0f, 0.0f, 0.5f);  // OpenGL docs.
		// Enable Smooth Shading, default not really needed.
		glShadeModel(GL_SMOOTH);// OpenGL docs.
		// Depth buffer setup.
		glClearDepthf(1.0f);// OpenGL docs.
		// Enables depth testing.
		glEnable(GL_DEPTH_TEST);// OpenGL docs.
		// The type of depth testing to do.
		glDepthFunc(GL_LEQUAL);// OpenGL docs.
		// Really nice perspective calculations.
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, // OpenGL docs.
                          GL_NICEST);


}

/////
// Called from the app framework.
void appDeinit()
{


}
//////


// Called from the app framework.
/* The tick is current time in milliseconds, width and height
 * are the image dimensions to be rendered.
 */
void appRender(long tick, int width, int height)
{


	// Clears the screen and depth buffer.
		//清除画面和深度
		glClear(GL_COLOR_BUFFER_BIT | // OpenGL docs.
                           GL_DEPTH_BUFFER_BIT);

}

void appResize( int width, int height){
        // Sets the current view port to the new size.
		// 设定opengl es 显示的大小
		glViewport(0, 0, width, height);// OpenGL docs.
		// Select the projection matrix
		glMatrixMode(GL_PROJECTION);// OpenGL docs.
		// Reset the projection matrix
		glLoadIdentity();// OpenGL docs.
		// Calculate the aspect ratio of the window
		// 设定画面的长宽比

		gluPerspective(45.0f,
                                   (float) width / (float) height,
                                   0.1f, 100.0f);

		// Select the modelview matrix
		glMatrixMode(GL_MODELVIEW);// OpenGL docs.
		// Reset the modelview matrix
		glLoadIdentity();// OpenGL docs.


}
