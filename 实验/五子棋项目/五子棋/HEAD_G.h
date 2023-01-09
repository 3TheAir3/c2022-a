#ifndef _HEAD_G
#define _HEAD_G

#include"HEAD.h"
extern GLuint rendering_program;

extern GLuint vs[2];
extern GLuint tcs;
extern GLuint tes;
extern GLuint gs;
extern GLuint fs[2];
extern GLuint rendering_program1;//����1����Ⱦ����
extern GLuint rendering_program2;//����2����Ⱦ����
extern GLuint vertex_array_object;
void compile_shader(void);
void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
int running(int running_mode);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void startup();
void render(double currentTime,GLFWwindow* window,int running_mode);
void shutdown();
#endif