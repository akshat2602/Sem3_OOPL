#include <iostream>
using namespace std;

class publication
{
    private:
    string title;
    float price;

    public:
    publication()
    {
        title = "";
        price = 0.0;
    }
    string get_title()
    {
        return title;
    }
    float get_price()
    {
        return price;
    }
    void set_title(string x)
    {
        title = x;
    }
    void set_price(float x)
    {
        price = x;
    }
};

class book : public publication
{
    private:
    int page_count;

    public: 
    book()
    {
        page_count = 0;
    }
    void display()
    {
        cout << "Title of the book is: " << get_title() << endl;
        cout << "Price of the book is: " << get_price() << endl;
        cout << "Number of pages in the book is: " << page_count << endl;
    }
    void input()
    {
        string temp_title;
        float temp_price;
        cout << "Enter title of the book: ";
        cin >> temp_title;
        cout << "Enter number of pages in the book: ";
        cin >> page_count;
        try
        {
            cout << "Enter price of the book: ";
            cin >> temp_price;
            if(temp_price < 0)
            {
                throw temp_price;
            }
        }
        catch(float x)
        {
            temp_price = 0.0;
            temp_title = "";
            page_count = 0;
            cout << "Exception occured!" << endl;
        }
        set_title(temp_title);
        set_price(temp_price);
    }
};


class tape : public publication
{
    private:
    float time;

    public: 
    tape()
    {
        time = 0.0;
    }
    void display()
    {
        cout << "Title of the tape is: " << get_title() << endl;
        cout << "Price of the tape is: " << get_price() << endl;
        cout << "Total running time of the tape is: " << time << endl;
    }
    void input()
    {
        string temp_title;
        float temp_price;
        cout << "Enter title of the tape: ";
        cin >> temp_title;
        cout << "Enter total running time of the tape: ";
        cin >> time;
        try
        {
            cout << "Enter price of the tape: ";
            cin >> temp_price;
            if(temp_price < 0)
            {
                throw temp_price;
            }
        }
        catch(float x)
        {
            temp_price = 0.0;
            temp_title = "";
            time = 0.0;
            cout << "Exception occured!" << endl;
        }
        set_title(temp_title);
        set_price(temp_price);
    }
};


int main(){
    book* a = new book;
    tape* b = new tape;
    a->input();
    b->input();
    a->display();
    b->display();
    delete a;
    delete b;
    return 0;
}