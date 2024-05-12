#include <cmath>
#include <iostream>
#include <string>

using namespace std;

float getDistance(float,float,float,float);
float getX(float,float,float,float,float);
float getY(float,float,float,float,float);

int main()
{
    float distance;
    int numVertices;
    float pixMove;
    float x1,y1,x2,y2;
    string polygon = "<polygon points=\"";

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

    for(int j = 0; j < numVertices; j++)
    {
        if((j+1) < numVertices)
        {
            x1 = curVertices[j][0];
            y1 = curVertices[j][1];
            x2 = curVertices[j+1][0];
            y2 = curVertices[j+1][1];
        }
        else
        {
            x1 = curVertices[j][0];
            y1 = curVertices[j][1];
            x2 = curVertices[0][0];
            y2 = curVertices[0][1];
        }
        nextVertices[j][0] = getX(x1,y1,x2,y2,pixMove);
        nextVertices[j][1] = getY(x1,y1,x2,y2,pixMove);

        polygon += to_string(nextVertices[j][0]);
        polygon += ",";
        polygon += to_string(nextVertices[j][1]);
        if((j+1) < numVertices)
            polygon += " ";
        else
            polygon += "\" ";
    }

    polygon += " stroke=\"white\" fill=\"none\" stroke-width=\"1\"/>";

    cout << polygon << endl;

    return 0;
}

float getDistance(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow((x2-x1),2)+pow((y2-y1),2));

    return d;
}

float getX(float x1, float y1, float x2, float y2, float pixMove)
{
    float distance = getDistance(x1,y1,x2,y2);
    float scale = (pixMove/distance); // percentage
    float x = x1+(scale*(x2-x1));

    return x;
}

float getY(float x1, float y1, float x2, float y2, float pixMove)
{
    float distance = getDistance(x1,y1,x2,y2);
    float scale = (pixMove/distance); // percentage
    float y = y1+(scale*(y2-y1));

    return y;
}
