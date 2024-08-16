//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string>
#include "student.hpp"

int main()
{
	string line;
	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);

	int stu_count = 1;
	int i = 0;
	int dnum = 100;
	NodePtr d_h = NULL;
	while (getline(domesticFile, line))
	{
		istringstream ss(line);

		string firstName, lastName, province, s_cgpa, s_researchScore;
		float cgpa;
		int researchScore;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get province separated by comma
		getline(ss, province, ',');

		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		D_StudentPtr s = new DomesticStudent;
		s->setFirst(firstName);
		s->setLast(lastName);
		s->setCGPA(cgpa);
		s->setResearch(researchScore);
		s->setProvince(province);
		s->setApplication(20200000 + stu_count - 1);

		insert(d_h, s);

		stu_count++;
		i++;
	}

	//close your file
	domesticFile.close();

	string line2;
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open())
	{
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	getline(internationalFile, line2);

	i = 0;
	int inum = 100;
	NodePtr i_h = NULL;
	while (getline(internationalFile, line2))
	{
		istringstream ss(line2);

		string firstName, lastName, country, s_cgpa, s_researchScore, s_read, s_listen, s_speak, s_write;
		float cgpa;
		int researchScore;
		int read, listen, speak, write;
		ToeflScore toefl;

		getline(ss, firstName, ',');

		getline(ss, lastName, ',');

		getline(ss, country, ',');

		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		getline(ss, s_read, ',');
		read = atoi(s_read.c_str());

		getline(ss, s_listen, ',');
		listen = atoi(s_listen.c_str());

		getline(ss, s_speak, ',');
		speak = atoi(s_speak.c_str());

		getline(ss, s_write, ',');
		write = atoi(s_write.c_str());

		toefl.setReading(read);
		toefl.setListening(listen);
		toefl.setSpeaking(speak);
		toefl.setWriting(write);
		toefl.setTotal();

		I_StudentPtr s = new InternationalStudent;
		s->setFirst(firstName);
		s->setLast(lastName);
		s->setCGPA(cgpa);
		s->setResearch(researchScore);
		s->setCountry(country);
		s->setToefl(toefl);
		s->setApplication(20200000 + stu_count - 1);

		insert(i_h, s);

		stu_count++;
		i++;
	}

	//close your file
	internationalFile.close();

	NodePtr h = NULL;

	Lab3(d_h, i_h, h);

	cout << endl;


	//unit test start here
	NodePtr dlist = NULL;
	cout<<"Domestic Student: "<<endl;
	cout<<"******testing normal case******"<<endl;
	string firstname = "Tao";
	string lastname = "Li";
	string province = "BC";
	const float cgpa = 3.5;
	const int research = 90;
	const int idnum = 20208888;
	//add student
	D_StudentPtr ds = new DomesticStudent;
	ds->set(firstname, lastname,cgpa,research,province,idnum);
	cout<<"insert a domestic student Tao"<<endl;
	insert(dlist,ds);
	print_link(dlist);
	cout<<"insert another student He Yuhan"<<endl;
	ds = new DomesticStudent;
	ds->set("Yuhan","He",4.3,95,"AB",20206666);
	insert(dlist,ds);
	print_link(dlist);
	cout<<endl<<"search Tao by CGPA and research score"<<endl;
	searchCGPA(dlist);
	searchName(dlist );
	cout<<endl<<"remove student Tao"<<endl;
	deleteExistNode(dlist );
	print_link(dlist);
	cout<<endl<<endl;

	cout<<"******testing corner case******"<<endl;
	cout<<"search a student by name(first and last) and score(cpga and research) which is the only student in the list: "<<endl;
	searchCGPA(dlist);
	searchName(dlist);
	cout<<"delete the only student in the list"<<endl;
	deleteExistNode(dlist);
	print_link(dlist);
	cout<<endl<<endl<<endl;

	cout<<"******testing illegal case******"<<endl;
	cout<<"search for a non-exsitence student in the list:"<<endl;
	searchCGPA(dlist);
	searchName(dlist);
	//delete head and tail node
	remove_front_tail(dlist);

    cout<<"International students: "<<endl;
    cout<<"******Testing normal case******"<<endl;
    ToeflScore tss;
	NodePtr ilist = NULL;
        tss.setReading(27);
        tss.setListening(29);
        tss.setSpeaking(30);
        tss.setWriting(30);
        tss.setTotal();
	I_StudentPtr iss = new InternationalStudent;
	cout<<"insert an international student Ke Yi"<<endl;
	iss->set("Ke","Yi","India",tss,3.6,87,20202335);
	insert(ilist, iss);
	print_link(ilist);
	cout<<endl<<"insert second international student Ao kei"<<endl;
    tss.setReading(25);
    tss.setListening(27);
    tss.setSpeaking(29);
    tss.setWriting(29);
    tss.setTotal();
    iss = new InternationalStudent;
    iss->set("Ao","Kei","Korea",tss,3.4,89,20202425);
    insert(ilist, iss);
    print_link(ilist);
    cout<<endl<<"search Tao by CGPA and research score"<<endl;
	searchCGPA(ilist);
	searchName(ilist );
	cout<<endl<<"remove student Ke Yi"<<endl;
	deleteExistNode(ilist );
	print_link(ilist);
	cout<<endl<<endl;

    cout<<"******testing corner case******"<<endl;
	cout<<"search a student by name(first and last) and score(cpga and research) which is the onlt one in the list: "<<endl;
	searchCGPA(ilist);
	searchName(ilist);
	cout<<"delete the only student in the list"<<endl;
	deleteExistNode(ilist);
	print_link(ilist);
	cout<<endl<<endl<<endl;

    cout<<"******testing illegal case******"<<endl;
	cout<<"search for a non-exsitence student in the list:"<<endl;
	searchCGPA(ilist);
	searchName(ilist);
	//delete head and tail node
	remove_front_tail(ilist);
	print_link(ilist);
    cout<<endl<<endl<<endl;


	//now testing merging function
	cout<<"******Testing mergng function*******"<<endl;
	cout<<"first create 4 students(2 domestic and 2 international)"<<endl;
	cout<<"now create 2 link lists"<<endl<<endl;
	NodePtr dslist = NULL;
	D_StudentPtr dss = new DomesticStudent;
	dss->set("Guan","Yu",3.96,80,"BC",20203456);
	insert(dslist, dss);
	dss = new DomesticStudent;
	dss->set("Zhang","Fei",2.31,74, "QC",20201234);
	insert(dslist, dss);
	cout<<"print domestic student link list"<<endl;
	print_link(dslist);

	//2 international
	ToeflScore ts;
	NodePtr islist = NULL;
    ts.setReading(30);
    ts.setListening(30);
    ts.setSpeaking(30);
    ts.setWriting(30);
    ts.setTotal();
	I_StudentPtr is = new InternationalStudent;
	is->set("Liu","bei","China",ts,4.33,100,20202345);
	insert(islist, is);
    ts.setReading(26);
    ts.setListening(27);
    ts.setSpeaking(28);
    ts.setWriting(29);
    ts.setTotal();
    is = new InternationalStudent;
    is->set("Wu","Di","China",ts,2.12,79,20202445);
    insert(islist, is);
    cout<<endl<<"print internaitonal student link list"<<endl;
    print_link(islist);

    cout<<endl;
	NodePtr lis = NULL;
	lis = sortAll(dslist, islist);
	print_link(lis);
	cout<<endl;
	searchMerged(lis);

	return 0;
}
