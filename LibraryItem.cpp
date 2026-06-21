#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
protected:
    string title;

public:
    LibraryItem(string t) {
        title = t;
    }

    virtual void showMenu() = 0;

    virtual string getTitle() const {
        return title;
    }

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    int math = 8, science = 7, history = 9, literature = 10;
    int pili;

public:
    Book(string t) : LibraryItem(t) {}

    void setPili(int p) {
        pili = p;
    }

    void showMenu() override {
        cout << "\nAvailable Books in the Library:\n";
        cout << "1. Math: " << math << endl;
        cout << "2. Science: " << science << endl;
        cout << "3. History: " << history << endl;
        cout << "4. Literature: " << literature << endl;
    }

    Book& operator--() {
        if (pili == 1) math--;
        else if (pili == 2) science--;
        else if (pili == 3) history--;
        else if (pili == 4) literature--;
        return *this;
    }

    void showSelectedValue() {
        if (pili == 1)
            cout << "Math Books Remaining: " << math << endl;
        else if (pili == 2)
            cout << "Science Books Remaining: " << science << endl;
        else if (pili == 3)
            cout << "History Books Remaining: " << history << endl;
        else if (pili == 4)
            cout << "Literature Books Remaining: " << literature << endl;
    }

    void showSelectedValue(int category) {
        if (category == 1)
            cout << "Math Books Remaining: " << math << endl;
        else if (category == 2)
            cout << "Science Books Remaining: " << science << endl;
        else if (category == 3)
            cout << "History Books Remaining: " << history << endl;
        else if (category == 4)
            cout << "Literature Books Remaining: " << literature << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int fashion = 5, technology = 6, health = 4, travel = 8;
    int pili;

public:
    Magazine(string t) : LibraryItem(t) {}

    void setPili(int p) {
        pili = p;
    }
    void showMenu() override {
        cout << "\nAvailable Magazines in the Library:\n";
        cout << "1. Fashion: " << fashion << endl;
        cout << "2. Technology: " << technology << endl;
        cout << "3. Health: " << health << endl;
        cout << "4. Travel: " << travel << endl;
    }

    Magazine& operator--() {
        if (pili == 1) fashion--;
        else if (pili == 2) technology--;
        else if (pili == 3) health--;
        else if (pili == 4) travel--;
        return *this;
    }

    void showSelectedValue() {
        if (pili == 1)
            cout << "Fashion Magazines Remaining: " << fashion << endl;
        else if (pili == 2)
            cout << "Technology Magazines Remaining: " << technology << endl;
        else if (pili == 3)
            cout << "Health Magazines Remaining: " << health << endl;
        else if (pili == 4)
            cout << "Travel Magazines Remaining: " << travel << endl;
    }

    void showSelectedValue(int category) {
        if (category == 1)
            cout << "Fashion Magazines Remaining: " << fashion << endl;
        else if (category == 2)
            cout << "Technology Magazines Remaining: " << technology << endl;
        else if (category == 3)
            cout << "Health Magazines Remaining: " << health << endl;
        else if (category == 4)
            cout << "Travel Magazines Remaining: " << travel << endl;
    }
};

class DVD : public LibraryItem {
private:
    int action = 4, comedy = 6, drama = 3, documentary = 4;
    int pili;

public:
    DVD(string t) : LibraryItem(t) {}

    void setPili(int p) {
        pili = p;
    }
    void showMenu() override {
        cout << "\nAvailable DVD's in the Library:\n";
        cout << "1. Action: " << action << endl;
        cout << "2. Comedy: " << comedy << endl;
        cout << "3. Drama: " << drama << endl;
        cout << "4. Documentary: " << documentary << endl;
    }

    DVD& operator--() {
        if (pili == 1) action--;
        else if (pili == 2) comedy--;
        else if (pili == 3) drama--;
        else if (pili == 4) documentary--;
        return *this;
    }

    void showSelectedValue() {
        if (pili == 1)
            cout << "Action DVDs Remaining: " << action << endl;
        else if (pili == 2)
            cout << "Comedy DVDs Remaining: " << comedy << endl;
        else if (pili == 3)
            cout << "Drama DVDs Remaining: " << drama << endl;
        else if (pili == 4)
            cout << "Documentary DVDs Remaining: " << documentary << endl;
    }

