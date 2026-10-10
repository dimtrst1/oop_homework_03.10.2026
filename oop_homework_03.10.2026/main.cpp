#include <iostream>
using namespace std;

class CPU
{
private:
    string model;
    int cores;

public:
    CPU(string m = "Intel Core i5", int c = 6)
    {
        model = m;
        cores = c;
    }

    void Print()
    {
        cout << "CPU: " << model << endl;
        cout << "Cores: " << cores << endl;
    }
};

class SSD
{
private:
    string model;
    int capacity;

public:
    SSD(string m = "Samsung", int c = 512)
    {
        model = m;
        capacity = c;
    }

    void Print()
    {
        cout << "SSD: " << model << endl;
        cout << "Capacity: " << capacity << " GB" << endl;
    }
};

class RAM
{
private:
    string model;
    int capacity;

public:
    RAM(string m = "Kingston", int c = 16)
    {
        model = m;
        capacity = c;
    }

    void Print()
    {
        cout << "RAM: " << model << endl;
        cout << "Capacity: " << capacity << " GB" << endl;
    }
};

class Mouse
{
private:
    string model;

public:
    Mouse(string m = "Logitech")
    {
        model = m;
    }

    void Print()
    {
        cout << "Mouse: " << model << endl;
    }
};

class Web
{
private:
    string model;

public:
    Web(string m = "Logitech C920")
    {
        model = m;
    }

    void Print()
    {
        cout << "Web camera: " << model << endl;
    }
};

class Laptop
{
private:
    string model;
    double price;

    CPU cpu;
    SSD ssd;
    RAM ram;

    Mouse* mouse;
    Web* web;

public:
    Laptop(string m, double p, CPU c, SSD s, RAM r)
        : model(m), price(p), cpu(c), ssd(s), ram(r)
    {
        mouse = nullptr;
        web = nullptr;
    }

    void SetMouse(Mouse* m)
    {
        mouse = m;
    }

    void SetWeb(Web* w)
    {
        web = w;
    }

    void Print()
    {
        cout << "Laptop: " << model << endl;
        cout << "Price: " << price << "$" << endl;

        cout << endl;

        cpu.Print();
        ssd.Print();
        ram.Print();

        cout << endl;

        if (mouse != nullptr)
        {
            mouse->Print();
        }
        else
        {
            cout << "Mouse is not connected" << endl;
        }

        if (web != nullptr)
        {
            web->Print();
        }
        else
        {
            cout << "Web camera is not connected" << endl;
        }
    }
};

int main()
{
    CPU cpu("Intel Core i7", 8);
    SSD ssd("Samsung 980 Pro", 1000);
    RAM ram("Kingston Fury", 32);

    Laptop laptop("ASUS ZenBook", 1500, cpu, ssd, ram);

    Mouse mouse1("Logitech G Pro");
    Mouse mouse2("Razer DeathAdder");

    Web web1("Logitech C920");
    Web web2("Razer Kiyo");

    laptop.SetMouse(&mouse1);
    laptop.SetWeb(&web1);

    cout << "First configuration:" << endl;
    laptop.Print();

    cout << "\nChanging devices...\n" << endl;

    laptop.SetMouse(&mouse2);
    laptop.SetWeb(&web2);

    cout << "Second configuration:" << endl;
    laptop.Print();

    cout << "\nDisconnecting devices...\n" << endl;

    laptop.SetMouse(nullptr);
    laptop.SetWeb(nullptr);

    laptop.Print();
}
