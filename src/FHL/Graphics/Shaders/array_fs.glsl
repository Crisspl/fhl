"#version 330 core\n"

"in vec4 outColor;\n"

"out vec4 col;\n"

"void main()\n"
"{\n"
	"vec4 tempColor = outColor;\n"
	"if(tempColor.a == 0)\n"
		"discard;\n"
		
	"col = tempColor;\n"
"}"