#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>  //system call
using namespace std;
void line(int handle, double point1x,double point1y, double point2x, double point2y);
 ofstream obj;
int main()
{
    double 	X1, Y1, X2, Y2;
    cout<<"Enter co-ordinates of point one: ";
    cin>>X1>>Y1;
    cout<<"Enter co-ordinates of point two: ";
    cin>>X2>>Y2;

   
    obj.open("entity.dxf");
    obj << "0\nSECTION\n2\nENTITIES\n";

    line(45, X1, Y1, X2, Y1);
    line(46, X2, Y1, X2, Y2);
    line(47, X2, Y2, X1, Y2);
    line(48, X1, Y2, X1, Y1);
    obj.close();
    
    string line;
    ifstream head("header.dxf");
    ifstream entity("entity.dxf");
    ifstream foot("footer.dxf");
    ofstream myfile;
    myfile.open("rectangle.dxf");   
    while(getline(head,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
    while(getline(entity,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
		
     while(getline(foot,line,'\n'))  
		{
			myfile<<line<<"\n";  
		}
entity.close();
foot.close();		
myfile.close();
head.close();


    system("librecad rectangle.dxf");

}
void line(int handle, double point1x, double point1y, double point2x, double point2y)
{   
obj<< "0\nLINE\n5\n"<<handle<<"\n100\nAcDbEntity\n100\nAcDbLine\n8\n0\n62\n256\n370\n-1\n6\nByLayer\n10\n"<<point1x<<"\n20\n"<<point1y<<"\n30\n0.0\n11\n"<<point2x<<"\n21\n"<<point2y<<"\n31\n0.0\n";
    
}
