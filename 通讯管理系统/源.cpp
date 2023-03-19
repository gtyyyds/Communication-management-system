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
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		cout << "请输入性别：" << endl
			<< "1 --- 男" << endl
			<< "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		cout << "请输入年龄：" << endl;
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
				cout << "这个人还没出生呢？请重新输入数据：" << endl;
			}
			else
			{
				cout << "年龄这么大了，会用电话吗？请重新输入数据：" << endl;
			}
		}
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "联系人添加成功!" << endl;
		system("pause");
		system("cls");

	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "岁" << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
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
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移 
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！所以爱会消失的，对吗？" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");

}
void findPreson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名： " << abs->personArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "岁" << "\t";
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void modifyPreson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入你要修改的内容：" << endl << "1---姓名" << endl
			<< "2---性别" << endl
			<< "3---年龄" << endl
			<< "4---电话" << endl
			<< "5---住址" << endl;
		int num = 0;
		while (true)
		{
			cin >> num;
			if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5)
			{
				if (num == 1)
				{
					cout << "请输入联系人的新名字：" << endl;
					string name;
					cin >> name;
					abs->personArray[ret].m_Name = name;
					cout << "修改成功！" << endl;
					break;
				}
				else if (num == 2)
				{
					cout << "请输入联系人的新性别：" << endl
						<< "1 --- 男" << endl
						<< "2 --- 女" << endl;
					int sex = 0;
					while (true)
					{
						cin >> sex;
						if (sex == 1 || sex == 2)
						{
							abs->personArray[ret].m_Sex = sex;
							cout << "修改成功！" << endl;
							break;
						}
						cout << "输入有误，请重新输入！" << endl;
					}
				}
				else if (num == 3)
				{
					cout << "请输入新年龄：" << endl;
					int age = 0;
					while (true)
					{
						cin >> age;
						if (age >= 0 && age <= 150)
						{
							abs->personArray[ret].m_Age = age;
							cout << "修改成功！" << endl;
							break;
						}
						else if (age < 0)
						{
							cout << "这个人还没出生呢？请重新输入数据：" << endl;
						}
						else
						{
							cout << "年龄这么大了，会用电话吗？请重新输入数据：" << endl;
						}
					}
				}
				else if (num == 4)
				{
					cout << "请输入新联系电话：" << endl;
					string phone;
					cin >> phone;
					abs->personArray[ret].m_Phone = phone;
					cout << "修改成功！" << endl;
					break;
				}
				else if (num == 5)
				{
					cout << "请输入新家庭住址：" << endl;
					string address;
					cin >> address;
					abs->personArray[ret].m_Addr = address;
					cout << "修改成功！" << endl;
					break;
				}
			}
			else
			{
				cout << "请输入需要修改内容前面正确的编号!" << endl;
			}
			break;
		}
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void cleanPreson(Addressbooks* abs)
{
	cout << "你确定要清空通讯录吗？" << endl
		<< "1---确定" << endl
		<< "2---不确定" << endl;
	int num;
	while (true)
	{
		cin >> num;
		if (num == 1 || num == 2)
		{
			if (num == 1)
			{
				abs->m_Size = 0;
				cout << "通讯录已清空！" << endl;
				break;
			}
			else
			{
				cout << "通讯录未清空" << endl;
				break;
			}
		}
		else
		{
			cout << "请正确输入选项前编号！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
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
		case 1://添加联系人
			addPerson(&abs);
			break;

		case 2://显示联系人
			showPerson(&abs);
			break;

		case 3://删除联系人
			deletePerson(&abs);
			break;

		case 4://查找联系人
			findPreson(&abs);
			break;

		case 5://修改联系人
			modifyPreson(&abs);
			break;

		case 6://清空联系人
			cleanPreson(&abs);
			break;

		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
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