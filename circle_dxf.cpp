#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>    //system call
using namespace std;

int main()
{
    int color;
    string line_type, layer_name;
    double centerX,centerY,radius;
    cout<<"\n\tEnter center of circle: ";
    cin>>centerX>>centerY;
    cout<<"\n\tEnter radius of circle: ";
    cin>>radius;
    cout<<"\n\tWhat color you want?\n\tEnter 1 for red\n\tEnter 2 for yellow\n\tEnter 3 for Green\n\tEnter 4 for Cyan\n\tEnter 5 for Blue\n\tEnter 6 for Magenta\n\tEnter 7 for White\n\tEnter 8 for Grey\n\tEnter 9 for Light Grey\n";
    cin>>color;
    cout<<"\n\tEnter line type(dot,dashed,continuous): ";
    cin>>line_type;
    cout<<"Enter layer name:";
    cin>>layer_name;

    ofstream obj;
    obj.open("entity.dxf");
    obj << "0\nSECTION\n2\nENTITIES\n0\nCIRCLE\n5\n43\n100\nAcDbEntity\n100\nAcDbCircle\n8\n"<<layer_name<<"\n62\n"<<color<<"\n370\n-1\n6\n"<<line_type<<"\n10\n"<<centerX<<"\n20\n"<<centerY<<"\n30\n0.0\n40\n"<<radius<<"\n0\nENDSEC\n";
    obj.close();

    string line;
    ifstream head("header.dxf");
    ifstream entity("entity.dxf");
    ifstream foot("footer.dxf");
    ofstream myfile;
    myfile.open("circle.dxf");
		while(getline(head,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
		while(getline(entity,line,'\n'))  
		{
			myfile<<line<<endl;  
		}
		while(getline(foot,line,'\n'))  
		{
			myfile<<line<<endl;  
		}

    entity.close();
    foot.close();		
    myfile.close();
    head.close();		

    system("librecad circle.dxf");

}
