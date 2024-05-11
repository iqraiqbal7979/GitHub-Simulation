// PROJECT.cpp

#include "PROJECT.h"
////.................constructor.................\\\\

HashTable::Repository::Repository(const string& repoName) {
    name = repoName;
    isPublic = false;
    fileCount = 0;
    commitCount = 0;
    files = new string[TABLE_SIZE];
    commits = new string[TABLE_SIZE];
}
////.................Destructor.................\\\\

HashTable::Repository::~Repository() {
    delete[] files;
    delete[] commits;
}
////.................Function for AddFile.................\\\\

void HashTable::Repository::addFile(const string& fileName) {
    files[fileCount++] = fileName;
}
////.................Function for RemoveFile.................\\\\

void HashTable::Repository::removeFile(const string& fileName) {
    for (int i = 0; i < fileCount; i++) {
        if (files[i] == fileName) {
            for (int j = i; j < fileCount - 1; ++j) {
                files[j] = files[j + 1];
            }
            fileCount--;
            break;
        }
    }
}
////.................Function for Addcommit.................\\\\

void HashTable::Repository::addCommit(const string& commitMessage) {
    commits[commitCount++] = commitMessage;
}

////.................Function for userRecord.................\\\\

HashTable::UserRecord::UserRecord(const string& uname, const string& pwd) {
    username = uname;
    password = pwd;
    repositoryCount = 0;
    followerCount = 0;
    followingCount = 0;
    repositories = new Repository * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        repositories[i] = nullptr;
        followers[i] = nullptr;
        following[i] = nullptr;
    }
}
////.................Function for follow.................\\\\

bool HashTable::UserRecord::follows(const string& otherUsername) {
    for (int i = 0; i < followingCount; i++) {
        if (*following[i] == otherUsername) {
            return true;
        }
    }
    return false;
}

////.................constructor.................\\\\

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}
////.................HASH-FUNCTION.................\\\\

int HashTable::hashFunction(const string& key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % TABLE_SIZE;
}
////.................Function for ADD-USER.................\\\\

void HashTable::addUser(const string& username, const string& password) {
    int index = hashFunction(username);
    table[index] = new UserRecord(username, password);
}
////.................Function for login.................\\\\

bool HashTable::login(const string& username, const string& password) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username && table[index]->password == password) {
        return true;
    }
    return false;
}

////.................Function for Add-Repository.................\\\\

void HashTable::addRepository(const string& username, const string& repositoryName) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username) {
        table[index]->repositories[table[index]->repositoryCount++] = new Repository(repositoryName);
    }
}
////.................Function for Delete repository.................\\\\

void HashTable::deleteRepository(const string& username, const string& repositoryName) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username) {
        for (int i = 0; i < table[index]->repositoryCount; i++) {
            if (table[index]->repositories[i]->name == repositoryName) {
                delete table[index]->repositories[i];
                for (int j = i; j < table[index]->repositoryCount - 1; ++j) {
                    table[index]->repositories[j] = table[index]->repositories[j + 1];
                }
                table[index]->repositoryCount--;
                break;
            }
        }
    }
}
////.................Function for remove File.................\\\\

void HashTable::removeFile(const string& username, const string& repositoryName, const string& fileName) {
    int userIndex = hashFunction(username);
    if (table[userIndex] != nullptr && table[userIndex]->username == username) {
        for (int i = 0; i < table[userIndex]->repositoryCount; i++) {
            if (table[userIndex]->repositories[i]->name == repositoryName) {
                table[userIndex]->repositories[i]->removeFile(fileName);
                break;
            }
        }
    }
}
////.................Function for set visibility.................\\\\

void HashTable::setRepositoryVisibility(const string& username, const string& repositoryName, bool isPublic) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username) {
        for (int i = 0; i < table[index]->repositoryCount; i++) {
            if (table[index]->repositories[i]->name == repositoryName) {
                table[index]->repositories[i]->isPublic = isPublic;
                break;
            }
        }
    }
}
////.................Function for AddFile.................\\\\

void HashTable::addFile(const string& username, const string& repositoryName, const string& fileName) {
    int userIndex = hashFunction(username);
    if (table[userIndex] != nullptr && table[userIndex]->username == username) {
        for (int i = 0; i < table[userIndex]->repositoryCount; i++) {
            if (table[userIndex]->repositories[i]->name == repositoryName) {
                table[userIndex]->repositories[i]->addFile(fileName);
                break;
            }
        }
    }
}
////.................Function for list Repository .................\\\\

void HashTable::listRepositories(const string& username) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username) {
        for (int i = 0; i < table[index]->repositoryCount; i++) {
            cout << table[index]->repositories[i]->name << endl;
        }
    }
}

////.................Function for commit .................\\\\

void HashTable::commit(const string& username, const string& repositoryName, const string& commitMessage) {
    int userIndex = hashFunction(username);
    if (table[userIndex] != nullptr && table[userIndex]->username == username) {
        for (int i = 0; i < table[userIndex]->repositoryCount; i++) {
            if (table[userIndex]->repositories[i]->name == repositoryName) {
                table[userIndex]->repositories[i]->addCommit(commitMessage);
                break;
            }
        }
    }
}

////.................Function for fork repository .................\\\\

void HashTable::forkRepository(const string& sourceUsername, const string& sourceRepoName, const string& destinationUsername) {
    int sourceIndex = hashFunction(sourceUsername);
    int destIndex = hashFunction(destinationUsername);
    if (table[sourceIndex] != nullptr && table[sourceIndex]->username == sourceUsername) {
        for (int i = 0; i < table[sourceIndex]->repositoryCount; i++) {
            if (table[sourceIndex]->repositories[i]->name == sourceRepoName) {
                table[destIndex]->repositories[table[destIndex]->repositoryCount++] = table[sourceIndex]->repositories[i];
                break;
            }
        }
    }
}
////.................Function for Follow user .................\\\\

void HashTable::followUser(const string& username, const string& otherUsername) {
    int userIndex = hashFunction(username);
    int otherIndex = hashFunction(otherUsername);
    if (table[userIndex] != nullptr && table[userIndex]->username == username && table[otherIndex] != nullptr && table[otherIndex]->username == otherUsername) {
        table[userIndex]->following[table[userIndex]->followingCount++] = &table[otherIndex]->username;
        table[otherIndex]->followers[table[otherIndex]->followerCount++] = &table[userIndex]->username;
    }
}
////.................Function for unfollow user.................\\\\

void HashTable::unfollowUser(const string& username, const string& otherUsername) {
    int userIndex = hashFunction(username);
    if (table[userIndex] != nullptr && table[userIndex]->username == username) {
        for (int i = 0; i < table[userIndex]->followingCount; i++) {
            if (*table[userIndex]->following[i] == otherUsername) {
                for (int j = i; j < table[userIndex]->followingCount - 1; ++j) {
                    table[userIndex]->following[j] = table[userIndex]->following[j + 1];
                }
                table[userIndex]->followingCount--;
                break;
            }
        }
    }
}

////.................Function for View user profile.................\\\\ 

void HashTable::viewProfile(const string& username) {
    int index = hashFunction(username);
    if (table[index] != nullptr && table[index]->username == username) {
        cout << "Username: " << table[index]->username << endl;
        cout << "Repositories: " << table[index]->repositoryCount << endl;
        cout << "Followers: " << table[index]->followerCount << endl;
        cout << "Following: " << table[index]->followingCount << endl;
    }
}
////.................Destructor .................\\\\

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != nullptr) {
            delete table[i];
        }
    }
}

