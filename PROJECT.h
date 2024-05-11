// PROJECT.h

#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <thread>   
#include <chrono> 

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 1000;

    struct Repository {
        string name;
        bool isPublic;
        string* files;
        int fileCount;
        string* commits;
        int commitCount;

        Repository(const string& repoName);

        ~Repository();

        void addFile(const string& fileName);

        void removeFile(const string& fileName);

        void addCommit(const string& commitMessage);
    };

    struct UserRecord {
        string username;
        string password;
        Repository** repositories;
        int repositoryCount;
        string* followers[TABLE_SIZE];
        int followerCount;
        string* following[TABLE_SIZE];
        int followingCount;

        UserRecord(const string& uname, const string& pwd);

        bool follows(const string& otherUsername);
    };

    UserRecord* table[TABLE_SIZE];

    int hashFunction(const string& key);

public:

    HashTable();

    void addUser(const string& username, const string& password);

    bool login(const string& username, const string& password);

    void addRepository(const string& username, const string& repositoryName);

    void deleteRepository(const string& username, const string& repositoryName);

    void removeFile(const string& username, const string& repositoryName, const string& fileName);

    void setRepositoryVisibility(const string& username, const string& repositoryName, bool isPublic);

    void addFile(const string& username, const string& repositoryName, const string& fileName);

    void listRepositories(const string& username);

    void commit(const string& username, const string& repositoryName, const string& commitMessage);

    void forkRepository(const string& sourceUsername, const string& sourceRepoName, const string& destinationUsername);

    void followUser(const string& username, const string& otherUsername);

    void unfollowUser(const string& username, const string& otherUsername);

    void viewProfile(const string& username);

    ~HashTable();
};

#endif // PROJECT_H
#pragma once
