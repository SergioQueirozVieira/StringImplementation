#include <iostream>
#include <cassert>
#include <string.h>

using namespace std;

class String {
    int size;
    char* buffer;
public:
    String();//ok
    String(const String&);//ok
    String(const char*);//ok
    ~String();//ok
    void setBuffer(const char*);
    char* getBuffer();
    int length() const;//ok
    char& operator[] (unsigned int);
    int indice(char);
    void operator =(String&);//ok
    String operator +(String&);//teste
    void operator += (String&);//teste

    void upcase(unsigned int, unsigned int);
    void downcase(unsigned int, unsigned int);
    void toggle_case(unsigned int, unsigned int);

    friend bool operator==(String&, String&);//ok
    friend bool operator<=(const String&, const String&);//teste
    friend bool operator<(const String&, const String&);//teste
    friend bool operator>=(const String&, const String&);//teste
    friend bool operator>(const String&, const String&);//teste
    friend ostream& operator<<(ostream&, const String&);//ok
    friend istream& operator>>(istream&, const String&);//ok

};

String::String()
{
    buffer = nullptr;
    size = 0;
}

String::String(const String& s)
{
    size = s.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++) {
        buffer[i] = s.buffer[i];
    }
}

String::String(const char* p)
{
    int i = 0;
    const char* t = p;

    while (*p++)
    {
        i++;
    }

    buffer = new char[i];
    int j = 0;

    for (j; *t; t++, j++)
    {
        buffer[j] = *t;
    }
    size = j;
}

String::~String()
{
    delete[] buffer;
}

char* String::getBuffer()
{
    return buffer;
}

int String::length() const
{
    if (buffer == nullptr)
    {
        return 0;
    }
    else
    {
        return size;
    }
}

char& String::operator[] (unsigned int x)
{
    return buffer[x];
}

int String::indice(char x)
{
    int j = 0;

    for (j; j< length(); j++)
    {
        if (buffer[j] == x) {
            return j;
        }
        
    }
    return -1;
}

// void String::operator =(String& s)
// {
//     if(this != &s){
//         delete buffer;
//         buffer = new char[s.length()];
//         for(int i = 0; i < s.length(); i++){
//             buffer[i] = s.buffer[i];
//         }
//     }
       
// }

void String::upcase(unsigned int inicio, unsigned int fim)
{
    for(int i = inicio; i <= fim; i++){
       if(getBuffer()[i] >= 97 && getBuffer()[i] <= 122) {
        getBuffer()[i] = getBuffer()[i]-32;
       }
    }
}

void String::downcase(unsigned int inicio, unsigned int fim)
{
    for(int i = inicio; i <= fim; i++){
        if(getBuffer()[i] >= 65 && getBuffer()[i] <= 90){
             getBuffer()[i] = getBuffer()[i]+32;         
        }
    }
}

void String::toggle_case(unsigned int inicio, unsigned int fim)
{
    
    for(int i = inicio; i <= fim; i++){
        if(getBuffer()[i] >= 65 && getBuffer()[i] <= 90){
       getBuffer()[i] = getBuffer()[i]+32;         
    }else if(getBuffer()[i] >= 97 && getBuffer()[i] <= 122) {
        getBuffer()[i] = getBuffer()[i]-32;

        }
    }
}
 
 String String::operator +(String& s1)
{
    int newSize = s1.length()+length();
    char* conpi = new char[newSize];
    
    for (int i = 0; i < newSize; i++) {
        if(i < size){
        conpi[i] = getBuffer()[i];
        }else{
            conpi[i] = s1.getBuffer()[i-size];
        }
    }
    return conpi;
}

void String::operator +=(String& s)
{//a+=b
    int newSize = s.length()+length();
    char* conpi = new char[newSize];
    
    for (int i = 0; i < newSize; i++) {
        if(i < size){
        conpi[i] = getBuffer()[i];
        }else{
            conpi[i] = s.getBuffer()[i-size];
        }
    }
    delete buffer;
    size = newSize;
    buffer = conpi;
    
}

ostream& operator<<(ostream& os, const String& s)
{
    for (int i = 0; i < s.size; i++)
    {
        os << s.buffer[i];
    }
    return os;

}

istream& operator>>(istream& is, const String& s)
{
   
    is >> s.buffer;
    return is;

}

