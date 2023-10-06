#include <iostream>
#include <string>
using namespace std;

int n;
string str;

struct Node{
    char ch;
    Node *prev = NULL, *next = NULL;
};

class Password{
private:
    // start&end 는 문자열의 시작과 끝. (빈 노드)
    // cursor는 문자열의 오른쪽에 존재한다고 생각.
    // cursor가 가리키고 있는 노드의 오른쪽에 있다고 가정.
    Node *start, *cursor, *end;
    
public:
    Password(){
        start = new Node;
        end = new Node;
        
        start->next = end;
        end->prev = start;
        
        cursor = start;
    }
    
    Node* getStart(){
        return start;
    }
    
    void enterPass(char in){
        Node *newNode = new Node;
        newNode->ch = in;
        
        newNode->prev = cursor;
        newNode->next = cursor->next;
        
        cursor->next->prev = newNode;
        cursor->next = newNode;
    
        cursor = newNode;
    }
    
    void deletePass(){
        // 커서가 문자열의 제일 앞에 와있을 때는 삭제를 할 것이 없다.
        if(cursor != start){
            cursor->prev->next = cursor->next;
            cursor->next->prev = cursor->prev;
            cursor = cursor->prev;
        }
    }
    
    void moveLeft(){
        if(cursor != start)
            cursor = cursor->prev;
    }
    
    void moveRight(){
        if(cursor->next != end)
            cursor = cursor->next;
    }
    
    void printPass(){
        for(Node* temp = start->next; temp != end; temp = temp->next)
            cout << temp->ch;
        cout << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    while(n--){
        Password pw;
        
        cin >> str;
        
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '-'){
                pw.deletePass();
            }else if(str[i] == '<'){
                pw.moveLeft();
            }else if(str[i] == '>'){
                pw.moveRight();
            }else{
                pw.enterPass(str[i]);
            }
        }
        pw.printPass();
    }
    
    return 0;
}