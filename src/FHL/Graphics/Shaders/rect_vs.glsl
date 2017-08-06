"#version 330 core\n"

"layout (location = 0) in vec2 position;\n"

"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	 "gl_Position = mvp * vec4(position, 0.f, 1.f);\n"
"}"
