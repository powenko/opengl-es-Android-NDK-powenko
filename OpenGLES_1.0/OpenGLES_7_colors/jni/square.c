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


// Our vertices.
	 float vertices[] = {
		      -0.5f,  0.5f, 0.0f,  // 0, Top Left
		      -0.5f, -0.5f, 0.0f,  // 1, Bottom Left
		       0.5f, -0.5f, 0.0f,  // 2, Bottom Right
		       0.5f,  0.5f, 0.0f,  // 3, Top Right
		};

	// The order we like to connect them.
	 short indices[] = { 0, 1, 2, 0, 2, 3 };


	// The colors mapped to the vertices.
    float colors[] = {
            1.0f, 0.0f, 0.0f, 1.0f, // vertex 0 red
            0.0f, 1.0f, 0.0f, 1.0f, // vertex 1 green
            0.0f, 0.0f, 1.0f, 1.0f, // vertex 2 blue
            1.0f, 0.0f, 1.0f, 1.0f, // vertex 3 magenta
    };

/*
	// Our vertex buffer.
	 FloatBuffer vertexBuffer;

	// Our index buffer.
	 ShortBuffer indexBuffer;
*/



	 GLfloat *vertexBuffer;
	GLubyte *indexBuffer;
    GLfloat *colorBuffer;


void square_init() {
	int t_vertexslen=4;
	int t_vertex_size=3;
	vertexBuffer = (GLfloat *)malloc(t_vertex_size * t_vertexslen *  sizeof(GLfloat));

	int t1=t_vertex_size * t_vertexslen;
	int i=0;
	for(i=0;i<t1;i++){
	    vertexBuffer[i] =vertices[i];
	}

	////////

	t_vertexslen=6;
    t_vertex_size=1;
    indexBuffer = (GLubyte *)malloc(t_vertex_size * t_vertexslen *  sizeof(GLubyte));

    t1=t_vertex_size * t_vertexslen;
	i=0;
	for(i=0;i<t1;i++){
		indexBuffer[i] =indices[i];
	}

	/////////

	t_vertexslen=4;
	t_vertex_size=3;
	colorBuffer = (GLfloat *)malloc(t_vertex_size * t_vertexslen *  sizeof(GLfloat));

	t1=t_vertex_size * t_vertexslen;
    i=0;
	for(i=0;i<t1;i++){
		colorBuffer[i] =colors[i];
	}

	////////





}
void square_draw(){ //int i_action) {
	// Counter-clockwise winding.
		glFrontFace(GL_CCW);
		// Enable face culling.
	    glEnable(GL_CULL_FACE);
		// What faces to remove with the face culling.
		glCullFace(GL_BACK);
		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		// Enabled the vertices buffer for writing and to be used during
		// rendering.
		glEnableClientState(GL_VERTEX_ARRAY);
		// Specifies the location and data format of an array of vertex
		// coordinates to use when rendering.

		glVertexPointer(3, GL_FLOAT, 0, vertexBuffer);

		// Enable the color array buffer to be used during rendering.
		glEnableClientState(GL_COLOR_ARRAY); // NEW LINE ADDED.
		// Point out the where the color buffer is.
		glColorPointer(4, GL_FLOAT, 0, colorBuffer); // NEW LINE ADDED.


		glDrawElements(GL_TRIANGLES,   6,  //indices_length,
			GL_UNSIGNED_BYTE, indexBuffer);

        int indices_length=6;
		// Specifies the location and data format of an array of vertex




		// Disable the vertices buffer.
		glDisableClientState(GL_VERTEX_ARRAY);
		// Disable face culling.
		glDisable(GL_CULL_FACE);

}
