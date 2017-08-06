"#version 330 core\n"
"#define NORMAL_VEC vec3(0, 0, 1)\n"

"#define INFINITE_LIGHT 0\n"
"#define POINT_LIGHT 1\n"
"#define SPOT_LIGHT 2\n"

"struct Light\n"
"{\n"
	 "vec3 direction;\n"
	 "vec3 position;\n"
	 "vec4 color;\n"
	 "float linear;\n"
	 "float quadratic;\n"
	 "float cutOff;\n"
	 "float outerCutOff;\n"
	 "float illuminance;\n"
	 "int type;\n"
"};\n"

"in vec2 TexCoords;\n"
"in vec3 FragPos;\n"

"uniform sampler2D texSampler;\n"
"uniform vec4 color;\n"
"uniform vec3 cameraPos;\n"
"uniform Light light[50];\n"
"uniform int lightsCount;\n"

"out vec4 outColor;\n"

"vec3 calcLight(Light, vec3);\n"
"vec3 calcInfiniteLight(Light, vec3);\n"
"vec3 calcPointLight(Light, vec3);\n"
"vec3 calcSpotLight(Light, vec3);\n"

"void main()\n"
"{\n"
	 "outColor = texture(texSampler, TexCoords) * color;\n"
	 "if(outColor.a == 0)\n"
		  "discard;\n"

	 "vec3 viewDir = normalize(cameraPos - FragPos);\n"

	 "vec3 result;\n"
	 "for(int i = 0; i < lightsCount; i++)\n"
	 "result += calcLight(light[i], viewDir);\n"

	 "outColor *= vec4(result, 1.f);\n"
"}\n"

"vec3 calcLight(Light _light, vec3 _viewDir)\n"
"{\n"
	 "vec3 ret;\n"
	 "if(_light.type == INFINITE_LIGHT)\n"
		  "ret = calcInfiniteLight(_light, _viewDir);\n"
	 "else if(_light.type == POINT_LIGHT)\n"
		  "ret = calcPointLight(_light, _viewDir);\n"
	 "else if(_light.type == SPOT_LIGHT)\n"
		  "ret = calcSpotLight(_light, _viewDir);\n"
	 "return ret * _light.illuminance;\n"
"}\n"

"vec3 calcInfiniteLight(Light _light, vec3 _viewDir)\n"
"{\n"
	 "vec3 lightDir = normalize(-_light.direction);\n"
	 "float diff = max(dot(NORMAL_VEC, lightDir), 0.f);\n"
	 "vec3 reflectDir = normalize(reflect(-lightDir, NORMAL_VEC));\n"
	 "float spec = pow(max(dot(_viewDir, reflectDir), 0.f), 32);\n"

	 "vec3 diffuse = _light.color.xyz * diff;\n"
	 "vec3 specular = _light.color.xyz * spec;\n"

	 "return diffuse + specular;\n"
"}\n"

"vec3 calcPointLight(Light _light, vec3 _viewDir)\n"
"{\n"
	 "vec3 lightDir = normalize(_light.position - FragPos);\n"
	 "float diff = max(dot(NORMAL_VEC, lightDir), 0.f);\n"
	 "vec3 reflectDir = normalize(reflect(-lightDir, NORMAL_VEC));\n"
	 "float spec = pow(max(dot(_viewDir, reflectDir), 0.f), 32);\n"

	 "vec3 diffuse = _light.color.xyz * diff;\n"
	 "vec3 specular = _light.color.xyz * spec;\n"
	 "float distance = length(_light.position - FragPos);\n"
	 "float attenuation = 1.f / (1.f + _light.linear * distance + _light.quadratic * pow(distance, 2));\n"

	 "return (diffuse + specular) * attenuation;\n"
"}\n"

"vec3 calcSpotLight(Light _light, vec3 _viewDir)\n"
"{\n"
	 "vec3 lightDir = normalize(_light.position - FragPos);\n"
	 "vec3 ret = calcPointLight(_light, _viewDir);\n"

	 "float angleCos = dot(lightDir, normalize(-_light.direction));\n"
	 "float intensity = clamp((angleCos - _light.outerCutOff) / (_light.cutOff - _light.outerCutOff), 0.f, 1.f);\n"

	 "return ret * intensity;\n"
"}"
