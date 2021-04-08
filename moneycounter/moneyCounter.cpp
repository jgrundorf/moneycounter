//cash drawer and bill pay counter that saves information to an output file for my job

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;

class Counter
{
private:
	//variables
	ofstream drawer;
	float hun, fif, twe, ten, fiv, one, qua, dim, nic, pen;
	float total;
	float webPos;
	float ws;
	float refund;
	string today;

	//methods
	void openFile();
	void testFile();
	void userInputCash();
	void userInputBills();
	void userInputDate();
	void calcTotal();
	void writeFile();
	void closeFile();
	
	
public:
	void driver();
};

/**************************main*********************************/
int main()
{
	Counter cObj;		//instantiate an object of Counter

	cObj.driver();

	cout << "\n\n\n\n\n\n";
	return 0;
}

/*********************methods*************************/

//Counter: openFile
//open the file
void Counter::openFile()
{
	drawer.open("DrawerCount.txt");

	testFile();
}

//Counter: testFile
//test if the file opened properly
void Counter::testFile()
{
	if (!drawer)
	{
		std::cerr << "DrawerCount.txt did not open properly" << endl << endl;
		exit(1111);
	}
}

//Counter: userInput
//gather input from user
void Counter::userInputCash()
{

	//getting the input from the user, asking for the amounts of each bill
	cout << "100: ";
	cin >> hun;

	cout << "50: ";
	cin >> fif;

	cout << "20: ";
	cin >> twe;

	cout << "10: ";
	cin >> ten;

	cout << "5: ";
	cin >> fiv;

	cout << "1: ";
	cin >> one;

	cout << "25: ";
	cin >> qua;

	cout << "10: ";
	cin >> dim;

	cout << "5: ";
	cin >> nic;

	cout << "1: ";
	cin >> pen;

	userInputBills();
}

//Counter: userInputBills()
//getting the user input of the bill payment amounts
void Counter::userInputBills()
{
	cout << "WebPOS: ";
	cin >> webPos;
	cout << "Refunds: ";
	cin >> refund;
	cout << "WS Reports: ";
	cin >> ws;

	userInputDate();
}

//Counter: userInputDate
//get the current date from the user
void Counter::userInputDate()
{
	cout << "What is today's date? ";
	cin >> today;
}

//Counter: writeFile
//write the data into the output file
void Counter::writeFile()
{
	drawer << "Total in the drawer on " << today << " is $" << total << "."
		<< endl << "WebPOS final: " << webPos - refund << endl
		<< "WS Reports final: " << ws << endl << endl;
}

//Counter: calcTotal
//calculate the total money in the drawer
void Counter::calcTotal()
{
	//calculations for bills
	hun = hun * 100;
	fif = fif * 50;
	twe = twe * 20;
	ten = ten * 10;
	fiv = fiv * 5;

	//calculations for coins
	qua = qua * 0.25;
	dim = dim * 0.10;
	nic = nic * 0.05;
	pen = pen * 0.01;

	//calculation for total
	total = hun + fif + twe + ten
		+ fiv + one + qua
		+ dim + nic + pen;
}
//Counter: driver
//order of execution
void Counter::driver()
{
	openFile();
	userInputCash();
	calcTotal();
	writeFile();
}

