"#version 330 core\n"

"struct Material\n"
"{\n"
"	sampler2D texture_diffuse1;\n"
"	sampler2D texture_specular1;\n"
"	float shininess;\n"
"};\n"

"in vec2 TexCoords;\n"

"out vec4 color;\n"

"uniform Material material;\n"
"uniform bool useColorOnly;\n"
"uniform vec4 singleColor;\n"

"void main()\n"
"{\n"
	 "color = useColorOnly ? singleColor : texture(material.texture_diffuse1, TexCoords);\n"
"}"
