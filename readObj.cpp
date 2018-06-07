#include "readObj.h"
#include "OBJ_Loader.h"
#include <iostream>

using namespace std;

void readObj(char *fileName,
             Point &minCoords,
             Point &maxCoords,
             vector<Point> *vertices,
             vector<vector<int>> *flats
) {
    double minX = 1000, maxX = -1000;
    double minY = 1000, maxY = -1000;
    double minZ = 1000, maxZ = -1000;

    objl::Loader Loader;
    bool loadOut = Loader.LoadFile(fileName);

    if (loadOut) {
        for (int i = 0; i < Loader.LoadedMeshes.size(); i++) {
            objl::Mesh curMesh = Loader.LoadedMeshes[i];

            for (int j = 0; j < curMesh.Vertices.size(); j++) {
                Point curV;
                curV.x = curMesh.Vertices[j].Position.X;
                curV.y = curMesh.Vertices[j].Position.Y;
                curV.z = curMesh.Vertices[j].Position.Z;

                minX = minX < curV.x ? minX : curV.x;
                maxX = maxX > curV.x ? maxX : curV.x;

                minY = minY < curV.y ? minY : curV.y;
                maxY = maxY > curV.y ? maxY : curV.y;

                minZ = minZ < curV.z ? minZ : curV.z;
                maxZ = maxZ > curV.z ? maxZ : curV.z;

                vertices->push_back(curV);
            }
            for (int j = 0; j < curMesh.Indices.size(); j += 3) {
                vector<int> newIntV;
                newIntV.push_back(curMesh.Indices[j]);
                newIntV.push_back(curMesh.Indices[j+1]);
                newIntV.push_back(curMesh.Indices[j+2]);
                flats->push_back(newIntV);
            }
        }
        minCoords = Point(minX, minY, minZ);
        maxCoords = Point(maxX, maxY, maxZ);
    } else {
        cout << "Cannot load file: " << fileName << endl;
    }
}