/*
 * platformgeneral.h
 *
 *  Created on: Aug 11, 2010
 *      Author: rgreen
 */

#ifndef PLATFORMGL_H_
#define PLATFORMGL_H_

#ifdef ANDROID_NDK
	#include "android/importgl.h"
#endif /* ANDROID_NDK */

#ifdef _WIN32
#define _WINSOCKAPI_
	#include <windows.h>
	#include <gl/gl.h>
	#include <gl/glu.h>
	#define glOrthof(left,right,bottom,top,near,far) glOrtho(left,right,bottom,top,near,far)
	#define glFrustumf(xmin, xmax, ymin, ymax, zNear, zFar) glFrustum(xmin, xmax, ymin, ymax, zNear, zFar)
#endif /* _WIN32 */

#ifdef __APPLE__
	#include <TargetConditionals.h>
#endif

#if TARGET_OS_IPHONE
	#import <OpenGLES/ES1/gl.h>
	#import <OpenGLES/ES1/glext.h>
#endif /* IOS */

#include "opengles.h"

#endif /* PLATFORMGENERAL_H_ */
