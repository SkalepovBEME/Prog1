#include <iostream>
using namespace std;                                     //RIMF - Representation in memory function
void RIMFInteger(int number){
	unsigned int mask = 1 << sizeof(int) * 8 - 1;
	for (int i = 1; i <= sizeof(int) * 8; i++){
		putchar(number & mask ? '1' : '0');
		mask >>= 1;
		if (i == 1 | i % 8 == 0)
			putchar(' ');
		if (i == sizeof(int) * 8)
			cout << "(int)\n\n";
	}
}  
void RIMFloat(int plugCloneFloat){
	unsigned int mask = 1 << sizeof(int) * 8 - 1;
	for (int i = 1; i <= sizeof(int) * 8; i++){
		putchar(plugCloneFloat & mask ? '1' : '0');
		mask >>= 1;
		if (i == 1 | i == 9)
			putchar(' ');
		if (i > 9 & i % 8 == 0)
			putchar(' ');
		if (i == sizeof(int) * 8)
			cout << "(float)\n\n";
	}
}
void RIMFDouble(int cloneDuo[2]){
	for (int i = 1; i >= 0; i--){
		int unsigned mask = 1 << sizeof(int) * 8 - 1;
		for (int j = 1; j <= sizeof(int) * 8; j++){
			putchar(cloneDuo[i] & mask ? '1' : '0');
			mask >>= 1;
			if ((i == 1 & j == 1) | (i == 1 & j == 12))
				putchar(' ');
		}
	}
	cout << " (double)\n\n";
}
int st = 2;
int main(){
	setlocale(0, "");
	int сhoice = 1;
	int integerNumber;
	unsigned int mask;
	int shift;
	while (сhoice != 0){
		cout << "1) Вывод количества пямяти для различных типов данных.\n" \
			<< "2) Вывод на экран двоичного представления в памяти типа int.\n" \
			<< "3) Вывод на экран двоичного представления в памяти типа float.\n" \
			<< "4) Вывод на экран двоичного представления в памяти типа double.\n" \
			<< "5) IDZ 12\n" \
			<< "0) Мне ничего из этого не нужно\n" \
			<< "Введите номер функции, которой вы хотите воспользоваться: ";
		cin >> сhoice;
		switch (сhoice){
		case(0):
			break;
		case(1):
			cout << "\nint - " << sizeof(int) << endl << "short int - " << sizeof(short int) << endl \
				<< "long int - " << sizeof(long int) << endl << "float - " << sizeof(float) << endl \
				<< "double - " << sizeof(double) << endl << "long double - " << sizeof(long double) << endl \
				<< "char - " << sizeof(char) << endl << "bool - " << sizeof(bool) << endl << endl;
			break;
		case(2):
			cout << "\nВведите целое число, представление в памяти которого вам нужно: ";
			cin >> integerNumber;
			RIMFInteger(integerNumber);
			break;
		case(3):
			cout << "\nВведите число, представление в памяти которого вам нужно: ";
			union {
				float floatNumber;
				int plugCloneFloat;
			};
			cin >> floatNumber;
			RIMFloat(plugCloneFloat);
			break;
		case(4):
			cout << "\nВведите число, представление в пямяти когорого вам нужно: ";
			union {
				double doubleNumber;
				int cloneDuo[2];
			};
			cin >> doubleNumber;
			RIMFDouble(cloneDuo);
			break;
		case(5):
			int secondChoice;
			cout << "\n1) int.\n" \
				<< "2) float.\n" \
				<< "3) double.\n" \
				<< "0) Я хочу выйти в первоначальное меню.\n"
				<< "Введите номер функции, которой вы хотите воспользоваться: ";
			cin >> secondChoice;
			switch (secondChoice){
			case(0):
				cout << endl;
				break;
			case(1):
				cout << "\nВведите целое число и количество сдвигов вправо: ";
				cin >> integerNumber >> shift;
				RIMFInteger(integerNumber);
				mask = 1 << shift - 1;
				integerNumber >>= shift;
				RIMFInteger(integerNumber);
				break;
			case(2):
				cout << "\nВведите число и количество сдвигов вправо: ";
				union {
					float floatNumber;
					int plugCloneFloat;
				};
				cin >> floatNumber >> shift;
				RIMFloat(plugCloneFloat);
				plugCloneFloat >>= shift;
				RIMFloat(plugCloneFloat);
				break;
			case(3):
				cout << "\nВведите число и количество сдвигов вправо: ";
				union {
					double doubleNumber;
					int cloneDuo[2];
				};
				cin >> doubleNumber >> shift;
				RIMFDouble(cloneDuo);
				cloneDuo[0] >>= shift;
				cloneDuo[0] = (cloneDuo[1] << ((sizeof(int) * 8) - shift)) | cloneDuo[0];
				cloneDuo[1] >>= shift;
				RIMFDouble(cloneDuo);
				break;
			}
		}
	}
	return 0;
}