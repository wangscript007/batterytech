/*
 * boot.cpp
 *
 *  Created on: Jul 29, 2010
 *      Author: rgreen
 */

#ifdef ANDROID_NDK
#include "androidtypes.h"
#include "../platformgeneral.h"
#include "../../batterytech.h"
#include "../../render/GraphicsConfiguration.h"
#include "importgl.h"
#include <jni.h>
#include <android/log.h>
#include "../../util/strx.h"
#include "../opengles.h"
#include "../../audio/AudioManager.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NO_GLES2_LIB
	#ifdef GL_APICALL
	#undef GL_APICALL
	#endif
	#define GL_APICALL
	#ifdef GL_APIENTRY
	#undef GL_APIENTRY
	#endif
	#define  GL_APIENTRY
	GL_APICALL void         GL_APIENTRY glActiveTexture (GLenum texture){}
	GL_APICALL void         GL_APIENTRY glAttachShader (GLuint program, GLuint shader){}
	GL_APICALL void         GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const char* name){}
	GL_APICALL void         GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer){}
	GL_APICALL void         GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer){}
	GL_APICALL void         GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer){}
	GL_APICALL void         GL_APIENTRY glBindTexture (GLenum target, GLuint texture){}
	GL_APICALL void         GL_APIENTRY glBlendColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha){}
	GL_APICALL void         GL_APIENTRY glBlendEquation ( GLenum mode ){}
	GL_APICALL void         GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha){}
	GL_APICALL void         GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor){}
	GL_APICALL void         GL_APIENTRY glBlendFuncSeparate (GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha){}
	GL_APICALL void         GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void* data, GLenum usage){}
	GL_APICALL void         GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void* data){}
	GL_APICALL GLenum       GL_APIENTRY glCheckFramebufferStatus (GLenum target){}
	GL_APICALL void         GL_APIENTRY glClear (GLbitfield mask){}
	GL_APICALL void         GL_APIENTRY glClearColor (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha){}
	GL_APICALL void         GL_APIENTRY glClearDepthf (GLclampf depth){}
	GL_APICALL void         GL_APIENTRY glClearStencil (GLint s){}
	GL_APICALL void         GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha){}
	GL_APICALL void         GL_APIENTRY glCompileShader (GLuint shader){}
	GL_APICALL void         GL_APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data){}
	GL_APICALL void         GL_APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data){}
	GL_APICALL void         GL_APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border){}
	GL_APICALL void         GL_APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height){}
	GL_APICALL GLuint       GL_APIENTRY glCreateProgram (void){}
	GL_APICALL GLuint       GL_APIENTRY glCreateShader (GLenum type){}
	GL_APICALL void         GL_APIENTRY glCullFace (GLenum mode){}
	GL_APICALL void         GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint* buffers){}
	GL_APICALL void         GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint* framebuffers){}
	GL_APICALL void         GL_APIENTRY glDeleteProgram (GLuint program){}
	GL_APICALL void         GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint* renderbuffers){}
	GL_APICALL void         GL_APIENTRY glDeleteShader (GLuint shader){}
	GL_APICALL void         GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint* textures){}
	GL_APICALL void         GL_APIENTRY glDepthFunc (GLenum func){}
	GL_APICALL void         GL_APIENTRY glDepthMask (GLboolean flag){}
	GL_APICALL void         GL_APIENTRY glDepthRangef (GLclampf zNear, GLclampf zFar){}
	GL_APICALL void         GL_APIENTRY glDetachShader (GLuint program, GLuint shader){}
	GL_APICALL void         GL_APIENTRY glDisable (GLenum cap){}
	GL_APICALL void         GL_APIENTRY glDisableVertexAttribArray (GLuint index){}
	GL_APICALL void         GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count){}
	GL_APICALL void         GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void* indices){}
	GL_APICALL void         GL_APIENTRY glEnable (GLenum cap){}
	GL_APICALL void         GL_APIENTRY glEnableVertexAttribArray (GLuint index){}
	GL_APICALL void         GL_APIENTRY glFinish (void){}
	GL_APICALL void         GL_APIENTRY glFlush (void){}
	GL_APICALL void         GL_APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer){}
	GL_APICALL void         GL_APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level){}
	GL_APICALL void         GL_APIENTRY glFrontFace (GLenum mode){}
	GL_APICALL void         GL_APIENTRY glGenBuffers (GLsizei n, GLuint* buffers){}
	GL_APICALL void         GL_APIENTRY glGenerateMipmap (GLenum target){}
	GL_APICALL void         GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint* framebuffers){}
	GL_APICALL void         GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint* renderbuffers){}
	GL_APICALL void         GL_APIENTRY glGenTextures (GLsizei n, GLuint* textures){}
	GL_APICALL void         GL_APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name){}
	GL_APICALL void         GL_APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name){}
	GL_APICALL void         GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders){}
	GL_APICALL int          GL_APIENTRY glGetAttribLocation (GLuint program, const char* name){}
	GL_APICALL void         GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean* params){}
	GL_APICALL void         GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint* params){}
	GL_APICALL GLenum       GL_APIENTRY glGetError (void){}
	GL_APICALL void         GL_APIENTRY glGetFloatv (GLenum pname, GLfloat* params){}
	GL_APICALL void         GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetIntegerv (GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufsize, GLsizei* length, char* infolog){}
	GL_APICALL void         GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog){}
	GL_APICALL void         GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision){}
	GL_APICALL void         GL_APIENTRY glGetShaderSource (GLuint shader, GLsizei bufsize, GLsizei* length, char* source){}
	GL_APICALL const GLubyte* GL_APIENTRY glGetString (GLenum name){}
	GL_APICALL void         GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat* params){}
	GL_APICALL void         GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat* params){}
	GL_APICALL void         GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint* params){}
	GL_APICALL int          GL_APIENTRY glGetUniformLocation (GLuint program, const char* name){}
	GL_APICALL void         GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat* params){}
	GL_APICALL void         GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint* params){}
	GL_APICALL void         GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void** pointer){}
	GL_APICALL void         GL_APIENTRY glHint (GLenum target, GLenum mode){}
	GL_APICALL GLboolean    GL_APIENTRY glIsBuffer (GLuint buffer){}
	GL_APICALL GLboolean    GL_APIENTRY glIsEnabled (GLenum cap){}
	GL_APICALL GLboolean    GL_APIENTRY glIsFramebuffer (GLuint framebuffer){}
	GL_APICALL GLboolean    GL_APIENTRY glIsProgram (GLuint program){}
	GL_APICALL GLboolean    GL_APIENTRY glIsRenderbuffer (GLuint renderbuffer){}
	GL_APICALL GLboolean    GL_APIENTRY glIsShader (GLuint shader){}
	GL_APICALL GLboolean    GL_APIENTRY glIsTexture (GLuint texture){}
	GL_APICALL void         GL_APIENTRY glLineWidth (GLfloat width){}
	GL_APICALL void         GL_APIENTRY glLinkProgram (GLuint program){}
	GL_APICALL void         GL_APIENTRY glPixelStorei (GLenum pname, GLint param){}
	GL_APICALL void         GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units){}
	GL_APICALL void         GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels){}
	GL_APICALL void         GL_APIENTRY glReleaseShaderCompiler (void){}
	GL_APICALL void         GL_APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height){}
	GL_APICALL void         GL_APIENTRY glSampleCoverage (GLclampf value, GLboolean invert){}
	GL_APICALL void         GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height){}
	GL_APICALL void         GL_APIENTRY glShaderBinary (GLsizei n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length){}
	GL_APICALL void         GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const char** string, const GLint* length){}
	GL_APICALL void         GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask){}
	GL_APICALL void         GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask){}
	GL_APICALL void         GL_APIENTRY glStencilMask (GLuint mask){}
	GL_APICALL void         GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask){}
	GL_APICALL void         GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass){}
	GL_APICALL void         GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum fail, GLenum zfail, GLenum zpass){}
	GL_APICALL void         GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat,  GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid* pixels){}
	GL_APICALL void         GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param){}
	GL_APICALL void         GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat* params){}
	GL_APICALL void         GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param){}
	GL_APICALL void         GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint* params){}
	GL_APICALL void         GL_APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels){}
	GL_APICALL void         GL_APIENTRY glUniform1f (GLint location, GLfloat x){}
	GL_APICALL void         GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat* v){}
	GL_APICALL void         GL_APIENTRY glUniform1i (GLint location, GLint x){}
	GL_APICALL void         GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint* v){}
	GL_APICALL void         GL_APIENTRY glUniform2f (GLint location, GLfloat x, GLfloat y){}
	GL_APICALL void         GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat* v){}
	GL_APICALL void         GL_APIENTRY glUniform2i (GLint location, GLint x, GLint y){}
	GL_APICALL void         GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint* v){}
	GL_APICALL void         GL_APIENTRY glUniform3f (GLint location, GLfloat x, GLfloat y, GLfloat z){}
	GL_APICALL void         GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat* v){}
	GL_APICALL void         GL_APIENTRY glUniform3i (GLint location, GLint x, GLint y, GLint z){}
	GL_APICALL void         GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint* v){}
	GL_APICALL void         GL_APIENTRY glUniform4f (GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w){}
	GL_APICALL void         GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat* v){}
	GL_APICALL void         GL_APIENTRY glUniform4i (GLint location, GLint x, GLint y, GLint z, GLint w){}
	GL_APICALL void         GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint* v){}
	GL_APICALL void         GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){}
	GL_APICALL void         GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){}
	GL_APICALL void         GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value){}
	GL_APICALL void         GL_APIENTRY glUseProgram (GLuint program){}
	GL_APICALL void         GL_APIENTRY glValidateProgram (GLuint program){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib1f (GLuint indx, GLfloat x){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib1fv (GLuint indx, const GLfloat* values){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib2f (GLuint indx, GLfloat x, GLfloat y){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib2fv (GLuint indx, const GLfloat* values){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib3f (GLuint indx, GLfloat x, GLfloat y, GLfloat z){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib3fv (GLuint indx, const GLfloat* values){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib4f (GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w){}
	GL_APICALL void         GL_APIENTRY glVertexAttrib4fv (GLuint indx, const GLfloat* values){}
	GL_APICALL void         GL_APIENTRY glVertexAttribPointer (GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr){}
	GL_APICALL void         GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height){}
#endif /* NO_GLES2_LIB */

// the current env for the call
JNIEnv *jnienv;
jobject javaBoot;
extern AudioManager *_andSndMgr; // from androidgeneral
GraphicsConfiguration *gConfig;

void determineGPUCapabilities();

void Java_com_batterypoweredgames_batterytech_Boot_init(JNIEnv* env, jobject thiz, jint width, jint height) {
	jnienv = env;
	javaBoot = thiz;
	gConfig = new GraphicsConfiguration;
	determineGPUCapabilities();
	btInit(gConfig, width, height);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_release(JNIEnv* env, jobject thiz) {
	jnienv = env;
	javaBoot = thiz;
	btRelease();
	delete gConfig;
	jnienv = 0;
	javaBoot = 0;
}
void Java_com_batterypoweredgames_batterytech_Boot_update(JNIEnv* env, jobject thiz, jfloat delta) {
	//__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech Boot", "delta is %f", delta);
	jnienv = env;
	javaBoot = thiz;
	btUpdate((F32)delta);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_draw(JNIEnv* env, jobject thiz) {
	jnienv = env;
	javaBoot = thiz;
	btDraw();
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_suspend(JNIEnv* env, jobject thiz) {
	jnienv = env;
	javaBoot = thiz;
	btSuspend();
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_resume(JNIEnv* env, jobject thiz) {
	jnienv = env;
	javaBoot = thiz;
	btResume();
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_setPointerState(JNIEnv* env, jobject thiz, jint pointerId, jboolean down, jint x, jint y) {
	jnienv = env;
	javaBoot = thiz;
	btSetPointerState(pointerId, down, x, y);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_keyUp(JNIEnv* env, jobject thiz, jint keyCode) {
	jnienv = env;
	javaBoot = thiz;
	btKeyUp(keyCode);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_keyDown(JNIEnv* env, jobject thiz, jint keyCode) {
	jnienv = env;
	javaBoot = thiz;
	btKeyDown(keyCode);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_keyPressed(JNIEnv* env, jobject thiz, jint keyCode) {
	jnienv = env;
	javaBoot = thiz;
	btKeyPressed(keyCode);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_accelerometerChanged(JNIEnv* env, jobject thiz, jfloat x, jfloat y, jfloat z) {
	//__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech Boot", "delta is %f", delta);
	jnienv = env;
	javaBoot = thiz;
	btAccelerometerChanged(x,y,z);
	jnienv = 0;
	javaBoot = 0;
}

void Java_com_batterypoweredgames_batterytech_Boot_fillAudioBuffer(JNIEnv* env, jobject thiz, jshortArray jPCMData, jint length) {
	if (_andSndMgr) {
		signed short *buf = new signed short[length / 2];
		_andSndMgr->fillBuffer(buf, length);
		env->SetShortArrayRegion(jPCMData, 0, length / 2, buf);
		delete [] buf;
	}
}

void determineGPUCapabilities() {
	const char *vendor = (const char*)glGetString(GL_VENDOR);
	const char *renderer = (const char*)glGetString(GL_RENDERER);
	const char *version = (const char*)glGetString(GL_VERSION);
	const char *extensions = (const char*)glGetString(GL_EXTENSIONS);
	// 1.0 = 0, 1.1 = 1, 2.0 = 2
	int ver = 0;
	__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL Vendor %s", vendor);
	__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL Renderer %s", renderer);
	__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL Version %s", version);
	if (strstr(version, "2.0")) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL ES Version 2.0 found");
		ver = 2;
		gConfig->supportsShaders = TRUE;
	} else if (strstr(version, "1.1")) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL ES Version 1.1 found");
		ver = 1;
	}
	if (ver == 0) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "OpenGL ES Version 1.0 found");
	}
	if ((ver > 0) || gles_checkExtension(GLES_EXT_GENERATE_MIPMAP)) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "HW MipMap Gen Supported");
		gConfig->supportsHWmipmapgen = TRUE;
	}
	if ((ver > 0) || gles_checkExtension(GLES_EXT_VERTEX_BUFFER_OBJECT)) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "VBOs Supported");
		gConfig->supportsVBOs = TRUE;
	}
	if (strstr(renderer, "MSM7500")) {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "HW UV Transform not supported");
		gConfig->supportsUVTransform = FALSE;
	} else {
		__android_log_print(ANDROID_LOG_DEBUG, "BatteryTech", "HW UV Transform supported");
		gConfig->supportsUVTransform = TRUE;
	}
	if (strstr(renderer, ANDROID_RENDERER_PIXELFLINGER)) {
		gConfig->softGPU = TRUE;
	}
}

#ifdef __cplusplus
}
#endif

#endif /* _ANDROID */
