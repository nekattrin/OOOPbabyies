//17. Создать класс PostalAddress(почтовый адрес), содержащий
//информацию о почтовом адресе.Предусмотреть возможность изменения
//составных частей адреса(города, улицы, дома, индекса и т.д.), создания и
//уничтожения объектов этого класса.В класс добавить необходимый набор
//полей и методов(минимум два поля и два метода) на свое усмотрение.

#include <iostream>
#include <string>
//#include <algorithm>
#include <cctype>


using namespace std;

bool containsOnlyLetters(string const& str) {
	for (char c : str) {
		if (!isalpha(c)) {
			return false;
		}
	}
	return true;
}

bool containsOnlyDigits(string const& str) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;

	/*int i = 0; int count = 0;
	while (str[i])
	{
		if (isdigit(str[i]) == false) { count++; return false; }
		i++;
	}
	if (count == 0)
	{
		return true;
	}*/
}

bool contains6symbols(string const& str) {
	return str.length() == 6;
}


class PostalAdress {
	string city;
	string street;
	string house;
	string index;

public:
	PostalAdress(string city = "cityX", string street = "streetX", string house = "1", string index = "111111");
	void setAdress(string, string, string, string);
	void printAdress();
	int changeAdress(int);
};


PostalAdress::PostalAdress(string city, string street, string house, string index) {
	setAdress(city, street, house, index);
}

void PostalAdress::setAdress(string city, string street, string house, string index) {

	this->city = city;
	this->street = street;
	this->house = house;
	this->index = index;
}

void PostalAdress::printAdress() {

	//  city[0] = toupper(city[0]);
	cout << "the adress is: " << city << " city, " << street << " street, " << house << " house, " << index << " index." << endl;
}

int PostalAdress::changeAdress(int answer) {
	string newData;
	cout << "enter new data:   ";
	cin >> newData;
	if (answer == 1) { this->city = newData; printAdress(); return 0; }
	if (answer == 2) { this->street = newData; printAdress(); return 0; }
	if (answer == 3) { this->house = newData; printAdress(); return 0; }
	if (answer == 4) { this->index = newData; printAdress(); return 0; }

}



int main()
{
	bool contin = true;
	string city1;
	string street1;
	string house1;
	string index1;
	string changeAnswer;
	int changeAnswer2;


	cout << " ender adress" << endl;
	cout << "city: ";
	cin >> city1;
	if (containsOnlyLetters(city1) != true)
		do {
			{
				cout << "CITY!!!     ";
				cin >> city1;
			}
		} while (containsOnlyLetters(city1) != true);

		cout << "street: ";
		cin >> street1;

		if (containsOnlyLetters(street1) != true)
			do {
				{
					cout << "STREET!!!     ";
					cin >> street1;
				}
			} while (containsOnlyLetters(street1) != true);


			cout << "house: ";
			cin >> house1;
			if (containsOnlyDigits(house1) != true)
				do {
					{
						cout << "HOUSE!!!     ";
						cin >> house1;
					}
				} while (containsOnlyDigits(house1) != true);

				cout << "index: ";
				cin >> index1;

				if (containsOnlyDigits(index1) != true || contains6symbols(index1) != true)
					do {
						{
							cout << "INDEX!!!     ";
							cin >> index1;
						}
					} while (containsOnlyDigits(index1) != true || contains6symbols(index1) != true);

					PostalAdress adress(city1, street1, house1, index1);
					adress.printAdress();


					cout << "Are you sure about this adress? (yes or no)" << endl;
					cin >> changeAnswer;
					if (changeAnswer == "no")
					{

						cout << "What do you want to change?\n 1-city\n 2-street\n 3-house\n 4-index\n";
						cin >> changeAnswer2;

						adress.changeAdress(changeAnswer2);

					}
					else
					{
						return 0;
					}


					return 0;

}