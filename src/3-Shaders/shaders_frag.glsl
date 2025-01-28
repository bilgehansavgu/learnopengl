#version 330 core

out vec4 vertexColor;
in vec3 color;

void main(){
    vertexColor = vec4(color, 1.0);
}