#ifndef FHL_SHADERSRCS_H
#define FHL_SHADERSRCS_H

namespace fhl {
	namespace shaderSrcs {

		constexpr const char * vertexArray_Vertex =
#include <FHL/Graphics/Shaders/array_vs.glsl>
			;
		constexpr const char * vertexArray_Fragment =
#include <FHL/Graphics/Shaders/array_fs.glsl>
			;
		constexpr const char * model_Vertex =
#include <FHL/Graphics/Shaders/model_vs.glsl>
			;
		constexpr const char * model_Fragment =
#include <FHL/Graphics/Shaders/model_fs.glsl>
			;
		constexpr const char * model_LightVertex =
#include <FHL/Graphics/Shaders/modelLight_vs.glsl>
			;
		constexpr const char * model_LightFragment =
#include <FHL/Graphics/Shaders/modelLight_fs.glsl>
			;
		constexpr const char * coloredRect_Vertex =
#include <FHL/Graphics/Shaders/rect_vs.glsl>
			;
		constexpr const char * coloredRect_Fragment =
#include <FHL/Graphics/Shaders/rect_fs.glsl>
			;
		constexpr const char * coloredRect_LightVertex =
#include <FHL/Graphics/Shaders/rectLight_vs.glsl>
			;
		constexpr const char * coloredRect_LightFragment =
#include <FHL/Graphics/Shaders/rectLight_fs.glsl>
			;
		constexpr const char * sprite_Vertex =
#include <FHL/Graphics/Shaders/sprite_vs.glsl>
			;
		constexpr const char * sprite_Fragment =
#include <FHL/Graphics/Shaders/sprite_fs.glsl>
			;
		constexpr const char * sprite_LightVertex =
#include <FHL/Graphics/Shaders/spriteLight_vs.glsl>
			;
		constexpr const char * sprite_LightFragment =
#include <FHL/Graphics/Shaders/spriteLight_fs.glsl>
			;

}}


#endif // FHL_SHADERSRCS_H
