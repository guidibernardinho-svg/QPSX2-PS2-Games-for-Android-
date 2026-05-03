#include <GLES2/gl2.h>
#include <jni.h>

static GLuint program;

static const char* vertexShaderSrc = R"(
attribute vec4 position;
void main() {
    gl_Position = position;
}
)";

static const char* fragmentShaderSrc = R"(
precision mediump float;
void main() {
    gl_FragColor = vec4(0.2, 0.6, 1.0, 1.0); // azul PS2 vibe
}
)";

GLuint compileShader(GLenum type, const char* src) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);
    return shader;
}

void initRenderer() {
    GLuint v = compileShader(GL_VERTEX_SHADER, vertexShaderSrc);
    GLuint f = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);

    program = glCreateProgram();
    glAttachShader(program, v);
    glAttachShader(program, f);
    glLinkProgram(program);
}

void renderFrame() {
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f
    };

    GLint pos = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(pos);
    glVertexAttribPointer(pos, 2, GL_FLOAT, GL_FALSE, 0, vertices);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
