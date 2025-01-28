#version 330 core

layout (location = 0) in vec3 positionBuffer;
layout (location = 1) in vec3 colorBuffer;

uniform float horizontalOffset;
out vec3 color;

void main(){
    gl_Position = vec4(positionBuffer.x + horizontalOffset, positionBuffer.y, positionBuffer.z, 1.0);
    color = colorBuffer;
}