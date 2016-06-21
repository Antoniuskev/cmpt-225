#include<iostream>
//#include<cstring>
using namespace std;// THIS POINTER READ!!

class String
{
public:
	//Constructors
	String(); //Done
	String(const char s[]);

	//Big three
	String(const String& copy); //Copy Constructor
	String operator = (const String& ch); //Assignment operator, Done
	//~String(); //Deconstructor, Done

	//Functions
	bool empty(); //Done
	int length(); //Done
	String upper();
	int substring(const String&);

	//Operators (Not Done)
	bool operator == (const String& ch);
	String operator + (const String& ch);
	String operator +=(const String& ch);
	String operator +=(const char& ch);
	friend ostream& operator << (ostream& river, const String& ch);

private: //Making dynamic array with the three big functions
	char* str; // week 9 excercise 2 reading!!!
	int len;
};

//Default Constructor
String::String()
{
	str = new char[1];
	str[0] = '\0';
	len = 1;
}

//Custom Constructor
String::String(const char s[])
{
	int total = 0;
	while(s[total] != '\0')
		total = total + 1;
	len = total;

	str = new char[len+1];
	for (int i = 0; i < len; i++)
		str[i] = s[i];
	str[len+1] = '\0';
}

//Copy Constructor
String::String(const String& copy)
{
	len = copy.len; 
	str = new char[len+1];
	for(int i = 0; i < len; i ++)
		str[i] = copy.str[i];
	str[len+1] = '\0';
}

String String::operator = (const String& ch) 
{	
	int newLength = ch.len;
	if(newLength > len)
	{
		delete[] str;
		len = newLength;
		str = new char[len+1];
	}
	for (int i = 0; i <= len; i++)
		str[i] = ch.str[i];
	String newObj = ch;
	return newObj;
}

/*String::~String()
{
	cout << "Deconstructor called";
	if (len > 0)
		delete[] str;
	str = '\0';
}*/

ostream& operator << (ostream& river, const String& ch)
{
	for (int i = 0; i < ch.len; i++)
		river << ch.str[i];
	
	return river;
}

String operator + (const String& ch)
{
	String newObj;
	int newLength;
	return newObj;
}

bool String::empty()
{
	bool result = true;
	if (str[0] != '\0')
		result = false;
	
	return result;
}

int String::length()
{	
	int total = 0;
	while(str[total] != '\0' && str[total] >= 65 && str[total] <= 90 || str[total] >= 97 && str[total] <= 122)
	{
		cout << "str: " << str[total] << endl;
		total = total + 1;
	}
	
	return total;
}

