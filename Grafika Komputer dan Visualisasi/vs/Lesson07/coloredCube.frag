#version 330 core

in vec3 Normal;
in vec3 FragPos;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};
uniform Material material;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;

void main()
{
    // ambient
    float Ka = 0.5;
    vec3 ambient = Ka * lightColor * material.ambient;
    // diffuse 
	float Kd = 1.5;
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = Kd * max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor * material.diffuse;
    // specular
    float Ks = 0.8;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = Ks * spec * lightColor * material.specular;
    vec3 result = (ambient + diffuse + specular);
    gl_FragColor = vec4(result, 1.0);
}
