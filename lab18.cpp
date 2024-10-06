#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    float rating;
    string comment;
    Node *next;
};

Node *createNode(float rating, string &comment);
void addNodeToHead(Node *&head, float rating, string &comment);
void addNodeToTail(Node *&head, float rating, string &comment);
void output(Node *&head);

int main() {
    Node *head = nullptr;
    int choice;
    float rating;
    char addReview;
    string comment;

    cout << "Which linked list method should we use?" << endl;
    cout << string(4, ' ') << "[1] New nodes are added at the head of the linked list" << endl;
    cout << string(4, ' ') << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << "Choice: ";
    cin >> choice;

    do {
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1) {
            addNodeToHead(head, rating, comment);
        } else if (choice == 2) {
            addNodeToTail(head, rating, comment);
        } else {
            cout << "Invalid choice, choose 1 or 2" << endl;
            return 1;
        }

        cout << "Enter another review? Y/N: ";
        cin >> addReview;
    } while (addReview == 'Y' || addReview == 'y');

    output(head);
    
    return 0;
}

Node *createNode(float rating, string &comment) {
    Node *newNode = new Node;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;
    return newNode;
}

void addNodeToHead(Node *&head, float rating, string &comment) {
    Node *newNode = createNode(rating, comment);
    
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void addNodeToTail(Node *&head, float rating, string &comment) {
    Node *newNode = createNode(rating, comment);

    if (!head) {
        head = newNode;
    } else {
        Node *temp = head;

        while (temp->next = nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void output(Node *&head) {
    if (!head) {
        cout << "Empty.\n";
        return;
    }

    Node *temp = head;
    int count = 0;
    float toatlRating = 0.0, average = 0.0;
    
    cout << fixed << setprecision(1);
    cout << "Outputting all reviews:" << endl;
    while (temp) {
        cout << string(4, ' ') << "> Review #" << (count + 1) << ": " 
            << temp->rating << ": " << temp->comment << endl;

        toatlRating += temp->rating;
        count++;
        temp = temp->next;
    }

    cout << setprecision(5);
    if (count > 0) {
        average = toatlRating / count;
    } else {
        average = 0.0;
    }
    cout << string(4, ' ') << "> Average: " << average << endl;
}