// comparadores //
bool operator==(String& s, String& t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.getBuffer()[i] != t.getBuffer()[i])
            {
                return false;
            }
        }
    }
    return true;

}
bool operator!=(String& s, String& t)
{
    if (s.length() != t.length())
    {
        return true;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.getBuffer()[i] != t.getBuffer()[i])
            {
                return true;
            }
        }
    }
    return false;

}
bool operator<=(const String& s, const String& t)
{
    if (s.length() <= t.length())
    {
        return true;
    }
    return false;

}
bool operator <(const String& s, const String& t)
{
    if (s.length() < t.length())
    {
        return true;
    }
    return false;

}
bool operator >=(const String& s, const String& t)
{
    if (s.length() >= t.length())
    {
        return true;
    }
    return false;

}
bool operator >(const String& s, const String& t)
{
    if (s.length() > t.length())
    {
        return true;
    }
    return false;

}


int main()
{
    String s1("Sistemas Operacionais");  
    String s2("PrimeiroTrabalho");
    String s3("PrimeiroTrabalho");
    cout << "Teste do metodo length" << endl;
    cout << "Primeiro Teste" << endl;
    cout << "A string: " << s1;
    cout << " tem tamanho = " << s1.length() << endl;
    cout << "Segundo Teste" << endl;
    cout << "A string: " << s2 << " tem tamanho = " << s2.length() << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo indice" << endl;
    cout << "String 1: " << s1 << "; String 2 = " << s2 << endl; 
    cout << "Indice da PRIMEIRA letra 'a' nas duas strings" << endl;
    cout << s1.indice('a') << endl;
    cout << s2.indice('a') << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo == (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 == String 2" << endl;
    cout << (s1 == s2) << endl;
    cout << "String 3 = " << s3 << endl;
    cout << "String 2 == String 3" << endl;
    cout << (s2 == s3) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo != (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 != String 2" << endl;
    cout << (s1 != s2) << endl;
    cout << "String 3 = " << s3 << endl;
    cout << "String 2 != String 3" << endl;
    cout << (s2 != s3) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo > (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 > String 2" << endl;
    cout << (s1 > s2) << endl;
    cout << "String 2 > String 1" << endl;
    cout << (s2 > s1) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo < (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 < String 2" << endl;
    cout << (s1 < s2) << endl;
    cout << "String 2 < String 1" << endl;
    cout << (s2 < s1) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo <= (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 <= String 2" << endl;
    cout << (s1 <= s2) << endl;
    cout << "String 3 = " << s3 << endl;
    cout << "String 2 <= String 3" << endl;
    cout << (s2 <= s3) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo >= (0 = falso, 1 = true)" << endl;
    cout << "String 1 = " << s1 << endl;
    cout << "String 2 = " << s2 << endl;
    cout << "String 1 >= String 2" << endl;
    cout << (s1 >= s2) << endl;
    cout << "String 3 = " << s3 << endl;
    cout << "String 2 >= String 3" << endl;
    cout << (s2 >= s3) << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo upcase da posicao 2 ate 7" << endl;
    cout << "Antes: " << s1 << endl; 
    s1.upcase(2,7);
    cout << "Depois: " << s1 << endl;
    cout << "Teste do metodo upcase da posicao 5 ate 10" << endl;
    cout << "Antes: " << s2 << endl; 
    s2.upcase(5,10);
    cout << "Depois: " << s2 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo downcase da posicao 2 ate 7" << endl;
    cout << "Antes: " << s1 << endl; 
    s1.downcase(2,7);
    cout << "Depois: " << s1 << endl;
    cout << "Teste do metodo downcase da posicao 5 ate 10" << endl;
    cout << "Antes: " << s2 << endl; 
    s2.downcase(5,10);
    cout << "Depois: " << s2 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo toggle_case da posicao 2 ate 7" << endl;
    cout << "Antes: " << s1 << endl; 
    s1.toggle_case(2,7);
    cout << "Depois: " << s1 << endl;
    cout << "Teste do metodo toggle_case da posicao 5 ate 10" << endl;
    cout << "Antes: " << s2 << endl; 
    s2.toggle_case(5,10);
    cout << "Depois: " << s2 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo +" << endl;
    cout << "String 1: " << s1 << "; String 2 = " << s2 << endl; 
    cout << "s1 + s2 = " << (s1 + s2) << endl;
    cout << s1 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo =" << endl;
    cout << "String 1: " << s1 << "; String 2 = " << s2 << endl; 
    s1 = s2;
    cout << "s1 = s2 => " << s1 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo +=" << endl;
    cout << "String 1: " << s1 << "; String 2 = " << s2 << endl; 
    s1 += s2;
    cout << "s1 += s2 => " << s1 << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Teste do metodo >>" << endl;
    String x("                                             ");
    cout << "Digite uma string " << endl; 
    cin >> x;
    cout << "A String digitada foi: " << x << endl;
    cout << "-------------------------------------------------------------" << endl;
      
}