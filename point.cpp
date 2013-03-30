#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
    {
    double centerX, centerY;
    cout<<"Enter X coordinate of point: ";
    cin>>centerX;
    cout<<"Enter Y coordinate of point: ";
    cin>>centerY;
    
    ofstream obj("entity.dxf");
    obj<<"0\nSECTION\n2\nENTITIES\n0\nPOINT\n5\n43\n100\nAcDbEntity\n100\nAcDbPoint\n8\n0\n62\n256\n370\n-1\n6\nByLayer\n10\n"<<centerX<<"\n20\n"<<centerY<<"\n0\nENDSEC\n";
    obj.close();
    
    string line;
    ofstream myfile("point.dxf");
    ifstream head("header.dxf");
    ifstream entity("entity.dxf");
    ifstream foot("footer.dxf");
    
    while(getline(head,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
	head.close();	
    while(getline(entity,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
	entity.close();	
    while(getline(foot,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
	foot.close();
	
	
	myfile.close();
    system("librecad point.dxf");
    }
