#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"
#include "List.h"
using namespace std;

int main() {
	srand(time(0));
	List<Client> list, listCopy, resultList;
	Client client;
	size_t index;
	String item;
	char Buffer[200];
	int UserVariant = -1;
	while (UserVariant != 0) {
		cout << "Choose variant: ";
		cin >> UserVariant;
		switch (UserVariant) {
		case 1:
			cin >> client;
			break;
		case 2:
			cout << client;
			break;
		case 3:
			if (client.getFname().GetStr()) list.push_back(client);
			break;
		case 4:
			if (client.getFname().GetStr()) list.push_front(client);
			break;
		case 5:
			cin >> index;
			if (client.getFname().GetStr()) list.insert(index, client);
			break;
		case 6:
			list.pop_back();
			break;
		case 7:
			list.pop_front();
			break;
		case 8:
			cin >> index;
			list.pop_position(index);
			break;
		case 9:
			list.print();
			break;
		case 10:
			cin.ignore();
			cin.getline(Buffer, strlen(Buffer));
			item.SetStr(Buffer);
			cin.getline(item.GetStr(), sizeof(item.GetStr()));
			PrintByItem(list, item);
			break;
		case 11:
			DownloadList(list);
			break;
		case 12:
			SaveList(list);
			break;
		case 13:
			listCopy = list;
			listCopy.print();
			break;
		case 14:
			resultList = list + listCopy;
			resultList.print();
			break;
		default:
			break;
		}
	}
}