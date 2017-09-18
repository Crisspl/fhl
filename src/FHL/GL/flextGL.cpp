#include <FHL/GL/flextGL.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GL_VERSION_1_2 */
FLEXTGL_EXPORT void(APIENTRY *flextglCopyTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawRangeElements)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexImage3D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *) = nullptr;

/* GL_VERSION_1_3 */
FLEXTGL_EXPORT void(APIENTRY *flextglActiveTexture)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexImage1D)(GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexImage2D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexImage3D)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompressedTexSubImage3D)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetCompressedTexImage)(GLenum, GLint, void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSampleCoverage)(GLfloat, GLboolean) = nullptr;

/* GL_VERSION_1_4 */
FLEXTGL_EXPORT void(APIENTRY *flextglBlendColor)(GLfloat, GLfloat, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBlendEquation)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBlendFuncSeparate)(GLenum, GLenum, GLenum, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglMultiDrawArrays)(GLenum, const GLint *, const GLsizei *, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglMultiDrawElements)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglPointParameterf)(GLenum, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglPointParameterfv)(GLenum, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglPointParameteri)(GLenum, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglPointParameteriv)(GLenum, const GLint *) = nullptr;

/* GL_VERSION_1_5 */
FLEXTGL_EXPORT void(APIENTRY *flextglBeginQuery)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindBuffer)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBufferData)(GLenum, GLsizeiptr, const void *, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBufferSubData)(GLenum, GLintptr, GLsizeiptr, const void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteBuffers)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteQueries)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglEndQuery)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenBuffers)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenQueries)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetBufferParameteriv)(GLenum, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetBufferPointerv)(GLenum, GLenum, void **) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetBufferSubData)(GLenum, GLintptr, GLsizeiptr, void *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetQueryObjectiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetQueryObjectuiv)(GLuint, GLenum, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetQueryiv)(GLenum, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsBuffer)(GLuint) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsQuery)(GLuint) = nullptr;
FLEXTGL_EXPORT void *(APIENTRY *flextglMapBuffer)(GLenum, GLenum) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglUnmapBuffer)(GLenum) = nullptr;

/* GL_VERSION_2_0 */
FLEXTGL_EXPORT void(APIENTRY *flextglAttachShader)(GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindAttribLocation)(GLuint, GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBlendEquationSeparate)(GLenum, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglCompileShader)(GLuint) = nullptr;
FLEXTGL_EXPORT GLuint(APIENTRY *flextglCreateProgram)(void) = nullptr;
FLEXTGL_EXPORT GLuint(APIENTRY *flextglCreateShader)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteProgram)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteShader)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDetachShader)(GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDisableVertexAttribArray)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawBuffers)(GLsizei, const GLenum *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglEnableVertexAttribArray)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveAttrib)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveUniform)(GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetAttachedShaders)(GLuint, GLsizei, GLsizei *, GLuint *) = nullptr;
FLEXTGL_EXPORT GLint(APIENTRY *flextglGetAttribLocation)(GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetProgramInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetProgramiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetShaderInfoLog)(GLuint, GLsizei, GLsizei *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetShaderSource)(GLuint, GLsizei, GLsizei *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetShaderiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT GLint(APIENTRY *flextglGetUniformLocation)(GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetUniformfv)(GLuint, GLint, GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetUniformiv)(GLuint, GLint, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribPointerv)(GLuint, GLenum, void **) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribdv)(GLuint, GLenum, GLdouble *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribfv)(GLuint, GLenum, GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsProgram)(GLuint) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsShader)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglLinkProgram)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglShaderSource)(GLuint, GLsizei, const GLchar *const*, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglStencilFuncSeparate)(GLenum, GLenum, GLint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglStencilMaskSeparate)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglStencilOpSeparate)(GLenum, GLenum, GLenum, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1f)(GLint, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1fv)(GLint, GLsizei, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1i)(GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1iv)(GLint, GLsizei, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2f)(GLint, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2fv)(GLint, GLsizei, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2i)(GLint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2iv)(GLint, GLsizei, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3f)(GLint, GLfloat, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3fv)(GLint, GLsizei, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3i)(GLint, GLint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3iv)(GLint, GLsizei, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4f)(GLint, GLfloat, GLfloat, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4fv)(GLint, GLsizei, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4i)(GLint, GLint, GLint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4iv)(GLint, GLsizei, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUseProgram)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglValidateProgram)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1d)(GLuint, GLdouble) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1dv)(GLuint, const GLdouble *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1f)(GLuint, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1fv)(GLuint, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1s)(GLuint, GLshort) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib1sv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2d)(GLuint, GLdouble, GLdouble) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2dv)(GLuint, const GLdouble *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2f)(GLuint, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2fv)(GLuint, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2s)(GLuint, GLshort, GLshort) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib2sv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3d)(GLuint, GLdouble, GLdouble, GLdouble) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3dv)(GLuint, const GLdouble *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3f)(GLuint, GLfloat, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3fv)(GLuint, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3s)(GLuint, GLshort, GLshort, GLshort) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib3sv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nbv)(GLuint, const GLbyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Niv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nsv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nub)(GLuint, GLubyte, GLubyte, GLubyte, GLubyte) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nubv)(GLuint, const GLubyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nuiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4Nusv)(GLuint, const GLushort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4bv)(GLuint, const GLbyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4d)(GLuint, GLdouble, GLdouble, GLdouble, GLdouble) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4dv)(GLuint, const GLdouble *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4f)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4fv)(GLuint, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4iv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4s)(GLuint, GLshort, GLshort, GLshort, GLshort) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4sv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4ubv)(GLuint, const GLubyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4uiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttrib4usv)(GLuint, const GLushort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void *) = nullptr;