int main()
{
	String s1, s2;
	s1 = s2;
	cout << "s1 is empty? " << s1.empty() << endl;
	cout << "s2 is empty? " << s2.empty() << endl;
	String s3 = "Hello";
	s1 = s2 = s3;
	cout << s1 << '\t' << s2 << '\t' << s3 << endl;
	s2 = "hi";
	s3 = s2;
	cout << s1 << '\t' << s2 << '\t' << s3 << endl;
	cout << "Now s1 is empty? " << s1.empty() << endl;
	cout << s1.length() << '\t' << s2.length() << '\t' << s3.length() << endl;

	cout << "--------------- 0 ---------------" << endl << endl;

	//if (s1 == s2)
	//	cout << "They are equal\n";
	//else
	//	cout << "They are not equal\n";

	//if (s2 == "Hello")
	//	cout << "They are equal\n";
	//else
	//	cout << "They are not equal\n";

	//s1[0] = 'H';
	//s1[1] = s1[4];
	//for(int i = 0; i < s3.length(); ++i)
	//	cout << s3[i] << " ";
	//cout << endl;
	//cout << "s1 is " << s1 << endl;
	//cout << "s2 is " << s2 << endl;

	//cout << "--------------- 1 ---------------" << endl << endl;

	//String s4;
	//s4 = s1 + " " + s2;
	//cout << s4 << endl;

	//cout << "s4 length is " << s4.length() << endl;
	//if (s4 == s4)
	//	cout << "s4 equals s4\n";
	//else
	//	cout << "s4 not equals s4\n";
	//cout << endl;
	//
	//s3 = "Monday";
	//cout << "s3 is " << s3 << endl;
	//s3 = "";
	//cout << "s3 is " << s3 << endl;
	//s3 = s3 + "Friday";
	//cout << "s3 is " << s3 << endl;
	//s3 = "SundaySunday";
	//s3 = s3 + "   hahaha";
	//cout << "s3 is " << s3 << endl;

	//cout << "--------------- 2 ---------------" << endl << endl;

	//String s5;
	//cout << "Do we have output here? " << endl << endl;
	//for(int i = 0; i < s5.length(); ++i)
	//	cout << s5[i] << '?';

	//cout << "s4 is " << s4 << endl;
	//cout << s4.upper() << endl;
	//cout << s4 << endl;

	//cout << "The index of l in " << s4 << " is " << s4.position('l') << endl;
	//cout << "The index of k in " << s4 << " is " << s4.position('k') << endl;

	//cout << "--------------- 3 ---------------" << endl << endl;

	//cout << "s1 is: " << s1 << endl;
	//s1 += 'o';//char
	//s1 += "o";//string
	//cout << "s1 now is: " << s1 << endl;
	//String str;
	//cout << "str is " << str << endl;
	//char ch = 'A';
	//for(int i = 0; i < 10; ++i)
	//{
	//	str += ch;
	//	ch++;
	//}
	//str += "MORE...";
	//cout << "Now str is " << str << endl;

	//cout << "--------------- 4 ---------------" << endl << endl;

	//cout << "str length: " << str.length() << endl;
	//cout << "substring starting at 2 with size 5 is " << str.substr(2,5) << endl;
	//cout << "substring starting at 2 with size 20 is " << str.substr(2,20) << endl;
	//cout << "substring starting at 7 with size 1 is " << str.substr(7,1) << endl;
	//cout << "substring starting at 20 with size 5 is " << str.substr(20,5) << "empty string!" << endl;

	//cout << "--------------- 5 ---------------" << endl << endl;

	//s3 = "Hi";
	//int index = s1.substring(s3);
	//if (index >= 0)
	//	cout << "1) " << s3 << " is a substring of " << s1 << ", starting from index " << index << endl;
	//else
	//	cout << "1) " << s3 << " is not a substring of " << s1 << endl;

	//index = s1.substring("lo");
	//if (index >= 0)
	//	cout << "2) " << "lo is a substring of " << s1 << ", starting from index " << index << endl;
	//else
	//	cout << "2) " << "lo is not a substring of " << s1 << endl << endl;

	//String s6;
	//index = s1.substring(s6);
	//if (index >= 0)
	//	cout << "3) " << s6 << " is a substring of " << s1 << ", starting from index " << index << endl;
	//else
	//	cout << "3) " << s6 << " is not a substring of " << s1 << endl;


	//String s = "aabcccdefefg";
	//index = s.substring("bdg");
	//if (index >= 0)
	//	cout << "4) bdg is a substring of " << s << ", starting from index " << index << endl;
	//else
	//	cout << "4) bdg is not a substring of " << s << endl;

	//index = s.substring("cde");
	//if (index >= 0)
	//	cout << "5) cde is a substring of " << s << ", starting from index " << index << endl;
	//else
	//	cout << "5) cde is not a substring of " << s << endl;

	//s = "aabc";
	//s1 = "aabc ";
	//index = s.substring(s1);
	//if (index >= 0)
	//	cout << "6) " << s1 << " is a substring of " << s << ", starting from index " << index << endl;
	//else
	//	cout << "6) " << s1 << " is not a substring of " << s << endl;

	//index = s.substring(s);
	//if (index >= 0)
	//	cout << "7) " << s << " is a substring of " << s << ", starting from index " << index << endl;
	//else
	//	cout << "7) " << s << " is not a substring of " << s << endl;

	system("pause");
	return 0;
}