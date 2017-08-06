"#version 330 core\n"

"in vec2 fragTexCoords;\n"

"uniform sampler2D texSampler;\n"
"uniform vec4 color;\n"

"out vec4 outColor;\n"

"void main()\n"
"{\n"
	 "vec4 tempColor = texture(texSampler, fragTexCoords);\n"
	 "if(tempColor.a == 0)\n"
		  "discard;\n"
	 "outColor = tempColor * color;\n"
"}"
