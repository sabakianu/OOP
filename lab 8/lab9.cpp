#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstddef>
#include <queue>
using namespace std;
struct element
{
	string cuvant;
	int aparitii;
	element(string x,int y) : cuvant(x) , aparitii(y) {}
	bool operator<(const element& other) const
	{
		if (this->aparitii > other.aparitii)
			return false;
		if (this->aparitii == other.aparitii)
		{
			int r;
			r = this->cuvant.compare(other.cuvant);
			if (r > 0)
				return true;
			return false;
		}
		return true;
	}
};
int main()
{
	string s1;
	string temp;
	map<string, int> cuvinte;
	priority_queue<element> sortat;
	ifstream file("text.txt");
	if (file.is_open())
	{
		string linie;
		while (getline(file,linie))
		{
			s1 = s1 + linie;
			s1 = s1 + '\n';
		}
	}
	cout << s1;
	size_t cont1 = s1.find_first_not_of(" .,!?;");
	size_t cont2 = s1.find_first_of(" .,!?;",cont1+1);
	if (cont2 == std::string::npos)
		cont2 = s1.size();
	while (cont1 != std::string::npos)
	{
		temp = s1.substr(cont1, cont2 - cont1);
		if (temp[0] >= 'A' && temp[0] <= 'Z')
			temp[0] = temp[0] - 'A' + 'a';
		if (temp[0] != '\0')
			cuvinte[temp]++;
		temp.clear();
		cont1 = s1.find_first_not_of(" .,!?;", cont2 + 1);
		cont2 = s1.find_first_of(" .,!?;", cont1 + 1);
		if (cont1 == std::string::npos)
			break;
		if (cont2 == std::string::npos)
		{
			
			break;			
		}
	}
	map<string, int>::iterator j;
	for (j = cuvinte.begin(); j != cuvinte.end(); ++j)
	{
		element x(j->first, j->second);
		sortat.push(x);
	}
	while (!sortat.empty())
	{
		cout << sortat.top().cuvant << " => " << sortat.top().aparitii << endl;
		sortat.pop();
	}
	return 0;
}