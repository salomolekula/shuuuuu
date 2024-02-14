#include <iostream>
#include <string>
#include <vector>

class CashRegister
{
private:

    int cashOnHand = 500;

public:

    int cash = 0;

    CashRegister()
    {
        cash = 500;
    }

    CashRegister(int  cash)
        : cash(cash) {}

    void setCashOnHand(int newCashOnHand)
    {
        cashOnHand = newCashOnHand;
    }

    int getCurrentBalance()
    {
        return cashOnHand;
    }

    void acceptAmount(int cost)
    {
        cash += cost;
        cashOnHand -= cost;
    }
};

class DispenserType
{

private:

    int numberOfItems;
    int cost;

public:

    DispenserType()
    {
        numberOfItems = 50;
        cost = 50;
    }

    DispenserType(int numderOfItems, int cost)
        : numberOfItems(numberOfItems), cost(cost) {}

    int getNoOfItems()
    {
        return numberOfItems;
    }

    int getCost()
    {
        return cost;
    }

    void makeSale()
    {
        numberOfItems -= 1;
    }

};

std::ostream& operator<< (std::ostream& s, DispenserType eat)
{
    s << "В наличии имеется " << eat.getNoOfItems() << ". Цена - " << eat.getCost() << std::endl;
    return s;
}


void showSelection(std::vector<DispenserType> vct)
{
    const std::vector<std::string> nameVct{"gum", "cookies", "candies", "chips"};


   for (int i = 0; i < 4; i++)
   {
       std::cout << i + 1 << ". " << nameVct[i] << vct[i];
   }

}

void sellProduct(std::vector<DispenserType> vct, int number, CashRegister man)
{
    
    const std::vector<std::string> nameVct{ "gum", "cookie", "candie", "chips" };

    if (man.getCurrentBalance() >= vct[number].getCost())
    {
        vct[number].makeSale();
        man.acceptAmount(vct[number].getCost());
        std::cout << "Вы совершили покупку! Теперь у вас на руках " << man.getCurrentBalance() << " и " << nameVct[number] << std::endl;
    }
    else std::cout << "Ой-ой, деняк нема!";
}

int main()
{
    CashRegister man;
    std::vector<DispenserType> soldingItems;

    DispenserType cookies;
    DispenserType gum;
    DispenserType candies;
    DispenserType chips;

    soldingItems.push_back(gum);
    soldingItems.push_back(cookies);
    soldingItems.push_back(candies);
    soldingItems.push_back(chips);

    showSelection(soldingItems);

    std::cout << "Make a chose(tab number)" << std::endl;
    int number;
    std::cin >> number;



    sellProduct(soldingItems, number, man);
}