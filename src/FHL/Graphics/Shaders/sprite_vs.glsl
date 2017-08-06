"#version 330 core\n"

"layout (location = 0) in vec2 position;\n"
"layout (location = 1) in vec2 texCoords;\n"

"uniform mat4 mvp;\n"

"out vec2 fragTexCoords;\n"

"void main()\n"
"{\n"
	 "fragTexCoords = texCoords;\n"
	 "gl_Position = mvp * vec4(position, 0.f, 1.f);\n"
"}"
