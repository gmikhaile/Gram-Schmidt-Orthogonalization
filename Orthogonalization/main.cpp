
#include <iostream>

#include "OrthonormalSet.h"


int main()
{
    Set vectorSet = { Vec3D(0, 3, 4), Vec3D(1, 0, 1), Vec3D(1, 1, 3), Vec3D(4, 2, 1) };

    OrthonormalSet orthSet(vectorSet);

    orthSet.print();
}