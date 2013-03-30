#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
    {
    double pt1X, pt1Y, pt2X, pt2Y;
    cout<<"Enter coordinates of first point: ";
    cin>>pt1X>>pt1Y;
    cout<<"Enter coordinates of second point: ";
    cin>>pt2X>>pt2Y;
    
    ofstream obj("entity.dxf");
    obj<<"0\nSECTION\n2\nENTITIES\n0\nLINE\n5\n43\n100\nAcDbEntity\n100\nAcDbPoint\n8\n0\n62\n256\n370\n-1\n6\nByLayer\n10\n"<<pt1X<<"\n20\n"<<pt1Y<<"\n11\n"<<pt2X<<"\n21\n"<<pt2Y<<"\n0\nENDSEC\n";
    obj.close();
    
    string line;
    ofstream myfile("line.dxf");
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
    system("librecad line.dxf");
    }
