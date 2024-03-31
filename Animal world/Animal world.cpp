#include <iostream>
using namespace std;
class Lion;
class Bison;
class Wildebeest;
class Wolf;
class Continent{};
class Africa : public Continent{
    Wildebeest* wildebeest;
    Lion* lion;
};

class NorthAmerica : public Continent{
    Wolf* wolf;
    Bison* bison;
 
};

class Herbivore{
    double weight;
    bool life = true;
public:
    virtual ~Herbivore() {}

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Herbivore eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Herbivore\n";
    }

    friend class Client;
};
class Wildebeest : public Herbivore{
    double weight = 80 + rand() % (300 - 80) * 0.1;
    bool life = true;
protected:
    virtual ~Wildebeest(){}

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Wildebeest eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Wildebeest\n";
    }

    friend class Client;
};

class Bison : public Herbivore {
    double weight = 400 + rand() % (1200 - 400) * 0.1;
    bool life = true;
protected:
    virtual ~Bison(){}

    virtual void SetWeight(double weight)
    {
        this->weight = weight;
    }

    virtual double GetWeight() const
    {
        return weight;
    }

    virtual void SetLife(bool life)
    {
        this->life = life;
    }

    virtual bool GetLife() const
    {
        return life;
    }

    virtual void Eat() {
        cout << "Bison eats grass\n";
        weight += 10;
    }

    virtual void Print()
    {
        cout << "Bison\n";
    }

    friend class Client;
};

class Carnivore{
    int power;
public:
    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() const {
        return power;
    }

    virtual ~Carnivore(){}

    virtual void Eat(Herbivore* animal) {
        cout << "Carnivore eats "; 
        animal->Print();
    }

    virtual void Print()
    {
        cout << "Carnivore\n";
    }
    friend class Client;
};

class Wolf : public Carnivore{
    int power = 50 + rand() % (200 - 50);
protected:
    virtual ~Wolf(){}

    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() const {
        return power;
    }

    virtual void Eat(Herbivore* animal) {
        if(animal->GetLife())
        {
            if (power >= animal->GetWeight()) power += 10;
            else power -= 10;
            animal->SetLife(false);
            cout << "Wolf eats ";
            animal->Print();
        }
    }
    virtual void Print()
    {
        cout << "Wolf\n";
    }
    friend class Client;
};

class Lion : public Carnivore{
    int power = 100 + rand() % (500 - 100);
protected:
    virtual ~Lion() {}

    virtual void SetPower(int power) {
        this->power = power;
    }

    virtual int GetPower() const {
        return power;
    }

    virtual void Eat(Herbivore* animal) {
        if(animal->GetLife())
        {
            if (power >= animal->GetWeight()) power += 10;
            else power -= 10;
            animal->SetLife(false);
            cout << "Lion eats ";
            animal->Print();
        }
    }
    virtual void Print()
    {
        cout << "Lion\n";
    }
    friend class Client;
};

class Client {
public:
    void FeedHerbivore(Herbivore* herbivore) {
        herbivore->Eat();
    }

    void FeedCarnivore(Carnivore* carbivore, Herbivore* herbivore) {
        carbivore->Eat(herbivore);
    }

    void FeedAllHerbivores() {
        void (Herbivore:: *eat)() = &Herbivore::Eat;
        Herbivore* temp = new Herbivore;
        (temp->*eat)();
    }
};
int main()
{
    srand(time(0));
    Herbivore* herbivores[3];
    Carnivore* carnivores[3];
    for (int i = 0; i < 3; i++)
    {
        int random_number = rand() % 2;        
        if (random_number == 1){ 
            herbivores[i] = new Wildebeest;
            carnivores[i] = new Wolf;
        }
        else 
        {
            herbivores[i] = new Bison;
            carnivores[i] = new Lion;
        }
        herbivores[i]->Print();
        carnivores[i]->Print();
    }
    Client a;
    //a.FeedAllHerbivores();
    for(int i = 0; i < 3; i++)
    {
        cout << herbivores[i]->GetWeight() << " " << carnivores[i]->GetPower() << "\n";
        a.FeedCarnivore(carnivores[i], herbivores[i]);
    }
}
