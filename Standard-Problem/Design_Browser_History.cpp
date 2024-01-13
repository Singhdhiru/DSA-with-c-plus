#include <bits/stdc++.h>
#include<string>
using namespace std;
// ? 1472. Design Browser History(Leet Code)
class Node{
    public:
    string data;
    Node* next;
    Node* back;
    Node(string data){
        this->data = data;
        next = nullptr;
        back = nullptr;
    }

};
class Browser
{
    Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(const string &url)
    {
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps)
    {
        while(steps){
            if(currentPage->back){
                currentPage = currentPage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while(steps){
            if(currentPage->next){
                currentPage = currentPage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};

int main() {
    string homepage = "https://www.example.com";
    Browser browser(homepage);

    browser.visit("insta.com");
    browser.visit("facebook.com");
    browser.visit("linkdln.com");

    cout << "Current Page: " << browser.back(2) << endl;
    cout << "Current Page: " << browser.forward(1) << endl;

    return 0;
}
