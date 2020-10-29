#include <iostream> 
#include <cmath>
using namespace std; 

class Complex 
{ 
private: 
    float real, imag; 
public: 
    Complex(float r = 0, float i = 0) 
    {  
        real = r;   
        imag = i; 
    } 

    friend ostream & operator << (ostream &out, const Complex &c); 
    friend istream & operator >> (istream &in,  Complex &c); 

    Complex operator + (Complex const &obj) 
    { 
        Complex res; 
        res.real = real + obj.real; 
        res.imag = imag + obj.imag; 
        return res; 
    } 
    Complex operator * (Complex const &obj) 
    { 
        Complex res; 
        res.real = real * obj.real - imag * obj.imag; 
        res.imag = imag * obj.real + real * obj.imag; 
        return res; 
    } 
    Complex operator - (Complex const &obj) 
    { 
        Complex res; 
        res.real = real - obj.real; 
        res.imag = imag - obj.imag; 
        return res; 
    } 
    Complex operator / (Complex const &obj) 
    { 
        Complex res; 
        res.real = (real * obj.real + imag * obj.imag) / (pow(obj.real,2) + pow(obj.imag,2)); 
        res.imag = (imag * obj.real - real * obj.imag) / (pow(obj.real,2) + pow(obj.imag,2)); 
        return res; 
    } 
}; 
  
ostream & operator << (ostream &out, const Complex &c) 
{ 
    out << c.real; 
    out << "+" << c.imag << "i" << endl; 
    return out; 
} 
  
istream & operator >> (istream &in,  Complex &c) 
{ 
    cout << "Enter Real Part "; 
    in >> c.real; 
    cout << "Enter Imaginary Part "; 
    in >> c.imag; 
    return in; 
} 
  
int main() 
{ 
    Complex c1,c2,c3;
    cout << "Input first complex number:" << endl; 
    cin >> c1; 
    cout << "Input second complex number:" << endl;
    cin >> c2;
    c3 = c1 + c2;
    cout << "Addition is:" << c3;  
    c3 = c1 - c2;
    cout << "Substraction is:" << c3;
    c3 = c1 * c2;
    cout << "Multiplication is:" << c3;
    c3 = c1 / c2;
    cout << "Division is:" << c3;
    return 0; 
}