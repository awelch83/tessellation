#include <cmath>
#include <iostream>
using namespace std;

float getDistance(float,float,float,float);
float getX(float,float,float,float,float);
float getY(float,float,float,float,float);

int main()
{
    float distance;
    int numVertices;
    float pixMove;

    cout << "Vertices: ";
    cin >> numVertices;
    cout << "Pix to move: ";
    cin >> pixMove;

    float curVertices[numVertices][2];
    float nextVertices[numVertices][2];

    for(int i = 0; i < numVertices; i++)
    {
        cout << "x" << i+1 << ": ";
        cin >> curVertices[i][0];
        cout << "y" << i+1 << ": ";
        cin >> curVertices[i][1];
    }

    distance = getDistance(curVertices[0][0],curVertices[0][1],curVertices[1][0],curVertices[1][1]);
    cout << (pixMove/distance) << endl;

    return 0;
}

float getDistance(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow((x2-x1),2)+pow((y2-y1),2));

    return d;
}

float getX(float x1, float y1, float x2, float y2, float pixMove)
{
    float x;

    return x;
}

float getY(float x1, float y1, float x2, float y2, float pixMove)
{
    float y;

    return y;
}
