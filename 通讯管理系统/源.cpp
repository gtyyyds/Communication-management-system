#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "�������Ա�" << endl
			<< "1 --- ��" << endl
			<< "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else if (age < 0)
			{
				cout << "����˻�û�����أ��������������ݣ�" << endl;
			}
			else
			{
				cout << "������ô���ˣ����õ绰���������������ݣ�" << endl;
			}
		}
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "��ϵ����ӳɹ�!" << endl;
		system("pause");
		system("cls");

	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "��" << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ�� 
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ������԰�����ʧ�ģ�����" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");

}
void findPreson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������ " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personArray[ret].m_Age << "��" << "\t";
		cout << "�绰�� " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ�� " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPreson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "��������Ҫ�޸ĵ����ݣ�" << endl << "1---����" << endl
			<< "2---�Ա�" << endl
			<< "3---����" << endl
			<< "4---�绰" << endl
			<< "5---סַ" << endl;
		int num = 0;
		while (true)
		{
			cin >> num;
			if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5)
			{
				if (num == 1)
				{
					cout << "��������ϵ�˵������֣�" << endl;
					string name;
					cin >> name;
					abs->personArray[ret].m_Name = name;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				else if (num == 2)
				{
					cout << "��������ϵ�˵����Ա�" << endl
						<< "1 --- ��" << endl
						<< "2 --- Ů" << endl;
					int sex = 0;
					while (true)
					{
						cin >> sex;
						if (sex == 1 || sex == 2)
						{
							abs->personArray[ret].m_Sex = sex;
							cout << "�޸ĳɹ���" << endl;
							break;
						}
						cout << "�����������������룡" << endl;
					}
				}
				else if (num == 3)
				{
					cout << "�����������䣺" << endl;
					int age = 0;
					while (true)
					{
						cin >> age;
						if (age >= 0 && age <= 150)
						{
							abs->personArray[ret].m_Age = age;
							cout << "�޸ĳɹ���" << endl;
							break;
						}
						else if (age < 0)
						{
							cout << "����˻�û�����أ��������������ݣ�" << endl;
						}
						else
						{
							cout << "������ô���ˣ����õ绰���������������ݣ�" << endl;
						}
					}
				}
				else if (num == 4)
				{
					cout << "����������ϵ�绰��" << endl;
					string phone;
					cin >> phone;
					abs->personArray[ret].m_Phone = phone;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
				else if (num == 5)
				{
					cout << "�������¼�ͥסַ��" << endl;
					string address;
					cin >> address;
					abs->personArray[ret].m_Addr = address;
					cout << "�޸ĳɹ���" << endl;
					break;
				}
			}
			else
			{
				cout << "��������Ҫ�޸�����ǰ����ȷ�ı��!" << endl;
			}
			break;
		}
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPreson(Addressbooks* abs)
{
	cout << "��ȷ��Ҫ���ͨѶ¼��" << endl
		<< "1---ȷ��" << endl
		<< "2---��ȷ��" << endl;
	int num;
	while (true)
	{
		cin >> num;
		if (num == 1 || num == 2)
		{
			if (num == 1)
			{
				abs->m_Size = 0;
				cout << "ͨѶ¼����գ�" << endl;
				break;
			}
			else
			{
				cout << "ͨѶ¼δ���" << endl;
				break;
			}
		}
		else
		{
			cout << "����ȷ����ѡ��ǰ��ţ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;

		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;

		case 4://������ϵ��
			findPreson(&abs);
			break;

		case 5://�޸���ϵ��
			modifyPreson(&abs);
			break;

		case 6://�����ϵ��
			cleanPreson(&abs);
			break;

		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
	system("pause");
	return 0;
}