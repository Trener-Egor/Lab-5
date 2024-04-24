#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_set>

#include "Students.h"


void read_from_file(const std::string& file_name, std::set<student>& set)
{
	std::ifstream file(file_name);

	if (!file.is_open())
	{
		std::cout << "file didnt open\n";
		return;
	}

	while (!file.eof())
	{
		std::string grp;
		std::string f;
		std::string i;
		std::string o;
		int id;
		int arr[4];
		file >> grp >> id >> f >> i >> o >> arr[0] >> arr[1] >> arr[2] >> arr[3];

		student newstudent(f, i, o, grp, id);
		newstudent.set_marks(arr);

		std::pair<std::set<student>::iterator,bool> insert_result =  set.insert(newstudent);

		if(insert_result.second == true)
		{
			std::cout << "successfuly insert: " << insert_result.first->get_id() << std::endl;
		}
		else
		{
			std::cout << "cant insert: " << newstudent.get_id() << std::endl;
		}
	}
	file.close();
}

int main()
{
	std::string fname = "input.txt";
	std::set<student> set_st;

	read_from_file(fname, set_st);

	if (set_st.empty())
	{
		std::cout << "set is empty\n";
		return 0;
	}
	std::ofstream file("output.txt");

	if (!file.is_open())
	{
		std::cout << "file error\n";
		return 0;
	}

	for (std::set<student>::iterator it_b = set_st.begin(),
		                             it_e = set_st.end(); it_b != it_e; ++it_b)
	{
		file << *it_b;
	}
	
	std::unordered_set<student,student::hash> us_st;
	
	for (std::set<student>::iterator it_b = set_st.begin(),
		                             it_e = set_st.end(); it_b != it_e; ++it_b)
	{
		us_st.insert(*it_b);
	}
	file << "\nprint unordered_set:\n";


	for (std::unordered_set<student>::iterator it_b = us_st.begin(),
		                                       it_e = us_st.end(); it_b != it_e; ++it_b)
	{
		file << *it_b;
	}
	//file << "\ncopy list std::copy:\n";

	//std::list<student>  newlst;
	//std::copy(deq_st.begin(), deq_st.end(), std::back_inserter(newlst));

	//file << "\ncopy list print:\n";

	//for (std::list<student>::iterator it_b = newlst.begin(),
	//	it_e = newlst.end(); it_b != it_e; ++it_b)
	//{
	//	file << *it_b;
	//}
}
//iomanip std::setw(x) 
/*категори€ значений
*                                   expression
*               glvalue										 rvalue
*	  lvalue						  xvalue			 	              prvalue
*
* glvalue-generalized lvalue-представл€ет собой выражение,вычисление которого определ€ет идентичность объекта или функции
* сущности имеющей storage
* prvalue-pure value-выражение вычисление которого инициализирует объект(или битовое поле)или вычисл€ет значение операнда оператора
* пример:
* foo(std::string("hello")){}        foo(const std::string& s){}
* int v =5;  f(v);        f(3+2);    f(int arg)
* xvalue-объект или битовое поле ресурсы которого могут быть повторно использованы (обычно из-за того что вскоре исчезает его врем€ жизни)
* std::string str = "abc"
* foo(std::move(str))
* lvalue- представл€ет собой glvalue не €вл€ющейс€ xvalue
* rvalue- представл€ет собой либо prvalue либо xvalue
*/