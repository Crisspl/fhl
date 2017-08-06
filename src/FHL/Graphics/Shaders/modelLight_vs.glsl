"#version 330 core\n"

"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 normal;\n"
"layout (location = 2) in vec2 texCoords;\n"

"out vec3 Normal;\n"
"out vec3 FragPos;\n"
"out vec2 TexCoords;\n"

"uniform mat4 model;\n"
"uniform mat4 inverseModel;\n"
"uniform mat4 mvp;\n"

"void main()\n"
"{\n"
	 "gl_Position = mvp * vec4(position, 1.0f);\n"
	 "TexCoords = texCoords;\n"
	 "Normal = mat3(transpose(inverseModel)) * normal; //it cuts off translation and rotation and also non-uniform scaling effect\n"
	 "FragPos = vec3(model * vec4(position, 1.f));\n"
"}"