    void showSelectedValue(int category) {
        if (category == 1)
            cout << "Action DVDs Remaining: " << action << endl;
        else if (category == 2)
            cout << "Comedy DVDs Remaining: " << comedy << endl;
        else if (category == 3)
            cout << "Drama DVDs Remaining: " << drama << endl;
        else if (category == 4)
            cout << "Documentary DVDs Remaining: " << documentary << endl;
    }

};

class ResearchPaper : public LibraryItem {
private:
    int life = 8, robotics = 12, ai = 9, educ = 10;
    int pili;

public:
    ResearchPaper(string t) : LibraryItem(t) {}

    void setPili(int p) {
        pili = p;
    }
    void showMenu() override {
        cout << "\nAvailable Research Papers in the Library:\n";
        cout << "1. Life: " << life << endl;
        cout << "2. Robotics: " << robotics << endl;
        cout << "3. AI: " << ai << endl;
        cout << "4. Education: " << educ << endl;
    }

    ResearchPaper& operator--() {
        if (pili == 1) life--;
        else if (pili == 2) robotics--;
        else if (pili == 3) ai--;
        else if (pili == 4) educ--;
        return *this;
    }

    void showSelectedValue() {
        if (pili == 1)
            cout << "Life Science Papers Remaining: " << life << endl;
        else if (pili == 2)
            cout << "Robotics Papers Remaining: " << robotics << endl;
        else if (pili == 3)
            cout << "AI Papers Remaining: " << ai << endl;
        else if (pili == 4)
            cout << "Education Papers Remaining: " << educ << endl;
    }

        void showSelectedValue(int category) {
        if (category == 1)
            cout << "Life Science Papers Remaining: " << life << endl;
        else if (category == 2)
            cout << "Robotics Papers Remaining: " << robotics << endl;
        else if (category == 3)
            cout << "AI Papers Remaining: " << ai << endl;
        else if (category == 4)
            cout << "Education Papers Remaining: " << educ << endl;
    }
};

int main() {
    string name, title;
    int choice, pili;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\n===== Welcome " << name << " to the Library Management System! =====" << endl;
    cout << "Available Items in the Library: " << endl;
    cout << "1. Book" << endl;
    cout << "2. Magazine" << endl;
    cout << "3. DVD" << endl;
    cout << "4. Research Paper" << endl;
    cout << "What type of item are you interested in? (Choose 1-4): ";
    cin >> choice;
    do {
        if (choice < 1 || choice > 4) {
            cout << "Invalid value, please choose from 1-4" << endl;
            cout << "What type of item are you interested in? (Choose 1-4): ";
            cin >> choice;
        }
    } while (choice < 1 || choice > 4);

    LibraryItem* item = nullptr;

    if (choice == 1) {
        item = new Book(title);
    } else if (choice == 2) {
        item = new Magazine(title);
    } else if (choice == 3) {
        item = new DVD(title);
    } else if (choice == 4) {
        item = new ResearchPaper(title);
    }

    item->showMenu();

    cout << "Choose category (1-4): ";
    cin >> pili;
    do {
        if (pili < 1 || pili > 4) {
            cout << "Invalid value, please choose from 1-4" << endl;
            cout << "Choose category (1-4): ";
            cin >> pili;
        }
    } while (pili < 1 || pili > 4);

    cin.ignore();
    cout << "\nEnter title: ";
    cin >> title;

    cout << endl;

    if (choice == 1) {
        Book* b = (Book*)item;
        b->setPili(pili);
        --(*b);
    } else if (choice == 2) {
        Magazine* m = (Magazine*)item;
        m->setPili(pili);
        --(*m);
    } else if (choice == 3) {
        DVD* d = (DVD*)item;
        d->setPili(pili);
        --(*d);
    } else if (choice == 4) {
        ResearchPaper* r = (ResearchPaper*)item;
        r->setPili(pili);
        --(*r);
    }

    cout << "Borrowed Successfully: " << title << endl;

    if (choice == 1) {
        Book* b = (Book*)item;
        b->showSelectedValue();
    }
    else if (choice == 2) {
        Magazine* m = (Magazine*)item;
        m->showSelectedValue();
    }
    else if (choice == 3) {
        DVD* d = (DVD*)item;
        d->showSelectedValue();
    }
    else if (choice == 4) {
        ResearchPaper* r = (ResearchPaper*)item;
        r->showSelectedValue();
    }

    delete item;
    return 0;
}