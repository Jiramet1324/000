#include <iostream>
#include <fstream>
using namespace std;
void login();
void ONA();
void DM();
void WM();
void SA();

//-----------------------------

class LoginManager
{
public:

	LoginManager()
	{
		accessGranted = 0;
	}
	void login()
	{
		char PassAttempt[6];
		cout << "\n\n\n\t  BANK";
		cout << "\n\n\t  SYSTEM";
		cout << "\n\n\n\nUser ";
		cout << "\n\n\n\nUser ID :";
		cin >> UserAttempt;

		User = getFile("User.dat");
		if (UserAttempt == User)
		{
			cout << "Password :";
			cin >> PassAttempt;

			Pass = getFile("Pass.dat");

			if (PassAttempt == Pass)
			{
				cout << "Hey, that's right.";
				cin.get();
			}
			else
			{
				cout << "Not even close." << endl;
				login();
			}
		}
		else
		{
			cout << "Nice try, bud." << endl;
			login();
		}
	}
	string getFile(const char* p_fileName)
	{
		string line;
		fstream file;

		int eChar;

		file.open(p_fileName, ios::in);

		while (1)
		{
			file >> eChar;
			if (eChar == 0)
			{
				file.close();
				return line;
			}
			line += (char)decrypt(eChar);
		}
	}
	void saveFile(string p_line, const char* p_fileName)
	{
		fstream file;
		file.open(p_fileName, ios::out);

		for (int i = 0; i < p_line.length(); i++)
		{
			file << encrypt(p_line[i]);
			file << "\n";
		}

		file << "0";
		file.close();
	}

	int encrypt(int p_letter)
	{
		return p_letter + 3;
	}
	int decrypt(int p_letter)
	{
		return p_letter - 3;
	}

	private:
		string Pass;
		string User;
		string UserAttempt;
		string PassAttempt;
		bool accessGranted;
	};


int main() {
	char ch;
	int num;
	login();
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU" << endl;
		cout << "\n\n\t01. Open a new account" << endl;
		cout << "\n\n\t02. Deposit money" << endl;
		cout << "\n\n\t03. Withdraw money" << endl;
		cout << "\n\n\t04. Show another" << endl;
		cout << "\n\n\t05. EXIT << endl";
		cout << "\n\n\tSelect Your Option (1-5) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			ONA();
			break;
		case '2':
			DM();
			break;
		case '3':
			WM();
			break;
		case '4':
			SA();
			break;
		case '5':
			cout << "\n\n\tThanks for using bank ";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '5');
	return 0;
}

//Open_a_new_account
void ONA() {

}

//Deposit_money
void DM() {

}

//Withdraw_money
void WM() {

}

//Show_another
void SA() {

}