/* GL_VERSION_2_1 */
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix2x3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix2x4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix3x2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix3x4fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix4x2fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformMatrix4x3fv)(GLint, GLsizei, GLboolean, const GLfloat *) = nullptr;

/* GL_VERSION_3_0 */
FLEXTGL_EXPORT void(APIENTRY *flextglBeginConditionalRender)(GLuint, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBeginTransformFeedback)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindBufferBase)(GLenum, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindBufferRange)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindFragDataLocation)(GLuint, GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindFramebuffer)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindRenderbuffer)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindVertexArray)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBlitFramebuffer)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum) = nullptr;
FLEXTGL_EXPORT GLenum(APIENTRY *flextglCheckFramebufferStatus)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglClampColor)(GLenum, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglClearBufferfi)(GLenum, GLint, GLfloat, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglClearBufferfv)(GLenum, GLint, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglClearBufferiv)(GLenum, GLint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglClearBufferuiv)(GLenum, GLint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglColorMaski)(GLuint, GLboolean, GLboolean, GLboolean, GLboolean) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteFramebuffers)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteRenderbuffers)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteVertexArrays)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDisablei)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglEnablei)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglEndConditionalRender)(void) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglEndTransformFeedback)(void) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFlushMappedBufferRange)(GLenum, GLintptr, GLsizeiptr) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferRenderbuffer)(GLenum, GLenum, GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferTexture1D)(GLenum, GLenum, GLenum, GLuint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferTexture2D)(GLenum, GLenum, GLenum, GLuint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferTexture3D)(GLenum, GLenum, GLenum, GLuint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferTextureLayer)(GLenum, GLenum, GLuint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenFramebuffers)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenRenderbuffers)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenVertexArrays)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenerateMipmap)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetBooleani_v)(GLenum, GLuint, GLboolean *) = nullptr;
FLEXTGL_EXPORT GLint(APIENTRY *flextglGetFragDataLocation)(GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetFramebufferAttachmentParameteriv)(GLenum, GLenum, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetIntegeri_v)(GLenum, GLuint, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetRenderbufferParameteriv)(GLenum, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT const GLubyte *(APIENTRY *flextglGetStringi)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetTexParameterIiv)(GLenum, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetTexParameterIuiv)(GLenum, GLenum, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetTransformFeedbackVarying)(GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetUniformuiv)(GLuint, GLint, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribIiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetVertexAttribIuiv)(GLuint, GLenum, GLuint *) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsEnabledi)(GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsFramebuffer)(GLuint) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsRenderbuffer)(GLuint) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsVertexArray)(GLuint) = nullptr;
FLEXTGL_EXPORT void *(APIENTRY *flextglMapBufferRange)(GLenum, GLintptr, GLsizeiptr, GLbitfield) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglRenderbufferStorage)(GLenum, GLenum, GLsizei, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglRenderbufferStorageMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexParameterIiv)(GLenum, GLenum, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexParameterIuiv)(GLenum, GLenum, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTransformFeedbackVaryings)(GLuint, GLsizei, const GLchar *const*, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1ui)(GLint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform1uiv)(GLint, GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2ui)(GLint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform2uiv)(GLint, GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3ui)(GLint, GLuint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform3uiv)(GLint, GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4ui)(GLint, GLuint, GLuint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniform4uiv)(GLint, GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI1i)(GLuint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI1iv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI1ui)(GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI1uiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI2i)(GLuint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI2iv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI2ui)(GLuint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI2uiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI3i)(GLuint, GLint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI3iv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI3ui)(GLuint, GLuint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI3uiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4bv)(GLuint, const GLbyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4i)(GLuint, GLint, GLint, GLint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4iv)(GLuint, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4sv)(GLuint, const GLshort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4ubv)(GLuint, const GLubyte *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4ui)(GLuint, GLuint, GLuint, GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4uiv)(GLuint, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribI4usv)(GLuint, const GLushort *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribIPointer)(GLuint, GLint, GLenum, GLsizei, const void *) = nullptr;

