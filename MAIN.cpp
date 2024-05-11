#include <iostream>
#include <string>
#include <iomanip>
#include <thread>   
#include <chrono>
#include "PROJECT.h"

using namespace std;

int main() {
    HashTable users;

    int choice;
    string username, password, repositoryName, fileName, commitMessage, sourceUsername, sourceRepoName, destinationUsername;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl ;
    cout << "\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t*===================================================*" << endl;
    cout << "\t\t\t\t\t*                                                   *" << endl;
    cout << "\t\t\t\t\t*\t\tIqra Iqbal                          *\n";
    cout<< "\t\t\t\t\t*\t\t22F-3087                            *\n";
    cout << "\t\t\t\t\t*\t\tProject: GitHub Simulation          *\n";
    cout << "\t\t\t\t\t*                                                   *" << endl;
    cout << "\t\t\t\t\t*===================================================*" << endl;
    cout << "\t\t\t\t\t*****************************************************" << endl << endl;;

    this_thread::sleep_for(chrono::seconds(5));
    system("cls");
    do {
 
        cout << "\n========================================================================================================================" << endl << endl;
        cout << "\t\t\t\t\t\t\tMenu " << endl << endl;
        cout << "\n========================================================================================================================" << endl << endl;

        cout << "\t\t\t\t\t\t1.\tAdd User" << endl;
        cout << "\t\t\t\t\t\t2.\tLogin" << endl;
        cout << "\t\t\t\t\t\t3.\tAdd Repository" << endl;
        cout << "\t\t\t\t\t\t4.\tDelete Repository" << endl;
        cout << "\t\t\t\t\t\t5.\tRemove File" << endl;
        cout << "\t\t\t\t\t\t6.\tSet Repository Visibility" << endl;
        cout << "\t\t\t\t\t\t7.\tAdd File" << endl;
        cout << "\t\t\t\t\t\t8.\tList Repositories" << endl;
        cout << "\t\t\t\t\t\t9.\tCommit" << endl;
        cout << "\t\t\t\t\t\t10.\tFork Repository" << endl;
        cout << "\t\t\t\t\t\t11.\tFollow User" << endl;
        cout << "\t\t\t\t\t\t12.\tUnfollow User" << endl;
        cout << "\t\t\t\t\t\t13.\tView Profile" << endl;
        cout << "\t\t\t\t\t\t0.\tExit" << endl << endl;
        cout << "\n========================================================================================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Add User" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            users.addUser(username, password);
            cout << "User added successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 2:
            cout << "Login" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (users.login(username, password)) {
                cout << "Login successful!" << endl;
            }
            else {
                cout << "Login failed. Invalid username or password." << endl;
            }
            cout << "\n========================================================================================================================" << endl;
            break;
        case 3:
            cout << "Add Repository" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            users.addRepository(username, repositoryName);
            cout << "Repository added successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 4:
            cout << "Delete Repository" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            users.deleteRepository(username, repositoryName);
            cout << "Repository deleted successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 5:
            cout << "Remove File" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            cout << "Enter file name: ";
            cin >> fileName;
            users.removeFile(username, repositoryName, fileName);
            cout << "File removed successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 6:
            cout << "Set Repository Visibility" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            cout << "Set repository visibility (1 for public, 0 for private): ";
            bool isPublic;
            cin >> isPublic;
            users.setRepositoryVisibility(username, repositoryName, isPublic);
            cout << "Repository visibility set successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 7:
            cout << "Add File" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            cout << "Enter file name: ";
            cin >> fileName;
            users.addFile(username, repositoryName, fileName);
            cout << "File added successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 8:
            cout << "List Repositories" << endl;
            cout << "Enter username: ";
            cin >> username;
            users.listRepositories(username);
            cout << "========================================================================================================================" << endl;
            break;
        case 9:
            cout << "Commit" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter repository name: ";
            cin >> repositoryName;
            cout << "Enter commit message: ";
            cin.ignore();
            getline(cin, commitMessage);
            users.commit(username, repositoryName, commitMessage);
            cout << "Commit successful!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 10:
            cout << "Fork Repository" << endl;
            cout << "Enter source username: ";
            cin >> sourceUsername;
            cout << "Enter source repository name: ";
            cin >> sourceRepoName;
            cout << "Enter destination username: ";
            cin >> destinationUsername;
            users.forkRepository(sourceUsername, sourceRepoName, destinationUsername);
            cout << "Repository forked successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 11:
            cout << "Follow User" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter username to follow: ";
            cin >> destinationUsername;
            users.followUser(username, destinationUsername);
            cout << "User followed successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 12:
            cout << "Unfollow User" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter username to unfollow: ";
            cin >> destinationUsername;
            users.unfollowUser(username, destinationUsername);
            cout << "User unfollowed successfully!" << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        case 13:
            cout << "View Profile" << endl;
            cout << "Enter username: ";
            cin >> username;
            users.viewProfile(username);
            cout << "\n========================================================================================================================" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            cout << "Please enter a number between 0 and 13." << endl;
            cout << "\n========================================================================================================================" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}