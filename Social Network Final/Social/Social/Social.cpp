#include <iostream>
#include "../socialNetwork.h"

int main()
{
	SocialNetwork mySocialNetwork;
	User n1("mozi", "mozi", 21);//karim,mhsen
	User n2("karim", "karim", 24);//mozi,marwan,omar
	User n3("mhsen", "mhsen", 19);//mozi,mike,Amir	
	User n4("marwan", "marwan", 99);//karim	,omar
	User n5("mike", "mike", 89);//mhsen,hadary
	User n6("Amir","tala3",19);//Mizo,mhsen
	User n7("Hadary","lesbab",20);//Badra,mike
	User n8("Mizo","tala3ahh",19);//Badra,Amir
	User n9("Omar","password",19);//Karim,marwan
	User n10("Badra","mnbo2y",18);//Mizo,Hadary
    mySocialNetwork.users.addNode(&n1);
    mySocialNetwork.users.addNode(&n2);
    mySocialNetwork.users.addNode(&n3);
    mySocialNetwork.users.addNode(&n4);
    mySocialNetwork.users.addNode(&n5);
    mySocialNetwork.users.addNode(&n6);
    mySocialNetwork.users.addNode(&n7);
    mySocialNetwork.users.addNode(&n8);
    mySocialNetwork.users.addNode(&n9);
    mySocialNetwork.users.addNode(&n10);
    mySocialNetwork.users.addEdge(0,1);
    mySocialNetwork.users.addEdge(0,2);
    mySocialNetwork.users.addEdge(3,1);
    mySocialNetwork.users.addEdge(8,1);
    mySocialNetwork.users.addEdge(4,2);
    mySocialNetwork.users.addEdge(5,2);
    mySocialNetwork.users.addEdge(8,3);
    mySocialNetwork.users.addEdge(6,4);
    mySocialNetwork.users.addEdge(7,5);
    mySocialNetwork.users.addEdge(9,6);
    mySocialNetwork.users.addEdge(9,7);
	short key = 0;
	int userIndex = -1;
	cout << "SABRY \n";
	cout << "HASSAN";
	
	while (true) {
		cout << "Do u want to login(0) or signup(1)";
		cin >> key;
		userIndex = mySocialNetwork.handleUser(key);
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
				mySocialNetwork.showFriends(userIndex);
				break;
			case 2:
				cout << "Search : " << '\n';
				cin >> search_para;
				mySocialNetwork.search(search_para, userIndex);
				break;
			case 3:
				mySocialNetwork.peopleYouMayKnow(userIndex);
				break;
			case 4:
				mySocialNetwork.showRequests(userIndex);
				break;
			case 5:
				userIndex = -1;
				break;
			}
		}
	}
	
	return 0;
}
