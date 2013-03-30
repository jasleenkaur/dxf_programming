#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>    //system call
using namespace std;

int main()
{
    int color_entity, color_hatching;
    string line_type, layer_name, pattren;
    double centerX, centerY, radius;
    cout<<"\n\tEnter center of circle: ";
    cin>>centerX>>centerY;
    cout<<"\n\tEnter radius of circle: ";
    cin>>radius;
    cout<<"\n\tCode for colours are\n\t1 for red\n\t2 for yellow\n\t3 for Green\n\t4 for Cyan\n\t5 for Blue\n\t6 for Magenta\n\t7 for White\n\t8 for Grey\n\t9 for Light Grey\n";
    cout<<"\n\tEnter color code for entity: ";
    cin>>color_entity;
    cout<<"\n\tEnter pattren you want for hatching (hex, ansi31, honeycomb, paisley): ";
    cin>>pattren;
    cout<<"\n\tEnter color code for hatching: ";
    cin>>color_hatching;
    cout<<"\n\tEnter line type(dot,dashed,continuous): ";
    cin>>line_type;
    
    ofstream obj;
    obj.open("entity.dxf");
    obj<<"0\nSECTION\n2\nENTITIES\n0\nHATCH\n5\n44\n8\nLayer1\n62\n"<<color_hatching<<"\n370\n-1\n6\nByLayer\n100\nAcDbEntity\n100\nAcDbHatch\n10\n0.0\n20\n0.0\n30\n0.0\n210\n0.0\n220\n0.0\n230\n1.0\n2\n"<<pattren<<"\n70\n0\n70\n0\n91\n1\n92\n1\n93\n1\n72\n2\n";
    obj<<"10\n"<<centerX<<"\n20\n"<<centerY<<"\n40\n"<<radius<<"\n50\n0.0\n51\n360.0\n73\n1\n97\n0\n75\n0\n76\n1\n52\n30.0\n41\n0.9\n77\n0\n78\n1\n53\n45.0\n43\n0.0\n44\n0.0\n45\n-0.0883883476483184\n46\n0.088388347\n79\n0\n98\n0\n";         
    obj << "0\nSECTION\n2\nENTITIES\n0\nCIRCLE\n5\n43\n100\nAcDbEntity\n100\nAcDbCircle\n8\nLayer2\n62\n"<<color_entity<<"\n370\n-1\n6\n"<<line_type<<"\n10\n"<<centerX<<"\n20\n"<<centerY<<"\n30\n0.0\n40\n"<<radius<<"\n0\nENDSEC\n";
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
