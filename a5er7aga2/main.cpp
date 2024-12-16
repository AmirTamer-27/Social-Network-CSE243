#include <iostream>
using namespace std;
#include "Graph.cpp"

int main()
{
	short key=0;
	int userIndex=-1;
	Graph socialNetwork;
	User n1("mozi", "mozi", 21);//karim,mhsen
	User n2("karim", "karim", 24);//mozi,marwan
	User n3("mhsen", "mhsen", 19);//mozi,mike	
	User n4("marwan", "marwan", 99);//karim	
	User n5("mike", "mike", 89);//mhsen	
	n1.friends.insert(2,0);
	n1.friends.insert(3,1);
	n1.friends.insert(1,2);
	n2.friends.insert(0,0);
	socialNetwork.users.push_back(&n1);
	socialNetwork.users.push_back(&n2);
	socialNetwork.users.push_back(&n3);
	socialNetwork.users.push_back(&n4);
	socialNetwork.users.push_back(&n5);
	while(true){
	cout << "Do u want to login(0) or signup(1)";
	cin >> key;
	User user;
	userIndex = socialNetwork.handleUser(key,user);
	cout <<  endl << userIndex << endl;
	string search_para;
	while(userIndex != -1){
		cout << "1-Show friends" << endl;
		cout << "2-Search" << endl;
		cout << "3-People you may know" << endl;
		cout << "4-Logout" << endl;
		cin >> key;
		switch(key){
			case 1 :
				socialNetwork.showFriends(userIndex);
				break;
			case 2 :
				cout << "Search : " << '\n';
				cin >> search_para;
				socialNetwork.search(search_para, userIndex);
				break;
			case 4 :
				userIndex = -1;
				break; 
		}
	}
	}
	return 0;
}