/* GL_VERSION_3_1 */
FLEXTGL_EXPORT void(APIENTRY *flextglCopyBufferSubData)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawArraysInstanced)(GLenum, GLint, GLsizei, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawElementsInstanced)(GLenum, GLsizei, GLenum, const void *, GLsizei) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveUniformBlockName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveUniformBlockiv)(GLuint, GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveUniformName)(GLuint, GLuint, GLsizei, GLsizei *, GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetActiveUniformsiv)(GLuint, GLsizei, const GLuint *, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT GLuint(APIENTRY *flextglGetUniformBlockIndex)(GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetUniformIndices)(GLuint, GLsizei, const GLchar *const*, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglPrimitiveRestartIndex)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexBuffer)(GLenum, GLenum, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglUniformBlockBinding)(GLuint, GLuint, GLuint) = nullptr;

/* GL_VERSION_3_2 */
FLEXTGL_EXPORT GLenum(APIENTRY *flextglClientWaitSync)(GLsync, GLbitfield, GLuint64) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteSync)(GLsync) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawElementsBaseVertex)(GLenum, GLsizei, GLenum, const void *, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawElementsInstancedBaseVertex)(GLenum, GLsizei, GLenum, const void *, GLsizei, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDrawRangeElementsBaseVertex)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint) = nullptr;
FLEXTGL_EXPORT GLsync(APIENTRY *flextglFenceSync)(GLenum, GLbitfield) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglFramebufferTexture)(GLenum, GLenum, GLuint, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetBufferParameteri64v)(GLenum, GLenum, GLint64 *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetInteger64i_v)(GLenum, GLuint, GLint64 *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetInteger64v)(GLenum, GLint64 *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetMultisamplefv)(GLenum, GLuint, GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetSynciv)(GLsync, GLenum, GLsizei, GLsizei *, GLint *) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsSync)(GLsync) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglMultiDrawElementsBaseVertex)(GLenum, const GLsizei *, GLenum, const void *const*, GLsizei, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglProvokingVertex)(GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSampleMaski)(GLuint, GLbitfield) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexImage2DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglTexImage3DMultisample)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglWaitSync)(GLsync, GLbitfield, GLuint64) = nullptr;

/* GL_VERSION_3_3 */
FLEXTGL_EXPORT void(APIENTRY *flextglBindFragDataLocationIndexed)(GLuint, GLuint, GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglBindSampler)(GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglDeleteSamplers)(GLsizei, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGenSamplers)(GLsizei, GLuint *) = nullptr;
FLEXTGL_EXPORT GLint(APIENTRY *flextglGetFragDataIndex)(GLuint, const GLchar *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetQueryObjecti64v)(GLuint, GLenum, GLint64 *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetQueryObjectui64v)(GLuint, GLenum, GLuint64 *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetSamplerParameterIiv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetSamplerParameterIuiv)(GLuint, GLenum, GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetSamplerParameterfv)(GLuint, GLenum, GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglGetSamplerParameteriv)(GLuint, GLenum, GLint *) = nullptr;
FLEXTGL_EXPORT GLboolean(APIENTRY *flextglIsSampler)(GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglQueryCounter)(GLuint, GLenum) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameterIiv)(GLuint, GLenum, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameterIuiv)(GLuint, GLenum, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameterf)(GLuint, GLenum, GLfloat) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameterfv)(GLuint, GLenum, const GLfloat *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameteri)(GLuint, GLenum, GLint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglSamplerParameteriv)(GLuint, GLenum, const GLint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribDivisor)(GLuint, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP1ui)(GLuint, GLenum, GLboolean, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP1uiv)(GLuint, GLenum, GLboolean, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP2ui)(GLuint, GLenum, GLboolean, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP2uiv)(GLuint, GLenum, GLboolean, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP3ui)(GLuint, GLenum, GLboolean, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP3uiv)(GLuint, GLenum, GLboolean, const GLuint *) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP4ui)(GLuint, GLenum, GLboolean, GLuint) = nullptr;
FLEXTGL_EXPORT void(APIENTRY *flextglVertexAttribP4uiv)(GLuint, GLenum, GLboolean, const GLuint *) = nullptr;

#ifdef __cplusplus
}
#endif