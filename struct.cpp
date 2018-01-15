#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <typeinfo>

using namespace std;

struct FORMAT  
{  
    double x;  
    double y;  
    double z;  
};  
   
struct GYRODATA  
{  
    vector<FORMAT> gyroscopeData; 
    vector<FORMAT> accelerometerData;  
    vector<FORMAT> magnetometerData;  
    vector<double> timeData;  
};  
  
template <typename T>  
struct Type2Type  
{  
    typedef T type;  
};  
  
template <typename T>  
inline void sscanfData(const char* buf,T& tempData,Type2Type<double>)  
{  
    sscanf(buf,"%lf",&tempData);  
}  
  
template <typename T>  
inline void sscanfData(const char* buf,T& tempData,Type2Type<FORMAT>)  
{  
    sscanf(buf,"%lf %lf %lf",&tempData.x,&tempData.y,&tempData.z);  
}  

template <class T>  
void getDatafromTxt(const string filename,vector<T>& vecData)  
{  
    char buf[1024];          
    string message;    
    ifstream infile;    
    infile.open(filename);    
  
    if(infile.is_open())             
    {    
        while(infile.good() && !infile.eof())    
        {    
            memset(buf,0,1024);    
            infile.getline(buf,1024);   
  
            T tempData;  
            sscanfData(buf,tempData,Type2Type<T>());  
            //sscanf(buf,"%lf %lf %lf",&tempData.x,&tempData.y,&tempData.z);  
            vecData.push_back(tempData);   
        }    
        infile.close();    
    }   
    else cout<<"file open failed..."<<endl;  
}  
  
template<typename... Elements> 
class mytuple;

template<typename Head, typename... Tail>
class mytuple<Head, Tail...> : private mytuple<Tail...> {
    Head head;
public:
    /* implementation */
};

template<>
class mytuple<> {
    /* zero-tuple implementation */
};

int main()  
{  
    GYRODATA GyroData;  
    Type2Type<FORMAT> f1;
    Type2Type<double> f2;
    
    mytuple<double, double, double> tt;    

    cout << typeid(GyroData).name() << '\n';
    cout << typeid(GyroData.gyroscopeData).name() << '\n';
    cout << typeid(Type2Type<FORMAT>::type).name() << '\n';
    cout << typeid(Type2Type<double>::type).name() << '\n';
    cout << typeid(Type2Type<FORMAT>).name() << '\n';  
    cout << typeid(tt).name() << '\n';
    cout << sizeof(double) << '\n';  
    cout << sizeof(std::string) << '\n';
    cout << sizeof(tt) << '\n';
    return 0;  
}
