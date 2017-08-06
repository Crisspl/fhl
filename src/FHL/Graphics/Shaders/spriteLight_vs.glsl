"#version 330 core\n"

"layout (location = 0) in vec2 position;\n"
"layout (location = 1) in vec2 texCoords;\n"

"out vec2 TexCoords;\n"
"out vec3 FragPos;\n"

"uniform mat4 model;\n"
"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	 "TexCoords = texCoords;\n"
	 "FragPos = vec3(model * vec4(position, 0.f, 1.f));\n"
	 "gl_Position = mvp * vec4(position, 0.f, 1.f);\n"
"}"
