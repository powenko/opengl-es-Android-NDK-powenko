/* 2012 10 07 version 1.0 update by Powen Ko (www.powenko.com)
 *    rewrite the opengl es sample and release on github.com
 *
 * San Angeles Observation OpenGL ES version example
 * Copyright 2004-2005 Jetro Lauha
 * All rights reserved.
 * Web: http://iki.fi/jetro/
 *
 * This source is free software; you can redistribute it and/or
 * modify it under the terms of EITHER:
 *   (1) The GNU Lesser General Public License as published by the Free
 *       Software Foundation; either version 2.1 of the License, or (at
 *       your option) any later version. The text of the GNU Lesser
 *       General Public License is included with this source in the
 *       file LICENSE-LGPL.txt.
 *   (2) The BSD-style license that is included with this source in
 *       the file LICENSE-BSD.txt.
 *
 * This source is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the files
 * LICENSE-LGPL.txt and LICENSE-BSD.txt for more details.
 *
 * $Id: demo.c,v 1.10 2005/02/08 20:54:39 tonic Exp $
 * $Revision: 1.10 $
 */

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



#define PI              3.1415f

static unsigned long sRandomSeed = 0;
static void gluPerspective(GLfloat fovy, GLfloat aspect,
                           GLfloat zNear, GLfloat zFar)
{
    GLfloat xmin, xmax, ymin, ymax;

    ymax = zNear * (GLfloat)tan(fovy * PI / 360);
    ymin = -ymax;
    xmin = ymin * aspect;
    xmax = ymax * aspect;

    glFrustumx((GLfixed)(xmin * 65536), (GLfixed)(xmax * 65536),
               (GLfixed)(ymin * 65536), (GLfixed)(ymax * 65536),
               (GLfixed)(zNear * 65536), (GLfixed)(zFar * 65536));
}

///////////////////////////
// Called from the app framework.
void appInit()
{
	// Set the background color to black ( rgba ).
		glClearColor(0.5f, 0.0f, 0.0f, 0.5f);  // OpenGL docs.
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
		square_init();

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
float angle=0;
float m_z=0;
void appRender(long tick, int width, int height)
{
	    // Clears the screen and depth buffer.
		//清除画面和深度

		// Clears the screen and depth buffer.
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				// Replace the current matrix with the identity matrix
				glLoadIdentity();
				// Translates 4 units into the screen.
				//glTranslatef(0, 0, -4);
				glTranslatef(0, 0, -6);
			//	glScalef(.5f, .5f, .5f);

				// Draw our square.
				//m_z=m_z-0.01f;
				//square_draw();
				// SQUARE A
					// Save the current matrix.
					glPushMatrix();
					// Rotate square A counter-clockwise.
					glRotatef(angle, 0, 0, 1);
					// setup color
					glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
					// Draw square A.
					square_draw();
					// Restore the last matrix.
					glPopMatrix();

					// SQUARE B
					// Save the current matrix
					glPushMatrix();
					// Rotate square B before moving it, making it rotate around A.
					glRotatef(-angle, 0, 0, 1);
					// Move square B.
					glTranslatef(2, 0, 0);
					// Scale it to 50% of square A
					glScalef(.5f, .5f, .5f);
					// setup color
					glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
					// Draw square B.
					square_draw();

					// SQUARE C
					// Save the current matrix
					glPushMatrix();
					// Make the rotation around B
					glRotatef(-angle, 0, 0, 1);
					glTranslatef(2, 0, 0);
					// Scale it to 50% of square B
					glScalef(.5f, .5f, .5f);
					// Rotate around it's own center.
					glRotatef(angle*10, 0, 0, 1);
					// setup color
					glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
					// Draw square C.
					square_draw();

					// Restore to the matrix as it was before C.
					glPopMatrix();
					// Restore to the matrix as it was before B.
					glPopMatrix();

					// Increse the angle.
					// angle=45; //++;

					angle++;


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

	    gluPerspective(45, (float)width / height, 0.1f, 100.0f);

		//gluPerspective(45.0f, (float) width / (float) height,     0.1f, 100.0f);

		// Select the modelview matrix
		glMatrixMode(GL_MODELVIEW);// OpenGL docs.
		// Reset the modelview matrix
		glLoadIdentity();// OpenGL docs.


}

