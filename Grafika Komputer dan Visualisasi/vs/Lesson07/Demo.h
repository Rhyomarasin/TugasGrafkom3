#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>

class Demo :
	public RenderEngine
{
public:
	Demo();
	~Demo();
private:
	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2;
	GLuint shadowmapShader, cubeVBO, cubeVAO, cubeEBO, cube_texture, planeVBO, planeVAO, planeEBO, plane_texture, cubeVBO2, cubeVAO2, cubeEBO2, cube_texture2, stexture, stexture2, stexture3;
	GLuint activeProgram;
	int oldKeyState = GLFW_RELEASE;
	bool toggleTextured = false;
	virtual void Init();
	virtual void DeInit();
	virtual void Update(double deltaTime);
	virtual void Render();
	void switchShaderProgram();
	virtual void ProcessInput(GLFWwindow *window);
	void BuildColoredCube();
	void BuildColoredDoor();
	void BuildColoredPlane();
	void DrawColoredCube();
	void DrawColoredDoor();
	void DrawColoredPlane();
	void BuildTexturedCube();
	void BuildTexturedPlane();
	void DrawTexturedCube();
	void DrawTexturedPlane();
};

