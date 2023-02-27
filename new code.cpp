#include<iostream>
#include<string>
#include<vector>

struct Birthday
{
    std::string name;
    std::string mail;
    int day;
    int month;
    int year;
};

void add_birthday(std::vector<Birthday>& birthdays)
{
    Birthday b;
    std::cout<<"Enter name:";
    std::cin>>b.name;
    std::cout<<"Enter mail:";
    std::cin>>b.mail;
    std::cout<<"Enter day:";
    std::cin>>b.day;
    std::cout<<"Enter month:";
    std::cin>>b.month;
    std::cout<<"Enter year:";
    std::cin>>b.year;
    birthdays.push_back(b);

}

void list_birthdays_in_month(const std::vector<Birthday>& birthdays)
{
    int month;
    std::cout<<"Enter month:";
    std::cin>>month;
    std::cout<<"Birthday in month:"<<month<<":\n";
    for(const auto& b : birthdays)
    {
        if (b.month == month)
        {
            std::cout<<b.name<<"("<<b.day<<")\n";
        }
    }

}

void edit_birthday(std::vector<Birthday>& birthdays)
{
    std::string name;
    std::cout<<"Enter name";
    std::cin>>name;
        for(auto& b : birthdays)
        {
            if (b.name == name)
            {
                std::cout<<"Enter day:";
                std::cin>>b.day;
                std::cout<<"Enter month:";
                std::cin>>b.month;
                std::cout<<"Enter year:";
                std::cin>>b.year;
                return;
            }
        }
        std::cout<<"Birthday not found.\n";

}

void search_birthday(const std::vector<Birthday>& birthdays)
{


    std::string name;
    std::cout<<"Enter name:";
    std::cin>>name;
    for(const auto& b : birthdays)
    {
        if(b.name == name)
        {
            std::cout<<"NAME :"<<b.name;
            std::cout<<",Email:"<<b.mail;
            std::cout<<",DATE :"<<b.day<<b.month<<b.year<<"\n";
            return;
        }
    }
    std::cout<<"Birthday not found.\n";

}



void display_menu()
{
    std::cout<<"1.Add birthday\n";
    std::cout<<"2.List birthdays in a month\n";
    std::cout<<"3.Edit birthday\n";
    std::cout<<"4.Search for a birthdays\n";
    std::cout<<"5.Display all birthdays\n";
    std::cout<<"6.Exit\n";
    std::cout<<"Enter your choice(1-6):";

}
void display_birthdays(const std::vector<Birthday>& birthdays)
{
    std::cout<<"All birthdays:\n";
    {
        for(const auto& b : birthdays)
        {
            std::cout<<"NAME  :"<<b.name;
            std::cout<<",EMAIL :"<<b.mail;
            std::cout<<",DATE :"<<b.day<<b.month<<b.year<<"\n";
        }
    }
}
int main()
{
    std::vector<Birthday> birthdays;
    int choice;
    do
    {
        display_menu();
        std::cin>>choice;
        switch(choice)
        {
        case 1:
            add_birthday(birthdays);
            break;
        case 2:
            list_birthdays_in_month(birthdays);
            break;
        case 3:
            edit_birthday(birthdays);
            break;
        case 4:
            search_birthday(birthdays);
            break;
        case 5:
            display_birthdays(birthdays);
            break;
        case 6:
            std::cout<<"Existing...\n";
            break;
        default :
            std::cout<<"Invalid choice.\n";

        }
    }while(choice != 6);

    return 0;

}