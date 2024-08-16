//student.cpp to implement your classes
#include "student.hpp"

void Lab3(NodePtr& d_h, NodePtr& i_h, NodePtr& h)
{
	string kind;
	char Stop = 'n';
	while (Stop == 'n') {
		char choise;
		string choise1;
		char stop = 'n';
		char stop1 = 'n';
		cout << "Ungraduated Student Management System" << endl
			<< "1 Search Separately(search_s)\t\t2 Insert Student(insert)\t\t3 Delete Student(delete_stu)\n"
			<< "4 Delete Head and Tail(delete_h_t)\t5 Sort All Student(sort)\t\t6 Print Student(print)\n"
			<< "7 Search All(search_a)\t\t\t8 Exit(exit)" << endl
			<< "What do you want to do? ";
		cin >> kind;
		if (stringMatch(kind) == stringMatch("search_s")) {
			while (stop == 'n') {
				cout << "What kind of student do you want to search(d or i)? ";
				cin >> choise;
				if (choise == 'd') {
					while (stop1 == 'n') {
						cout << "What kind of searching(CGPA/research/ID/name)? ";
						cin >> choise1;
						if (stringMatch(choise1) == stringMatch("CGPA")) {
							searchCGPA(d_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("research")) {
							searchResearch(d_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("ID")) {
							searchID(d_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("name")) {
							searchName(d_h);
							cout << "\n\n";
						}
						else {
							cout << "Input illegal, please input again." << endl;
							continue;
						}
						cout << "Do uou want to stop searching Domestic Student(n/y)? ";
						cin >> stop1;
					}
					cout << "Do uou want to stop searching(n/y)? ";
					cin >> stop;
				}
				else if (choise == 'i') {
					while (stop1 == 'n') {
						cout << "What kind of searching(CGPA/research/ID/name)? ";
						cin >> choise1;
						if (stringMatch(choise1) == stringMatch("CGPA")) {
							searchCGPA(i_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("research")) {
							searchResearch(i_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("ID")) {
							searchID(i_h);
							cout << "\n\n";
						}
						else if (stringMatch(choise1) == stringMatch("name")) {
							searchName(i_h);
							cout << "\n\n";
						}
						else {
							cout << "Input illegal, please input again." << endl;
							continue;
						}
						cout << "Do uou want to stop searching International Student(n/y)? ";
						cin >> stop1;
					}
					cout << "Do uou want to stop searching(n/y)? ";
					cin >> stop;
				}
			}
		}
		else if (stringMatch(kind) == stringMatch("insert")) {
			while (stop == 'n') {
				cout << "What kind of student do you want to insert(d or i)? ";
				cin >> choise;
				if (choise == 'd') {
					insertDomestic(d_h);
					cout << "\n\n";
				}
				else if (choise == 'i') {
					insertInternationl(i_h);
					cout << "\n\n";
				}
				else {
					cout << "Input illegal, please input again." << endl;
					continue;
				}
				cout << "Do uou want to stop insert(n/y)? ";
				cin >> stop;
			}
		}
		else if (stringMatch(kind) == stringMatch("delete_stu")) {
			while (stop == 'n') {
				cout << "What kind of student do you want to delete(d or i)? ";
				cin >> choise;
				if (choise == 'd') {
					deleteExistNode(d_h);
					cout << "\n\n";
				}
				else if (choise == 'i') {
					deleteExistNode(i_h);
					cout << "\n\n";
				}
				else {
					cout << "Input illegal, please input again." << endl;
					continue;
				}
				cout << "Do uou want to stop delete(n/y)? ";
				cin >> stop;
			}
		}
		else if (stringMatch(kind) == stringMatch("delete_h_t")) {
			while (stop == 'n') {
				cout << "What kind of student do you want to delete head and tail(d or i)? ";
				cin >> choise;
				if (choise == 'd') {
					remove_front_tail(d_h);
					cout << "\n\n";
				}
				else if (choise == 'i') {
					remove_front_tail(i_h);
					cout << "\n\n";
				}
				else {
					cout << "Input illegal, please input again." << endl;
					continue;
				}
				cout << "Do uou want to stop delete(n/y)? ";
				cin >> stop;
			}
		}
		else if (stringMatch(kind) == stringMatch("sort")) {
			h = sortAll(d_h, i_h);
			cout << "\n\n";
		}
		else if (stringMatch(kind) == stringMatch("search_a")) {
			searchMerged(h);
			cout << "\n\n";
		}
		else if (stringMatch(kind) == stringMatch("print")) {
			while (stop == 'n') {
				cout << "What kind of student do you want to print(d or i or a)? ";
				cin >> choise;
				if (choise == 'd') {
					print_link(d_h);
					cout << "\n\n\n";
				}
				else if (choise == 'i') {
					print_link(i_h);
					cout << "\n\n\n";
				}
				else if (choise == 'a') {
					print_link(h);
					cout << "\n\n\n";
				}
				else {
					cout << "Input illegal, please input again." << endl;
					continue;
				}
				cout << "Do uou want to stop print(n/y)? ";
				cin >> stop;
			}
		}
		else if (stringMatch(kind) == stringMatch("exit")) {
			return;
		}
		else {
			cout << "Input illegal, please input again." << endl;
			continue;
		}
		cout << "Do uou want to stop processing(n/y)? ";
		cin >> Stop;
	}
}

DomesticStudent::DomesticStudent():Student()
{
	first_name = '\0';
	last_name = '\0';
	province = '\0';
	setCGPA(0);
	setResearch(0);
	setApplication(0);
}

DomesticStudent::DomesticStudent(const string &first, const string &last, const float &C,
	const int &research, const string &prov, const int &application)
{
	setFirst(first);
	setLast(last);
	setCGPA(C);
	setProvince(prov);
	setResearch(research);
	setApplication(application);
}
DomesticStudent::DomesticStudent(const DomesticStudent& s)
{
	setFirst(s.getFirst());
	setLast(s.getLast());
	setCGPA(s.getCGPA());
	setProvince(s.getProvince());
	setResearch(s.getResearch());
	setApplication(s.getApplication());
}
string DomesticStudent::getFirst() const
{
	return first_name;
}
string DomesticStudent::getLast() const
{
	return last_name;
}
string DomesticStudent::getProvince() const
{
	return province;
}
string DomesticStudent::getCountry() const
{
	string coun;
	coun = '\0';
	return coun;
}
ToeflScore DomesticStudent::getToefl() const
{
	ToeflScore t;
	t.setListening(0);
	t.setSpeaking(0);
	t.setWriting(0);
	t.setReading(0);
	return t;
}
float DomesticStudent::getCGPA() const
{
	return CGPA;
}
int DomesticStudent::getResearch() const
{
	return research_score;
}
int DomesticStudent::getApplication() const
{
	return application_id;
}
void DomesticStudent::set(const string& first, const string& last, const float& C, 
	const int& research, const string& prov, const int& application)
{
	setFirst(first);
	setLast(last);
	setCGPA(C);
	setResearch(research);
	setProvince(prov);
	setApplication(application);
}
void DomesticStudent::setFirst(const string &first)
{
	first_name = first;
}
void DomesticStudent::setLast(const string &last)
{
	last_name = last;
}
void DomesticStudent::setProvince(const string &prov)
{
	province = prov;
}
void DomesticStudent::setCGPA(const float &C)
{
	if (C > 4.33 || C < 0)
		cout << "illigal value for cgpa score.\n";
	CGPA = C;
}
void DomesticStudent::setResearch(const int &research)
{
	if (research > 100 || research < 0)
		cout << "illigal value for research score.\n";
	research_score = research;

}
void DomesticStudent::setApplication(const int &application)
{
	application_id = application;
}
void DomesticStudent::print() const
{
	if (getApplication() == 0 || getFirst() == "\0" || getLast() == "\0" ||
		getProvince() == "\0" || getCGPA() == 0 || getResearch() == 0)
	{
		cout << "One field is missing" << endl;
		pthread_exit(0);
	}
	else
		cout << " " << "The Domestic Student " << getApplication() << " "
			<< getFirst() << " " << getLast() << " comes from " << getProvince() << " has cgpa of "
			<< getCGPA() << ", and research score of " << getResearch() << "." << endl;
}
DomesticStudent& DomesticStudent::operator = (const DomesticStudent& s)
{
	this->setCGPA(s.getCGPA());
	this->setFirst(s.getFirst());
	this->setLast(s.getLast());
	this->setResearch(s.getResearch());
	this->setApplication(s.getApplication());
	this->setProvince(s.getProvince());
	return *this;
}
ostream& operator << (ostream& outputStream, const DomesticStudent& s)
{
	outputStream << " " << "The Domestic Student " << s.getApplication() << " "
		<< s.getFirst() << " " << s.getLast() << " comes from " << s.getProvince() << " has cgpa of "
		<< s.getCGPA() << ", and research score of " << s.getResearch() << "." << endl;
	return outputStream;
}

InternationalStudent::InternationalStudent()
{
	first_name = '\0';
	last_name = '\0';
	setCGPA(0);
	setResearch(0);
	setApplication(0);
	country = '\0';
	toeflscore.setReading(0);
	toeflscore.setSpeaking(0);
	toeflscore.setListening(0);
	toeflscore.setWriting(0);
}
InternationalStudent::InternationalStudent(const string &first, const string &last, const string &coun,
	const ToeflScore& toefl, const float &C, const int &research, const int &application)
{
	setFirst(first);
	setLast(last);
	setCGPA(C);
	setResearch(research);
	setApplication(application);
	setCountry(coun);
	toeflscore.setReading(toefl.getReading());
	toeflscore.setSpeaking(toefl.getSpeaking());
	toeflscore.setListening(toefl.getListening());
	toeflscore.setWriting(toefl.getWriting());
}
InternationalStudent::InternationalStudent(const InternationalStudent& s) :Student(s)
{
	setFirst(s.getFirst());
	setLast(s.getLast());
	setCGPA(s.getCGPA());
	setResearch(s.getResearch());
	setApplication(s.getApplication());
	setCountry(s.getCountry());
	toeflscore.setReading(s.toeflscore.getReading());
	toeflscore.setSpeaking(s.toeflscore.getSpeaking());
	toeflscore.setListening(s.toeflscore.getListening());
	toeflscore.setWriting(s.toeflscore.getWriting());
}
string InternationalStudent::getFirst() const
{
	return first_name;
}
string InternationalStudent::getLast() const
{
	return last_name;
}
string InternationalStudent::getProvince() const
{
	string prov;
	prov = '\0';
	return prov;
}
string InternationalStudent::getCountry() const
{
	return country;
}
ToeflScore InternationalStudent::getToefl() const
{
	return toeflscore;
}
float InternationalStudent::getCGPA() const
{
	return CGPA;
}
int InternationalStudent::getResearch() const
{
	return research_score;
}
int InternationalStudent::getApplication() const
{
	return application_id;
}
void InternationalStudent::setFirst(const string& first)
{
	first_name = first;
}
void InternationalStudent::setLast(const string& last)
{
	last_name = last;
}
void InternationalStudent::setCountry(const string& coun)
{
	country = coun;
}
void InternationalStudent::setToefl(const ToeflScore& toefl)
{
	toeflscore = toefl;
}
void InternationalStudent::set(const string& first, const string& last, const string& coun,
	const ToeflScore& toefl, const float& C, const int& research, const int& application)
{
	setFirst(first);
	setLast(last);
	setCGPA(C);
	setResearch(research);
	setCountry(coun);
	setToefl(toefl);
	setApplication(application);
}
void InternationalStudent::setCGPA(const float& C)
{
	if (C > 4.33 || C < 0)
		cout << "illigal value for cgpa score.\n";
	CGPA = C;
}
void InternationalStudent::setResearch(const int& research)
{
	if (research > 100 || research < 0)
		cout << "illigal value for research score.\n";
	research_score = research;

}
void InternationalStudent::setApplication(const int& application)
{
	application_id = application;
}
void InternationalStudent::print() const
{
	if (getApplication() == 0 || getFirst() == "\0" || getLast() == "\0" ||
		getCountry() == "\0" || getCGPA() == 0 || getResearch() == 0 ||
		getToefl().getReading() == 0 || getToefl().getSpeaking() == 0 || getToefl().getListening() == 0 || getToefl().getWriting() == 0)
	{
		cout << "One field is missing" << endl;
		pthread_exit(0);
	}
	else
		cout<< " " << "The International Student " << getApplication() << " "
			<< getFirst() << " " << getLast() << " comes from " << getCountry() << " has cgpa of "
			<< getCGPA() << ", and research score of " << getResearch() << ", Toeflscore of total "
			<< getToefl().getTotal() << ", " << getToefl().getReading() << " in reading, " << getToefl().getListening()
			<< " in listening, " << getToefl().getSpeaking() << " in speaking, " << getToefl().getWriting() << " in writing. " << endl;
}
ostream& operator << (ostream& outputStream, const InternationalStudent& s)
{
	outputStream << " " << "The International Student " << s.getApplication() << " "
		<< s.getFirst() << " " << s.getLast() << " comes from " << s.getCountry() << " has cgpa of "
		<< s.getCGPA() << ", and research score of " << s.getResearch() << ", Toeflscore of total "
		<< s.getToefl().getTotal() << ", " << s.getToefl().getReading() << " in reading, " << s.getToefl().getListening()
		<< " in listening, " << s.getToefl().getSpeaking() << " in speaking, " << s.getToefl().getWriting() << " in writing. " << endl;
	return outputStream;
}
InternationalStudent& InternationalStudent::operator = (const InternationalStudent& s)
{
	this->setCGPA(s.getCGPA());
	this->setFirst(s.getFirst());
	this->setLast(s.getLast());
	this->setResearch(s.getResearch());
	this->setApplication(s.getApplication());
	this->setCountry(s.getCountry());
	this->setToefl(s.getToefl());
	return *this;
}

ToeflScore::ToeflScore()
{
	setReading(0);
	setListening(0);
	setSpeaking(0);
	setWriting(0);
	setTotal();
}
ToeflScore::ToeflScore(const int &read, const int &listen, const int &speak, const int &write)
{
	setReading(read);
	setListening(listen);
	setSpeaking(speak);
	setWriting(write);
	setTotal();
}
int ToeflScore::getReading() const
{
	return reading;
}
int ToeflScore::getListening() const
{
	return listening;
}
int ToeflScore::getSpeaking() const
{
	return speaking;
}
int ToeflScore::getWriting() const
{
	return writing;
}
int ToeflScore::getTotal() const
{
	return total_score;
}
void ToeflScore::set(const int& read, const int& listen, const int& speak, const int& write)
{
	setReading(read);
	setListening(listen);
	setSpeaking(speak);
	setWriting(write);
}
void ToeflScore::setReading(const int& read)
{
	if (read > 30 || read < 0)
		cout << "illigal value for toefl score.\n";
	reading = read;
}
void ToeflScore::setListening(const int& listen)
{
	if (listen > 30 || listen < 0)
		cout << "illigal value for toefl score.\n";
	listening = listen;
}
void ToeflScore::setSpeaking(const int& speak)
{	
	if (speak > 30 || speak < 0)
		cout << "illigal value for toefl score.\n";
	speaking = speak;
}
void ToeflScore::setWriting(const int& write)
{
	if (write > 30 || write < 0)
		cout << "illigal value for toefl score.\n";
	writing = write;
}
void ToeflScore::setTotal()
{
	total_score = reading + listening + speaking + writing;
}
ToeflScore& ToeflScore::operator = (const ToeflScore& f)
{
	this->setReading(f.getReading());
	this->setListening(f.getListening());
	this->setSpeaking(f.getSpeaking());
	this->setWriting(f.getWriting());
	this->setTotal();
	return *this;
}

Node::Node()
{
	this->sPtr = NULL;
	this->link = NULL;
}
Node::Node(StudentPtr sPtr, Node* link)
{
	this->sPtr = sPtr;
	this->link = link;
}
Node::~Node()
{
	if (this->sPtr != NULL)
	{
		delete this->sPtr;
		this->sPtr = NULL;
	}
}
StudentPtr Node::getStudentPtr() const
{
	return this->sPtr;
}
Node* Node::getLink() const
{
	return this->link;
}
void Node::setStudentPtr(StudentPtr sPtr)
{
	this->sPtr = sPtr;
}
void Node::setLink(Node* link)
{
	this->link = link;
}

int compareCGPA(const Student* a, const Student* b)
{
	if (a->getCGPA() > b->getCGPA())
		return 1;
	else if (a->getCGPA() == b->getCGPA())
		return 2;
	else
		return 3;
}
int compareResearchScore(const Student* a, const Student* b)
{
	if (a->getResearch() > b->getResearch())
		return 1;
	else if (a->getResearch() == b->getResearch())
		return 2;
	else
		return 3;
}
int compareFirstName(const Student* a, const Student* b)
{
	if (stringMatch(a->getFirst()) > stringMatch(b->getFirst()))
		return 1;
	else if (stringMatch(a->getFirst()) == stringMatch(b->getFirst()))
		return 2;
	else
		return 3;
}
int compareLastName(const Student* a, const Student* b)
{
	if (stringMatch(a->getLast()) > stringMatch(b->getLast()))
		return 1;
	else if (stringMatch(a->getLast()) == stringMatch(b->getLast()))
		return 2;
	else
		return 3;
}
int compareProvince(const Student* a, const Student* b)
{
	if (stringMatch(a->getProvince()) > stringMatch(b->getProvince()))
		return 1;
	else if (stringMatch(a->getProvince()) == stringMatch(b->getProvince()))
		return 2;
	else
		return 3;
}
int compareCountry(const Student* a, const Student* b)
{
	if (stringMatch(a->getCountry()) > stringMatch(b->getCountry()))
		return 1;
	else if (stringMatch(a->getCountry()) == stringMatch(b->getCountry()))
		return 2;
	else
		return 3;
}

int compareCGPA(const Student& a, const Student& b)
{
	if (a.getCGPA() > b.getCGPA())
		return 1;
	else if (a.getCGPA() == b.getCGPA())
		return 2;
	else
		return 3;
}
int compareResearchScore(const Student& a, const Student& b)
{
	if (a.getResearch() > b.getResearch())
		return 1;
	else if (a.getResearch() == b.getResearch())
		return 2;
	else
		return 3;
}
int compareFirstName(const Student& a, const Student& b)
{
	if (stringMatch(a.getFirst()) > stringMatch(b.getFirst()))
		return 1;
	else if (stringMatch(a.getFirst()) == stringMatch(b.getFirst()))
		return 2;
	else
		return 3;
}
int compareLastName(const Student& a, const Student& b)
{
	if (stringMatch(a.getLast()) > stringMatch(b.getLast()))
		return 1;
	else if (stringMatch(a.getLast()) == stringMatch(b.getLast()))
		return 2;
	else
		return 3;
}

int compareProvince(const Student& a, const Student& b)
{
	if (stringMatch(a.getProvince()) > stringMatch(b.getProvince()))
		return 1;
	else if (stringMatch(a.getProvince()) == stringMatch(b.getProvince()))
		return 2;
	else
		return 3;
}

int compareCountry(const Student& a, const Student& b)
{
	if (stringMatch(a.getCountry()) > stringMatch(b.getCountry()))
		return 1;
	else if (stringMatch(a.getCountry()) == stringMatch(b.getCountry()))
		return 2;
	else
		return 3;
}

//Lab 3
//Part 1
void Head_insert(NodePtr& h, StudentPtr s)
{
	NodePtr node = new Node();
	node->setStudentPtr(s);
	node->setLink(h);
	h = node;
}
void Insert_after(NodePtr& n, StudentPtr s)
{
	NodePtr node = new Node();
	node->setStudentPtr(s);
	node->setLink(n->getLink());
	n->setLink(node);
}
void Tail_insert(NodePtr& h, StudentPtr s)
{
	if (h == NULL)
	{
		cout << "Empty Linked List. Nothing to print." << endl;
		return;
	}
	else
	{
		NodePtr temp = h;
		while (temp->getLink() != NULL)
			temp = temp->getLink();
		NodePtr node = new Node();
		node->setStudentPtr(s);
		node->setLink(NULL);
		temp->setLink(node);
	}
}
void Insert_before(NodePtr& h, NodePtr& n, StudentPtr s)
{
	if (n == h)
		Head_insert(h, s);
	else {
		NodePtr temp = h;
		while (temp->getLink() != n)
			temp = temp->getLink();
		NodePtr node = new Node();
		node->setStudentPtr(s);
		node->setLink(n);
		temp->setLink(node);
	}
}
void insert(NodePtr& h, D_StudentPtr s)
{
	if (checkProvince(s->getProvince()) == false) {
		cout << "It¡¯s not a valid province " << endl;
		pthread_exit(0);
	}
	else {
		if (h == NULL)
			Head_insert(h, s);
		else {
			NodePtr temp = h;
			while (temp != NULL)
			{
				if (compareResearchScore(temp->getStudentPtr(), s) == 3) {
					Insert_before(h, temp, s);
					break;
				}
				else if (compareResearchScore(temp->getStudentPtr(), s) == 2) {
					if (compareCGPA(temp->getStudentPtr(), s) == 3) {
						Insert_before(h, temp, s);
						break;
					}
					else if (compareCGPA(temp->getStudentPtr(), s) == 2) {
						if (compareProvince(temp->getStudentPtr(), s) != 3) {
							Insert_before(h, temp, s);
							break;
						}
						else
							temp = temp->getLink();
					}
					else
						temp = temp->getLink();
				}
				else
					temp = temp->getLink();
			}
			if (temp == NULL)
				Tail_insert(h, s);
		}
	}
}
void insert(NodePtr& h, I_StudentPtr s)
{
	checkCountry(s);
	if ((s->getToefl().getTotal() >= 93)
		&& (s->getToefl().getReading() >= 20) && (s->getToefl().getListening() >= 20)
		&& (s->getToefl().getSpeaking() >= 20) && (s->getToefl().getWriting() >= 20)) {
		if (h == NULL)
			Head_insert(h, s);
		else {
			NodePtr temp = h;
			while (temp != NULL)
			{
				if (compareResearchScore(temp->getStudentPtr(), s) == 3) {
					Insert_before(h, temp, s);
					break;
				}
				else if (compareResearchScore(temp->getStudentPtr(), s) == 2) {
					if (compareCGPA(temp->getStudentPtr(), s) == 3) {
						Insert_before(h, temp, s);
						break;
					}
					else if (compareCGPA(temp->getStudentPtr(), s) == 2) {
						if (compareCountry(temp->getStudentPtr(), s) != 3) {
							Insert_before(h, temp, s);
							break;
						}
						else
							temp = temp->getLink();
					}
					else
						temp = temp->getLink();
				}
				else
					temp = temp->getLink();
			}
			if (temp == NULL)
				Tail_insert(h, s);
		}
	}
	else
		return;
}

//Part 2
void searchID(NodePtr& h)
{
	int application;
	for (int i = 0;; i++) {
		cout << "Input ID you want to search: ";
		cin >> application;
		if (cin.good() == true) {
			if (application < 10000000 || application > 30000000) {
				cout << "Illegal ID, please input again." << endl;
			}
			else
				break;
		}
		else {
			cout << "Wrong Input." << endl;
			pthread_exit(0);
		}
	}
	NodePtr temp = h;
	while (temp != NULL) {
		if (temp->getStudentPtr()->getApplication() == application) {
			temp->getStudentPtr()->print();
			temp = temp->getLink();
		}
		else
			temp = temp->getLink();
	}
	if (temp == NULL)
		cout << "No thing else to print." << endl;
}
void searchCGPA(NodePtr& h)
{
	float C;
	for (int i = 0; i < 10; i++) {
		cout << "Input CGPA you want to search: ";
		cin >> C;
		if (cin.good() == true) {
			if (C < 0 || C > 4.33) {
				cout << "Illegal CGPA, please input again." << endl;
			}
			else
				break;
		}
		else {
			cout << "Wrong Input." << endl;
			pthread_exit(0);
		}
	}
	NodePtr temp = h;
	while (temp != NULL) {
		if (temp->getStudentPtr()->getCGPA() == C) {
			temp->getStudentPtr()->print();
			temp = temp->getLink();
		}
		else
			temp = temp->getLink();
	}
	if (temp == NULL)
		cout << "No thing else to print." << endl;
}
void searchResearch(NodePtr& h)
{
	int research;
	for (int i = 0;; i++) {
		cout << "Input research score you want to search: ";
		cin >> research;
		if (cin.good() == true) {
			if (research < 0 || research > 100) {
				cout << "Illegal research score, please input again." << endl;
			}
			else
				break;
		}
		else {
			cout << "Wrong Input." << endl;
			pthread_exit(0);
		}
	}
	NodePtr temp = h;
	while (temp != NULL) {
		if (temp->getStudentPtr()->getResearch() == research) {
			temp->getStudentPtr()->print();
			temp = temp->getLink();
		}
		else
			temp = temp->getLink();
	}
	if (temp == NULL)
		cout << "No thing else to print." << endl;
}
void searchName(NodePtr& h)
{
	string first, last;
	cout << "Input name you want to search: ";
	cin >> first >> last;
	NodePtr temp = h;
	while (temp != NULL) {
		if (stringMatch(temp->getStudentPtr()->getFirst()) == stringMatch(first)
			&& stringMatch(temp->getStudentPtr()->getLast()) == stringMatch(last)) {
			temp->getStudentPtr()->print();
			temp = temp->getLink();
		}
		else
			temp = temp->getLink();
	}
	if (temp == NULL)
		cout << "No thing else to print." << endl;
}

void insertDomestic(NodePtr& h)
{
	string first, last, prov;
	int research, application;
	float C;
	cout << "Input name, province, research score, CGPA, and ID: ";
	cin >> first >> last >> prov >> research >> C >> application;
	for (int i = 0;; i++) {
		if (application < 10000000 || application > 30000000) {
			cout << "Illegal ID, please input again:" << endl;
			cin >> application;
		}
		else if (research < 0 || research > 100) {
			cout << "Illegal research score, please input again:" << endl;
			cin >> research;
		}
		else if (C < 0 || C > 4.33) {
			cout << "Illegal CGPA, please input again." << endl;
			cin >> C;
		}
		else
			break;
	}
	if (checkProvince(prov) == false) {
		cout << "It¡¯s not a valid province " << endl;
		pthread_exit(0);
	}
	D_StudentPtr s = new DomesticStudent();
	s->set(first, last, C, research, prov, application);
	if (h == NULL)
		Head_insert(h, s);
	else {
		NodePtr temp = h;
		while (temp != NULL)
		{
			if (compareResearchScore(temp->getStudentPtr(), s) == 3) {
				Insert_before(h, temp, s);
				break;
			}
			else if (compareResearchScore(temp->getStudentPtr(), s) == 2) {
				if (compareCGPA(temp->getStudentPtr(), s) != 1) {
					Insert_before(h, temp, s);
					break;
				}
				else
					temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		if (temp == NULL)
			Tail_insert(h, s);
	}
}
void insertInternationl(NodePtr& h)
{
	string first, last, coun;
	int read, listen, speak, write, research, application;
	float C;
	cout << "Input name, country, Toefl score(reading, listening, speaking, writing), research score, CGPA, and ID: ";
	cin >> first >> last >> coun >> read >> listen >> speak >> write >> research >> C >> application;
	for (int i = 0;; i++) {
		if (application < 10000000 || application > 30000000) {
			cout << "Illegal ID, please input again:" << endl;
			cin >> application;
		}
		else if (research < 0 || research > 100) {
			cout << "Illegal research score, please input again:" << endl;
			cin >> research;
		}
		else if (C < 0 || C > 4.33) {
			cout << "Illegal CGPA, please input again." << endl;
			cin >> C;
		}
		else if (read < 0 || read > 30) {
			cout << "Illegal read score, please input again." << endl;
			cin >> read;
		}
		else if (listen < 0 || listen > 30) {
			cout << "Illegal listen score, please input again." << endl;
			cin >> listen;
		}
		else if (speak < 0 || speak > 30) {
			cout << "Illegal speak score, please input again." << endl;
			cin >> speak;
		}
		else if (write < 0 || write > 30) {
			cout << "Illegal write score, please input again." << endl;
			cin >> write;
		}
		else
			break;
	}
	ToeflScore toefl;
	toefl.set(read, listen, speak, write);
	I_StudentPtr s = new InternationalStudent();
	s->set(first, last, coun, toefl, C, research, application);
	checkCountry(s);
	if ((s->getToefl().getTotal() >= 93)
		&& (s->getToefl().getReading() >= 20) && (s->getToefl().getListening() >= 20)
		&& (s->getToefl().getSpeaking() >= 20) && (s->getToefl().getWriting() >= 20)) {
		if (h == NULL)
			Head_insert(h, s);
		else {
			NodePtr temp = h;
			while (temp != NULL)
			{
				if (compareResearchScore(temp->getStudentPtr(), s) == 3) {
					Insert_before(h, temp, s);
					break;
				}
				else if (compareResearchScore(temp->getStudentPtr(), s) == 2) {
					if (compareCGPA(temp->getStudentPtr(), s) != 1) {
						Insert_before(h, temp, s);
						break;
					}
					else
						temp = temp->getLink();
				}
				else
					temp = temp->getLink();
			}
			if (temp == NULL)
				Tail_insert(h, s);
		}
	}
	else
		return;
}

void deleteExistNode(NodePtr& h)
{
	string first, last;
	cout << "Input name you want to delete: ";
	cin >> first >> last;
	if (stringMatch(h->getStudentPtr()->getFirst()) == stringMatch(first) 
		&& stringMatch(h->getStudentPtr()->getLast()) == stringMatch(last)) {
		NodePtr n1 = h;
		h = h->getLink();
		delete n1;
		cout << "Delete student " << first << " " << last << endl;
	}
	else {
		NodePtr temp = h;
		while (temp != NULL) {
			if (stringMatch(temp->getStudentPtr()->getFirst()) == stringMatch(first)
				&& stringMatch(temp->getStudentPtr()->getLast()) == stringMatch(last)) {
				NodePtr node = h;
				while (node->getLink() != temp)
					node = node->getLink();
				NodePtr n2 = temp->getLink();
				node->setLink(n2);
				cout << "Delete student " << first << " " << last << endl;
				temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		delete temp;
	}
}

void remove_front_tail(NodePtr& h)
{
	if (h == NULL)
	{
		cout << "Linked list empty" << endl;
	}
	else
	{
		NodePtr n1 = h;
		h = h->getLink();
		delete n1;
		cout << "The head node has been deleted." << endl;
		NodePtr n2 = h;
		while (n2->getLink()->getLink() != NULL)
			n2 = n2->getLink();
		NodePtr temp = n2->getLink();
		n2->setLink(NULL);
		delete temp;
		cout << "The tail node has been deleted." << endl;
	}
}

//Part 3
void Head_insert(NodePtr& h, NodePtr& n)
{
	NodePtr node = new Node;
	StudentPtr s = n->getStudentPtr();
	node->setStudentPtr(s);
	node->setLink(h);
	h = node;
}
void Tail_insert(NodePtr& h, NodePtr& n)
{
	if (h == NULL)
		Head_insert(h, n);
	else
	{
		NodePtr node = new Node;
		NodePtr temp = h;
		while (temp->getLink() != NULL)
			temp = temp->getLink();
		node->setStudentPtr(n->getStudentPtr());
		node->setLink(NULL);
		temp->setLink(node);
	}
}
void Insert_after(NodePtr& n1, NodePtr& n2)
{
	NodePtr node = new Node;
	StudentPtr s = n2->getStudentPtr();
	node->setStudentPtr(s);
	node->setLink(n1->getLink());
	n1->setLink(node);
}
void Insert_before(NodePtr& h, NodePtr& n1, NodePtr& n2)
{
	if (n1 == h)
		Head_insert(h, n2);
	else {
		NodePtr temp = h;
		while (temp->getLink() != n1)
			temp = temp->getLink();
		NodePtr node = new Node;
		StudentPtr s = n2->getStudentPtr();
		node->setStudentPtr(s);
		node->setLink(n1);
		temp->setLink(node);
	}
}
NodePtr sortAll(NodePtr& h1, NodePtr& h2)
{
	NodePtr h = NULL;
	int total, read, listen, speak, write;
	cout << "Input the ToeflScore requirement: ";
	cin >> total >> read >> listen >> speak >> write;
	NodePtr n;
	NodePtr n1 = h1;
	NodePtr n2 = h2;
	while (n1 != NULL) {
		Tail_insert(h, n1);
		n1 = n1->getLink();
	}
	while (n2 != NULL){
		n = h;
		if (n2->getStudentPtr()->getToefl().getTotal() >= total &&
			n2->getStudentPtr()->getToefl().getReading() >= read &&
			n2->getStudentPtr()->getToefl().getListening() >= listen &&
			n2->getStudentPtr()->getToefl().getSpeaking() >= speak &&
			n2->getStudentPtr()->getToefl().getWriting() >= write) {
			while (n != NULL) {
				if (n->getStudentPtr()->getResearch() < n2->getStudentPtr()->getResearch()) {
					Insert_before(h, n, n2);
					break;
				}
				else if (n->getStudentPtr()->getResearch() == n2->getStudentPtr()->getResearch()) {
					if (n->getStudentPtr()->getCGPA() < n2->getStudentPtr()->getCGPA()) {
						Insert_before(h, n, n2);
						break;
					}
					else
						n = n->getLink();
				}
				else
					n = n->getLink();
			}
			if (n == NULL)
				Tail_insert(h, n2);
			n2 = n2->getLink();
		}
		else {
			n2 = n2->getLink();
		}
	}
	return h;
}

void searchMerged(NodePtr& h)
{
	float cgpa_threshold;
	int researchScore_threshold;
	cout << "Input the CGPA and research score they should be: ";
	cin >> cgpa_threshold >> researchScore_threshold;
	NodePtr temp = h;
	while (temp != NULL) {
		if (temp->getStudentPtr()->getCGPA() >= cgpa_threshold
			&& temp->getStudentPtr()->getResearch() >= researchScore_threshold) {
			temp->getStudentPtr()->print();
			temp = temp->getLink();
		}
		else
			temp = temp->getLink();
	}
	cout << "Nothing else to print." << endl << endl;
}

void print_link(NodePtr& h)
{
	if (h == NULL)
	{
		cout << "Empty Linked List. Nothing to print." << endl;
		return;
	}
	NodePtr temp = h;
	while (temp != NULL)
	{
		temp->getStudentPtr()->print();
		temp = temp->getLink();
	}
}

//Lab4

string stringMatch(const string& name)
{
	string n = name;
	for (int i = 0; n[i] != '\0'; i++) {
		if (n[i] >= 'a')
			n[i] -= 32;
	}
	return n;
}
bool checkProvince(const string& prov)
{
	vector<string> Province;
	Province.push_back("NL");
	Province.push_back("PE");
	Province.push_back("NS");
	Province.push_back("NB");
	Province.push_back("QC");
	Province.push_back("ON");
	Province.push_back("MB");
	Province.push_back("SK");
	Province.push_back("AB");
	Province.push_back("BC");
	Province.push_back("NT");
	Province.push_back("YT");
	Province.push_back("NU");
	for (int i = 0; i < Province.size(); i++) {
		if (prov == Province[i])
			return true;
	}
	return false;
}
void checkCountry(I_StudentPtr s)
{
	vector<string> Country;
	Country.push_back("Canada");
	Country.push_back("China");
	Country.push_back("India");
	Country.push_back("Iran");
	Country.push_back("Korea");
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < Country.size()) {
		if (s->getCountry().size() == Country[i].size()) {
			j = 0;
			while (j < Country[i].size()) {
				k = 0;
				while (k < s->getCountry().size()) {
					if (stringMatch(s->getCountry())[k] == stringMatch(Country[i])[j]) {
						j++;
						break;
					}
					else
						k++;
				}
				if (k == s->getCountry().size()) {
					break;
				}
			}
			if (j == Country[i].size() && k < s->getCountry().size()) {
				s->setCountry(Country[i]);
				break;
			}
			else
				i++;
		}
		else
			i++;
	}
	if (i == Country.size()) {
		cout << "It¡¯s not a valid country " << endl;
		pthread_exit(0);
	}
}