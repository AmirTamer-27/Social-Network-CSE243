#include <iostream>
#include "Graph.cpp"

int main()
{
	short key = 0;
	int userIndex = -1;
	Graph socialNetwork;
	User n1("mozi", "mozi", 21);//karim,mhsen
	User n2("karim", "karim", 24);//mozi,marwan,omar
	User n3("mhsen", "mhsen", 19);//mozi,mike,Amir	
	User n4("marwan", "marwan", 99);//karim	,omar
	User n5("mike", "mike", 89);//mhsen,hadary
	User n6("Amir","tala3",19);//Mizo,mhsen,Hadary
	User n7("Hadary","lesbab",20);//Badra,mike
	User n8("Mizo","tala3ahh",19);//Badra,Amir
	User n9("Omar","password",19);//Karim,marwan
	User n10("Badra","mnbo2y",18);//Mizo,Hadary
	n1.friends.insert(1, 0);
	n1.friends.insert(2, 1);
	n2.friends.insert(3, 0);
	n2.friends.insert(0, 1);
	n2.friends.insert(8, 2);
	n3.friends.insert(0, 0);
	n3.friends.insert(4, 1);
	n3.friends.insert(5, 2);
	n4.friends.insert(1, 0);
	n4.friends.insert(8, 1);
	n5.friends.insert(2, 0);
	n5.friends.insert(7, 1);
	n6.friends.insert(7, 0);
	n6.friends.insert(2, 1);
	n6.friends.insert(6, 2);
	n7.friends.insert(9, 0);
	n7.friends.insert(4, 1);
	n8.friends.insert(9, 0);
	n8.friends.insert(5, 1);
	n9.friends.insert(1, 0);
	n9.friends.insert(3, 1);
	n10.friends.insert(7, 0);
	n10.friends.insert(6, 1);
	socialNetwork.users.push_back(&n1);
	socialNetwork.users.push_back(&n2);
	socialNetwork.users.push_back(&n3);
	socialNetwork.users.push_back(&n4);
	socialNetwork.users.push_back(&n5);
	socialNetwork.users.push_back(&n6);
	socialNetwork.users.push_back(&n7);
	socialNetwork.users.push_back(&n8);
	socialNetwork.users.push_back(&n9);
	socialNetwork.users.push_back(&n10);
	while (true) {
		cout << "Do u want to login(0) or signup(1)";
		cin >> key;
		userIndex = socialNetwork.handleUser(key);
		// cout << endl << userIndex << endl;1
		string search_para;
		while (userIndex != -1) {
			cout << "1-Show friends" << endl;
			cout << "2-Search" << endl;
			cout << "3-People you may know" << endl;
			cout << "4-Show requests" << endl;
			cout << "5-Logout" << endl;
			cin >> key;
			switch (key) {
			case 1:
				socialNetwork.showFriends(userIndex);
				break;
			case 2:
				cout << "Search : " << '\n';
				cin >> search_para;
				socialNetwork.search(search_para, userIndex);
				break;
			case 3:
				socialNetwork.peopleYouMayKnow(userIndex);
				break;
			case 4:
				socialNetwork.showRequests(userIndex);
				break;
			case 5:
				userIndex = -1;
				break;
			}
		}
	}
	return 0;
}
