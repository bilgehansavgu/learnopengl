#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>


// Vertex data containers
struct Position { float x, y, z; };
struct TexCoord { float u, v; };
struct Normal { float nx, ny, nz; };

// Combined vertex attributes
struct Vertex {
    Position position;
    TexCoord texCoord;
    Normal normal;
};

std::vector<Position> positions;
std::vector<TexCoord> texCoords;
std::vector<Normal> normals;
std::vector<Vertex> vertices;
std::vector<unsigned int> indices;