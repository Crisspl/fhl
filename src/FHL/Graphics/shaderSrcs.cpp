#include <FHL/Graphics/shaderSrcs.h>

namespace fhl { namespace shaderSrcs {

	const char * const vertexArray_Vertex =
	#include <FHL/Graphics/Shaders/array_vs.glsl>
	;
	const char * const vertexArray_Fragment =
	#include <FHL/Graphics/Shaders/array_fs.glsl>
	;
	const char * const model_Vertex =
	#include <FHL/Graphics/Shaders/model_vs.glsl>
	;
	const char * const model_Fragment =
	#include <FHL/Graphics/Shaders/model_fs.glsl>
	;
	const char * const model_LightVertex =
	#include <FHL/Graphics/Shaders/modelLight_vs.glsl>
	;
	const char * const model_LightFragment =
	#include <FHL/Graphics/Shaders/modelLight_fs.glsl>
	;
	const char * const coloredRect_Vertex =
	#include <FHL/Graphics/Shaders/rect_vs.glsl>
	;
	const char * const coloredRect_Fragment =
	#include <FHL/Graphics/Shaders/rect_fs.glsl>
	;
	const char * const coloredRect_LightVertex =
	#include <FHL/Graphics/Shaders/rectLight_vs.glsl>
	;
	const char * const coloredRect_LightFragment =
	#include <FHL/Graphics/Shaders/rectLight_fs.glsl>
	;
	const char * const sprite_Vertex =
	#include <FHL/Graphics/Shaders/sprite_vs.glsl>
	;
	const char * const sprite_Fragment =
	#include <FHL/Graphics/Shaders/sprite_fs.glsl>
	;
	const char * const sprite_LightVertex =
	#include <FHL/Graphics/Shaders/spriteLight_vs.glsl>
	;
	const char * const sprite_LightFragment =
	#include <FHL/Graphics/Shaders/spriteLight_fs.glsl>
	;

}}
