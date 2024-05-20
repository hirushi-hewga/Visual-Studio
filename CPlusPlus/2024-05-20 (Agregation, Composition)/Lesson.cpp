#include <iostream>
using namespace std;

class Cartridge
{
public:
	enum TYPE { NONE, STANDART, L, XL };
private:
	string color;
	float volume;
	TYPE type;
public:
	Cartridge():color("no color"),volume(0),type(NONE) {}
	Cartridge(string c, float v, TYPE t):color(c),volume(v),type(t) {}


	void ShowInfo()const
	{
		cout << "Color : " << color << endl;
		cout << "Volume : " << volume << endl;
		switch (type)
		{
		case Cartridge::NONE: cout << "None" << endl; break;
		case Cartridge::STANDART: cout << "Standart" << endl; break;
		case Cartridge::L: cout << "L" << endl; break;
		case Cartridge::XL: cout << "XL" << endl; break;
		}
		cout << endl;
	}
};

class Scanner
{
private:
	float height, width;
	float scanResolution;
public:
	Scanner():height(0),width(0),scanResolution(0) {}
	Scanner(float h, float w, float s):height(h),width(w),scanResolution(s) {}
	void ShowInfo()const
	{
		cout << "Scanner with " << scanResolution << " dpi" << endl;
		cout << "Area : " << height << " mm. ,   " << width << " mm" << endl;
	}
};

class Printer
{
private:
	string model;
	int year;
	Cartridge* cartridges;
	int countCartridges;
	Scanner scanner; // Default constructor
	const Document* currentDoc;
public:
	Printer():model("no model"),year(0),cartridges(nullptr), countCartridges(0), currentDoc(nullptr) {}
	Printer(string model, int year, float h, float w, float scanR):currentDoc(nullptr)
	{
		this->model = model;
		this->year = year;

		scanner = Scanner(h, w, scanR);

		countCartridges = 4;
		cartridges = new Cartridge[countCartridges];
		cartridges[0] = Cartridge("Black", 500, Cartridge::XL);
		cartridges[1] = Cartridge("Blue", 300, Cartridge::L);
		cartridges[2] = Cartridge("Green", 200, Cartridge::L);
		cartridges[3] = Cartridge("Red", 100, Cartridge::L);
	}

	void Scan()
	{
		cout << "Scanning.........." << endl;
		scanner.ShowInfo();
	}
	void PrintDocument()
	{
		cout << "Printing document" << endl;
		currentDoc->ShowInfo();
	}
	void ShowProperties()
	{
		cout << "Printing with setting : " << endl;
		for (int i = 0; i < countCartridges; i++)
		{
			cartridges[i].ShowInfo();
		}
	}
	void AddToQueue(const Document& doc)
	{
		currentDoc = &doc;
	}

	~Printer()
	{
		if (cartridges != nullptr)
			delete[] cartridges;
	}
};

class Document
{
private:
	string name;
	string format;
	int pages;
public:
	Document():name("no name"), format("no format"), pages(0) {}
	Document(string name, string format, int pages):name(name), format(format)
	{
		this->pages = pages > 0 ? pages : 0;
	}

	void ShowInfo()const
	{
		cout << "______________ Document : " << name << " ______________" << endl;
		cout << "Format : " << format << endl;
		cout << "Pages : " << pages << endl;
	}
};



int main()
{
	Printer printer("Cannon", 2020, 50, 50, 300);
	printer.Scan();
	printer.PrintDocument();
	printer.ShowProperties();
}