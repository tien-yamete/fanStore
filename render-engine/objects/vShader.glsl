#version 400
in vec4 vPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vPosition;
    //gl_Position = model * vPosition;
}