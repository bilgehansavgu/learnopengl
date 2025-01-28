#ifndef SHADER_H
#define SHADER_H

class Shader
{
public:
    Shader();
    ~Shader();

    bool load(const char* vertexPath, const char* fragPath);

    void use() const;

    unsigned int getID() const;
    

private:
    unsigned int ID;

};

#endif
