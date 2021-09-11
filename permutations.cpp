#include<iostream>

void per(std::string before, std::string now)
{
	int len = now.length();
	if(len == 0)
	{
		std::cout<<before<<std::endl;
		return;
	}
	for(int i=0; i<len;i++)
	{
		//std::cout << in[i] << std::endl;
		//std::cout << in.substr(0,i) + in.substr(i+1,len-i-1) << std::endl;
		per(before + now[i], now.substr(0,i) + now.substr(i+1,len-i-1));
	}
}

void permutations(std::string in)\
{
	per("",in);
}