#ifndef HW1
#define HW1

#define MAX_HOBBIES 25
#define MAX_DATA 100

typedef class
{
	public:
		std::string street;
		std::string city;
		int index;
} address;

typedef class
{
	public:
		std::string name;
		int hobbiesNum;
		std::string hobbies[MAX_HOBBIES];
		address place;
} data;

int Read_Data(int, data*);
std::string Read_Hobby(std::ofstream&);
void Output_Data(int, data*, std::ofstream&);
void Find_People(int, data*, std::string, std::ofstream&);
bool iequals(const std::string&, const std::string&);

#endif
