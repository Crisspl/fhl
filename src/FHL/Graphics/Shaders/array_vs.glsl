"#version 330 core\n"

"layout (location = 0) in vec2 position;\n"
"layout (location = 1) in vec4 color;\n"

"out vec4 outColor;\n"

"uniform mat4 view;\n"
"uniform mat4 projection;\n"

"void main()\n"
"{\n"
	"outColor = color;\n"
	"gl_Position = projection * view * vec4(position, 0.f, 1.f);\n"
"}"