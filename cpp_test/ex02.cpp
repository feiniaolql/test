#include <iostream>
using namespace std;

class score {
	private :
	float english_score;
	public :
	score()
	{ english_score = 1.0; }

	void setscore(float set_number)
	{
		english_score = set_number;
	}
	void printscore()
	{
		cout<<"english score: "<<english_score<<endl;
	}

};

int main()
{
	score stu1, stu2;
	stu1.printscore();
	stu2.printscore();
	stu1.setscore(85.5);
	stu2.setscore(93.5);
	stu1.printscore();
	stu2.printscore();
	return 0;
}
