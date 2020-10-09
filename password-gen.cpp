#include <random>
#include <iostream>
#include <fstream>
char *d;
char *randomize(int input);
bool check();
void reg(char *input);
int main()
{
    do{
    int cnt;
    char *val;
    std::cout<<("Please state how many digits you want in your password: "); std::cin>>(cnt);
    val=randomize(cnt);
    for (size_t i = 0; i < cnt; i++)
    {
        std::cout<<val[i];
    }
    std::cout<<std::endl;
    std::cout<<"Would you like to save this password to a .txt file?(Y/N)";
    if(check())
    {
        reg(val);
    }
    std::cout<<"Would you like to create another password?(Y/N)";
    }while (check());
}
char *randomize(int input)
{
    srand(time(0));
    d=new char[input];
    for (size_t i = 0; i < input; i++)
    {
        int r;
        r=rand()%74+48;//48-122-(58-64)&&-(91-96)       
        for (size_t j = 58; j < 65; j++)//Checking if char is as wanted
        {if (r==j) r=48+rand()%9;}
        for(size_t k=91;k<97;k++)//Checking if char is as wanted
        {if(r==k) r=48+rand()%9;}
        d[i]=r;
    }
    return d;
}
bool check()
{
    char ask;
    std::cin>>ask;
    if (ask=='y')
    {
    return true;
    }    
    return false;
}
void reg(char *input)
{
    std::string name;
    std::ofstream save;
    save.open("totally not passwords.txt", std::ios::app);
    std::cout<<"What do you want to use this password for? "; std::cin>>name;
    save<<"Password for "<<name<<" is: "<<input<<"\n";
}